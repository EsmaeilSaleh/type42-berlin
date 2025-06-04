#include "../../includes/libft_master.h"
#include <stdio.h>

void run_mode(Mode mode, LibFunc *func) {
	char user_input[MAX_INPUT_SIZE];

	if (!func)
		return;

	switch (mode) {
		case COPY_MODE:
			printf("Copy Mode:\n\n%s\n", func->code);
			break;
		case RECALL_MODE:
			printf("Recall Mode:\n\nFunction: %s\nDescription: %s\n", func->name, func->description);
			break;
		default:
			fprintf(stderr, "Unknown mode.\n");
			break;
	}
	get_user_input(user_input, MAX_INPUT_SIZE);
	printf("\n--- Your Input ---\n%s", user_input);
	int score = compute_similarity_score(user_input, func->code);
	printf("\nScore: %d%%\n", score);

	if (score == 100)
		printf("✅ Perfect!\n");
	else if (score >= 80)
		printf("👍 Good job, just a few issues.\n");
	else if (score >= 50)
		printf("⚠️ Getting there, review carefully.\n");
	else
		printf("❌ Needs work. Try again.\n");
	save_score_log(func->name, score, mode == COPY_MODE ? "Copy" : "Recall");
}
