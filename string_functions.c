#include "libft_master.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

// String-related functions

size_t	ft_strlen(const char *s)
{
	size_t i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dst, const char *src)
{
	size_t i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	size_t len = ft_strlen(s1);
	char *copy = (char *)malloc(len + 1);
	if (!copy)
		return (NULL);
	return (ft_strcpy(copy, s1));
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	const char *last = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last = s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return ((char *)last);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t needle_len = ft_strlen(needle);

	if (needle_len == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && (i + needle_len) <= len)
	{
		if (ft_strncmp(&haystack[i], needle, needle_len) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}

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
