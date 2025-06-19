#include "core.h"

LibFunc ft_printf_handlers_functions[] = {
    {"handle_char",
     "Handles %c format specifier.",
     "Returns the number of characters printed (1).",
     NULL,
     0,
     "int handle_char(va_list args)\n"
     "{\n"
     "    char c = (char)va_arg(args, int);\n"
     "    write(1, &c, 1);\n"
     "    return 1;\n"
     "}"},
    {"handle_percent",
     "Handles %% format specifier.",
     "Returns the number of characters printed (1).",
     NULL,
     0,
     "int handle_percent(void)\n"
     "{\n"
     "    write(1, \"%\", 1);\n"
     "    return 1;\n"
     "}"},
    {"handle_string",
     "Handles %s format specifier.",
     "Returns the number of characters printed.",
     NULL,
     0,
     "int handle_string(va_list args)\n"
     "{\n"
     "    char *str = va_arg(args, char *);\n"
     "    if (!str)\n"
     "        str = \"(null)\";\n"
     "    int len = 0;\n"
     "    while (str[len])\n"
     "        len++;\n"
     "    write(1, str, len);\n"
     "    return len;\n"
     "}"},
    {"handle_int",
     "Handles %d, %i format specifiers.",
     "Returns the number of characters printed.",
     NULL,
     0,
     "int handle_int(va_list args)\n"
     "{\n"
     "    int n = va_arg(args, int);\n"
     "    char *str = ft_itoa(n);\n"
     "    int len = ft_strlen(str);\n"
     "    write(1, str, len);\n"
     "    free(str);\n"
     "    return len;\n"
     "}"},
    {"handle_unsigned",
     "Handles %u format specifier.",
     "Returns the number of characters printed.",
     NULL,
     0,
     "int handle_unsigned(va_list args)\n"
     "{\n"
     "    unsigned int n = va_arg(args, unsigned int);\n"
     "    char *str = ft_uitoa(n);\n"
     "    int len = ft_strlen(str);\n"
     "    write(1, str, len);\n"
     "    free(str);\n"
     "    return len;\n"
     "}"},
    {"handle_hex_lower",
     "Handles %x format specifier.",
     "Returns the number of characters printed.",
     NULL,
     0,
     "int handle_hex_lower(va_list args)\n"
     "{\n"
     "    unsigned int n = va_arg(args, unsigned int);\n"
     "    return ft_putnbr_base(n, \"0123456789abcdef\");\n"
     "}"},
    {"handle_hex_upper",
     "Handles %X format specifier.",
     "Returns the number of characters printed.",
     NULL,
     0,
     "int handle_hex_upper(va_list args)\n"
     "{\n"
     "    unsigned int n = va_arg(args, unsigned int);\n"
     "    return ft_putnbr_base(n, \"0123456789ABCDEF\");\n"
     "}"},
    {"handle_pointer",
     "Handles %p format specifier.",
     "Returns the number of characters printed.",
     NULL,
     0,
     "int handle_pointer(va_list args)\n"
     "{\n"
     "    unsigned long ptr = (unsigned long)va_arg(args, void *);\n"
     "    int len = write(1, \"0x\", 2);\n"
     "    len += ft_putnbr_base(ptr, \"0123456789abcdef\");\n"
     "    return len;\n"
     "}"}};

int get_ft_printf_handlers_functions_count(void)
{
    return sizeof(ft_printf_handlers_functions) / sizeof(LibFunc);
}

LibFunc get_ft_printf_handlers_functions_by_index(int index)
{
    if (index < 0 || index >= get_ft_printf_handlers_functions_count())
    {
        fprintf(stderr, "Invalid ft printf handlers function!\\n");
        exit(1);
    }
    return ft_printf_handlers_functions[index];
}