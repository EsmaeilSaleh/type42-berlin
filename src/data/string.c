#include "core.h"
#include <stdio.h>  // for fprintf, stderr
#include <stdlib.h> // for exit

static const Variant strcpy_variants[] = {
	{
		"index-based",
		"char\t*ft_strcpy(char *dst, const char *src)\n"
			"{\n"
			"\tsize_t\ti = 0;\n"
			"\twhile (src[i])\n"
			"\t{\n"
			"\t\tdst[i] = src[i];\n"
			"\t\ti++;\n"
			"\t}\n"
			"\tdst[i] = '\\0';\n"
			"\treturn (dst);\n"
			"}"
	},
	{
		"pointer-based",
		"char\t*ft_strcpy(char *dst, const char *src)\n"
			"{\n"
			"\tchar\t*ret = dst;\n"
			"\twhile (*src)\n"
			"\t\t*dst++ = *src++;\n"
			"\t*dst = '\\0';\n"
			"\treturn (ret);\n"
			"}"
	}
};


LibFunc string_functions[] = {
	{
		"ft_strlen",
		"Calculates the length of a string.",
		"Returns the number of characters in the string, excluding the null terminator.",
		NULL,
		0,
		"size_t\tft_strlen(const char *s)\n"
			"{\n"
			"\tsize_t\ti;\n"
			"\n"
			"\ti = 0;\n"
			"\twhile (s[i])\n"
			"\t\ti++;\n"
			"\treturn (i);\n"
			"}"
	},
	{
		"ft_strcpy",
		"Copies the string src to dst including the null terminator.",
		"Returns dst.",
		strcpy_variants,
		2,
		NULL
	},
	{
		"ft_strdup",
		"Returns a pointer to a new string which is a duplicate of the string s1.",
		"Returns a newly allocated duplicate of the string s. Returns NULL if allocation fails.",
		"char\t*ft_strdup(const char *s1)\n"
			"{\n"
			"\tsize_t len = ft_strlen(s1);\n"
			"\tchar *copy = (char *)malloc(len + 1);\n"
			"\tif (!copy)\n"
			"\t\treturn (NULL);\n"
			"\treturn (ft_strcpy(copy, s1));\n"
			"}"
	},
	{
		"ft_strchr",
		"Locates the first occurrence of c in the string s.",
		"Returns a pointer to the first occurrence of character c in string s, or NULL if not found.",
		"char\t*ft_strchr(const char *s, int c)\n"
			"{\n"
			"\twhile (*s)\n"
			"\t{\n"
			"\t\tif (*s == (char)c)\n"
			"\t\t\treturn ((char *)s);\n"
			"\t\ts++;\n"
			"\t}\n"
			"\tif (c == '\\0')\n"
			"\t\treturn ((char *)s);\n"
			"\treturn (NULL);\n"
			"}"
	},
	{
		"ft_strrchr",
		"Locates the last occurrence of c in the string s.",
		"Returns a pointer to the last occurrence of character c in string s, or NULL if not found.",
		"char\t*ft_strrchr(const char *s, int c)\n"
			"{\n"
			"\tconst char *last = NULL;\n"
			"\twhile (*s)\n"
			"\t{\n"
			"\t\tif (*s == (char)c)\n"
			"\t\t\tlast = s;\n"
			"\t\ts++;\n"
			"\t}\n"
			"\tif (c == '\\0')\n"
			"\t\treturn ((char *)s);\n"
			"\treturn ((char *)last);\n"
			"}"
	},
	{
		"ft_strncmp",
		"Compares up to n characters of the strings s1 and s2.",
		"Returns 0 if equal, or the difference between the first differing characters.",
		"int\tft_strncmp(const char *s1, const char *s2, size_t n)\n"
			"{\n"
			"\tsize_t i = 0;\n"
			"\twhile (i < n && (s1[i] || s2[i]))\n"
			"\t{\n"
			"\t\tif ((unsigned char)s1[i] != (unsigned char)s2[i])\n"
			"\t\t\treturn ((unsigned char)s1[i] - (unsigned char)s2[i]);\n"
			"\t\ti++;\n"
			"\t}\n"
			"\treturn (0);\n"
			"}"
	},
	{
		"ft_strnstr",
		"Locates the first occurrence of the null-terminated string needle in haystack, searching not more than len characters.",
		"Returns a pointer to the first match or NULL if not found.",
		"char\t*ft_strnstr(const char *haystack, const char *needle, size_t len)\n"
			"{\n"
			"\tsize_t i;\n"
			"\tsize_t needle_len = ft_strlen(needle);\n"
			"\tif (needle_len == 0)\n"
			"\t\treturn ((char *)haystack);\n"
			"\ti = 0;\n"
			"\twhile (haystack[i] && (i + needle_len) <= len)\n"
			"\t{\n"
			"\t\tif (ft_strncmp(&haystack[i], needle, needle_len) == 0)\n"
			"\t\t\treturn ((char *)&haystack[i]);\n"
			"\t\ti++;\n"
			"\t}\n"
			"\treturn (NULL);\n"
			"}"
	},
	{
		"ft_strlcpy",
		"Copies up to dstsize - 1 characters from src to dst, NUL-terminating the result.",
		"Returns the total length of src.",
		"size_t\tft_strlcpy(char *dst, const char *src, size_t dstsize)\n"
			"{\n"
			"\tsize_t i;\n"
			"\tsize_t src_len;\n"
			"\n"
			"\tsrc_len = 0;\n"
			"\twhile (src[src_len])\n"
			"\t\tsrc_len++;\n"
			"\tif (dstsize == 0)\n"
			"\t\treturn (src_len);\n"
			"\ti = 0;\n"
			"\twhile (src[i] && i < dstsize - 1)\n"
			"\t{\n"
			"\t\tdst[i] = src[i];\n"
			"\t\ti++;\n"
			"\t}\n"
			"\tdst[i] = '\\0';\n"
			"\treturn (src_len);\n"
			"}"
	},
	{
		"ft_strlcat",
		"Appends src to string dst of size dstsize, NUL-terminating the result.",
		"Returns the length it tried to create (dst_len + src_len).",
		"size_t\tft_strlcat(char *dst, const char *src, size_t dstsize)\n"
			"{\n"
			"\tsize_t dst_len;\n"
			"\tsize_t src_len;\n"
			"\tsize_t i;\n"
			"\n"
			"\tdst_len = 0;\n"
			"\twhile (dst[dst_len] && dst_len < dstsize)\n"
			"\t\tdst_len++;\n"
			"\tsrc_len = 0;\n"
			"\twhile (src[src_len])\n"
			"\t\tsrc_len++;\n"
			"\tif (dst_len == dstsize)\n"
			"\t\treturn (dstsize + src_len);\n"
			"\ti = 0;\n"
			"\twhile (src[i] && (dst_len + i) < (dstsize - 1))\n"
			"\t{\n"
			"\t\tdst[dst_len + i] = src[i];\n"
			"\t\ti++;\n"
			"\t}\n"
			"\tdst[dst_len + i] = '\\0';\n"
			"\treturn (dst_len + src_len);\n"
			"}"
	},
	{
		"ft_strtrim",
		"Returns a copy of s1 with characters in set trimmed from the start and end.",
		"Returns newly allocated trimmed string, or NULL if allocation fails.",
		"char\t*ft_strtrim(char const *s1, char const *set)\n"
			"{\n"
			"\tsize_t start;\n"
			"\tsize_t end;\n"
			"\tsize_t i;\n"
			"\tchar *trimmed;\n"
			"\n"
			"\tif (!s1 || !set)\n"
			"\t\treturn (NULL);\n"
			"\tstart = 0;\n"
			"\twhile (s1[start] && strchr(set, s1[start]))\n"
			"\t\tstart++;\n"
			"\tend = ft_strlen(s1);\n"
			"\twhile (end > start && strchr(set, s1[end - 1]))\n"
			"\t\tend--;\n"
			"\ttrimmed = malloc(end - start + 1);\n"
			"\tif (!trimmed)\n"
			"\t\treturn (NULL);\n"
			"\ti = 0;\n"
			"\twhile (start < end)\n"
			"\t\ttrimmed[i++] = s1[start++];\n"
			"\ttrimmed[i] = '\\0';\n"
			"\treturn (trimmed);\n"
			"}"
	},
	/*
	   {
	   "ft_split",
	   "Splits string s by delimiter c into a NULL-terminated array of strings.",
	   "static size_t\tcount_words(char const *s, char c)\n"
	   "{\n"
	   "\tsize_t count = 0;\n"
	   "\tint in_word = 0;\n"
	   "\n"
	   "\twhile (*s)\n"
	   "\t{\n"
	   "\t\tif (*s != c && !in_word)\n"
	   "\t\t{\n"
	   "\t\t\tin_word = 1;\n"
	   "\t\t\tcount++;\n"
	   "\t\t}\n"
	   "\t\telse if (*s == c)\n"
	   "\t\t\tin_word = 0;\n"
	   "\t\ts++;\n"
	   "\t}\n"
	   "\treturn (count);\n"
	   "}\n"
	   "\n"
	   "static char\t*word_dup(char const *start, size_t len)\n"
	   "{\n"
	   "\tchar *word = malloc(len + 1);\n"
	   "\tsize_t i;\n"
	   "\n"
	   "\tif (!word)\n"
	   "\t\treturn (NULL);\n"
	   "\ti = 0;\n"
	   "\twhile (i < len)\n"
	   "\t{\n"
	   "\t\tword[i] = start[i];\n"
	   "\t\ti++;\n"
	   "\t}\n"
	   "\tword[i] = '\\0';\n"
	   "\treturn (word);\n"
	   "}\n"
	   "\n"
	   "char\t*ft_split(char const *s, char c)\n"
	   "{\n"
	   "\tsize_t i = 0;\n"
	   "\tsize_t j = 0;\n"
	   "\tsize_t start = 0;\n"
	   "\tsize_t word_count;\n"
	   "\tchar **split;\n"
	   "\n"
	   "\tif (!s)\n"
	   "\t\treturn (NULL);\n"
	   "\tword_count = count_words(s, c);\n"
	   "\tsplit = malloc(sizeof(char *) * (word_count + 1));\n"
	   "\tif (!split)\n"
	   "\t\treturn (NULL);\n"
	   "\ti = 0;\n"
	   "\tj = 0;\n"
	   "\twhile (s[i])\n"
	   "\t{\n"
	   "\t\tif (s[i] != c && (i == 0 || s[i - 1] == c))\n"
	   "\t\t\tstart = i;\n"
	   "\t\tif (s[i] != c && (s[i + 1] == c || s[i + 1] == '\\0'))\n"
	   "\t\t{\n"
	   "\t\t\tsplit[j] = word_dup(s + start, i - start + 1);\n"
	   "\t\t\tj++;\n"
	   "\t\t}\n"
	   "\t\ti++;\n"
	   "\t}\n"
	   "\tsplit[j] = NULL;\n"
	   "\treturn (split);\n"
	   "}"
	   },
	*/
	{
		"ft_strmapi",
			"Applies function f to each char of s, passing index, returning new string.",
			"Returns a newly allocated string or NULL.",
			"char\t*ft_strmapi(char const *s, char (*f)(unsigned int, char))\n"
				"{\n"
				"\tchar *result;\n"
				"\tsize_t i;\n"
				"\n"
				"\tif (!s || !f)\n"
				"\t\treturn (NULL);\n"
				"\tresult = malloc(ft_strlen(s) + 1);\n"
				"\tif (!result)\n"
				"\t\treturn (NULL);\n"
				"\ti = 0;\n"
				"\twhile (s[i])\n"
				"\t{\n"
				"\t\tresult[i] = f(i, s[i]);\n"
				"\t\ti++;\n"
				"\t}\n"
				"\tresult[i] = '\\0';\n"
				"\treturn (result);\n"
				"}"
	},
	{
		"ft_striteri",
		"Applies function f to each char of s, passing index, modifying in-place.",
		"Returns nothing (void).",
		"void\tft_striteri(char *s, void (*f)(unsigned int, char *))\n"
			"{\n"
			"\tsize_t i = 0;\n"
			"\n"
			"\tif (!s || !f)\n"
			"\t\treturn;\n"
			"\twhile (s[i])\n"
			"\t{\n"
			"\t\tf(i, &s[i]);\n"
			"\t\ti++;\n"
			"\t}\n"
			"}"
	},
	{
		"count_words",
		"Counts the number of words in s separated by delimiter c.",
		"Returns the number of words as size_t.",
		"size_t\tcount_words(const char *s, char c)\n"
			"{\n"
			"\tsize_t count = 0;\n"
			"\tint in_word = 0;\n"
			"\n"
			"\twhile (*s)\n"
			"\t{\n"
			"\t\tif (*s != c && !in_word)\n"
			"\t\t{\n"
			"\t\t\tin_word = 1;\n"
			"\t\t\tcount++;\n"
			"\t\t}\n"
			"\t\telse if (*s == c)\n"
			"\t\t\tin_word = 0;\n"
			"\t\ts++;\n"
			"\t}\n"
			"\treturn (count);\n"
			"}"
	},
	{
		"word_dup",
		"Duplicates a substring of length len starting at start.",
		"Returns a new string or NULL if allocation fails.",
		"char\t*word_dup(const char *start, size_t len)\n"
			"{\n"
			"\tchar *word = malloc(len + 1);\n"
			"\tsize_t i = 0;\n"
			"\n"
			"\tif (!word)\n"
			"\t\treturn (NULL);\n"
			"\twhile (i < len)\n"
			"\t{\n"
			"\t\tword[i] = start[i];\n"
			"\t\ti++;\n"
			"\t}\n"
			"\tword[i] = '\\0';\n"
			"\treturn (word);\n"
			"}"
	},
	{
		"ft_split",
		"Splits string s by delimiter c into a NULL-terminated array of strings.",
		"Returns a NULL-terminated array or NULL on failure.",
		"char\t**ft_split(const char *s, char c)\n"
			"{\n"
			"\tsize_t i = 0;\n"
			"\tsize_t j = 0;\n"
			"\tsize_t start = 0;\n"
			"\tsize_t word_count;\n"
			"\tchar **split;\n"
			"\n"
			"\tif (!s)\n"
			"\t\treturn (NULL);\n"
			"\tword_count = count_words(s, c);\n"
			"\tsplit = malloc(sizeof(char *) * (word_count + 1));\n"
			"\tif (!split)\n"
			"\t\treturn (NULL);\n"
			"\ti = 0;\n"
			"\tj = 0;\n"
			"\twhile (s[i])\n"
			"\t{\n"
			"\t\tif (s[i] != c && (i == 0 || s[i - 1] == c))\n"
			"\t\t\tstart = i;\n"
			"\t\tif (s[i] != c && (s[i + 1] == c || s[i + 1] == '\\0'))\n"
			"\t\t{\n"
			"\t\t\tsplit[j++] = word_dup(s + start, i - start + 1);\n"
			"\t\t}\n"
			"\t\ti++;\n"
			"\t}\n"
			"\tsplit[j] = NULL;\n"
			"\treturn (split);\n"
			"}"
	},
};

int get_string_function_count(void) {
	return sizeof(string_functions) / sizeof(LibFunc);
}

LibFunc get_string_function_by_index(int index) {
	if (index < 0 || index >= get_string_function_count()) {
		fprintf(stderr, "Invalid string function index.\n");
		exit(1);
	}
	return string_functions[index];
}
