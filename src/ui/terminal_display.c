#include "core.h"
#include "line_editor.h"

typedef struct s_input_redraw_ctx
{
    const char *prompt;
} InputRedrawCtx;

static void redraw_input_line(const char *buf, size_t cursor, void *ctx)
{
    InputRedrawCtx *draw_ctx;
    size_t prompt_len;

    draw_ctx = (InputRedrawCtx *)ctx;
    prompt_len = strlen(draw_ctx->prompt);
    printf("\r\033[2K%s%s", draw_ctx->prompt, buf);
    printf("\r");
    if (prompt_len + cursor > 0)
        printf("\033[%zuC", prompt_len + cursor);
    fflush(stdout);
}

void print_function_list(LibFunc (*get_func_by_index)(int), int count)
{
    printf("\nAvailable functions:\n");
    for (int i = 0; i < count; i++)
    {
        LibFunc f = get_func_by_index(i);
        printf("%2d. %s\n", i + 1, f.name);
    }
    printf(" 0. category menu\n");
}
void get_user_input(char *buffer, size_t size)
{
    char line[1024];
    int status;
    InputRedrawCtx draw_ctx;

    buffer[0] = '\0';
    draw_ctx.prompt = "> ";

    printf("\nStart typing below. Type 'END' on a line to finish.\n\n");
    while (1)
    {
        status = read_line_edit(line, sizeof(line), redraw_input_line, &draw_ctx);
        printf("\n");
        if (status <= 0)
            break;
        if (strcmp(line, "END") == 0)
            break;

        if (strlen(buffer) + strlen(line) + 2 >= size)
        {
            fprintf(stderr, "Input buffer full. Truncating input.\n");
            break;
        }

        strncat(buffer, line, size - strlen(buffer) - 1);
        strncat(buffer, "\n", size - strlen(buffer) - 1);
    }
}

void print_mode_menu(void)
{
    printf("Choose a mode:\n");
    printf("1. Copy Mode   (see function code and type it)\n");
    printf("2. Recall Mode (type function from memory)\n");
    printf("3. Free Mode   (type and test your own version)\n");
    printf("\033[1;31m╔════════════════╗\n");
    printf("║    0. Quit     ║\n");
    printf("╚════════════════╝\033[0m\n");
    printf("Your choice: ");
}

void print_category_menu(void)
{
    printf("Select category:\n");
    printf(" 1. Char functions              (%d)\n", get_char_function_count());
    printf(" 2. String functions            (%d)\n", get_string_function_count());
    printf(" 3. Memory functions            (%d)\n", get_memory_function_count());
    printf(" 4. Conversion functions        (%d)\n", get_conv_function_count());
    printf(" 5. Input/Output functions      (%d)\n", get_io_function_count());
    printf(" 6. Linked List functions       (%d)\n", get_bonus_function_count());
    printf(" -------------------------------\n");
    printf(" 7. Get Next Line functions     (%d)\n", get_get_next_line_function_count());
    printf(" -------------------------------\n");
    printf(" 8. ft_printf – Part 1 (Basics)\n");
    printf(" 9. ft_printf – Part 2 (Handlers)\n");
    printf("10. ft_printf – Part 3 (Dispatcher & Core)\n");
    printf("11. ft_printf – Part 4 (Bonus flags)\n");
    printf("12. Exam Rank 02\n");
    printf("\033[1;31m╔════════════════════════════╗\n");
    printf("║       0. Change Mode       ║\n");
    printf("╚════════════════════════════╝\033[0m\n");
    printf("Enter choice: ");
}

void print_exam02_level_menu(void)
{
    printf("Exam Rank 02 - Select level:\n");
    printf(" 1. Level 1\n");
    printf(" 2. Level 2\n");
    printf(" 3. Level 3\n");
    printf(" 4. Level 4\n");
    printf("\033[1;31m╔════════════════════════════╗\n");
    printf("║          0. Back           ║\n");
    printf("╚════════════════════════════╝\033[0m\n");
    printf("Enter choice: ");
}

void print_styled(const char *text, const char *style)
{
    printf("\033[%sm%s\033[0m", style, text);
}

void print_banner(void)
{
    printf("\033[36;1m"
           "\n"
           " ░▒▓██████▓▒░ ░▒▓██████▓▒░░▒▓███████▓▒░░▒▓████████▓▒░ \n"
           "░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░        \n"
           "░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░        \n"
           "░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓███████▓▒░░▒▓██████▓▒░   \n"
           "░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░        \n"
           "░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░        \n"
           " ░▒▓█████▓▒░ ░▒▓██████▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓████████▓▒░ \n"
           "                                                      \n");
    printf("        Welcome to type42-berlin\n\n\033[0m");
}
