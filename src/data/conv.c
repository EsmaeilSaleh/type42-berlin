// conv_functions.c
#include "libft_master.h"
#include <stdio.h>
#include <stdlib.h>

LibFunc conv_functions[] = {
	{
		"ft_atoi",
		"Converts the initial portion of the string pointed to by str to int.",
		"int\tft_atoi(const char *str)\n"
			"{\n"
			"\tint\t\tsign;\n"
			"\tlong\tresult;\n"
			"\n"
			"\tsign = 1;\n"
			"\tresult = 0;\n"
			"\twhile (*str == ' ' || (*str >= '\\t' && *str <= '\\r'))\n"
			"\t\tstr++;\n"
			"\tif (*str == '-' || *str == '+')\n"
			"\t{\n"
			"\t\tif (*str == '-')\n"
			"\t\t\tsign = -1;\n"
			"\t\tstr++;\n"
			"\t}\n"
			"\twhile (*str >= '0' && *str <= '9')\n"
			"\t{\n"
			"\t\tresult = result * 10 + (*str - '0');\n"
			"\t\tstr++;\n"
			"\t}\n"
			"\treturn ((int)(result * sign));\n"
			"}"
	},
	{
		"ft_itoa",
		"Allocates and returns a string representing the integer n.",
		"char\t*ft_itoa(int n)\n"
			"{\n"
			"\tchar\t*str;\n"
			"\tlong\tnb;\n"
			"\tint\t\tlen;\n"
			"\n"
			"\tnb = n;\n"
			"\tlen = 1;\n"
			"\tif (nb < 0)\n"
			"\t{\n"
			"\t\tnb = -nb;\n"
			"\t\tlen++;\n"
			"\t}\n"
			"\tlong temp = nb;\n"
			"\twhile (temp >= 10)\n"
			"\t{\n"
			"\t\ttemp /= 10;\n"
			"\t\tlen++;\n"
			"\t}\n"
			"\tstr = (char *)malloc(sizeof(char) * (len + 1));\n"
			"\tif (!str)\n"
			"\t\treturn (NULL);\n"
			"\tstr[len] = '\\0';\n"
			"\twhile (len--)\n"
			"\t{\n"
			"\t\tstr[len] = (nb % 10) + '0';\n"
			"\t\tnb /= 10;\n"
			"\t}\n"
			"\tif (n < 0)\n"
			"\t\tstr[0] = '-';\n"
			"\treturn (str);\n"
			"}"
	}
};

const int CONV_FUNC_COUNT = sizeof(conv_functions) / sizeof(LibFunc);

LibFunc get_conv_function_by_index(int index)
{
	if (index < 0 || index >= CONV_FUNC_COUNT)
	{
		fprintf(stderr, "Invalid conversion function index.\n");
		exit(1);
	}
	return (conv_functions[index]);
}

int get_conv_function_count(void)
{
	return CONV_FUNC_COUNT;
}
