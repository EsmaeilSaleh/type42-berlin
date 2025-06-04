// char_functions.c
#include "core.h"

LibFunc char_functions[] = {
	{
		"ft_isalpha",
		"Checks if the character is alphabetic.",
		"int\tft_isalpha(int c)\n"
			"{\n"
			"\treturn ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));\n"
			"}"
	},
	{
		"ft_isdigit",
		"Checks if the character is a digit (0-9).",
		"int\tft_isdigit(int c)\n"
			"{\n"
			"\treturn (c >= '0' && c <= '9');\n"
			"}"
	},
	{
		"ft_isalnum",
		"Checks if the character is alphanumeric (letter or digit).",
		"int\tft_isalnum(int c)\n"
			"{\n"
			"\treturn (ft_isalpha(c) || ft_isdigit(c));\n"
			"}"
	},
	{
		"ft_isascii",
		"Checks if the character is an ASCII character (0-127).",
		"int\tft_isascii(int c)\n"
			"{\n"
			"\treturn (c >= 0 && c <= 127);\n"
			"}"
	},
	{
		"ft_isprint",
		"Checks if the character is printable including space.",
		"int\tft_isprint(int c)\n"
			"{\n"
			"\treturn (c >= 32 && c <= 126);\n"
			"}"
	},
	{
		"ft_toupper",
		"Converts a lowercase letter to uppercase.",
		"int\tft_toupper(int c)\n"
			"{\n"
			"\tif (c >= 'a' && c <= 'z')\n"
			"\t\treturn (c - 32);\n"
			"\treturn (c);\n"
			"}"
	},
	{
		"ft_tolower",
		"Converts an uppercase letter to lowercase.",
		"int\tft_tolower(int c)\n"
			"{\n"
			"\tif (c >= 'A' && c <= 'Z')\n"
			"\t\treturn (c + 32);\n"
			"\treturn (c);\n"
			"}"
	}
};
#include <stdio.h>
#include <stdlib.h>

const int CHAR_FUNC_COUNT = sizeof(char_functions) / sizeof(LibFunc);

LibFunc get_char_function_by_index(int index)
{
	if (index < 0 || index >= CHAR_FUNC_COUNT)
	{
		fprintf(stderr, "Invalid char function index.\n");
		exit(1);
	}
	return (char_functions[index]);
}

int get_char_function_count(void)
{
	return CHAR_FUNC_COUNT;
}
