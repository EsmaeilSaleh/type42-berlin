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
	printf("4. conv functions\n");
	printf("Enter choice: ");
}

int main(void)
{
	int mode;
	int category;

	srand(time(NULL)); // Seed RNG

	print_mode_menu();
	if (scanf("%d", &mode) != 1 || (mode != 1 && mode != 2))
	{
		fprintf(stderr, "Invalid mode selected.\n");
		return 1;
	}

	print_category_menu(); // <- You need to implement this if you haven't
	if (scanf("%d", &category) != 1 || (category < 1 || category > 4))
	{
		fprintf(stderr, "Invalid category selected.\n");
		return 1;
	}

	getchar(); // Consume leftover newline from scanf

	if (category == 1)
		run_typing_session(mode, get_string_function_by_index, get_string_function_count);
	else if (category == 2)
		run_typing_session(mode, get_memory_function_by_index, get_memory_function_count);
	else if (category == 3)
		run_typing_session(mode, get_char_function_by_index, get_char_function_count);
	else if (category == 4)
		run_typing_session(mode, get_conv_function_by_index, get_conv_function_count);
	else
		fprintf(stderr, "Unsupported category.\n");

	return 0;
}
