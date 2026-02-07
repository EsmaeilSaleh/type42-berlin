#ifndef TERMINAL_DISPLAY_H
#define TERMINAL_DISPLAY_H

#include <stddef.h>
#include "core.h"

void print_banner(void);
void print_function_list(LibFunc (*get_func_by_index)(int), int count);
void print_mode_menu(void);
void print_category_menu(void);
void print_exam02_level_menu(void);
void print_styled(const char *text, const char *style);
void get_user_input(char *buffer, size_t size);

#endif // TERMINAL_DISPLAY_H
