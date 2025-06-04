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

int loose_compare(const char *input, const char *expected)
{
	// Quick shortcut: both are NULL
	if (!input || !expected) return 0;

	int matches = 0;
	int total = 0;

	const char *p1 = input;
	const char *p2 = expected;

	while (*p1 && *p2)
	{
		// Skip whitespace
		while (isspace(*p1)) p1++;
		while (isspace(*p2)) p2++;

		if (!*p1 || !*p2) break;

		if (*p1 == *p2)
			matches++;

		p1++;
		p2++;
		total++;
	}

	// Allow a small mismatch margin
	double similarity = (total > 0) ? ((double)matches / total) : 0;
	return (similarity >= 0.85);  // 85%+ match is good enough
}
