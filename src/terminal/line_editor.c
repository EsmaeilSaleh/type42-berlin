#include "line_editor.h"
#include <ctype.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <termios.h>
#include <unistd.h>

enum e_line_key
{
    KEY_NONE = 0,
    KEY_EOF,
    KEY_ENTER,
    KEY_BACKSPACE,
    KEY_DELETE,
    KEY_LEFT,
    KEY_RIGHT,
    KEY_HOME,
    KEY_END,
    KEY_CTRL_A,
    KEY_CTRL_B,
    KEY_CTRL_C,
    KEY_CTRL_D,
    KEY_CTRL_E,
    KEY_CTRL_F,
    KEY_CTRL_H,
    KEY_CTRL_J,
    KEY_CTRL_K,
    KEY_CTRL_L,
    KEY_CTRL_T,
    KEY_CTRL_U,
    KEY_CTRL_W,
    KEY_CTRL_X,
    KEY_CTRL_Y,
    KEY_CTRL_UNDERSCORE,
    KEY_ALT_B,
    KEY_ALT_D,
    KEY_ALT_F,
    KEY_ALT_CTRL_J,
    KEY_TAB,
    KEY_PRINTABLE
};

typedef struct s_key_event
{
    enum e_line_key key;
    char ch;
} KeyEvent;

typedef struct s_editor_state
{
    size_t len;
    size_t cursor;
    size_t mark;
    int mark_set;
    int quoted_insert;
    int ctrl_x_pending;
    char *kill_buf;
    size_t kill_len;
    char *undo_buf;
    size_t undo_len;
    size_t undo_cursor;
    int undo_valid;
} EditorState;

static int is_word_char(char c)
{
    return (isalnum((unsigned char)c) || c == '_');
}

static int read_byte(char *c)
{
    ssize_t n;

    n = read(STDIN_FILENO, c, 1);
    return (n == 1);
}

static int read_byte_timeout(char *c, int timeout_ms)
{
    fd_set rfds;
    struct timeval tv;
    int rv;

    FD_ZERO(&rfds);
    FD_SET(STDIN_FILENO, &rfds);
    tv.tv_sec = timeout_ms / 1000;
    tv.tv_usec = (timeout_ms % 1000) * 1000;
    rv = select(STDIN_FILENO + 1, &rfds, NULL, NULL, &tv);
    if (rv <= 0)
        return (0);
    return (read_byte(c));
}

static KeyEvent parse_escape_sequence(void)
{
    KeyEvent ev;
    char c2;
    char c3;
    char c4;

    ev.key = KEY_NONE;
    ev.ch = '\0';
    if (!read_byte_timeout(&c2, 30))
        return (ev);
    if (c2 == '[' || c2 == 'O')
    {
        if (!read_byte_timeout(&c3, 30))
            return (ev);
        if (c2 == '[' && c3 >= '0' && c3 <= '9')
        {
            if (!read_byte_timeout(&c4, 30) || c4 != '~')
                return (ev);
            if (c3 == '1' || c3 == '7')
                ev.key = KEY_HOME;
            else if (c3 == '4' || c3 == '8')
                ev.key = KEY_END;
            else if (c3 == '3')
                ev.key = KEY_DELETE;
            return (ev);
        }
        if (c3 == 'D')
            ev.key = KEY_LEFT;
        else if (c3 == 'C')
            ev.key = KEY_RIGHT;
        else if (c3 == 'H')
            ev.key = KEY_HOME;
        else if (c3 == 'F')
            ev.key = KEY_END;
        return (ev);
    }
    if (c2 == 'b' || c2 == 'B')
        ev.key = KEY_ALT_B;
    else if (c2 == 'd' || c2 == 'D')
        ev.key = KEY_ALT_D;
    else if (c2 == 'f' || c2 == 'F')
        ev.key = KEY_ALT_F;
    else if (c2 == 10)
        ev.key = KEY_ALT_CTRL_J;
    return (ev);
}

static KeyEvent read_key_event(void)
{
    KeyEvent ev;
    char c;

    ev.key = KEY_NONE;
    ev.ch = '\0';
    if (!read_byte(&c))
    {
        ev.key = KEY_EOF;
        return (ev);
    }
    if (c == '\r')
        ev.key = KEY_ENTER;
    else if (c == 127)
        ev.key = KEY_BACKSPACE;
    else if (c == 27)
        ev = parse_escape_sequence();
    else if (c == 1)
        ev.key = KEY_CTRL_A;
    else if (c == 2)
        ev.key = KEY_CTRL_B;
    else if (c == 3)
        ev.key = KEY_CTRL_C;
    else if (c == 4)
        ev.key = KEY_CTRL_D;
    else if (c == 5)
        ev.key = KEY_CTRL_E;
    else if (c == 6)
        ev.key = KEY_CTRL_F;
    else if (c == 8)
        ev.key = KEY_CTRL_H;
    else if (c == 9)
        ev.key = KEY_TAB;
    else if (c == 10)
        ev.key = KEY_CTRL_J;
    else if (c == 11)
        ev.key = KEY_CTRL_K;
    else if (c == 12)
        ev.key = KEY_CTRL_L;
    else if (c == 20)
        ev.key = KEY_CTRL_T;
    else if (c == 21)
        ev.key = KEY_CTRL_U;
    else if (c == 23)
        ev.key = KEY_CTRL_W;
    else if (c == 24)
        ev.key = KEY_CTRL_X;
    else if (c == 25)
        ev.key = KEY_CTRL_Y;
    else if (c == 31)
        ev.key = KEY_CTRL_UNDERSCORE;
    else if (isprint((unsigned char)c))
    {
        ev.key = KEY_PRINTABLE;
        ev.ch = c;
    }
    return (ev);
}

static int enable_raw_mode(struct termios *saved)
{
    struct termios raw;

    if (tcgetattr(STDIN_FILENO, saved) == -1)
        return (0);
    raw = *saved;
    raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
    raw.c_oflag &= ~(OPOST);
    raw.c_cflag |= (CS8);
    raw.c_lflag &= ~(ECHO | ICANON | IEXTEN);
    raw.c_cc[VMIN] = 1;
    raw.c_cc[VTIME] = 0;
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1)
        return (0);
    return (1);
}

static void restore_mode(const struct termios *saved)
{
    tcsetattr(STDIN_FILENO, TCSAFLUSH, saved);
}

static void redraw_if_needed(void (*redraw)(const char *buf, size_t cursor, void *ctx),
                             const char *buf, size_t cursor, void *ctx)
{
    if (redraw)
        redraw(buf, cursor, ctx);
}

static void save_undo(EditorState *st, const char *buf)
{
    memcpy(st->undo_buf, buf, st->len + 1);
    st->undo_len = st->len;
    st->undo_cursor = st->cursor;
    st->undo_valid = 1;
}

static void apply_undo(EditorState *st, char *buf)
{
    if (!st->undo_valid)
        return;
    memcpy(buf, st->undo_buf, st->undo_len + 1);
    st->len = st->undo_len;
    st->cursor = st->undo_cursor;
    if (st->cursor > st->len)
        st->cursor = st->len;
}

static void set_kill_text(EditorState *st, const char *src, size_t len)
{
    memcpy(st->kill_buf, src, len);
    st->kill_buf[len] = '\0';
    st->kill_len = len;
}

static int insert_bytes(char *buf, size_t cap, EditorState *st,
                        const char *src, size_t src_len)
{
    size_t n;

    if (cap == 0 || src_len == 0)
        return (0);
    n = src_len;
    if (st->len + n >= cap)
        n = (cap - 1) - st->len;
    if (n == 0)
        return (0);
    memmove(buf + st->cursor + n, buf + st->cursor, (st->len - st->cursor) + 1);
    memcpy(buf + st->cursor, src, n);
    st->len += n;
    st->cursor += n;
    return (1);
}

static int delete_range(char *buf, EditorState *st, size_t start, size_t end, int save_kill)
{
    size_t n;

    if (end <= start || end > st->len)
        return (0);
    n = end - start;
    if (save_kill)
        set_kill_text(st, buf + start, n);
    memmove(buf + start, buf + end, (st->len - end) + 1);
    st->len -= n;
    if (st->cursor > end)
        st->cursor -= n;
    else if (st->cursor > start)
        st->cursor = start;
    return (1);
}

static size_t word_left_index(const char *buf, size_t cursor)
{
    size_t i;

    i = cursor;
    while (i > 0 && !is_word_char(buf[i - 1]))
        i--;
    while (i > 0 && is_word_char(buf[i - 1]))
        i--;
    return (i);
}

static size_t word_right_index(const char *buf, size_t len, size_t cursor)
{
    size_t i;

    i = cursor;
    while (i < len && !is_word_char(buf[i]))
        i++;
    while (i < len && is_word_char(buf[i]))
        i++;
    return (i);
}

static int transpose_chars(char *buf, EditorState *st)
{
    char tmp;
    size_t i;

    if (st->len < 2 || st->cursor == 0)
        return (0);
    if (st->cursor == st->len)
        i = st->len - 2;
    else
        i = st->cursor - 1;
    tmp = buf[i];
    buf[i] = buf[i + 1];
    buf[i + 1] = tmp;
    if (st->cursor < st->len)
        st->cursor++;
    return (1);
}

static void handle_ctrl_x_chord(EditorState *st, KeyEvent ev, char *buf)
{
    size_t tmp;

    if (ev.key == KEY_CTRL_U)
        apply_undo(st, buf);
    else if (ev.key == KEY_CTRL_X)
    {
        if (!st->mark_set)
        {
            st->mark = st->cursor;
            st->mark_set = 1;
            return;
        }
        tmp = st->cursor;
        st->cursor = st->mark;
        if (st->cursor > st->len)
            st->cursor = st->len;
        st->mark = tmp;
    }
}

int read_line_edit(char *buf, size_t cap,
                   void (*redraw)(const char *buf, size_t cursor, void *ctx),
                   void *ctx)
{
    struct termios saved;
    EditorState st;
    int ret;

    if (!buf || cap == 0)
        return (0);
    if (!enable_raw_mode(&saved))
        return (0);
    st.kill_buf = (char *)malloc(cap);
    st.undo_buf = (char *)malloc(cap);
    if (!st.kill_buf || !st.undo_buf)
    {
        free(st.kill_buf);
        free(st.undo_buf);
        restore_mode(&saved);
        return (0);
    }

    buf[0] = '\0';
    st.len = 0;
    st.cursor = 0;
    st.mark = 0;
    st.mark_set = 0;
    st.quoted_insert = 0;
    st.ctrl_x_pending = 0;
    st.kill_len = 0;
    st.kill_buf[0] = '\0';
    st.undo_len = 0;
    st.undo_cursor = 0;
    st.undo_valid = 0;
    ret = 0;

    redraw_if_needed(redraw, buf, st.cursor, ctx);
    while (1)
    {
        KeyEvent ev;

        if (st.quoted_insert)
        {
            char literal;

            if (!read_byte(&literal))
            {
                ret = -1;
                break;
            }
            st.quoted_insert = 0;
            save_undo(&st, buf);
            if (insert_bytes(buf, cap, &st, &literal, 1))
                redraw_if_needed(redraw, buf, st.cursor, ctx);
            continue;
        }

        ev = read_key_event();
        if (ev.key == KEY_EOF)
        {
            ret = -1;
            break;
        }

        if (st.ctrl_x_pending)
        {
            handle_ctrl_x_chord(&st, ev, buf);
            st.ctrl_x_pending = 0;
            redraw_if_needed(redraw, buf, st.cursor, ctx);
            continue;
        }

        if (ev.key == KEY_ENTER)
        {
            ret = 1;
            break;
        }
        if (ev.key == KEY_CTRL_C)
        {
            ret = 0;
            break;
        }
        if (ev.key == KEY_CTRL_J || ev.key == KEY_ALT_CTRL_J)
        {
            st.quoted_insert = 1;
            continue;
        }
        if (ev.key == KEY_CTRL_X)
        {
            st.ctrl_x_pending = 1;
            continue;
        }

        if (ev.key == KEY_CTRL_A || ev.key == KEY_HOME)
            st.cursor = 0;
        else if (ev.key == KEY_CTRL_E || ev.key == KEY_END)
            st.cursor = st.len;
        else if ((ev.key == KEY_LEFT || ev.key == KEY_CTRL_B) && st.cursor > 0)
            st.cursor--;
        else if ((ev.key == KEY_RIGHT || ev.key == KEY_CTRL_F) && st.cursor < st.len)
            st.cursor++;
        else if (ev.key == KEY_ALT_B)
            st.cursor = word_left_index(buf, st.cursor);
        else if (ev.key == KEY_ALT_F)
            st.cursor = word_right_index(buf, st.len, st.cursor);
        else if ((ev.key == KEY_BACKSPACE || ev.key == KEY_CTRL_H) && st.cursor > 0)
        {
            save_undo(&st, buf);
            delete_range(buf, &st, st.cursor - 1, st.cursor, 0);
        }
        else if (ev.key == KEY_CTRL_D)
        {
            if (st.len == 0)
            {
                ret = -1;
                break;
            }
            if (st.cursor < st.len)
            {
                save_undo(&st, buf);
                delete_range(buf, &st, st.cursor, st.cursor + 1, 0);
            }
        }
        else if (ev.key == KEY_DELETE && st.cursor < st.len)
        {
            save_undo(&st, buf);
            delete_range(buf, &st, st.cursor, st.cursor + 1, 0);
        }
        else if (ev.key == KEY_CTRL_K && st.cursor < st.len)
        {
            save_undo(&st, buf);
            delete_range(buf, &st, st.cursor, st.len, 1);
        }
        else if (ev.key == KEY_CTRL_U && st.cursor > 0)
        {
            save_undo(&st, buf);
            delete_range(buf, &st, 0, st.cursor, 1);
        }
        else if (ev.key == KEY_CTRL_W)
        {
            size_t start;

            start = word_left_index(buf, st.cursor);
            if (start < st.cursor)
            {
                save_undo(&st, buf);
                delete_range(buf, &st, start, st.cursor, 1);
            }
        }
        else if (ev.key == KEY_ALT_D)
        {
            size_t end;

            end = word_right_index(buf, st.len, st.cursor);
            if (end > st.cursor)
            {
                save_undo(&st, buf);
                delete_range(buf, &st, st.cursor, end, 1);
            }
        }
        else if (ev.key == KEY_CTRL_Y && st.kill_len > 0)
        {
            save_undo(&st, buf);
            insert_bytes(buf, cap, &st, st.kill_buf, st.kill_len);
        }
        else if (ev.key == KEY_CTRL_T)
        {
            save_undo(&st, buf);
            transpose_chars(buf, &st);
        }
        else if (ev.key == KEY_CTRL_UNDERSCORE)
            apply_undo(&st, buf);
        else if (ev.key == KEY_CTRL_L)
            write(STDOUT_FILENO, "\033[2J\033[H", 7);
        else if (ev.key == KEY_TAB)
        {
            char tab;

            tab = '\t';
            save_undo(&st, buf);
            insert_bytes(buf, cap, &st, &tab, 1);
        }
        else if (ev.key == KEY_PRINTABLE)
        {
            save_undo(&st, buf);
            insert_bytes(buf, cap, &st, &ev.ch, 1);
        }
        redraw_if_needed(redraw, buf, st.cursor, ctx);
    }

    free(st.kill_buf);
    free(st.undo_buf);
    restore_mode(&saved);
    return (ret);
}
