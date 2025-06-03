#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TEMP_FILE "temp_typing.c"

void write_temp_file(const char *mode, const char *function_name, const char *description, const char *impl, int is_copy_mode) {
	FILE *fp = fopen(TEMP_FILE, "w");
	if (!fp) {
		perror("Failed to create temp file");
		exit(1);
	}

	fprintf(fp, "/* Mode: %s */\n", mode);
	fprintf(fp, "/* Function: %s */\n", function_name);
	fprintf(fp, "/* Description: %s */\n", description);

	if (is_copy_mode) {
		fprintf(fp, "/*\n%s\n*/\n", impl);
	}

	fprintf(fp, "\n// Type your implementation below:\n\n");

	fclose(fp);
}

void launch_vim() {
	system("vim " TEMP_FILE);
}

void read_user_input(char *buffer, size_t size) {
	FILE *fp = fopen(TEMP_FILE, "r");
	if (!fp) {
		perror("Failed to read temp file");
		return;
	}

	fread(buffer, 1, size - 1, fp);
	buffer[size - 1] = '\0';
	fclose(fp);
}

int main() {
	int choice;

	const char *function_name = "ft_strlen";
	const char *description = "Returns the number of characters in the string.";
	const char *correct_impl =
		"size_t ft_strlen(const char *s) {\n"
		"    size_t i = 0;\n"
		"    while (s[i])\n"
		"        i++;\n"
		"    return i;\n"
		"}";

	printf("Choose a mode:\n");
	printf("1. Copy Mode (see function code and type it)\n");
	printf("2. Recall Mode (type function from memory)\n");
	printf("Your choice: ");
	scanf("%d", &choice);
	getchar(); // consume newline

	if (choice != 1 && choice != 2) {
		printf("Invalid choice.\n");
		return 1;
	}

	int is_copy_mode = (choice == 1);
	write_temp_file(is_copy_mode ? "Copy" : "Recall", function_name, description, correct_impl, is_copy_mode);

	time_t start = time(NULL);
	launch_vim();
	time_t end = time(NULL);

	char user_code[8192];
	read_user_input(user_code, sizeof(user_code));

	printf("\n--- Your Input ---\n%s", user_code);
	printf("\n--- Typing Time: %ld seconds ---\n", end - start);

	// TODO: Compare to correct_impl and score
	return 0;
}
