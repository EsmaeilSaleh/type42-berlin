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
	if (compute_similarity_score(user_input, func->code))
		printf("\n✅ Looks good! Function is correct.\n");
	else
		printf("\n❌ Something seems off. Check your formatting or logic.\n");
}
