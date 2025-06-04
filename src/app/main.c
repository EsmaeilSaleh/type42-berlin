#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "libft_master.h"

void print_mode_menu(void)
{
	printf("Choose a mode:\n");
	printf("1. Copy Mode   (see function code and type it)\n");
	printf("2. Recall Mode (type function from memory)\n");
	printf("Your choice: ");
}

void print_category_menu(void)
{
	printf("Select category:\n");
	printf("1. String functions\n");
	printf("2. Memory functions\n");
	printf("3. Char functions\n");
	printf("4. Conv functions\n");
	printf("5. Bonus functions\n");
	printf("Enter choice: ");
}

int main(void)
{
	while (1) {
		print_mode_menu();
		int mode;
		if (scanf("%d", &mode) != 1 || (mode != 1 && mode != 2))
			break;
		getchar();

		while (1) {
			print_category_menu();
			int category;
			if (scanf("%d", &category) != 1 || category == 0)
				break;
			getchar();

			while (1) {
				if (category == 1)
					run_typing_session(mode, get_string_function_by_index, get_string_function_count);
				else if (category == 2)
					run_typing_session(mode, get_memory_function_by_index, get_memory_function_count);
				else if (category == 3)
					run_typing_session(mode, get_char_function_by_index, get_char_function_count);
				else if (category == 4)
					run_typing_session(mode, get_conv_function_by_index, get_conv_function_count);
				else if (category == 5)
					run_typing_session(mode, get_bonus_function_by_index, get_bonus_function_count);
				else
					fprintf(stderr, "Unsupported category.\n");

				printf("\nWhat would you like to do next?\n");
				printf("1. Try another function in this category\n");
				printf("2. Return to main menu\n");
				printf("3. Return to mode selection\n");
				printf("Enter your choice: ");

				int next_action;
				if (scanf("%d", &next_action) != 1 || next_action < 1 || next_action > 3) {
					fprintf(stderr, "Invalid input. Returning to main menu.\n");
					return;
				}
				getchar();

				if (next_action == 1)
					continue; // restart function list
				else if (next_action == 2)
					return; // go back to category
				else if (next_action == 3)
					longjmp(mode_menu_jump, 1)

			}

		}
	}

	return 0;
}
