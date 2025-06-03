#ifndef LIBFT_MASTER_H
#define LIBFT_MASTER_H

#define MAX_INPUT 8192
#define FUNC_COUNT 3

typedef struct {
    const char *name;
    const char *description;
    const char *impl;
} LibFunc;

void print_mode_menu(void);
LibFunc get_function_by_index(int index);
void run_typing_session(const LibFunc *func, int is_copy_mode);
void get_user_input(char *buffer, size_t size);

#endif
