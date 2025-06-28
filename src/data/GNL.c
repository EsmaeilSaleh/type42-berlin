#include "core.h"
#include <stdio.h>
#include <stdlib.h>

LibFunc get_next_line_functions[] = {
	{"get_next_line",
	 "Reads a line from a file descriptor until a newline or EOF.",
	 "Returns a line read from the file descriptor, or NULL on EOF or error.",
	 NULL,
	 0,
	 "char\t*get_next_line(int fd)\n"
	 "{\n"
	 "\tint\t\t\tbytes;\n"
	 "\tchar\t\t*line;\n"
	 "\tchar\t\tbuffer[BUFFER_SIZE + 1];\n"
	 "\tstatic char\t*stash;\n"
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
	 "}\n"},
	{"get_next_line_bonus",
	 "Reads a line from a file descriptor with multi-fd support.",
	 "Returns a line read from the given fd, maintaining state for each fd.",
	 NULL,
	 0,
	 "char\t*get_next_line_bonus(int fd)\n"
	 "{\n"
	 "\tint\t\t\tbytes;\n"
	 "\tchar\t\t*line;\n"
	 "\tchar\t\tbuffer[BUFFER_SIZE + 1];\n"
	 "\tstatic char\t*stash[10240];\n"
	 "\n"
	 "\tif (fd < 0 || fd >= 10240 || BUFFER_SIZE <= 0)\n"
	 "\t\treturn (NULL);\n"
	 "\tbytes = 1;\n"
	 "\twhile (!ft_strchr(stash[fd], '\\n') && bytes > 0)\n"
	 "\t{\n"
	 "\t\tbytes = read(fd, buffer, BUFFER_SIZE);\n"
	 "\t\tif (bytes < 0)\n"
	 "\t\t\treturn (NULL);\n"
	 "\t\tbuffer[bytes] = '\\0';\n"
	 "\t\tstash[fd] = ft_strjoin(stash[fd], buffer);\n"
	 "\t}\n"
	 "\tline = extract_line(stash[fd]);\n"
	 "\tstash[fd] = update_stash(stash[fd]);\n"
	 "\treturn (line);\n"
	 "}\n"},
	{"ft_strchr",
	 "Locates the first occurrence of c in the string s.",
	 "Returns a pointer to the matched character or NULL if not found.",
	 NULL,
	 0,
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
	 "}"},
	{"ft_strlen",
	 "Returns the length of the string s.",
	 "Returns the number of characters before the null terminator.",
	 NULL,
	 0,
	 "size_t\tft_strlen(const char *s)\n"
	 "{\n"
	 "\tsize_t\ti;\n"
	 "\n"
	 "\ti = 0;\n"
	 "\twhile (s[i])\n"
	 "\t\ti++;\n"
	 "\treturn (i);\n"
	 "}"},
	{"ft_strjoin",
	 "Concatenates stash and buffer into a new string.",
	 "Returns a new string consisting of stash followed by buffer, or NULL on failure.",
	 NULL,
	 0,
	 "char\t*ft_strjoin(char *stash, const char *buffer)\n"
	 "{\n"
	 "\tchar\t*joined;\n"
	 "\tsize_t\ti;\n"
	 "\tsize_t\tj;\n"
	 "\n"
	 "\tif (!stash && !buffer)\n"
	 "\t\treturn (NULL);\n"
	 "\tjoined = malloc(ft_strlen(stash) + ft_strlen(buffer) + 1);\n"
	 "\tif (!joined)\n"
	 "\t\treturn (NULL);\n"
	 "\ti = 0;\n"
	 "\twhile (stash && stash[i])\n"
	 "\t{\n"
	 "\t\tjoined[i] = stash[i];\n"
	 "\t\ti++;\n"
	 "\t}\n"
	 "\tj = 0;\n"
	 "\twhile (buffer && buffer[j])\n"
	 "\t{\n"
	 "\t\tjoined[i] = buffer[j];\n"
	 "\t\ti++;\n"
	 "\t\tj++;\n"
	 "\t}\n"
	 "\tjoined[i] = '\\0';\n"
	 "\tfree(stash);\n"
	 "\treturn (joined);\n"
	 "}"},
	{"extract_line",
	 "Extracts the next line including newline from the stash.",
	 "Returns the line to be returned by get_next_line.",
	 NULL,
	 0,
	 "char\t*extract_line(char *stash)\n"
	 "{\n"
	 "\tint\t\ti;\n"
	 "\tint\t\tlen;\n"
	 "\tchar\t*line;\n"
	 "\n"
	 "\tif (!stash || !stash[0])\n"
	 "\t\treturn (NULL);\n"
	 "\ti = 0;\n"
	 "\twhile (stash[i] && stash[i] != '\\n')\n"
	 "\t\ti++;\n"
	 "\tlen = i + 1;\n"
	 "\tif (stash[i] == '\\n')\n"
	 "\t\tlen++;\n"
	 "\tline = malloc(sizeof(char) * len);\n"
	 "\tif (!line)\n"
	 "\t\treturn (NULL);\n"
	 "\ti = 0;\n"
	 "\twhile (stash[i] && stash[i] != '\\n')\n"
	 "\t\tline[i] = stash[i++];\n"
	 "\tif (stash[i] == '\\n')\n"
	 "\t\tline[i++] = '\\n';\n"
	 "\tline[i] = '\\0';\n"
	 "\treturn (line);\n"
	 "}\n"},
	{"update_stash",
	 "Updates the stash by removing the line that was just extracted.",
	 "Returns a new stash with the remaining content after the newline.",
	 NULL,
	 0,
	 "char\t*update_stash(char *stash)\n"
	 "{\n"
	 "\tint\t\ti;\n"
	 "\tint\t\tj;\n"
	 "\tchar\t*new_stash;\n"
	 "\tsize_t\tlen;\n"
	 "\n"
	 "\ti = 0;\n"
	 "\tj = 0;\n"
	 "\twhile (stash[i] && stash[i] != '\\n')\n"
	 "\t\ti++;\n"
	 "\tif (!stash[i])\n"
	 "\t{\n"
	 "\t\tfree(stash);\n"
	 "\t\treturn (NULL);\n"
	 "\t}\n"
	 "\tlen = ft_strlen(stash) - i;\n"
	 "\tnew_stash = malloc(sizeof(char) * (len + 1));\n"
	 "\tif (!new_stash)\n"
	 "\t\treturn (NULL);\n"
	 "\ti++;\n"
	 "\twhile (stash[i])\n"
	 "\t\tnew_stash[j++] = stash[i++];\n"
	 "\tnew_stash[j] = '\\0';\n"
	 "\tfree(stash);\n"
	 "\treturn (new_stash);\n"
	 "}\n"},
	{"main",
	 "Demonstrates the use of get_next_line by reading from a file.",
	 "Reads lines from a file descriptor using get_next_line and prints them.",
	 NULL,
	 0,
	 "int\tmain(void)\n"
	 "{\n"
	 "\tint\t\tfd;\n"
	 "\tchar\t*line;\n"
	 "\n"
	 "\tfd = open(\"test.txt\", O_RDONLY);\n"
	 "\tif (fd < 0)\n"
	 "\t{\n"
	 "\t\tperror(\"Error opening file\");\n"
	 "\t\treturn (1);\n"
	 "\t}\n"
	 "\tline = get_next_line(fd);\n"
	 "\twhile (line)\n"
	 "\t{\n"
	 "\t\tprintf(\"%s\", line);\n"
	 "\t\tfree(line);\n"
	 "\t\tline = get_next_line(fd);\n"
	 "\t}\n"
	 "\tclose(fd);\n"
	 "\treturn (0);\n"
	 "}\n"}};

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
