#include "core.h"
#include <stdio.h>
#include <stdlib.h>

LibFunc get_next_line_functions[] = {
	{
		"get_next_line",
		"Reads a line from a file descriptor until a newline or EOF.",
		"char\t*get_next_line(int fd)\n"
			"{\n"
			"\tstatic char\t*stash;\n"
			"\tchar\t\t\tbuffer[BUFFER_SIZE + 1];\n"
			"\tchar\t\t\t*line;\n"
			"\tint\t\t\t\tbytes;\n"
			"\n"
			"\tif (fd < 0 || BUFFER_SIZE <= 0)\n"
			"\t\treturn (NULL);\n"
			"\tbytes = 1;\n"
			"\twhile (!ft_strchr(stash, '\\n') && bytes > 0)\n"
			"\t{\n"
			"\t\tbytes = read(fd, buffer, BUFFER_SIZE);\n"
			"\t\tif (bytes < 0)\n"
			"\t\t\treturn (NULL);\n"
			"\t\tbuffer[bytes] = '\\0';\n"
			"\t\tstash = ft_strjoin(stash, buffer);\n"
			"\t}\n"
			"\tline = extract_line(stash);\n"
			"\tstash = update_stash(stash);\n"
			"\treturn (line);\n"
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
		"ft_strlen",
		"Returns the length of the string s.",
		"size_t\tft_strlen(const char *s)\n"
			"{\n"
			"\tsize_t i = 0;\n"
			"\twhile (s[i])\n"
			"\t\ti++;\n"
			"\treturn (i);\n"
			"}"
	},
	{
		"ft_strjoin",
		"Concatenates s1 and s2 into a new string.",
		"char\t*ft_strjoin(char const *s1, char const *s2)\n"
			"{\n"
			"\tchar *joined;\n"
			"\tsize_t i = 0, j = 0;\n"
			"\tif (!s1 || !s2)\n"
			"\t\treturn (NULL);\n"
			"\tjoined = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);\n"
			"\tif (!joined)\n"
			"\t\treturn (NULL);\n"
			"\twhile (s1[i])\n"
			"\t\tjoined[i++] = s1[i];\n"
			"\twhile (s2[j])\n"
			"\t\tjoined[i++] = s2[j++];\n"
			"\tjoined[i] = '\\0';\n"
			"\treturn (joined);\n"
			"}"
	},
	{
		"ft_substr",
		"Extracts a substring from s, starting at start with length len.",
		"char\t*ft_substr(char const *s, unsigned int start, size_t len)\n"
			"{\n"
			"\tchar *sub;\n"
			"\tsize_t i = 0;\n"
			"\tif (!s || start >= ft_strlen(s))\n"
			"\t\treturn (ft_strdup(\"\"));\n"
			"\tif (len > ft_strlen(s + start))\n"
			"\t\tlen = ft_strlen(s + start);\n"
			"\tsub = malloc(len + 1);\n"
			"\tif (!sub)\n"
			"\t\treturn (NULL);\n"
			"\twhile (i < len)\n"
			"\t\tsub[i++] = s[start++];\n"
			"\tsub[i] = '\\0';\n"
			"\treturn (sub);\n"
			"}"
	}
};

int get_get_next_line_function_count(void)
{
	return sizeof(get_next_line_functions) / sizeof(LibFunc);
}

LibFunc get_get_next_line_function_by_index(int index)
{
	if (index < 0 || index >= get_get_next_line_function_count())
	{
		fprintf(stderr, "Invalid get_next_line function index.\\n");
		exit(1);
	}
	return get_next_line_functions[index];
}
