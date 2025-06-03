#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT 8192
#define FUNC_COUNT 1

typedef struct {
	const char *name;
	const char *description;
	const char *impl;
} LibFunc;

void print_mode_menu() {
	printf("Choose a mode:\n");
	printf("1. Copy Mode   (see function code and type it)\n");
	printf("2. Recall Mode (type function from memory)\n");
	printf("Your choice: ");
}

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

void run_typing_session(const LibFunc *func, int is_copy_mode) {
	printf("\nFunction: %s\n", func->name);
	printf("Description: %s\n\n", func->description);

	if (is_copy_mode) {
		printf("--- Copy the code below ---\n\n%s\n", func->impl);
	} else {
		printf("--- Type the function from memory ---\n");
	}

	char user_input[MAX_INPUT];
	time_t start = time(NULL);
	get_user_input(user_input, sizeof(user_input));
	time_t end = time(NULL);

	printf("\n--- Your Input ---\n%s", user_input);
	printf("\n--- Typing Time: %ld seconds ---\n", end - start);

	// TODO: Add comparison logic later
}

int main() {
	LibFunc functions[FUNC_COUNT] = {
		{
			"ft_strlen",
			"Returns the number of characters in the string.",
			"size_t ft_strlen(const char *s)"
				"{\n"
				"	size_t i = 0;\n"
				"	while (s[i])\n"
				"		i++;\n"
				"	return i;\n"
				"}"
		}
	};

	int choice = 0;
	print_mode_menu();
	scanf("%d", &choice);
	getchar(); // consume newline

	if (choice != 1 && choice != 2) {
		printf("Invalid choice.\n");
		return 1;
	}

	int is_copy_mode = (choice == 1);
	run_typing_session(&functions[0], is_copy_mode);

	return 0;
}
