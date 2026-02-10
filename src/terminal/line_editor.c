#include "line_editor.h"
#include <ctype.h>
#include <stddef.h>
#include <string.h>
#include <sys/select.h>
#include <termios.h>
#include <unistd.h>

enum e_line_key
{
    KEY_NONE = 0,
    KEY_ENTER,
    KEY_BACKSPACE,
    KEY_DELETE,
    KEY_LEFT,
    KEY_RIGHT,
    KEY_HOME,
    KEY_END,
    KEY_CTRL_A,
    KEY_CTRL_D,
    KEY_CTRL_E,
    KEY_CTRL_H,
    KEY_CTRL_K,
    KEY_CTRL_L,
    KEY_CTRL_U,
    KEY_CTRL_W,
    KEY_CTRL_C,
    KEY_PRINTABLE
};

typedef struct s_key_event
{
    enum e_line_key key;
    char ch;
} KeyEvent;

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
    if (c2 != '[' && c2 != 'O')
        return (ev);
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

static KeyEvent read_key_event(void)
{
    KeyEvent ev;
    char c;

    ev.key = KEY_NONE;
    ev.ch = '\0';
    if (!read_byte(&c))
        return (ev);
    if (c == '\r' || c == '\n')
        ev.key = KEY_ENTER;
    else if (c == 127)
        ev.key = KEY_BACKSPACE;
    else if (c == 27)
        ev = parse_escape_sequence();
    else if (c == 1)
        ev.key = KEY_CTRL_A;
    else if (c == 3)
        ev.key = KEY_CTRL_C;
    else if (c == 4)
        ev.key = KEY_CTRL_D;
    else if (c == 5)
        ev.key = KEY_CTRL_E;
    else if (c == 8)
        ev.key = KEY_CTRL_H;
    else if (c == 11)
        ev.key = KEY_CTRL_K;
    else if (c == 12)
        ev.key = KEY_CTRL_L;
    else if (c == 21)
        ev.key = KEY_CTRL_U;
    else if (c == 23)
        ev.key = KEY_CTRL_W;
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

static void delete_prev_word(char *buf, size_t *len, size_t *cursor)
{
    size_t start;
    size_t to_remove;

    if (*cursor == 0)
        return;
    start = *cursor;
    while (start > 0 && isspace((unsigned char)buf[start - 1]))
        start--;
    while (start > 0 && !isspace((unsigned char)buf[start - 1]))
        start--;
    to_remove = *cursor - start;
    memmove(buf + start, buf + *cursor, (*len - *cursor) + 1);
    *len -= to_remove;
    *cursor = start;
}

int read_line_edit(char *buf, size_t cap,
                   void (*redraw)(const char *buf, size_t cursor, void *ctx),
                   void *ctx)
{
    struct termios saved;
    size_t len;
    size_t cursor;

    if (!buf || cap == 0)
        return (0);
    if (!enable_raw_mode(&saved))
        return (0);
    buf[0] = '\0';
    len = 0;
    cursor = 0;
    redraw_if_needed(redraw, buf, cursor, ctx);
    while (1)
    {
        KeyEvent ev = read_key_event();
        if (ev.key == KEY_ENTER)
        {
            restore_mode(&saved);
            return (1);
        }
        if (ev.key == KEY_CTRL_C)
        {
            restore_mode(&saved);
            return (0);
        }
        if (ev.key == KEY_CTRL_A || ev.key == KEY_HOME)
            cursor = 0;
        else if (ev.key == KEY_CTRL_E || ev.key == KEY_END)
            cursor = len;
        else if ((ev.key == KEY_BACKSPACE || ev.key == KEY_CTRL_H) && cursor > 0)
        {
            memmove(buf + cursor - 1, buf + cursor, (len - cursor) + 1);
            cursor--;
            len--;
        }
        else if (ev.key == KEY_CTRL_D)
        {
            if (len == 0)
            {
                restore_mode(&saved);
                return (-1);
            }
            if (cursor < len)
            {
                memmove(buf + cursor, buf + cursor + 1, len - cursor);
                len--;
            }
        }
        else if (ev.key == KEY_DELETE && cursor < len)
        {
            memmove(buf + cursor, buf + cursor + 1, len - cursor);
            len--;
        }
        else if (ev.key == KEY_CTRL_K)
        {
            buf[cursor] = '\0';
            len = cursor;
        }
        else if (ev.key == KEY_CTRL_U && cursor > 0)
        {
            memmove(buf, buf + cursor, (len - cursor) + 1);
            len -= cursor;
            cursor = 0;
        }
        else if (ev.key == KEY_CTRL_W)
            delete_prev_word(buf, &len, &cursor);
        else if (ev.key == KEY_LEFT && cursor > 0)
            cursor--;
        else if (ev.key == KEY_RIGHT && cursor < len)
            cursor++;
        else if (ev.key == KEY_CTRL_L)
            write(STDOUT_FILENO, "\033[2J\033[H", 7);
        else if (ev.key == KEY_PRINTABLE && len + 1 < cap)
        {
            memmove(buf + cursor + 1, buf + cursor, (len - cursor) + 1);
            buf[cursor] = ev.ch;
            cursor++;
            len++;
        }
        redraw_if_needed(redraw, buf, cursor, ctx);
    }
}
