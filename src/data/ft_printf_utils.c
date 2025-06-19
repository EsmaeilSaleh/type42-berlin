#include "core.h"

LibFunc ft_printf_utils_functions[] = {
    {"ft_putchar_fd",
     "Outputs the character c to the given file descriptor.",
     "None.",
     NULL,
     0,
     "void\tft_putchar_fd(char c, int fd)\n"
     "{\n"
     "\twrite(fd, &c, 1);\n"
     "}"},
    {"ft_putstr_fd",
     "Outputs the string s to the given file descriptor.",
     "None.",
     NULL,
     0,
     "void\tft_putstr_fd(char *s, int fd)\n"
     "{\n"
     "\tint\ti;\n"
     "\n"
     "\tif (!s)\n"
     "\t\treturn;\n"
     "\ti = 0;\n"
     "\twhile (s[i])\n"
     "\t{\n"
     "\t\twrite(fd, &s[i], 1);\n"
     "\t\ti++;\n"
     "\t}\n"
     "}"},
    {"ft_strlen",
     "Returns the length of the string s.",
     "Returns the number of characters before the null terminator.",
     NULL,
     0,
     "size_t\tft_strlen(const char *s)\n"
     "{\n"
     "\tsize_t\ti;\n"
     "\n"
     "\ti = 0;\n"
     "\twhile (s[i])\n"
     "\t\ti++;\n"
     "\treturn (i);\n"
     "}"},
    {"ft_putnbr_fd",
     "Outputs an integer n to the given file descriptor.",
     "None.",
     NULL,
     0,
     "void\tft_putnbr_fd(int n, int fd)\n"
     "{\n"
     "\tchar\tc;\n"
     "\tif (n == -2147483648)\n"
     "\t\treturn (write(fd, \"-2147483648\", 11));\n"
     "\tif (n < 0)\n"
     "\t{\n"
     "\t\twrite(fd, \"-\", 1);\n"
     "\t\tn = -n;\n"
     "\t}\n"
     "\tif (n > 9)\n"
     "\t\tft_putnbr_fd(n / 10, fd);\n"
     "\tc = n % 10 + '0';\n"
     "\twrite(fd, &c, 1);\n"
     "}"},
};

int get_ft_printf_utils_functions_count(void)
{
    return sizeof(ft_printf_utils_functions) / sizeof(LibFunc);
}

LibFunc get_ft_printf_utils_functions_by_index(int index)
{
    if (index < 0 || index >= get_bonus_function_count())
    {
        fprintf(stderr, "Invalid get_next_line function index.\\n");
        exit(1);
    }
    return ft_printf_utils_functions[index];
}