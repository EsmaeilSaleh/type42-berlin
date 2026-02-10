#include "core.h"
#include "free_runner.h"
#include "line_editor.h"
#include <stdio.h>
#include <string.h>

typedef struct s_free_redraw_ctx
{
    const char *prompt;
} FreeRedrawCtx;

static size_t visual_width_until(const char *buf, size_t limit)
{
    size_t i;
    size_t width;

    i = 0;
    width = 0;
    while (buf[i] && i < limit)
    {
        if (buf[i] == '\t')
            width += 4;
        else
            width++;
        i++;
    }
    return (width);
}

static void print_with_tabs_expanded(const char *buf)
{
    size_t i;

    i = 0;
    while (buf[i])
    {
        if (buf[i] == '\t')
            printf("    ");
        else
            putchar(buf[i]);
        i++;
    }
}

static void redraw_free_input_line(const char *buf, size_t cursor, void *ctx)
{
    FreeRedrawCtx *draw_ctx;
    size_t prompt_len;
    size_t visual_cursor;

    draw_ctx = (FreeRedrawCtx *)ctx;
    prompt_len = strlen(draw_ctx->prompt);
    visual_cursor = prompt_len + visual_width_until(buf, cursor);
    printf("\r\033[2K%s", draw_ctx->prompt);
    print_with_tabs_expanded(buf);
    printf("\r");
    if (visual_cursor > 0)
        printf("\033[%zuC", visual_cursor);
    fflush(stdout);
}

void run_free_mode(LibFunc *func)
{
    char line[1024];
    char typed_text[MAX_INPUT_SIZE];
    char result_output[4096];
    size_t used_len;
    int status;
    int result;
    FreeRedrawCtx draw_ctx;

    // Print header
    printf("\n\033[1;36mFree Mode – Practice: %s\033[0m\n", func->name);
    printf("Type your function below (type END alone in a line to finish):\n");
    draw_ctx.prompt = "> ";
    typed_text[0] = '\0';
    used_len = 0;

    while (1)
    {
        status = read_line_edit(line, sizeof(line), redraw_free_input_line, &draw_ctx);
        printf("\n");
        if (status <= 0)
            break;
        if (strcmp(line, "END") == 0)
            break;
        if (used_len + strlen(line) + 2 >= sizeof(typed_text))
        {
            printf("\n\033[1;31mInput buffer full. Stopping capture.\033[0m\n");
            break;
        }
        strcat(typed_text, line);
        strcat(typed_text, "\n");
        used_len = strlen(typed_text);
    }
    printf("\nCompiling and running tests...\n\n");
    result = free_mode_compile_and_test(func->name, typed_text,
                                        result_output, sizeof(result_output));
    if (result == FREE_RUNNER_OK)
        printf("\033[1;32m✅ OK\033[0m\n%s\n", result_output);
    else if (result == FREE_RUNNER_COMPILE_ERROR)
        printf("\033[1;31m❌ COMPILE ERROR\033[0m\n%s\n", result_output);
    else if (result == FREE_RUNNER_FAIL)
        printf("\033[1;31m❌ FAIL\033[0m\n%s\n", result_output);
    else
        printf("\033[1;31m❌ ERROR\033[0m\n%s\n", result_output);

    printf("\nPress Enter to return to menu...");
    getchar();
}
