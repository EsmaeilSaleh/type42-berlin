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

int main(void)
{
	int mode;
	int func_index;

	srand(time(NULL)); // Seed RNG for random function selection
	print_mode_menu();
	if (scanf("%d", &mode) != 1 || (mode != 1 && mode != 2))
	{
		fprintf(stderr, "Invalid mode selected.\n");
		return 1;
	}
	getchar(); // Consume leftover newline from scanf

	func_index = rand() % get_function_count();
	LibFunc func = get_function_by_index(func_index);

	run_typing_session(&func, mode == 1);
	return 0;
}
