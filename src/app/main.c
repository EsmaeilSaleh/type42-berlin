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

				printf("\nTry another function in this category? (y/n): ");
				char again;
				scanf(" %c", &again);
				getchar();
				if (again != 'y' && again != 'Y')
					break;
			}

			printf("\nReturn to main menu? (y/n): ");
			char main_again;
			scanf(" %c", &main_again);
			getchar();
			if (main_again != 'y' && main_again != 'Y')
				break;
		}
	}

	return 0;
}
