// src/app/mode_runner.c
#include <stdio.h>
#include "libft_master.h"

void run_typing_session(Mode mode,
		LibFunc (*get_func_by_index)(int),
		int (*get_func_count)(void))
{
	int count = get_func_count();
	int func_choice;

	print_function_list(get_func_by_index, count);

	printf("Select a function to practice: ");
	if (scanf("%d", &func_choice) != 1 || func_choice < 0 || func_choice > count) {
		fprintf(stderr, "Invalid function choice.\n");
		return;
	}
	getchar(); // consume newline

	if (func_choice == 0)
		return ;
	LibFunc func = get_func_by_index(func_choice - 1);
	run_mode(mode, &func);
}
