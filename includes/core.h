#ifndef LIBFT_MASTER_H
#define LIBFT_MASTER_H

#include <stddef.h> // for size_t
#include <ctype.h>
#include <string.h>
#define MAX_INPUT 1024
#define MAX_INPUT_SIZE 8192
#define FUNC_COUNT (get_string_function_count() + get_memory_function_count())

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef enum e_mode {
    COPY_MODE = 1,
    RECALL_MODE = 2
} Mode;

typedef struct s_libfunc
{
	const char	*name;
	const char	*description;
	const char	*code;
}	LibFunc;

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
LibFunc get_function_by_index(int index);
int get_function_count(void);

void run_typing_session(Mode mode, LibFunc (*get_func_by_index)(int), int (*get_func_count)(void));
void run_mode(Mode mode, LibFunc *func);
void print_function_list(LibFunc (*get_func_by_index)(int), int count);
void get_user_input(char *buffer, size_t size);
void save_score_log(const char *func_name, int score, const char *mode);
int compute_similarity_score(const char *input, const char *expected);

LibFunc get_get_next_line_function_by_index(int index);
int get_get_next_line_function_count(void);

#endif
