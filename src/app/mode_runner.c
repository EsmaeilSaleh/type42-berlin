#include "../../includes/libft_master.h"
#include <stdio.h>

void run_typing_session(Mode mode, LibFunc (*get_func_by_index)(int), int (*get_func_count)(void)) {
	int count = get_func_count();
	for (int i = 0; i < count; i++) {
		LibFunc func = get_func_by_index(i);
		run_mode(mode, &func);
	}
}
