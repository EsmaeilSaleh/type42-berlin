#include "libft_master.h"
#include <stdio.h>  // for fprintf, stderr
#include <stdlib.h> // for exit

LibFunc string_functions[] = {
	{
		"ft_strlen",
		"Calculates the length of a string.",
		"size_t\tft_strlen(const char *s)\n"
			"{\n"
			"\tsize_t i = 0;\n"
			"\twhile (s[i])\n"
			"\t\ti++;\n"
			"\treturn (i);\n"
			"}"
	},
	{
		"ft_strcpy",
		"Copies a string from src to dst.",
		"char\t*ft_strcpy(char *dst, const char *src)\n"
			"{\n"
			"\tsize_t i = 0;\n"
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
		"ft_strdup",
		"Returns a pointer to a new string which is a duplicate of the string s1.",
		"char\t*ft_strdup(const char *s1)\n"
			"{\n"
			"\tsize_t len = ft_strlen(s1);\n"
			"\tchar *copy = (char *)malloc(len + 1);\n"
			"\tif (!copy)\n"
			"\t\treturn (NULL);\n"
			"\treturn (ft_strcpy(copy, s1));\n"
			"}"
	},
	{
		"ft_strchr",
		"Locates the first occurrence of c in the string s.",
		"char\t*ft_strchr(const char *s, int c)\n"
			"{\n"
			"\twhile (*s)\n"
			"\t{\n"
			"\t\tif (*s == (char)c)\n"
			"\t\t\treturn ((char *)s);\n"
			"\t\ts++;\n"
			"\t}\n"
			"\tif (c == '\\0')\n"
			"\t\treturn ((char *)s);\n"
			"\treturn (NULL);\n"
			"}"
	},
	{
		"ft_strrchr",
		"Locates the last occurrence of c in the string s.",
		"char\t*ft_strrchr(const char *s, int c)\n"
			"{\n"
			"\tconst char *last = NULL;\n"
			"\twhile (*s)\n"
			"\t{\n"
			"\t\tif (*s == (char)c)\n"
			"\t\t\tlast = s;\n"
			"\t\ts++;\n"
			"\t}\n"
			"\tif (c == '\\0')\n"
			"\t\treturn ((char *)s);\n"
			"\treturn ((char *)last);\n"
			"}"
	},
	{
		"ft_strncmp",
		"Compares up to n characters of the strings s1 and s2.",
		"int\tft_strncmp(const char *s1, const char *s2, size_t n)\n"
			"{\n"
			"\tsize_t i = 0;\n"
			"\twhile (i < n && (s1[i] || s2[i]))\n"
			"\t{\n"
			"\t\tif ((unsigned char)s1[i] != (unsigned char)s2[i])\n"
			"\t\t\treturn ((unsigned char)s1[i] - (unsigned char)s2[i]);\n"
			"\t\ti++;\n"
			"\t}\n"
			"\treturn (0);\n"
			"}"
	},
	{
		"ft_strnstr",
		"Locates the first occurrence of the null-terminated string needle in haystack, searching not more than len characters.",
		"char\t*ft_strnstr(const char *haystack, const char *needle, size_t len)\n"
			"{\n"
			"\tsize_t i;\n"
			"\tsize_t needle_len = ft_strlen(needle);\n"
			"\tif (needle_len == 0)\n"
			"\t\treturn ((char *)haystack);\n"
			"\ti = 0;\n"
			"\twhile (haystack[i] && (i + needle_len) <= len)\n"
			"\t{\n"
			"\t\tif (ft_strncmp(&haystack[i], needle, needle_len) == 0)\n"
			"\t\t\treturn ((char *)&haystack[i]);\n"
			"\t\ti++;\n"
			"\t}\n"
			"\treturn (NULL);\n"
			"}"
	}
};

int get_string_function_count(void) {
	return sizeof(string_functions) / sizeof(LibFunc);
}

LibFunc get_string_function_by_index(int index) {
	if (index < 0 || index >= get_string_function_count()) {
		fprintf(stderr, "Invalid string function index.\n");
		exit(1);
	}
	return string_functions[index];
}
