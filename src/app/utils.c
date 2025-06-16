#include <stdio.h>
#include <string.h>
#include <time.h>
#include "core.h"

#define MAX_INPUT_SIZE 8192

void print_function_list(LibFunc (*get_func_by_index)(int), int count)
{
	printf("\nAvailable functions:\n");
	for (int i = 0; i < count; i++)
	{
		LibFunc f = get_func_by_index(i);
		printf("%d. %s\n", i + 1, f.name);
	}
	printf("0. Return to category menu\n");
}

void get_user_input(char *buffer, size_t size)
{
	char line[1024];
	buffer[0] = '\0';

	printf("\nStart typing below. Type 'END' on a line to finish.\n\n");

	while (fgets(line, sizeof(line), stdin))
	{
		// Remove newline from input
		line[strcspn(line, "\r\n")] = '\0';

		if (strcmp(line, "END") == 0)
			break;

		if (strlen(buffer) + strlen(line) + 2 >= size) // +1 for newline, +1 for '\0'
		{
			fprintf(stderr, "Input buffer full. Truncating input.\n");
			break;
		}

		// Safe append line
		strncat(buffer, line, size - strlen(buffer) - 1);
		strncat(buffer, "\n", size - strlen(buffer) - 1);
	}
}
int compute_similarity_score(const char *input, const char *expected)
{
	// Quick shortcut: both are NULL
	if (!input || !expected)
		return 0;

	int matches = 0;
	int total = 0;

	const char *p1 = input;
	const char *p2 = expected;

	while (*p1 && *p2)
	{
		// Skip whitespace
		while (isspace(*p1))
			p1++;
		while (isspace(*p2))
			p2++;

		if (!*p1 || !*p2)
			break;

		if (*p1 == *p2)
			matches++;

		p1++;
		p2++;
		total++;
	}

	// Allow a small mismatch margin
	return total ? (matches * 100 / total) : 0;
}

void save_score_log(const char *func_name, int score, const char *mode)
{
	FILE *log = fopen("score_log.txt", "a");
	if (!log)
	{
		perror("Failed to open score_log.txt");
		return;
	}

	time_t now = time(NULL);
	struct tm *t = localtime(&now);

	fprintf(log, "[%04d-%02d-%02d %02d:%02d:%02d] Mode: %s | Function: %s | Score: %d%%\n",
			t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
			t->tm_hour, t->tm_min, t->tm_sec,
			mode, func_name, score);

	fclose(log);
}
