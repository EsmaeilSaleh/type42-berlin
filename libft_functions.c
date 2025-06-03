// libft_functions.c
#include <stdio.h>
#include <stdlib.h>
#include "libft_master.h"

LibFunc get_function_by_index(int index) {
	static LibFunc functions[] = {
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
		},
		{
			"ft_memcpy",
			"Copies n bytes from memory area src to memory area dst.",
			"void\t*ft_memcpy(void *dst, const void *src, size_t n)\n"
				"{\n"
				"\tsize_t\ti;\n"
				"\tunsigned char\t*d;\n"
				"\tconst unsigned char\t*s;\n"
				"\n"
				"\td = (unsigned char *)dst;\n"
				"\ts = (const unsigned char *)src;\n"
				"\ti = 0;\n"
				"\twhile (i < n)\n"
				"\t{\n"
				"\t\td[i] = s[i];\n"
				"\t\ti++;\n"
				"\t}\n"
				"\treturn (dst);\n"
				"}"
		},
		{
			"ft_memmove",
			"Copies n bytes from src to dst, handling overlapping memory.",
			"void\t*ft_memmove(void *dst, const void *src, size_t len)\n"
				"{\n"
				"\tunsigned char\t*d;\n"
				"\tconst unsigned char\t*s;\n"
				"\n"
				"\td = (unsigned char *)dst;\n"
				"\ts = (const unsigned char *)src;\n"
				"\tif (d < s)\n"
				"\t{\n"
				"\t\tsize_t i = 0;\n"
				"\t\twhile (i < len)\n"
				"\t\t{\n"
				"\t\t\td[i] = s[i];\n"
				"\t\t\ti++;\n"
				"\t\t}\n"
				"\t}\n"
				"\telse if (d > s)\n"
				"\t{\n"
				"\t\tsize_t i = len;\n"
				"\t\twhile (i-- > 0)\n"
				"\t\t\td[i] = s[i];\n"
				"\t}\n"
				"\treturn (dst);\n"
				"}"
		},
		{
			"ft_memcmp",
			"Compares the first n bytes of two memory areas.",
			"int\tft_memcmp(const void *s1, const void *s2, size_t n)\n"
				"{\n"
				"\tsize_t\ti;\n"
				"\tconst unsigned char\t*u1;\n"
				"\tconst unsigned char\t*u2;\n"
				"\n"
				"\tu1 = (const unsigned char *)s1;\n"
				"\tu2 = (const unsigned char *)s2;\n"
				"\ti = 0;\n"
				"\twhile (i < n)\n"
				"\t{\n"
				"\t\tif (u1[i] != u2[i])\n"
				"\t\t\treturn (u1[i] - u2[i]);\n"
				"\t\ti++;\n"
				"\t}\n"
				"\treturn (0);\n"
				"}"
		},
		{
			"ft_memchr",
			"Scans memory for character c in the first n bytes.",
			"void\t*ft_memchr(const void *s, int c, size_t n)\n"
				"{\n"
				"\tsize_t\ti;\n"
				"\tconst unsigned char\t*str;\n"
				"\n"
				"\tstr = (const unsigned char *)s;\n"
				"\ti = 0;\n"
				"\twhile (i < n)\n"
				"\t{\n"
				"\t\tif (str[i] == (unsigned char)c)\n"
				"\t\t\treturn ((void *)(str + i));\n"
				"\t\ti++;\n"
				"\t}\n"
				"\treturn (NULL);\n"
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
