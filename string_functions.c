#include "./includes/libft_master.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

// String-related functions
LibFunc string_functions[] = {
	{"ft_strlen", "Calculates the length of a string.", "size_t ft_strlen(const char *s)", ft_strlen},
	{"ft_strcpy", "Copies a string to another.", "char *ft_strcpy(char *dst, const char *src)", ft_strcpy},
	{"ft_strdup", "Duplicates a string.", "char *ft_strdup(const char *s1)", ft_strdup},
	{"ft_strchr", "Finds first occurrence of a character in a string.", "char *ft_strchr(const char *s, int c)", ft_strchr},
	{"ft_strrchr", "Finds last occurrence of a character in a string.", "char *ft_strrchr(const char *s, int c)", ft_strrchr},
	{"ft_strncmp", "Compares two strings up to n characters.", "int ft_strncmp(const char *s1, const char *s2, size_t n)", ft_strncmp},
	{"ft_strnstr", "Locates a substring in a string within n characters.", "char *ft_strnstr(const char *haystack, const char *needle, size_t len)", ft_strnstr},
};
const int STRING_FUNC_COUNT = sizeof(string_functions) / sizeof(LibFunc);

LibFunc get_string_function_by_index(int index)
{
	if (index < 0 || index >= STRING_FUNC_COUNT)
	{
		fprintf(stderr, "Invalid string function index.\n");
		exit(1);
	}
	return (string_functions[index]);
}

int get_string_function_count(void)
{
	return STRING_FUNC_COUNT;
}
