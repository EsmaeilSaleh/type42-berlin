#include <stdio.h>
#include <stdlib.h>
#include "libft_master.h"

int main() {
	int choice = 0;
	print_mode_menu();
	scanf("%d", &choice);
	getchar(); // consume newline

	if (choice != 1 && choice != 2) {
		printf("Invalid choice.\n");
		return 1;
	}

	int is_copy_mode = (choice == 1);
	LibFunc func = get_function_by_index(0);  // Replace with random/indexed later
	run_typing_session(&func, is_copy_mode);

	return 0;
}
