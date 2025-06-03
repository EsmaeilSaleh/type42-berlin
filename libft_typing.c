#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// List of libft function names
const char* libft_funcs[] = {
	"ft_strlen", "ft_memcpy", "ft_memset", "ft_bzero", "ft_strlcpy",
	"ft_strlcat", "ft_strchr", "ft_strrchr", "ft_strncmp", "ft_atoi",
	"ft_isalpha", "ft_isdigit", "ft_isalnum", "ft_isascii", "ft_isprint",
	"ft_tolower", "ft_toupper", "ft_strdup", "ft_calloc", "ft_substr",
	"ft_strjoin", "ft_strtrim", "ft_split", "ft_itoa", "ft_strmapi"
};

const int FUNC_COUNT = sizeof(libft_funcs) / sizeof(libft_funcs[0]);

void clear_input_buffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
	srand(time(NULL));
	char input[100];
	int score = 0;
	int rounds = 10;

	printf("🧠 Typing Practice: libft Function Names\n");
	printf("Type the function name exactly as shown. Let's go!\n\n");

	for (int i = 0; i < rounds; i++) {
		const char* target = libft_funcs[rand() % FUNC_COUNT];
		printf("[%d/%d] Type this: %s\n", i + 1, rounds, target);

		clock_t start = clock();
		if (fgets(input, sizeof(input), stdin) == NULL) {
			printf("Input error.\n");
			break;
		}
		clock_t end = clock();

		// Remove newline
		input[strcspn(input, "\n")] = '\0';

		double elapsed = (double)(end - start) / CLOCKS_PER_SEC;

		if (strcmp(input, target) == 0) {
			printf("✅ Correct! Time: %.2f seconds\n\n", elapsed);
			score++;
		} else {
			printf("❌ Wrong! You typed: %s\n", input);
			printf("   Correct was: %s\n\n", target);
		}
	}

	printf("🎯 Final Score: %d/%d\n", score, rounds);
	return 0;
}
