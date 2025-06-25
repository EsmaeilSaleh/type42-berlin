#ifndef FT_PRINTF_BONUS_H
#define FT_PRINTF_BONUS_H

#include <stdbool.h>
#include "core.h"

bool is_flag_char(char c);
int parse_number(const char *format, int *i);
int handle_plus_flag(int n);
int handle_field_width(const char *s, int width);

int get_ft_printf_bonus_functions_count(void);
LibFunc get_ft_printf_bonus_function_by_index(int index);

#endif