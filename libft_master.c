#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "./includes/libft_master.h"

#define FUNC_COUNT (get_string_function_count() + get_memory_function_count())

void print_mode_menu(void) {
	printf("Choose a mode:\n");
	printf("1. Copy Mode   (see function code and type it)\n");
	printf("2. Recall Mode (type function from memory)\n");
	printf("Your choice: ");
}

