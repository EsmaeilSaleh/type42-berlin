#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <setjmp.h>
#include "libft_master.h"

jmp_buf mode_menu_jump;

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

int select_mode(void)
{
	int mode;
	print_mode_menu();
	if (scanf("%d", &mode) != 1 || (mode != 1 && mode != 2)) {
		fprintf(stderr, "Exiting.\n");
		return 0;
	}
	getchar();
	return mode;
}

int select_category(void)
{
	int category;
	print_category_menu();
	if (scanf("%d", &category) != 1 || category < 1 || category > 5)
		return 0;
	getchar();
	return category;
}

int run_category_loop(int mode, int category)
{
	LibFunc (*get_func_by_index)(int) = NULL;
	int (*get_func_count)(void) = NULL;

	switch (category) {
		case 1:
			get_func_by_index = get_string_function_by_index;
			get_func_count = get_string_function_count;
			break;
		case 2:
			get_func_by_index = get_memory_function_by_index;
			get_func_count = get_memory_function_count;
			break;
		case 3:
			get_func_by_index = get_char_function_by_index;
			get_func_count = get_char_function_count;
			break;
		case 4:
			get_func_by_index = get_conv_function_by_index;
			get_func_count = get_conv_function_count;
			break;
		case 5:
			get_func_by_index = get_bonus_function_by_index;
			get_func_count = get_bonus_function_count;
			break;
		default:
			fprintf(stderr, "Invalid category.\n");
			return 1;
	}

	while (1) {
		run_typing_session(mode, get_func_by_index, get_func_count);

		printf("\nWhat would you like to do next?\n");
		printf("1. Try another function in this category\n");
		printf("2. Return to category menu\n");
		printf("3. Return to mode selection\n");
		printf("Enter your choice: ");

		int choice;
		if (scanf("%d", &choice) != 1 || choice < 1 || choice > 3)
			break;
		getchar();

		if (choice == 1)
			continue;
		else if (choice == 2)
			break;
		else if (choice == 3)
			longjmp(mode_menu_jump, 1);
	}
	return 0;
}

int main(void)
{
	system("clear");
	if (setjmp(mode_menu_jump) != 0)
		printf("\nReturning to mode selection...\n");

	while (1) {
		int mode = select_mode();
		if (mode == 0)
			break;

		while (1) {
			int category = select_category();
			if (category == 0)
				break;

			run_category_loop(mode, category);
		}
	}

	return 0;
}
