#include "core.h"
#include <stdio.h>  // for fprintf, stderr
#include <stdlib.h> // for exit

LibFunc memory_functions[] = {
	{
		"ft_memset",
		"Fills the first n bytes of the memory area pointed to by s with the constant byte c.",
		"void\t*ft_memset(void *s, int c, size_t n)\n"
			"{\n"
			"\tunsigned char\t*p;\n"
			"\tsize_t\t\ti;\n"
			"\n"
			"\tp = (unsigned char *)s;\n"
			"\ti = 0;\n"
			"\twhile (i < n)\n"
			"\t\tp[i++] = (unsigned char)c;\n"
			"\treturn (s);\n"
			"}"
	},
	{
		"ft_bzero",
		"Erases the data in the n bytes of the memory starting at the location pointed to by s, by writing zeros to that area.",
		"void\tft_bzero(void *s, size_t n)\n"
			"{\n"
			"\tft_memset(s, 0, n);\n"
			"}"
	},
	{
		"ft_memcpy",
		"Copies n bytes from memory area src to memory area dest.",
		"void\t*ft_memcpy(void *dest, const void *src, size_t n)\n"
			"{\n"
			"\tsize_t\t\ti;\n"
			"\tunsigned char\t\t*d;\n"
			"\tconst unsigned char\t*s;\n"
			"\n"
			"\tif (!dest && !src)\n"
			"\t\treturn (NULL);\n"
			"\td = (unsigned char *)dest;\n"
			"\ts = (const unsigned char *)src;\n"
			"\ti = 0;\n"
			"\twhile (i < n)\n"
			"\t{\n"
			"\t\td[i] = s[i];\n"
			"\t\ti++;\n"
			"\t}\n"
			"\treturn (dest);\n"
			"}"
	},
	{
		"ft_memmove",
		"Copies n bytes from memory area src to memory area dest. Handles overlapping memory areas safely.",
		"void\t*ft_memmove(void *dest, const void *src, size_t n)\n"
			"{\n"
			"\tunsigned char *d = (unsigned char *)dest;\n"
			"\tconst unsigned char *s = (const unsigned char *)src;\n"
			"\tif (d == s || n == 0)\n"
			"\t\treturn (dest);\n"
			"\tif (d < s)\n"
			"\t\tfor (size_t i = 0; i < n; i++)\n"
			"\t\t\td[i] = s[i];\n"
			"\telse\n"
			"\t\tfor (size_t i = n; i > 0; i--)\n"
			"\t\t\td[i - 1] = s[i - 1];\n"
			"\treturn (dest);\n"
			"}"
	},
	{
		"ft_memchr",
		"Scans the first n bytes of the memory area pointed to by s for the character c.",
		"void\t*ft_memchr(const void *s, int c, size_t n)\n"
			"{\n"
			"\tconst unsigned char *p = (const unsigned char *)s;\n"
			"\tfor (size_t i = 0; i < n; i++)\n"
			"\t\tif (p[i] == (unsigned char)c)\n"
			"\t\t\treturn ((void *)(p + i));\n"
			"\treturn (NULL);\n"
			"}"
	},
	{
		"ft_memcmp",
		"Compares the first n bytes of the memory areas s1 and s2.",
		"int\tft_memcmp(const void *s1, const void *s2, size_t n)\n"
			"{\n"
			"\tconst unsigned char *p1 = (const unsigned char *)s1;\n"
			"\tconst unsigned char *p2 = (const unsigned char *)s2;\n"
			"\tfor (size_t i = 0; i < n; i++)\n"
			"\t\tif (p1[i] != p2[i])\n"
			"\t\t\treturn (p1[i] - p2[i]);\n"
			"\treturn (0);\n"
			"}"
	},
	{
		"ft_calloc",
		"Allocates memory for an array of nmemb elements of size bytes each and returns a pointer to the allocated memory, set to zero.",
		"void\t*ft_calloc(size_t nmemb, size_t size)\n"
			"{\n"
			"\tvoid *ptr = malloc(nmemb * size);\n"
			"\tif (!ptr)\n"
			"\t\treturn (NULL);\n"
			"\tft_bzero(ptr, nmemb * size);\n"
			"\treturn (ptr);\n"
			"}"
	},
	{
		"ft_strdup",
		"Returns a pointer to a new string which is a duplicate of the string s.",
		"char\t*ft_strdup(const char *s)\n"
			"{\n"
			"\tsize_t len = ft_strlen(s);\n"
			"\tchar *dup = (char *)malloc(len + 1);\n"
			"\tif (!dup)\n"
			"\t\treturn (NULL);\n"
			"\tft_strcpy(dup, s);\n"
			"\treturn (dup);\n"
			"}"
	}
};

int get_memory_function_count(void) {
	return sizeof(memory_functions) / sizeof(LibFunc);
}

LibFunc get_memory_function_by_index(int index) {
	if (index < 0 || index >= get_memory_function_count()) {
		fprintf(stderr, "Invalid memory function index.\n");
		exit(1);
	}
	return memory_functions[index];
}
