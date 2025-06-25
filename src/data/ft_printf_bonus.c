

#include "core.h"

LibFunc ft_printf_bonus_functions[] = {
    {"handle_plus_flag",
     "Handles the '+' flag in integer formatting.",
     "Adds a leading '+' to positive integers if specified in the format string.",
     NULL,
     0,
     "int	handle_plus_flag(int n)\n"
     "{\n"
     "\tif (n >= 0)\n"
     "\t\treturn (printf(\"+%d\", n));\n"
     "\treturn (printf(\"%d\", n));\n"
     "}\n"},
    {"handle_field_width",
     "Pads the output with spaces to meet a minimum field width.",
     "Ensures right-aligned output if no '-' flag is present.",
     NULL,
     0,
     "int	handle_field_width(const char *s, int width)\n"
     "{\n"
     "\tint len = strlen(s);\n"
     "\tint padding = width - len;\n"
     "\twhile (padding-- > 0)\n"
     "\t\twrite(1, \" \", 1);\n"
     "\treturn (printf(\"%s\", s));\n"
     "}\n"},
    {NULL, NULL, NULL, NULL, 0, NULL}};

int get_ft_printf_bonus_functions_count(void)
{
    return sizeof(ft_printf_bonus_functions) / sizeof(LibFunc) - 1;
}

LibFunc get_ft_printf_bonus_function_by_index(int index)
{
    if (index < 0 || index >= get_ft_printf_bonus_functions_count())
    {
        fprintf(stderr, "Invalid ft_printf bonus function!\n");
        exit(1);
    }
    return ft_printf_bonus_functions[index];
}