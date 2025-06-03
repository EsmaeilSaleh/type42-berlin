// libft_functions.c
#include <stdio.h>
#include <stdlib.h>
#include "libft_master.h"

LibFunc get_function_by_index(int index) {
	static LibFunc functions[] = {
		{
			"ft_strlen",
			"Returns the number of characters in the string.",
			"size_t\tft_strlen(const char *s)\n"
				"{\n"
				"\tsize_t\ti;\n"
				"\n"
				"\ti = 0;\n"
				"\twhile (s[i])\n"
				"\t\ti++;\n"
				"\treturn (i);\n"
				"}"
		},
		{
			"ft_strcpy",
			"Copies string src to dst (including null terminator).",
			"char\t*ft_strcpy(char *dst, const char *src)\n"
				"{\n"
				"\tsize_t\ti;\n"
				"\n"
				"\ti = 0;\n"
				"\twhile (src[i])\n"
				"\t{\n"
				"\t\tdst[i] = src[i];\n"
				"\t\ti++;\n"
				"\t}\n"
				"\tdst[i] = '\\0';\n"
				"\treturn (dst);\n"
				"}"
		},
		{
			"ft_memset",
			"Fills memory with constant byte.",
			"void\t*ft_memset(void *b, int c, size_t len)\n"
				"{\n"
				"\tsize_t\t\ti;\n"
				"\tunsigned char\t*ptr;\n"
				"\n"
				"\tptr = (unsigned char *)b;\n"
				"\ti = 0;\n"
				"\twhile (i < len)\n"
				"\t{\n"
				"\t\tptr[i] = (unsigned char)c;\n"
				"\t\ti++;\n"
				"\t}\n"
				"\treturn (b);\n"
				"}"
		}
	};

	int total = sizeof(functions) / sizeof(functions[0]);
	if (index < 0 || index >= total) {
		fprintf(stderr, "Invalid function index.\n");
		exit(1);
	}
	return functions[index];
}
