#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT 2048

typedef struct {
	const char* name;
	const char* description;  // For Recall Mode
	const char* code;         // Full Implementation
} LibftFunc;

// Sample functions
const LibftFunc libft_funcs[] = {
	{
		"ft_strlen",
		"Returns the length of the string `s`, not including the null terminator.",
		"size_t ft_strlen(const char *s) {\n"
			"    size_t i = 0;\n"
			"    while (s[i])\n"
			"        i++;\n"
			"    return i;\n"
			"}"
	},
	{
		"ft_memcpy",
		"Copies `n` bytes from memory area `src` to memory area `dst`. The memory areas must not overlap.",
		"void *ft_memcpy(void *dst, const void *src, size_t n) {\n"
			"    unsigned char *d = dst;\n"
			"    const unsigned char *s = src;\n"
			"    while (n--)\n"
			"        *d++ = *s++;\n"
			"    return dst;\n"
			"}"
	}
};

const int FUNC_COUNT = sizeof(libft_funcs) / sizeof(libft_funcs[0]);

void read_multiline_input(char* buffer, size_t max_size) {
	char line[256];
	buffer[0] = '\0';

	printf("🔰 Finish with an empty line:\n\n");
	while (fgets(line, sizeof(line), stdin)) {
		if (strcmp(line, "\n") == 0) break;
		if (strlen(buffer) + strlen(line) < max_size)
			strcat(buffer, line);
		else
			break;
	}
}

int choose_mode() {
	int mode;
	printf("📘 Choose mode:\n");
	printf("  1 - Copy Mode (type what you see)\n");
	printf("  2 - Recall Mode (type from memory)\n");
	printf("Enter mode: ");
	scanf("%d", &mode);
	getchar(); // consume newline
	return (mode == 2) ? 2 : 1;
}

int main() {
	srand(time(NULL));
	char input[MAX_INPUT];
	int rounds = 1;
	int score = 0;

	printf("🧠 Libft Typing Practice\n");
	int mode = choose_mode();

	for (int i = 0; i < rounds; i++) {
		const LibftFunc* func = &libft_funcs[rand() % FUNC_COUNT];

		printf("\n🧪 [%d/%d] Function: %s\n", i + 1, rounds, func->name);

		if (mode == 1) {
			// Copy Mode
			printf("📄 Type the following exactly:\n\n%s\n\n", func->code);
		} else {
			// Recall Mode
			printf("📜 Description: %s\n\n", func->description);
		}

		clock_t start = clock();
		read_multiline_input(input, MAX_INPUT);
		clock_t end = clock();

		double elapsed = (double)(end - start) / CLOCKS_PER_SEC;

		if (strcmp(input, func->code) == 0) {
			printf("✅ Correct! Time: %.2f seconds\n", elapsed);
			score++;
		} else {
			printf("❌ Incorrect.\n");
			printf("🔍 Your input:\n%s\n", input);
			printf("✅ Expected:\n%s\n", func->code);
		}
	}

	printf("\n🎯 Final Score: %d/%d\n", score, rounds);
	return 0;
}
