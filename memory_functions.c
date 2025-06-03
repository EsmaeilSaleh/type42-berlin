#include "libft_master.h"

static LibFunc memory_functions[] = {
	{
		"ft_memset",
		"Fills the first n bytes of the memory area pointed to by s with the constant byte c.",
		"void\t*ft_memset(void *s, int c, size_t n)\n"
			"{\n"
			"\tunsigned char *p = (unsigned char *)s;\n"
			"\tsize_t i = 0;\n"
			"\twhile (i < n)\n"
			"\t\tp[i++] = (unsigned char)c;\n"
			"\treturn (s);\n"
			"}"
	},
	{
		"ft_bzero",
		"Erases the data in the n bytes of the memory starting at the location pointed to by s, by writing zeros to that area.",
		"void\tft_bzero(void *s, size_t n)\n"
			"{\n"
			"\tft_memset(s, 0, n);\n"
			"}"
	},
	{
		"ft_memcpy",
		"Copies n bytes from memory area src to memory area dest.",
		"void\t*ft_memcpy(void *dest, const void *src, size_t n)\n"
			"{\n"
			"\tsize_t\t\ti;\n"
			"\tunsigned char\t\t*d;\n"
			"\tconst unsigned char\t*s;\n"
			"\n"
			"\tif (!dest && !src)\n"
			"\t\treturn (NULL);\n"
			"\td = (unsigned char *)dest;\n"
			"\ts = (const unsigned char *)src;\n"
			"\ti = 0;\n"
			"\twhile (i < n)\n"
			"\t{\n"
			"\t\td[i] = s[i];\n"
			"\t\ti++;\n"
			"\t}\n"
			"\treturn (dest);\n"
			"}"
	}
};

int get_memory_function_count(void) {
	return sizeof(memory_functions) / sizeof(LibFunc);
}

LibFunc get_memory_function_by_index(int index) {
	if (index < 0 || index >= get_memory_function_count()) {
		fprintf(stderr, "Invalid memory function index.\n");
		exit(1);
	}
	return memory_functions[index];
}
