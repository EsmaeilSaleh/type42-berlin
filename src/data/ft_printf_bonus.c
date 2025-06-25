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
    {"handle_hash_flag",
     "Handles the '#' (alternate form) flag in formatting.",
     "For 'o' adds a leading 0; for 'x'/'X' adds 0x/0X prefix.",
     NULL,
     0,
     "int	handle_hash_flag(char specifier, unsigned int n)\n"
     "{\n"
     "\tif (specifier == 'o')\n"
     "\t\treturn (printf(\"0%o\", n));\n"
     "\telse if (specifier == 'x')\n"
     "\t\treturn (printf(\"0x%x\", n));\n"
     "\telse if (specifier == 'X')\n"
     "\t\treturn (printf(\"0X%X\", n));\n"
     "\treturn (printf(\"%u\", n));\n"
     "}\n"},
    {"handle_space_flag",
     "Handles the ' ' (space) flag in integer formatting.",
     "Adds a leading space to positive integers if no '+' flag is present.",
     NULL,
     0,
     "int	handle_space_flag(int n)\n"
     "{\n"
     "\tif (n >= 0)\n"
     "\t\treturn (printf(\" %d\", n));\n"
     "\treturn (printf(\"%d\", n));\n"
     "}\n"},
    {"handle_left_align_flag",
     "Handles the '-' (left-align) flag with field width.",
     "Left-justifies the given string within the specified field width.",
     NULL,
     0,
     "int	handle_left_align_flag(const char *s, int width)\n"
     "{\n"
     "\tint len = strlen(s);\n"
     "\tint padding = width - len;\n"
     "\tint printed = printf(\"%s\", s);\n"
     "\twhile (padding-- > 0)\n"
     "\t\twrite(1, \" \", 1);\n"
     "\treturn printed + (width - len > 0 ? width - len : 0);\n"
     "}\n"},
    {"handle_zero_flag",
     "Handles the '0' (zero-padding) flag with numeric output.",
     "Pads numeric output with leading zeros to match the specified width.",
     NULL,
     0,
     "int	handle_zero_flag(int n, int width)\n"
     "{\n"
     "\tint len = snprintf(NULL, 0, \"%d\", n);\n"
     "\tint padding = width - len;\n"
     "\twhile (padding-- > 0)\n"
     "\t\twrite(1, \"0\", 1);\n"
     "\treturn padding + printf(\"%d\", n);\n"
     "}\n"},
    {"handle_precision",
     "Handles the '.' (precision) flag for integers.",
     "Pads the integer with leading zeros to reach the specified precision.",
     NULL,
     0,
     "int	handle_precision(int n, int precision)\n"
     "{\n"
     "\tint len = snprintf(NULL, 0, \"%d\", n);\n"
     "\tint padding = precision - len;\n"
     "\twhile (padding-- > 0)\n"
     "\t\twrite(1, \"0\", 1);\n"
     "\treturn printf(\"%d\", n);\n"
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