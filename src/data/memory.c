#include "core.h"
#include <stdio.h>	// for fprintf, stderr
#include <stdlib.h> // for exit

static const Variant memcpy_variants[] = {
	{"index-based",
	 "void\t*ft_memcpy(void *dest, const void *src, size_t n)\n"
	 "{\n"
	 "\tsize_t\t\t\ti;\n"
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
	 "}"},
	{"pointer-based",
	 "void\t*ft_memcpy(void *dest, const void *src, size_t n)\n"
	 "{\n"
	 "\tunsigned char\t\t*d = (unsigned char *)dest;\n"
	 "\tconst unsigned char\t*s = (const unsigned char *)src;\n"
	 "\n"
	 "\tif (!d && !s)\n"
	 "\t\treturn (NULL);\n"
	 "\twhile (n--)\n"
	 "\t\t*d++ = *s++;\n"
	 "\treturn (dest);\n"
	 "}"},
};
static const Variant memset_variants[] = {
	{"index-based",
	 "void\t*ft_memset(void *s, int c, size_t n)\n"
	 "{\n"
	 "\tsize_t\t\t\t\ti;\n"
	 "\tunsigned char\t*p;\n"
	 "\n"
	 "\ti = 0;\n"
	 "\tp = (unsigned char *)s;\n"
	 "\twhile (i < n)\n"
	 "\t{\n"
	 "\t\tp[i] = (unsigned char)c;\n"
	 "\t\ti++;\n"
	 "\t}\n"
	 "\treturn (s);\n"
	 "}\n"},
	{"pointer-based",
	 "void\t*ft_memset(void *s, int c, size_t n)\n"
	 "{\n"
	 "\tunsigned char\t*p;\n"
	 "\n"
	 "\tp = (unsigned char *)s;\n"
	 "\twhile (n--)\n"
	 "\t\t*p++ = (unsigned char)c;\n"
	 "\treturn (s);\n"
	 "}"}};

static const Variant bzero_variants[] = {
	{"manual-loop",
	 "void\tft_bzero(void *s, size_t n)\n"
	 "{\n"
	 "\tunsigned char\t*p;\n"
	 "\n"
	 "\tp = (unsigned char *)s;\n"
	 "\twhile (n--)\n"
	 "\t\t*p++ = 0;\n"
	 "}"},
	{"using-memset",
	 "void\tft_bzero(void *s, size_t n)\n"
	 "{\n"
	 "\tft_memset(s, 0, n);\n"
	 "}"}};

static const Variant memchr_variants[] = {
	{"index-based",
	 "void\t*ft_memchr(const void *s, int c, size_t n)\n"
	 "{\n"
	 "\tsize_t\t\t\ti;\n"
	 "\tconst unsigned char\t*p;\n"
	 "\n"
	 "\ti = 0;\n"
	 "\tp = (const unsigned char *)s;\n"
	 "\twhile (i < n)\n"
	 "\t{\n"
	 "\t\tif (p[i] == (unsigned char)c)\n"
	 "\t\t\treturn ((void *)(p + i));\n"
	 "\t\ti++;\n"
	 "\t}\n"
	 "\treturn (NULL);\n"
	 "}"},
	{"pointer-based",
	 "void\t*ft_memchr(const void *s, int c, size_t n)\n"
	 "{\n"
	 "\tconst unsigned char\t*p;\n"
	 "\n"
	 "\tp = (const unsigned char *)s;\n"
	 "\twhile (n--)\n"
	 "\t{\n"
	 "\t\tif (*p == (unsigned char)c)\n"
	 "\t\t\treturn ((void *)p);\n"
	 "\t\tp++;\n"
	 "\t}\n"
	 "\treturn (NULL);\n"
	 "}"}};

static const Variant memmove_variants[] = {
	{"index-based",
	 "void\t*ft_memmove(void *dest, const void *src, size_t n)\n"
	 "{\n"
	 "\tunsigned char\t\t*d;\n"
	 "\tconst unsigned char\t*s;\n"
	 "\tsize_t\t\t\ti;\n"
	 "\n"
	 "\td = (unsigned char *)dest;\n"
	 "\ts = (const unsigned char *)src;\n"
	 "\tif (d == s || n == 0)\n"
	 "\t\treturn (dest);\n"
	 "\tif (d < s)\n"
	 "\t{\n"
	 "\t\ti = 0;\n"
	 "\t\twhile (i < n)\n"
	 "\t\t{\n"
	 "\t\t\td[i] = s[i];\n"
	 "\t\t\ti++;\n"
	 "\t\t}\n"
	 "\t}\n"
	 "\telse\n"
	 "\t{\n"
	 "\t\ti = n;\n"
	 "\t\twhile (i > 0)\n"
	 "\t\t{\n"
	 "\t\t\ti--;\n"
	 "\t\t\td[i] = s[i];\n"
	 "\t\t}\n"
	 "\t}\n"
	 "\treturn (dest);\n"
	 "}"},
	{"pointer-based",
	 "void\t*ft_memmove(void *dest, const void *src, size_t n)\n"
	 "{\n"
	 "\tunsigned char\t\t*d;\n"
	 "\tconst unsigned char\t*s;\n"
	 "\n"
	 "\tif (dest == src || n == 0)\n"
	 "\t\treturn (dest);\n"
	 "\td = (unsigned char *)dest;\n"
	 "\ts = (const unsigned char *)src;\n"
	 "\tif (d < s)\n"
	 "\t\twhile (n--)\n"
	 "\t\t\t*d++ = *s++;\n"
	 "\telse\n"
	 "\t{\n"
	 "\t\td += n;\n"
	 "\t\ts += n;\n"
	 "\t\twhile (n--)\n"
	 "\t\t\t*--d = *--s;\n"
	 "\t}\n"
	 "\treturn (dest);\n"
	 "}"}};

static const Variant memcmp_variants[] = {
	{"index-based",
	 "int\tft_memcmp(const void *s1, const void *s2, size_t n)\n"
	 "{\n"
	 "\tsize_t\t\t\ti;\n"
	 "\tconst unsigned char\t*p1;\n"
	 "\tconst unsigned char\t*p2;\n"
	 "\n"
	 "\ti = 0;\n"
	 "\tp1 = (const unsigned char *)s1;\n"
	 "\tp2 = (const unsigned char *)s2;\n"
	 "\twhile (i < n)\n"
	 "\t{\n"
	 "\t\tif (p1[i] != p2[i])\n"
	 "\t\t\treturn (p1[i] - p2[i]);\n"
	 "\t\ti++;\n"
	 "\t}\n"
	 "\treturn (0);\n"
	 "}"},
	{"pointer-based",
	 "int\tft_memcmp(const void *s1, const void *s2, size_t n)\n"
	 "{\n"
	 "\tconst unsigned char\t*p1;\n"
	 "\tconst unsigned char\t*p2;\n"
	 "\n"
	 "\tp1 = (const unsigned char *)s1;\n"
	 "\tp2 = (const unsigned char *)s2;\n"
	 "\twhile (n--)\n"
	 "\t{\n"
	 "\t\tif (*p1 != *p2)\n"
	 "\t\t\treturn (*p1 - *p2);\n"
	 "\t\tp1++;\n"
	 "\t\tp2++;\n"
	 "\t}\n"
	 "\treturn (0);\n"
	 "}"}};
static const Variant calloc_variants[] = {
	{"manual-bzero",
	 "void\t*ft_calloc(size_t nmemb, size_t size)\n"
	 "{\n"
	 "\tvoid *ptr = malloc(nmemb * size);\n"
	 "\tif (!ptr)\n"
	 "\t\treturn (NULL);\n"
	 "\tft_bzero(ptr, nmemb * size);\n"
	 "\treturn (ptr);\n"
	 "}"},
	{"manual-loop",
	 "void\t*ft_calloc(size_t nmemb, size_t size)\n"
	 "{\n"
	 "\tunsigned char *p;\n"
	 "\tsize_t total = nmemb * size;\n"
	 "\tsize_t i = 0;\n"
	 "\tp = (unsigned char *)malloc(total);\n"
	 "\tif (!p)\n"
	 "\t\treturn (NULL);\n"
	 "\twhile (i < total)\n"
	 "\t\tp[i++] = 0;\n"
	 "\treturn ((void *)p);\n"
	 "}"}};
static const Variant strdup_variants[] = {
	{"index-based",
	 "char\t*ft_strdup(const char *s)\n"
	 "{\n"
	 "\tsize_t\tlen;\n"
	 "\tchar\t*dup;\n"
	 "\tsize_t\ti;\n"
	 "\n"
	 "\tlen = ft_strlen(s);\n"
	 "\tdup = (char *)malloc(len + 1);\n"
	 "\tif (!dup)\n"
	 "\t\treturn (NULL);\n"
	 "\ti = 0;\n"
	 "\twhile (s[i])\n"
	 "\t{\n"
	 "\t\tdup[i] = s[i];\n"
	 "\t\ti++;\n"
	 "\t}\n"
	 "\tdup[i] = '\\0';\n"
	 "\treturn (dup);\n"
	 "}"},
	{"pointer-based",
	 "char\t*ft_strdup(const char *s)\n"
	 "{\n"
	 "\tchar\t*dup;\n"
	 "\tchar\t*ret;\n"
	 "\tsize_t\tlen;\n"
	 "\n"
	 "\tlen = ft_strlen(s);\n"
	 "\tdup = (char *)malloc(len + 1);\n"
	 "\tif (!dup)\n"
	 "\t\treturn (NULL);\n"
	 "\tret = dup;\n"
	 "\twhile (*s)\n"
	 "\t{\n"
	 "\t\t*dup = *s;\n"
	 "\t\tdup++;\n"
	 "\t\ts++;\n"
	 "\t}\n"
	 "\t*dup = '\\0';\n"
	 "\treturn (ret);\n"
	 "}"}};
LibFunc memory_functions[] = {
	{"ft_memset",
	 "Fills the first n bytes of the memory area pointed to by s with the constant byte c.",
	 "Returns a pointer to the memory area s.",
	 memset_variants,
	 2,
	 NULL},
	{"ft_bzero",
	 "Erases the data in the n bytes of the memory starting at the location pointed to by s, by writing zeros to that area.",
	 "Returns nothing.",
	 bzero_variants,
	 2,
	 NULL},
	{"ft_memcpy",
	 "Copies n bytes from memory area src to memory area dest.",
	 "Returns a pointer to dest.",
	 memcpy_variants,
	 2,
	 NULL},
	{"ft_memmove",
	 "Copies n bytes from memory area src to memory area dest. Handles overlapping memory areas safely.",
	 "Returns a pointer to dest.",
	 memmove_variants,
	 2,
	 NULL},
	{"ft_memchr",
	 "Scans the first n bytes of the memory area pointed to by s for the character c.",
	 "Returns a pointer to the matching byte or NULL if not found.",
	 memchr_variants,
	 2,
	 NULL},
	{"ft_memcmp",
	 "Compares the first n bytes of the memory areas s1 and s2.",
	 "Returns an integer less than, equal to, or greater than zero.",
	 memcmp_variants,
	 2,
	 NULL},
	{"ft_calloc",
	 "Allocates memory for an array of nmemb elements of size bytes each and returns a pointer to the allocated memory, set to zero.",
	 "Returns a pointer to the allocated memory, or NULL on failure.",
	 calloc_variants,
	 2,
	 NULL},
	{"ft_strdup",
	 "Returns a pointer to a new string which is a duplicate of the string s.",
	 "Returns a pointer to the duplicated string, or NULL if insufficient memory was available.",
	 strdup_variants,
	 2,
	 NULL}};

int get_memory_function_count(void)
{
	return sizeof(memory_functions) / sizeof(LibFunc);
}

LibFunc get_memory_function_by_index(int index)
{
	if (index < 0 || index >= get_memory_function_count())
	{
		fprintf(stderr, "Invalid memory function index.\n");
		exit(1);
	}
	return memory_functions[index];
}
