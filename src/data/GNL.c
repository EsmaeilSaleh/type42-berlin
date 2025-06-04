#include "core.h"
#include <stdio.h>
#include <stdlib.h>

static LibFunc get_next_line_functions[] = {
	{
		"get_next_line",
		"Reads a line from a file descriptor until a newline or EOF.",
		"char\t*get_next_line(int fd)\n"
			"{\n"
			"\t// your implementation here\n"
			"\treturn (NULL);\n"
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
