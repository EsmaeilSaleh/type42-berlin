#include "core.h"
#include "terminal_display.h"
#include "scoring.h"
#include "ft_printf_bonus.h"
#include "line_editor.h"

static int g_exam02_selected_level = 1;
static int g_exam02_selected_topic = 1;

typedef struct s_exam02_topic_entry
{
    const char *display_name;
    const char *question_name;
    int level;
} Exam02TopicEntry;

typedef struct s_exam02_topic
{
    const char *label;
    const Exam02TopicEntry *entries;
    int count;
} Exam02Topic;

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

static const Exam02TopicEntry g_exam02_topic_1[] = {
    {"putstr", "ft_putstr", 1},
    {"fizzbuzz", "fizzbuzz", 1},
    {"rev_print", "rev_print", 1},
    {"tab_mult", "tab_mult", 3},
    {"paramsum", "paramsum", 3}};

static const Exam02TopicEntry g_exam02_topic_2[] = {
    {"first_word", "first_word", 1},
    {"token_loop_skeleton", "token_loop_skeleton", 1},
    {"last_word", "last_word", 2},
    {"epur_str", "epur_str", 3},
    {"expand_str", "expand_str", 3},
    {"ft_split_is_sep", "ft_split_is_sep", 4},
    {"ft_split_word_count", "ft_split_word_count", 4},
    {"ft_split_word_len", "ft_split_word_len", 4},
    {"ft_split_dup_word", "ft_split_dup_word", 4},
    {"ft_split", "ft_split", 4},
    {"rev_wstr", "rev_wstr", 4},
    {"rostring", "rostring", 4}};

static const Exam02TopicEntry g_exam02_topic_3[] = {
    {"repeat_alpha", "repeat_alpha", 1},
    {"ulstr", "ulstr", 1},
    {"rot_13", "rot_13", 1},
    {"rotone", "rotone", 1},
    {"alpha_mirror", "alpha_mirror", 2},
    {"camel_to_snake", "camel_to_snake", 2},
    {"snake_to_camel", "snake_to_camel", 2},
    {"search_and_replace", "search_and_replace", 1}};

static const Exam02TopicEntry g_exam02_topic_4[] = {
    {"ft_strlen", "ft_strlen", 1},
    {"ft_strcmp", "ft_strcmp", 2},
    {"ft_strdup", "ft_strdup", 2},
    {"ft_strcspn", "ft_strcspn", 2},
    {"ft_strspn", "ft_strspn", 2},
    {"ft_strpbrk", "ft_strpbrk", 2},
    {"ft_strrev", "ft_strrev", 2}};

static const Exam02TopicEntry g_exam02_topic_5[] = {
    {"hidenp", "hidenp", 3},
    {"wdmatch", "wdmatch", 2},
    {"str_capitalizer", "str_capitalizer", 3},
    {"rstr_capitalizer", "rstr_capitalizer", 3}};

static const Exam02TopicEntry g_exam02_topic_6[] = {
    {"ft_atoi", "ft_atoi", 2},
    {"print_hex", "print_hex", 3},
    {"ft_atoi_base", "ft_atoi_base", 3},
    {"ft_itoa", "ft_itoa", 4},
    {"do_op", "do_op", 2}};

static const Exam02TopicEntry g_exam02_topic_7[] = {
    {"max", "max", 2},
    {"is_power_of_2", "is_power_of_2", 2},
    {"lcm", "lcm", 3},
    {"pgcd", "pgcd", 3},
    {"add_prime_sum", "add_prime_sum", 3},
    {"fprime", "fprime", 4}};

static const Exam02TopicEntry g_exam02_topic_8[] = {
    {"print_bits", "print_bits", 2},
    {"reverse_bits", "reverse_bits", 2},
    {"swap_bits", "swap_bits", 2}};

static const Exam02TopicEntry g_exam02_topic_9[] = {
    {"ft_range", "ft_range", 3},
    {"ft_rrange", "ft_rrange", 3},
    {"sort_int_tab", "sort_int_tab", 4}};

static const Exam02TopicEntry g_exam02_topic_10[] = {
    {"inter", "inter", 2},
    {"union", "union", 2}};

static const Exam02TopicEntry g_exam02_topic_11[] = {
    {"ft_list_size", "ft_list_size", 3},
    {"ft_list_foreach", "ft_list_foreach", 4},
    {"ft_list_remove_if", "ft_list_remove_if", 4},
    {"sort_list", "sort_list", 4}};

static const Exam02TopicEntry g_exam02_topic_12[] = {
    {"flood_fill", "flood_fill", 4}};

static const Exam02Topic g_exam02_topics[] = {
    {"Output & small CLI exercises", g_exam02_topic_1, sizeof(g_exam02_topic_1) / sizeof(g_exam02_topic_1[0])},
    {"Word/whitespace handling", g_exam02_topic_2, sizeof(g_exam02_topic_2) / sizeof(g_exam02_topic_2[0])},
    {"Character transform / per-char mapping", g_exam02_topic_3, sizeof(g_exam02_topic_3) / sizeof(g_exam02_topic_3[0])},
    {"Libft-style string functions", g_exam02_topic_4, sizeof(g_exam02_topic_4) / sizeof(g_exam02_topic_4[0])},
    {"Matching / subsequence / case rules", g_exam02_topic_5, sizeof(g_exam02_topic_5) / sizeof(g_exam02_topic_5[0])},
    {"Conversions & base/parsing", g_exam02_topic_6, sizeof(g_exam02_topic_6) / sizeof(g_exam02_topic_6[0])},
    {"Math & number theory", g_exam02_topic_7, sizeof(g_exam02_topic_7) / sizeof(g_exam02_topic_7[0])},
    {"Bitwise", g_exam02_topic_8, sizeof(g_exam02_topic_8) / sizeof(g_exam02_topic_8[0])},
    {"Arrays / ranges / sorting", g_exam02_topic_9, sizeof(g_exam02_topic_9) / sizeof(g_exam02_topic_9[0])},
    {"Sets / uniqueness", g_exam02_topic_10, sizeof(g_exam02_topic_10) / sizeof(g_exam02_topic_10[0])},
    {"Linked lists", g_exam02_topic_11, sizeof(g_exam02_topic_11) / sizeof(g_exam02_topic_11[0])},
    {"Grids / recursion", g_exam02_topic_12, sizeof(g_exam02_topic_12) / sizeof(g_exam02_topic_12[0])}};

static int select_exam_browse_mode(void)
{
    int browse_mode;

    print_exam02_browse_mode_menu();
    if (!read_menu_choice("Enter choice: ", &browse_mode) || browse_mode < 0 || browse_mode > 2)
        return (-1);
    return (browse_mode);
}

static int select_topic(void)
{
    int topic_choice;

    print_exam02_topic_menu();
    if (!read_menu_choice("Enter choice: ", &topic_choice)
        || topic_choice < 0
        || topic_choice > (int)(sizeof(g_exam02_topics) / sizeof(g_exam02_topics[0])))
        return (-1);
    return (topic_choice);
}

static const Exam02Topic *exam02_get_selected_topic(void)
{
    if (g_exam02_selected_topic < 1
        || g_exam02_selected_topic > (int)(sizeof(g_exam02_topics) / sizeof(g_exam02_topics[0])))
        return (NULL);
    return (&g_exam02_topics[g_exam02_selected_topic - 1]);
}

static void print_exam02_topic_function_menu(const Exam02Topic *topic)
{
    int i;

    printf("Exam Rank 02 - Topic %d: %s\n", g_exam02_selected_topic, topic->label);
    printf("Available functions:\n");
    i = 0;
    while (i < topic->count)
    {
        printf("%2d. %s (L%d)\n", i + 1, topic->entries[i].display_name, topic->entries[i].level);
        i++;
    }
    printf("\033[1;31m╔════════════════════════════╗\n");
    printf("║          0. Back           ║\n");
    printf("╚════════════════════════════╝\033[0m\n");
    printf("Enter choice: ");
}

static int select_function_from_topic(const Exam02Topic *topic)
{
    int function_choice;

    print_exam02_topic_function_menu(topic);
    if (!read_menu_choice("Enter choice: ", &function_choice)
        || function_choice < 0
        || function_choice > topic->count)
        return (-1);
    return (function_choice);
}

static int exam02_find_question_index(int level, const char *question_name)
{
    int i;
    int count;
    LibFunc question;

    count = exam02_question_count(level);
    i = 0;
    while (i < count)
    {
        question = exam02_get_question(level, i);
        if (strcmp(question.name, question_name) == 0)
            return (i);
        i++;
    }
    return (-1);
}

static int exam02_topic_has_question(const char *question_name)
{
    int topic_index;
    int entry_index;

    topic_index = 0;
    while (topic_index < (int)(sizeof(g_exam02_topics) / sizeof(g_exam02_topics[0])))
    {
        entry_index = 0;
        while (entry_index < g_exam02_topics[topic_index].count)
        {
            if (strcmp(g_exam02_topics[topic_index].entries[entry_index].question_name, question_name) == 0)
                return (1);
            entry_index++;
        }
        topic_index++;
    }
    return (0);
}

static int exam02_count_missing_topic_questions(void)
{
    int level;
    int index;
    int count;
    LibFunc question;
    int missing_count;

    missing_count = 0;
    level = 1;
    while (level <= exam02_level_count())
    {
        count = exam02_question_count(level);
        index = 0;
        while (index < count)
        {
            question = exam02_get_question(level, index);
            if (!exam02_topic_has_question(question.name))
                missing_count++;
            index++;
        }
        level++;
    }
    return (missing_count);
}

static LibFunc exam02_get_selected_topic_question(int index)
{
    const Exam02Topic *topic;
    int question_index;
    LibFunc empty_func;

    memset(&empty_func, 0, sizeof(empty_func));
    topic = exam02_get_selected_topic();
    if (!topic || index < 0 || index >= topic->count)
    {
        fprintf(stderr, "Invalid Exam Rank 02 topic selection.\n");
        return (empty_func);
    }
    question_index = exam02_find_question_index(topic->entries[index].level, topic->entries[index].question_name);
    if (question_index < 0)
    {
        fprintf(stderr, "Question '%s' is not available in current Exam Rank 02 data.\n", topic->entries[index].display_name);
        return (empty_func);
    }
    return (exam02_get_question(topic->entries[index].level, question_index));
}

static int run_exam_rank_02_level_loop(int mode)
{
    int level_choice;

    while (1)
    {
        system("clear");
        print_banner();
        print_exam02_level_menu();
        if (!read_menu_choice("Enter choice: ", &level_choice))
            return (0);

        if (level_choice == 0)
            return (0);
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
                return (1);
            longjmp(mode_menu_jump, 1);
        }
    }
}

static int run_exam_rank_02_topic_loop(int mode)
{
    int topic_choice;
    int function_choice;
    const Exam02Topic *topic;
    LibFunc func;
    int choice;
    int missing_count;
    int warning_shown;

    missing_count = exam02_count_missing_topic_questions();
    warning_shown = 0;

    while (1)
    {
        system("clear");
        print_banner();
        if (missing_count > 0 && !warning_shown)
        {
            printf("Warning: topic list missing %d functions; updated mapping required.\n", missing_count);
            warning_shown = 1;
        }
        topic_choice = select_topic();
        if (topic_choice == -1)
            continue;
        if (topic_choice == 0)
            return (0);
        g_exam02_selected_topic = topic_choice;
        topic = exam02_get_selected_topic();
        if (!topic)
            continue;
        while (1)
        {
            system("clear");
            print_banner();
            function_choice = select_function_from_topic(topic);
            if (function_choice == -1)
                continue;
            if (function_choice == 0)
                break;
            func = exam02_get_selected_topic_question(function_choice - 1);
            if (!func.name)
                continue;
            run_mode(mode, &func);
            printf("\n-------------------------------------------\n");
            printf("\nWhat would you like to do next?\n");
            printf("1. Try another question in this topic\n");
            printf("2. Change Topic\n");
            printf("3. Change Browse Mode\n");
            printf("4. Change Category\n");
            printf("5. Change Mode\n");
            if (!read_menu_choice("Enter your choice: ", &choice) || choice < 1 || choice > 5)
                break;
            if (choice == 1)
                continue;
            if (choice == 2)
                break;
            if (choice == 3)
                return (0);
            if (choice == 4)
                return (1);
            longjmp(mode_menu_jump, 1);
        }
    }
}

static int run_exam_rank_02_loop(int mode)
{
    int browse_mode;
    int action;

    while (1)
    {
        system("clear");
        print_banner();
        browse_mode = select_exam_browse_mode();
        if (browse_mode == -1)
            continue;
        if (browse_mode == 0)
            return (0);
        if (browse_mode == 1)
            action = run_exam_rank_02_level_loop(mode);
        else
            action = run_exam_rank_02_topic_loop(mode);
        if (action == 1)
            return (0);
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
