#include "core.h"
#include "terminal_display.h"
#include "scoring.h"
#include "ft_printf_bonus.h"
#include "line_editor.h"

static int g_exam02_selected_level = 1;

typedef struct s_menu_redraw_ctx
{
    const char *prompt;
} MenuRedrawCtx;

static void redraw_menu_input_line(const char *buf, size_t cursor, void *ctx)
{
    MenuRedrawCtx *draw_ctx;
    size_t prompt_len;

    draw_ctx = (MenuRedrawCtx *)ctx;
    prompt_len = strlen(draw_ctx->prompt);
    printf("\r\033[2K%s%s", draw_ctx->prompt, buf);
    printf("\r");
    if (prompt_len + cursor > 0)
        printf("\033[%zuC", prompt_len + cursor);
    fflush(stdout);
}

static int parse_positive_int(const char *s, int *out)
{
    long val;
    int i;

    if (!s || !s[0])
        return (0);
    i = 0;
    val = 0;
    while (s[i])
    {
        if (s[i] < '0' || s[i] > '9')
            return (0);
        val = (val * 10) + (s[i] - '0');
        if (val > 2147483647)
            return (0);
        i++;
    }
    *out = (int)val;
    return (1);
}

static int read_menu_choice(const char *prompt, int *out)
{
    char line[64];
    int status;
    MenuRedrawCtx draw_ctx;

    draw_ctx.prompt = prompt;
    status = read_line_edit(line, sizeof(line), redraw_menu_input_line, &draw_ctx);
    printf("\n");
    if (status != 1)
        return (0);
    return (parse_positive_int(line, out));
}

static LibFunc exam02_get_selected_level_question(int index)
{
    return exam02_get_question(g_exam02_selected_level, index);
}

static int exam02_get_selected_level_count(void)
{
    return exam02_question_count(g_exam02_selected_level);
}

static int run_exam_rank_02_loop(int mode)
{
    int level_choice;

    while (1)
    {
        system("clear");
        print_banner();
        print_exam02_level_menu();
        if (!read_menu_choice("Enter choice: ", &level_choice))
            return 0;

        if (level_choice == 0)
            return 0;
        if (level_choice < 1 || level_choice > exam02_level_count())
            continue;

        g_exam02_selected_level = level_choice;
        while (1)
        {
            system("clear");
            print_banner();
            run_typing_session(mode, exam02_get_selected_level_question, exam02_get_selected_level_count);
            printf("\n-------------------------------------------\n");
            printf("\nWhat would you like to do next?\n");
            printf("1. Try another question in this level\n");
            printf("2. Change Level\n");
            printf("3. Change Category\n");
            printf("4. Change Mode\n");

            int choice;
            if (!read_menu_choice("Enter your choice: ", &choice) || choice < 1 || choice > 4)
                break;

            if (choice == 1)
                continue;
            if (choice == 2)
                break;
            if (choice == 3)
                return 0;
            longjmp(mode_menu_jump, 1);
        }
    }
}

int select_mode(void)
{

    int mode;
    print_mode_menu();
    if (!read_menu_choice("Your choice: ", &mode) || (mode != 1 && mode != 2 && mode != 3))
    {
        fprintf(stderr, "Exiting.\n");
        return 0;
    }
    return mode;
}

int select_category(void)
{
    int category;
    print_category_menu();
    if (!read_menu_choice("Enter choice: ", &category) || category < 1 || category > 12)
        return 0;
    return category;
}

int run_category_loop(int mode, int category)
{

    system("clear");
    print_banner();
    LibFunc (*get_func_by_index)(int) = NULL;
    int (*get_func_count)(void) = NULL;

    switch (category)
    {
    case 1:
        get_func_by_index = get_char_function_by_index;
        get_func_count = get_char_function_count;
        break;
    case 2:
        get_func_by_index = get_string_function_by_index;
        get_func_count = get_string_function_count;
        break;
    case 3:
        get_func_by_index = get_memory_function_by_index;
        get_func_count = get_memory_function_count;
        break;
    case 4:
        get_func_by_index = get_conv_function_by_index;
        get_func_count = get_conv_function_count;
        break;
    case 5:
        get_func_by_index = get_io_function_by_index;
        get_func_count = get_io_function_count;
        break;
    case 6:
        get_func_by_index = get_bonus_function_by_index;
        get_func_count = get_bonus_function_count;
        break;
    case 7:
        get_func_by_index = get_get_next_line_function_by_index;
        get_func_count = get_get_next_line_function_count;
        break;
    case 8:
        get_func_by_index = get_ft_printf_utils_functions_by_index;
        get_func_count = get_ft_printf_utils_functions_count;
        break;
    case 9:
        get_func_by_index = get_ft_printf_handlers_functions_by_index;
        get_func_count = get_ft_printf_handlers_functions_count;
        break;
    case 10:
        get_func_by_index = get_ft_printf_main_functions_by_index;
        get_func_count = get_ft_printf_main_functions_count;
        break;
    case 11:
        get_func_by_index = get_ft_printf_bonus_function_by_index;
        get_func_count = get_ft_printf_bonus_functions_count;
        break;
    case 12:
        return run_exam_rank_02_loop(mode);
    default:
        fprintf(stderr, "Invalid category.\n");
        return 1;
    }

    while (1)
    {
        run_typing_session(mode, get_func_by_index, get_func_count);
        printf("\n-------------------------------------------\n");
        printf("\nWhat would you like to do next?\n");
        printf("1. Try another function in this category\n");
        printf("2. Change Category\n");
        printf("3. Change Mode\n");

        int choice;
        if (!read_menu_choice("Enter your choice: ", &choice) || choice < 1 || choice > 3)
            break;

        if (choice == 1)
        {
            system("clear");
            print_banner();
            continue;
        }
        else if (choice == 2)
            break;
        else if (choice == 3)
            longjmp(mode_menu_jump, 1);
    }
    return 0;
}

void run_mode(Mode mode, LibFunc *func)
{
    if (!func)
        return;

    if (mode == FREE_MODE)
    {
        run_free_mode(func);
        return;
    }

    system("clear");

    printf("Function: %s\n", func->name);
    printf("Description: \033[32m%s\033[0m\n", func->description);
    printf("Return: %s\n\n", func->return_value);

    const char *code_to_practice = NULL;

    if (func->variant_count > 0)
    {
        printf("This function has multiple implementations:\n");
        for (int i = 0; i < func->variant_count; i++)
            printf("%d. %s\n", i + 1, func->variants[i].style);

        int v = 0;
        if (!read_menu_choice("Select variant: ", &v) || v < 1 || v > func->variant_count)
        {
            fprintf(stderr, "Invalid selection.\n");
            return;
        }
        code_to_practice = func->variants[v - 1].code;
    }
    else
    {
        code_to_practice = func->code;
    }

    // Show code in COPY mode
    if (mode == COPY_MODE && code_to_practice)
    {
        printf("--- Copy Mode ---\n\n");

        const char *line = code_to_practice;
        int line_num = 1;
        while (*line)
        {
            printf("%2d  ", line_num++);

            while (*line && *line != '\n')
            {
                putchar(*line++);
            }

            if (*line == '\n')
            {
                putchar(*line++);
            }
        }
    }
    else if (mode == RECALL_MODE)
    {
        printf("--- Recall Mode ---\nType the function from memory.\n");
    }

    char user_input[INPUT_BUFFER_SIZE] = {0};
    get_user_input(user_input, INPUT_BUFFER_SIZE);

    // printf("\n--- Your Input ---\n%s", user_input);
    if (mode == RECALL_MODE)
        printf("\n--- Correct Implementation ---\n%s\n", code_to_practice);
    int score = compute_similarity_score(user_input, code_to_practice);
    printf("\nScore: %d%%\n", score);

    char norm_file_path[128];
    snprintf(norm_file_path, sizeof(norm_file_path), "typed/%s.c", func->name);
    write_norminette_file(norm_file_path, func->name, user_input);

    int norm_score = check_norminette(norm_file_path);
    printf("Norminette: %s\n", norm_score == 100 ? "✅ Pass" : "❌ Fail");

    if (score == 100)
        printf("✅ Perfect!\n");
    else if (score >= 80)
        printf("👍 Good job, just a few issues.\n");
    else if (score >= 70)
        printf("👍 Not bad. Keep practicing!\n");
    else if (score >= 50)
        printf("⚠️ Getting there, review carefully.\n");
    else
        printf("❌ Needs improvement. Try again!\n");

    save_score_log(func->name, score, mode == COPY_MODE ? "Copy" : "Recall");
}
