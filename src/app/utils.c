#include <stdio.h>
#include <string.h>
#include <time.h>
#include "libft_master.h"

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

void print_function_list(LibFunc (*get_func_by_index)(int), int count) {
	for (int i = 0; i < count; i++) {
		LibFunc f = get_func_by_index(i);
		printf("%d. %s\n", i + 1, f.name);
	}
}
