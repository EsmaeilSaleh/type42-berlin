#ifndef LIBFT_MASTER_H
#define LIBFT_MASTER_H

typedef struct {
	const char *name;
	const char *description;
	const char *impl;
} LibFunc;

extern LibFunc libft_functions[];
#define FUNC_COUNT (sizeof(libft_functions) / sizeof(LibFunc))

#endif
