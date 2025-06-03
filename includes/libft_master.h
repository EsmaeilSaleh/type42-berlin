#ifndef LIBFT_MASTER_H
#define LIBFT_MASTER_H

#define MAX_FUNCTIONS 100  // Or however many you plan to support

typedef struct {
    const char *name;
    const char *description;
    const char *impl;
} LibFunc;

// Declare accessors
LibFunc get_function_by_index(int index);
int get_function_count(void);

#endif
