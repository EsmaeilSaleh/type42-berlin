#ifndef LIBFT_MASTER_H
#define LIBFT_MASTER_H

#include <stddef.h>

typedef struct {
    const char *name;
    const char *description;
    const char *impl;
} LibFunc;

LibFunc get_function_by_index(int index);
int get_function_count(void);
void run_typing_session(const LibFunc *func, int is_copy_mode);
void print_mode_menu(void);

#endif
