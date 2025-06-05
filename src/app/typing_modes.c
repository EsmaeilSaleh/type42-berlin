#include "../../includes/core.h"
#include <stdio.h>
#include <stdlib.h>

void run_mode(Mode mode, LibFunc *func) {

	if (!func)
		return;
	system("clear");

	printf("Function: %s\n", func->name);
	printf("Description: %s\n", func->description);
	printf("Return: %s\n\n", func->return_value);

	const char *code_to_practice = NULL;

	if (func->variant_count > 0)
	{
		printf("This function has multiple implementations:\n");
		for (int i = 0; i < func->variant_count; i++)
			printf("%d. %s\n", i + 1, func->variants[i].style);

		printf("Select variant: ");
		int v = 0;
		if (scanf("%d", &v) != 1 || v < 1 || v > func->variant_count)
		{
			fprintf(stderr, "Invalid selection.\n");
			return;
		}
		getchar(); // Consume leftover newline
		code_to_practice = func->variants[v - 1].code;
	}
	else
	{
		code_to_practice = func->code;
	}

	// Show code in COPY mode
	if (mode == COPY_MODE && code_to_practice)
	{
		printf("--- Copy Mode ---\n\n%s\n", code_to_practice);
	}
	else if (mode == RECALL_MODE)
	{
		printf("--- Recall Mode ---\nType the function from memory.\n");
	}

	char user_input[MAX_INPUT] = {0};
	get_user_input(user_input, MAX_INPUT);

	printf("\n--- Your Input ---\n%s", user_input);
	int score = compute_similarity_score(user_input, code_to_practice);
	printf("\nScore: %d%%\n", score);
	if (mode == RECALL_MODE)
		printf("\n--- Correct Implementation ---\n%s\n", code_to_practice);
	if (score == 100)
		printf("✅ Perfect!\n");
	else if (score >= 80)
		printf("👍 Good job, just a few issues.\n");
	else if (score >= 70)
		printf("👍 Not bad. Keep practicing!\n");
	else if (score >= 50)
		printf("⚠️ Getting there, review carefully.\n");
	else
		printf("❌ Needs improvement. Try again!\n");

	save_score_log(func->name, score, mode == COPY_MODE ? "Copy" : "Recall");
}
