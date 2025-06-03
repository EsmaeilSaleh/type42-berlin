#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT 2048

typedef struct {
	const char* name;
	const char* code;
} LibftFunc;

const LibftFunc libft_funcs[] = {
	{
		"ft_strlen",
		"size_t ft_strlen(const char *s) {\n"
			"    size_t i = 0;\n"
			"    while (s[i])\n"
			"        i++;\n"
			"    return i;\n"
			"}"
	},
	// Add more functions here...
};

const int FUNC_COUNT = sizeof(libft_funcs) / sizeof(libft_funcs[0]);

void read_multiline_input(char* buffer, size_t max_size) {
	char line[256];
	buffer[0] = '\0';

	printf("✍️  Type the full function implementation below.\n");
	printf("   Finish with an empty line:\n\n");

	while (fgets(line, sizeof(line), stdin)) {
		if (strcmp(line, "\n") == 0) break; // End input on empty line
		if (strlen(buffer) + strlen(line) < max_size)
			strcat(buffer, line);
		else
			break;
	}
}

int main() {
	srand(time(NULL));
	int score = 0;
	int rounds = 1; // You can increase this later
	char input[MAX_INPUT];

	printf("🔡 Typing Full libft Function Implementations\n\n");

	for (int i = 0; i < rounds; i++) {
		const LibftFunc* func = &libft_funcs[rand() % FUNC_COUNT];

		printf("🧪 [%d/%d] Type the implementation for: %s\n\n", i + 1, rounds, func->name);

		clock_t start = clock();
		read_multiline_input(input, MAX_INPUT);
		clock_t end = clock();

		double elapsed = (double)(end - start) / CLOCKS_PER_SEC;

		if (strcmp(input, func->code) == 0) {
			printf("✅ Correct! Time: %.2f seconds\n\n", elapsed);
			score++;
		} else {
			printf("❌ Incorrect.\n");
			printf("Your Input:\n%s\n", input);
			printf("Expected:\n%s\n", func->code);
		}
	}

	printf("🎯 Final Score: %d/%d\n", score, rounds);
	return 0;
}
