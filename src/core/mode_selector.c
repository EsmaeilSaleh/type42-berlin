#include "core.h"
#include "terminal_display.h"
#include "scoring.h"

int select_mode(void)
{

    int mode;
    print_mode_menu();
    if (scanf("%d", &mode) != 1 || (mode != 1 && mode != 2))
    {
        fprintf(stderr, "Exiting.\n");
        return 0;
    }
    getchar();
    return mode;
}

int select_category(void)
{
    int category;
    print_category_menu();
    if (scanf("%d", &category) != 1 || category < 1 || category > 10)
        return 0;
    getchar();
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
        printf("Enter your choice: ");

        int choice;
        if (scanf("%d", &choice) != 1 || choice < 1 || choice > 3)
            break;
        getchar();

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

        printf("Select variant: ");
        int v = 0;
        if (scanf("%d", &v) != 1 || v < 1 || v > func->variant_count)
        {
            fprintf(stderr, "Invalid selection.\n");
            return;
        }
        getchar(); // Consume leftover newline
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