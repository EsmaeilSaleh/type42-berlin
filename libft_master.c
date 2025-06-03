#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "./includes/libft_master.h"

#define FUNC_COUNT (get_string_function_count() + get_memory_function_count())

void print_mode_menu(void) {
	printf("Choose a mode:\n");
	printf("1. Copy Mode   (see function code and type it)\n");
	printf("2. Recall Mode (type function from memory)\n");
	printf("Your choice: ");
}

LibFunc get_function_by_index(int index) {
	static LibFunc functions[] = {
		{
			"ft_strlen",
			"Returns the number of characters in the string.",
			"size_t	ft_strlen(const char *s)\n"
				"{\n"
				"	size_t	i;\n"
				"\n"
				"	i = 0;\n"
				"	while (s[i])\n"
				"		i++;\n"
				"	return (i);\n"
				"}"
		},
		{
			"ft_strcpy",
			"Copies string src to dst (including null terminator).",
			"char	*ft_strcpy(char *dst, const char *src)\n"
				"{\n"
				"	size_t	i;\n"
				"\n"
				"	i = 0;\n"
				"	while (src[i])\n"
				"	{\n"
				"		dst[i] = src[i];\n"
				"		i++;\n"
				"	}\n"
				"	dst[i] = '\\0';\n"
				"	return (dst);\n"
				"}"
		},
		{
			"ft_memset",
			"Fills memory with constant byte.",
			"void	*ft_memset(void *b, int c, size_t len)\n"
				"{\n"
				"	size_t			i;\n"
				"	unsigned char	*ptr;\n"
				"\n"
				"	ptr = (unsigned char *)b;\n"
				"	i = 0;\n"
				"	while (i < len)\n"
				"	{\n"
				"		ptr[i] = (unsigned char)c;\n"
				"		i++;\n"
				"	}\n"
				"	return (b);\n"
				"}"
		}
	};
	//int total = sizeof(functions) / sizeof(functions[0]);
	if (index < 0 || index >= FUNC_COUNT)
	{
		fprintf(stderr, "Invalid function index.\n");
		exit(1);
	}
	return functions[index];
};

void get_user_input(char *buffer, size_t size) {
	printf("\nStart typing below. End with a single line containing only 'END'\n\n");
	buffer[0] = '\0';
	char line[1024];
	while (fgets(line, sizeof(line), stdin)) {
		if (strcmp(line, "END\n") == 0 || strcmp(line, "END\r\n") == 0)
			break;
		strncat(buffer, line, size - strlen(buffer) - 1);
	}
}
