#include "core.h"
#include "line_editor.h"
#include <stdio.h>
#include <stdlib.h>
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
    char command[4096];
    char func_file[256];
    char test_file[256];
    FILE *fp;
    char buffer[1024];
    int status;
    FreeRedrawCtx draw_ctx;

    // Build file paths
    snprintf(func_file, sizeof(func_file), "typed/%s.c", func->name);
    snprintf(test_file, sizeof(test_file), "tests/test_%s.c", func->name);

    // Print header
    printf("\n\033[1;36mFree Mode – Practice: %s\033[0m\n", func->name);
    printf("Type your function below (type END alone in a line to finish):\n");
    draw_ctx.prompt = "> ";

    fp = fopen(func_file, "w");
    if (!fp)
    {
        perror("Error opening file for writing");
        return;
    }

    // Prepend standard includes
    fprintf(fp, "#include <stddef.h>\n#include <stdlib.h>\n#include <unistd.h>\n\n");

    while (1)
    {
        status = read_line_edit(buffer, sizeof(buffer), redraw_free_input_line, &draw_ctx);
        printf("\n");
        if (status <= 0)
            break;
        if (strcmp(buffer, "END") == 0)
            break;
        fprintf(fp, "%s\n", buffer);
    }
    fclose(fp);

    // Confirm and compile
    printf("\n🛠️  Compiling and running tests...\n\n");

    snprintf(command, sizeof(command),
             "echo '\\n🛠️  Compiling %s and %s...' && gcc -I includes %s %s -o tmp_test 2>&1 | tee .compile_log && echo '\\n🧪 Running tests for %s:' && ./tmp_test && rm .tmp_test",
             func_file, test_file, func_file, test_file, func->name);

    int result = system(command);
    if (result != 0)
        printf("\n\033[1;31mTest failed or compilation error.\033[0m\n");
    else
        printf("\n\033[1;32mTest completed successfully.\033[0m\n");

    printf("\nPress Enter to return to menu...");
    getchar();
}
