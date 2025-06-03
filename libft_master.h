#ifndef LIBFT_MASTER_H
#define LIBFT_MASTER_H

#include <stddef.h>

#define MAX_INPUT 8192
#define FUNC_COUNT 5

typedef struct {
	const char *name;
	const char *description;
	const char *impl;
} LibFunc;

LibFunc get_function_by_index(int index);
void run_typing_session(const LibFunc *func, int is_copy_mode);

#endif
