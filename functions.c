#include "libft_master.h"

// --- Memory Functions ---
static LibFunc memory_funcs[] = {
	{
		"ft_memset",
		"Fills memory with a constant byte.",
		"void\t*ft_memset(void *b, int c, size_t len)\n"
			"{\n"
			"    size_t\t\t  i;\n"
			"    unsigned char\t*ptr;\n"
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
		"Zeroes out a block of memory.",
		"void\tft_bzero(void *s, size_t n)\n"
			"{\n"
			"    size_t\t  i;\n"
			"    char\t  *ptr;\n"
			"\n"
			"    ptr = (char *)s;\n"
			"    i = 0;\n"
			"    while (i < n)\n"
			"    {\n"
			"        ptr[i] = 0;\n"
			"        i++;\n"
			"    }\n"
			"}"
	},
	// Add more memory functions here
};

// --- String Functions ---
static LibFunc string_funcs[] = {
	{
		"ft_strlen",
		"Returns the number of characters in a string.",
		"size_t\tft_strlen(const char *s)\n"
			"{\n"
			"    size_t\ti;\n"
			"\n"
			"    i = 0;\n"
			"    while (s[i])\n"
			"        i++;\n"
			"    return (i);\n"
			"}"
	},
	// Add more string functions here
};

// Combine all categories into one list for lookup
static LibFunc *categories[] = {
	memory_funcs,
	string_funcs,
};

static int category_sizes[] = {
	sizeof(memory_funcs) / sizeof(LibFunc),
	sizeof(string_funcs) / sizeof(LibFunc),
};

// Total count of all functions
int get_function_count(void) {
	int total = 0;
	for (size_t i = 0; i < sizeof(category_sizes) / sizeof(int); i++)
		total += category_sizes[i];
	return total;
}

// Flat access by index
LibFunc get_function_by_index(int index) {
	int offset = 0;
	for (size_t i = 0; i < sizeof(category_sizes) / sizeof(int); i++) {
		if (index < offset + category_sizes[i])
			return categories[i][index - offset];
		offset += category_sizes[i];
	}
	fprintf(stderr, "Invalid function index.\n");
	exit(1);
}
