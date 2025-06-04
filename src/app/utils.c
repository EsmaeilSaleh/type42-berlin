#include <stdio.h>
#include <string.h>
#include <time.h>
#include "libft_master.h"

#define MAX_INPUT_SIZE 8192

void print_function_list(LibFunc (*get_func_by_index)(int), int count) {
	for (int i = 0; i < count; i++) {
		LibFunc f = get_func_by_index(i);
		printf("%d. %s\n", i + 1, f.name);
	}
}
void get_user_input(char *buffer, size_t size)
{
	char line[1024];
	buffer[0] = '\0';

	printf("\nStart typing below. Type 'END' on a line to finish.\n\n");

	while (fgets(line, sizeof(line), stdin))
	{
		if (strcmp(line, "END\n") == 0 || strcmp(line, "END\r\n") == 0)
			break;

		if (strlen(buffer) + strlen(line) + 1 >= size)
		{
			fprintf(stderr, "Input buffer full. Truncating input.\n");
			break;
		}

		strncat(buffer, line, size - strlen(buffer) - 1);
	}
}
