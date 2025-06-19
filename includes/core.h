#ifndef LIBFT_MASTER_H
#define LIBFT_MASTER_H

#include <stddef.h> // for size_t
#include <string.h>
#include <setjmp.h>
#include <ctype.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <libgen.h>
#include "core.h"
#define MAX_INPUT 1024
#define MAX_INPUT_SIZE 8192
#define FUNC_COUNT (get_string_function_count() + get_memory_function_count())

typedef struct s_list
{
	void *content;
	struct s_list *next;
} t_list;

typedef enum e_mode
{
	COPY_MODE = 1,
	RECALL_MODE = 2
} Mode;

typedef struct s_variant
{
	const char *style;
	const char *code;
} Variant;

typedef struct s_libfunc
{
	const char *name;
	const char *description;
	const char *return_value;

	// Optional variants
	const Variant *variants;
	int variant_count;

	// Fallback/default code (used if no variants or in Copy Mode)
	const char *code;
} LibFunc;

extern char g_base_path[PATH_MAX];

extern const int BONUS_FUNC_COUNT;
// Declare all external category arrays and counts
extern LibFunc memory_functions[];
extern int get_memory_function_count(void);

extern LibFunc string_functions[];
extern int get_string_function_count(void);

extern LibFunc char_functions[];
extern int get_char_function_count(void);

extern LibFunc conv_functions[];
extern int get_conv_function_count(void);

extern LibFunc bonus_functions[];
extern int get_bonus_function_count(void);

// Function declarations for bonus category
LibFunc get_bonus_function_by_index(int index);
int get_bonus_function_count(void);

LibFunc get_char_function_by_index(int index);
int get_char_function_count(void);

LibFunc get_string_function_by_index(int index);
int get_string_function_count(void);
LibFunc get_memory_function_by_index(int index);
int get_memory_function_count(void);

LibFunc get_conv_function_by_index(int index);
int get_conv_function_count(void);

void run_typing_session(Mode mode, LibFunc (*get_func_by_index)(int), int (*get_func_count)(void));
void run_mode(Mode mode, LibFunc *func);

LibFunc get_get_next_line_function_by_index(int index);
int get_get_next_line_function_count(void);

int get_io_function_count(void);
LibFunc get_io_function_by_index(int index);

LibFunc get_ft_printf_utils_functions_by_index(int index);
int get_ft_printf_utils_functions_count(void);

#endif
