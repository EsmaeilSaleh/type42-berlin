#ifndef LIBFT_MASTER_H
#define LIBFT_MASTER_H

#include <stddef.h> // for size_t
#define MAX_INPUT 1024
#define FUNC_COUNT (get_string_function_count() + get_memory_function_count())


typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_libfunc
{
	const char	*name;
	const char	*description;
	const char	*impl;
}	LibFunc;

typedef enum {
    MODE_COPY,
    MODE_RECALL
} Mode;

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
// For main function to get function count and function by index
LibFunc get_function_by_index(int index);
int get_function_count(void);

// For the typing session runner
//void run_typing_session(const LibFunc *func, int is_recall_mode);
void run_typing_session(Mode mode, LibFunc (*get_func_by_index)(int), int (*get_func_count)(void));
void run_mode(Mode mode, LibFunc *func);

#endif
