#include "core.h"

void print_function_list(LibFunc (*get_func_by_index)(int), int count)
{
    printf("\nAvailable functions:\n");
    for (int i = 0; i < count; i++)
    {
        LibFunc f = get_func_by_index(i);
        printf("%d. %s\n", i + 1, f.name);
    }
    printf("0. Return to category menu\n");
}
void get_user_input(char *buffer, size_t size)
{
    char line[1024];
    buffer[0] = '\0';

    printf("\nStart typing below. Type 'END' on a line to finish.\n\n");
    while (fgets(line, sizeof(line), stdin))
    {
        if (strcmp(line, "END\n") == 0 || strcmp(line, "END\r\n") == 0)
            break;

        if (strlen(buffer) + strlen(line) + 1 >= size)
        {
            fprintf(stderr, "Input buffer full. Truncating input.\n");
            break;
        }

        strncat(buffer, line, size - strlen(buffer) - 1);
    }
}

void print_mode_menu(void)
{
    printf("Choose a mode:\n");
    printf("1. Copy Mode   (see function code and type it)\n");
    printf("2. Recall Mode (type function from memory)\n");
    printf("\033[1;31m╔════════════════╗\n");
    printf("║    0. Quit     ║\n");
    printf("╚════════════════╝\033[0m\n");
    printf("Your choice: ");
}

void print_category_menu(void)
{
    printf("Select category:\n");
    printf("1. String functions\n");
    printf("2. Memory functions\n");
    printf("3. Char functions\n");
    printf("4. Conv functions\n");
    printf("5. Bonus functions\n");
    printf("6. IO functions\n");
    printf("------------------\n");
    printf("7. Get Next Line functions\n");
    printf("8. 📦 ft_printf - Part 1 (Basics)\n");
    printf("\033[1;31m╔══════════════════════════════╗\n");
    printf("║  0. Return to mode menu     ║\n");
    printf("╚══════════════════════════════╝\033[0m\n");
    printf("Enter choice: ");
}

void print_styled(const char *text, const char *style)
{
    printf("\033[%sm%s\033[0m", style, text);
}

void print_banner(void)
{
    printf(
        "\n"
        " ░▒▓██████▓▒░ ░▒▓██████▓▒░░▒▓███████▓▒░░▒▓████████▓▒░ \n"
        "░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░        \n"
        "░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░        \n"
        "░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓███████▓▒░░▒▓██████▓▒░   \n"
        "░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░        \n"
        "░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░        \n"
        " ░▒▓█████▓▒░ ░▒▓██████▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓████████▓▒░ \n"
        "                                                      \n"
        "                                                      \n");
}