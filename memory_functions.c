// memory_functions.c

#include "libft_master.h"

LibFunc memory_functions[] = {
	{
		"ft_memset",
		"Fills memory with a constant byte.",
		"void    *ft_memset(void *b, int c, size_t len)\n"
			"{\n"
			"    size_t          i;\n"
			"    unsigned char   *ptr;\n"
			"\n"
			"    ptr = (unsigned char *)b;\n"
			"    i = 0;\n"
			"    while (i < len)\n"
			"    {\n"
			"        ptr[i] = (unsigned char)c;\n"
			"        i++;\n"
			"    }\n"
			"    return (b);\n"
			"}"
	},
	{
		"ft_bzero",
		"Erases the data in the n bytes of the memory starting at the location pointed to by s.",
		"void    ft_bzero(void *s, size_t n)\n"
			"{\n"
			"    ft_memset(s, 0, n);\n"
			"}"
	},
	{
		"ft_memcpy",
		"Copies n bytes from memory area src to memory area dst.",
		"void    *ft_memcpy(void *dst, const void *src, size_t n)\n"
			"{\n"
			"    size_t  i;\n"
			"    char    *d;\n"
			"    char    *s;\n"
			"\n"
			"    d = (char *)dst;\n"
			"    s = (char *)src;\n"
			"    i = 0;\n"
			"    while (i < n)\n"
			"    {\n"
			"        d[i] = s[i];\n"
			"        i++;\n"
			"    }\n"
			"    return (dst);\n"
			"}"
	}
};

int get_memory_function_count(void) {
	return sizeof(memory_functions) / sizeof(memory_functions[0]);
}

LibFunc get_memory_function_by_index(int index) {
	if (index < 0 || index >= get_memory_function_count()) {
		fprintf(stderr, "Invalid memory function index.\n");
		exit(1);
	}
	return memory_functions[index];
}
