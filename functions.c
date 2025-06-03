#include <stdio.h>
#include <stdlib.h>
#include "../includes/libft_master.h"

// Define the array of functions
static LibFunc libft_functions[] = {
	{
		"ft_memset",
		"Fills memory with a constant byte.",
		"void\t*ft_memset(void *b, int c, size_t len)\n"
			"{\n"
			"\tsize_t\t\t\t i;\n"
			"\tunsigned char\t*ptr;\n\n"
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
		"Copies memory area.",
		"void\t*ft_memcpy(void *dst, const void *src, size_t n)\n"
			"{\n"
			"\tsize_t i;\n\n"
			"\tif (!dst && !src)\n"
			"\t\treturn (NULL);\n"
			"\ti = 0;\n"
			"\twhile (i < n)\n"
			"\t{\n"
			"\t\t((unsigned char *)dst)[i] = ((unsigned char *)src)[i];\n"
			"\t\ti++;\n"
			"\t}\n"
			"\treturn (dst);\n"
			"}"
	},
	{
		"#include <stddef.h>\n"
			"\n"
			"void	*ft_memcpy(void *dest, const void *src, size_t n)\n"
			"{\n"
			"	size_t				i;\n"
			"	unsigned char		*d;\n"
			"	const unsigned char	*s;\n"
			"\n"
			"	if (!dest && !src)\n"
			"		return (NULL);\n"
			"	d = (unsigned char *)dest;\n"
			"	s = (const unsigned char *)src;\n"
			"	i = 0;\n"
			"	while (i < n)\n"
			"	{\n"
			"		d[i] = s[i];\n"
			"		i++;\n"
			"	}\n"
			"	return (dest);\n"
			"}\n"
	},
	{
		"ft_memmove",
		"Moves memory area safely.",
		"void\t*ft_memmove(void *dst, const void *src, size_t len)\n"
			"{\n"
			"\tsize_t i;\n\n"
			"\tif (!dst && !src)\n"
			"\t\treturn (NULL);\n"
			"\tif (dst < src)\n"
			"\t{\n"
			"\t\ti = 0;\n"
			"\t\twhile (i < len)\n"
			"\t\t{\n"
			"\t\t\t((unsigned char *)dst)[i] = ((unsigned char *)src)[i];\n"
			"\t\t\ti++;\n"
			"\t\t}\n"
			"\t}\n"
			"\telse\n"
			"\t{\n"
			"\t\twhile (len-- > 0)\n"
			"\t\t\t((unsigned char *)dst)[len] = ((unsigned char *)src)[len];\n"
			"\t}\n"
			"\treturn (dst);\n"
			"}"
	},
	{
		"ft_memcmp",
		"Compares memory areas.",
		"int\tft_memcmp(const void *s1, const void *s2, size_t n)\n"
			"{\n"
			"\tsize_t i;\n\n"
			"\ti = 0;\n"
			"\twhile (i < n)\n"
			"\t{\n"
			"\t\tif (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])\n"
			"\t\t\treturn (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);\n"
			"\t\ti++;\n"
			"\t}\n"
			"\treturn (0);\n"
			"}"
	},
	{
		"ft_memchr",
		"Scans memory for a character.",
		"void\t*ft_memchr(const void *s, int c, size_t n)\n"
			"{\n"
			"\tsize_t i;\n\n"
			"\ti = 0;\n"
			"\twhile (i < n)\n"
			"\t{\n"
			"\t\tif (((unsigned char *)s)[i] == (unsigned char)c)\n"
			"\t\t\treturn ((void *)((unsigned char *)s + i));\n"
			"\t\ti++;\n"
			"\t}\n"
			"\treturn (NULL);\n"
			"}"
	}
};

// Returns the number of functions
int get_function_count(void) {
	return sizeof(libft_functions) / sizeof(LibFunc);
}

// Returns a function by index
LibFunc get_function_by_index(int index) {
	if (index < 0 || index >= get_function_count()) {
		fprintf(stderr, "Invalid function index.\n");
		exit(1);
	}
	return libft_functions[index];
}
