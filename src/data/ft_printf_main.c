#include "core.h"

LibFunc ft_printf_main_functions[] =
    {
        {"ft_printf",
         "The main printf function that parses the format string and prints formatted output.",
         "Returns the total number of characters printed.",
         NULL,
         0,
         "int\tft_printf(const char *format, ...)\n"
         "{\n"
         "\tva_list\targs;\n"
         "\tint\t\tcount;\n"
         "\n"
         "\tva_start(args, format);\n"
         "\tcount = parse_format(format, args);\n"
         "\tva_end(args);\n"
         "\treturn (count);\n"
         "}\n"},
        {"parse_format",
         "Parses the format string and dispatches format specifiers.",
         "Returns the total number of characters printed.",
         NULL,
         0,
         "int\tparse_format(const char *format, va_list args)\n"
         "{\n"
         "\tint\tcount = 0;\n"
         "\twhile (*format)\n"
         "\t{\n"
         "\t\tif (*format == '%')\n"
         "\t\t{\n"
         "\t\t\tformat++;\n"
         "\t\t\tcount += print_arg(*format, args);\n"
         "\t\t}\n"
         "\t\telse\n"
         "\t\t{\n"
         "\t\t\twrite(1, format, 1);\n"
         "\t\t\tcount++;\n"
         "\t\t}\n"
         "\t\tformat++;\n"
         "\t}\n"
         "\treturn (count);\n"
         "}"},
        {"print_arg",
         "Dispatches the format specifier to the correct handler function.",
         "Returns the number of characters printed by the handler.",
         NULL,
         0,
         "int\tprint_arg(char specifier, va_list args)\n"
         "{\n"
         "\tif (specifier == 'c')\n"
         "\t\treturn (handle_char(va_arg(args, int)));\n"
         "\telse if (specifier == 's')\n"
         "\t\treturn (handle_string(va_arg(args, char *)));\n"
         "\telse if (specifier == 'd' || specifier == 'i')\n"
         "\t\treturn (handle_int(va_arg(args, int)));\n"
         "\telse if (specifier == 'u')\n"
         "\t\treturn (handle_unsigned(va_arg(args, unsigned int)));\n"
         "\telse if (specifier == 'x')\n"
         "\t\treturn (handle_hex_lower(va_arg(args, unsigned int)));\n"
         "\telse if (specifier == 'X')\n"
         "\t\treturn (handle_hex_upper(va_arg(args, unsigned int)));\n"
         "\telse if (specifier == 'p')\n"
         "\t\treturn (handle_pointer(va_arg(args, void *)));\n"
         "\telse if (specifier == '%')\n"
         "\t\treturn (handle_percent());\n"
         "\treturn (0);\n"
         "}"}};

int get_ft_printf_main_functions_count(void)
{
    return (sizeof(ft_printf_main_functions) / sizeof(LibFunc));
}

LibFunc get_ft_printf_main_functions_by_index(int index)
{
    if (index < 0 || index >= get_ft_printf_main_functions_count())
    {
        fprintf(stderr, "Invalid printf main function!\n");
        exit(1);
    }
    return ft_printf_main_functions[index];
}