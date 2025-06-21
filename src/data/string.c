#include "core.h"
#include <stdio.h>	// for fprintf, stderr
#include <stdlib.h> // for exit

static const Variant strcpy_variants[] = {
	{"index-based",
	 "char\t*ft_strcpy(char *dst, const char *src)\n"
	 "{\n"
	 "\tsize_t\ti;\n"
	 "\n"
	 "\ti = 0;\n"
	 "\twhile (src[i])\n"
	 "\t{\n"
	 "\t\tdst[i] = src[i];\n"
	 "\t\ti++;\n"
	 "\t}\n"
	 "\tdst[i] = '\\0';\n"
	 "\treturn (dst);\n"
	 "}\n"},
	{"pointer-based",
	 "char\t*ft_strcpy(char *dst, const char *src)\n"
	 "{\n"
	 "\tchar\t*ret;\n"
	 "\n"
	 "\tret = dst;\n"
	 "\twhile (*src)\n"
	 "\t\t*dst++ = *src++;\n"
	 "\t*dst = '\\0';\n"
	 "\treturn (ret);\n"
	 "}\n"}};

static const Variant strlen_variants[] = {
	{"index-based",
	 "size_t\tft_strlen(const char *s)\n"
	 "{\n"
	 "\tsize_t\ti;\n"
	 "\n"
	 "\ti = 0;\n"
	 "\twhile (s[i])\n"
	 "\t\ti++;\n"
	 "\treturn (i);\n"
	 "}\n"},
	{"pointer-based",
	 "size_t\tft_strlen(const char *s)\n"
	 "{\n"
	 "\tconst char\t*start;\n"
	 "\n"
	 "\tstart = s;\n"
	 "\twhile (*s)\n"
	 "\t\ts++;\n"
	 "\treturn (s - start);\n"
	 "}\n"}};

LibFunc string_functions[] = {
	{"ft_strlen",
	 "Calculates the length of a string.",
	 "Returns the number of characters in the string, excluding the null terminator.",
	 strlen_variants,
	 2,
	 NULL},
	{"ft_strchr",
	 "Locates the first occurrence of c in the string s.",
	 "Returns a pointer to the first occurrence of character c in string s, or NULL if not found.",
	 NULL,
	 0,
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
	 "}\n"},
	{"ft_strrchr",
	 "Locates the last occurrence of c in the string s.",
	 "Returns a pointer to the last occurrence of character c in string s, or NULL if not found.",
	 NULL,
	 0,
	 "char\t*ft_strrchr(const char *s, int c)\n"
	 "{\n"
	 "\tconst char\t*last;\n"
	 "\n"
	 "\tlast = NULL;\n"
	 "\twhile (*s)\n"
	 "\t{\n"
	 "\t\tif (*s == (char)c)\n"
	 "\t\t\tlast = s;\n"
	 "\t\ts++;\n"
	 "\t}\n"
	 "\tif (c == '\\0')\n"
	 "\t\treturn ((char *)s);\n"
	 "\treturn ((char *)last);\n"
	 "}\n"},
	{"ft_strncmp",
	 "Compares up to n characters of the strings s1 and s2.",
	 "Returns 0 if equal, or the difference between the first differing characters.",
	 NULL,
	 0,
	 "int\tft_strncmp(const char *s1, const char *s2, size_t n)\n"
	 "{\n"
	 "\tsize_t\ti;\n"
	 "\n"
	 "\ti = 0;\n"
	 "\twhile (i < n && (s1[i] || s2[i]))\n"
	 "\t{\n"
	 "\t\tif ((unsigned char)s1[i] != (unsigned char)s2[i])\n"
	 "\t\t\treturn ((unsigned char)s1[i] - (unsigned char)s2[i]);\n"
	 "\t\ti++;\n"
	 "\t}\n"
	 "\treturn (0);\n"
	 "}\n"},
	{"ft_strcpy",
	 "Copies the string src to dst including the null terminator.",
	 "Returns dst.",
	 strcpy_variants,
	 2,
	 NULL},
	{"ft_strdup",
	 "Returns a pointer to a new string which is a duplicate of the string s1.",
	 "Returns a newly allocated duplicate of the string s. Returns NULL if allocation fails.",
	 NULL,
	 0,
	 "char\t*ft_strdup(const char *s1)\n"
	 "{\n"
	 "\tchar\t*copy;\n"
	 "\n"
	 "\tcopy = (char *)malloc(ft_strlen(s1) + 1);\n"
	 "\tif (!copy)\n"
	 "\t\treturn (NULL);\n"
	 "\treturn (ft_strcpy(copy, s1));\n"
	 "}\n"},
	{"ft_strlcpy",
	 "Copies up to dstsize - 1 characters from src to dst, NUL-terminating the result.",
	 "Returns the total length of src.",
	 NULL,
	 0,
	 "size_t\tft_strlcpy(char *dst, const char *src, size_t dstsize)\n"
	 "{\n"
	 "\tsize_t\ti;\n"
	 "\tsize_t\tsrc_len;\n"
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
	 "}\n"},
	{"ft_strlcat",
	 "Appends src to string dst of size dstsize, NUL-terminating the result.",
	 "Returns the length it tried to create (dst_len + src_len).",
	 NULL,
	 0,
	 "size_t\tft_strlcat(char *dst, const char *src, size_t dstsize)\n"
	 "{\n"
	 "\tsize_t\ti;\n"
	 "\tsize_t\tdst_len;\n"
	 "\tsize_t\tsrc_len;\n"
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
	 "}\n"},
	{"ft_substr",
	 "Allocates and returns a substring from the string s.",
	 "Returns a newly allocated string starting at index start and of maximum length len. Returns an empty string if start is beyond s length.",
	 NULL,
	 0,
	 "char\t*ft_substr(const char *s, unsigned int start, size_t len)\n"
	 "{\n"
	 "\tchar\t*substr;\n"
	 "\tsize_t\ti;\n"
	 "\tsize_t\ts_len;\n"
	 "\n"
	 "\tif (!s)\n"
	 "\t\treturn (NULL);\n"
	 "\ts_len = ft_strlen(s);\n"
	 "\tif (start >= s_len)\n"
	 "\t\treturn (ft_strdup(\"\"));\n"
	 "\tif (len > (s_len - start))\n"
	 "\t\tlen = s_len - start;\n"
	 "\tsubstr = malloc(len + 1);\n"
	 "\tif (!substr)\n"
	 "\t\treturn (NULL);\n"
	 "\ti = 0;\n"
	 "\twhile (i < len && s[start + i])\n"
	 "\t{\n"
	 "\t\tsubstr[i] = s[start + i];\n"
	 "\t\ti++;\n"
	 "\t}\n"
	 "\tsubstr[i] = '\\0';\n"
	 "\treturn (substr);\n"
	 "}\n"},
	{"ft_strjoin",
	 "Allocates and returns a new string, result of the concatenation of s1 and s2.",
	 "Returns a newly allocated string containing the concatenation of s1 and s2, or NULL if allocation fails.",
	 NULL,
	 0,
	 "char\t*ft_strjoin(const char *s1, const char *s2)\n"
	 "{\n"
	 "\tchar\t*joined;\n"
	 "\tsize_t\tlen1;\n"
	 "\tsize_t\tlen2;\n"
	 "\tsize_t\ti;\n"
	 "\n"
	 "\tif (!s1 || !s2)\n"
	 "\t\treturn (NULL);\n"
	 "\tlen1 = ft_strlen(s1);\n"
	 "\tlen2 = ft_strlen(s2);\n"
	 "\tjoined = malloc(len1 + len2 + 1);\n"
	 "\tif (!joined)\n"
	 "\t\treturn (NULL);\n"
	 "\ti = 0;\n"
	 "\twhile (*s1)\n"
	 "\t\tjoined[i++] = *s1++;\n"
	 "\twhile (*s2)\n"
	 "\t\tjoined[i++] = *s2++;\n"
	 "\tjoined[i] = '\\0';\n"
	 "\treturn (joined);\n"
	 "}\n"},
	{"ft_strnstr",
	 "Locates the first occurrence of the null-terminated string needle in haystack, searching not more than len characters.",
	 "Returns a pointer to the first match or NULL if not found.",
	 NULL,
	 0,
	 "char\t*ft_strnstr(const char *haystack, const char *needle, size_t len)\n"
	 "{\n"
	 "\tsize_t\ti;\n"
	 "\tsize_t\tneedle_len;\n"
	 "\n"
	 "\tneedle_len = ft_strlen(needle);\n"
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
	 "}\n"},
	{"ft_strtrim",
	 "Returns a copy of s1 with characters in set trimmed from the start and end.",
	 "Returns newly allocated trimmed string, or NULL if allocation fails.",
	 NULL,
	 0,
	 "char\t*ft_strtrim(const char *s1, const char *set)\n"
	 "{\n"
	 "\tsize_t\ti;\n"
	 "\tsize_t\tend;\n"
	 "\tsize_t\tstart;\n"
	 "\tchar\t*trimmed;\n"
	 "\n"
	 "\tif (!s1 || !set)\n"
	 "\t\treturn (NULL);\n"
	 "\tstart = 0;\n"
	 "\twhile (s1[start] && ft_strchr(set, s1[start]))\n"
	 "\t\tstart++;\n"
	 "\tend = ft_strlen(s1);\n"
	 "\twhile (end > start && ft_strchr(set, s1[end - 1]))\n"
	 "\t\tend--;\n"
	 "\ttrimmed = malloc(end - start + 1);\n"
	 "\tif (!trimmed)\n"
	 "\t\treturn (NULL);\n"
	 "\ti = 0;\n"
	 "\twhile (start < end)\n"
	 "\t\ttrimmed[i++] = s1[start++];\n"
	 "\ttrimmed[i] = '\\0';\n"
	 "\treturn (trimmed);\n"
	 "}\n"},
	{"ft_strmapi",
	 "Applies function f to each char of s, passing index, returning new string.",
	 "Returns a newly allocated string or NULL.",
	 NULL,
	 0,
	 "char\t*ft_strmapi(const char *s, char (*f)(unsigned int, char))\n"
	 "{\n"
	 "\tsize_t\ti;\n"
	 "\tchar\t*result;\n"
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
	 "}\n"},
	{"ft_striteri",
	 "Applies function f to each char of s, passing index, modifying in-place.",
	 "Returns nothing (void).",
	 NULL,
	 0,
	 "void\tft_striteri(char *s, void (*f)(unsigned int, char *))\n"
	 "{\n"
	 "\tsize_t\ti;\n"
	 "\n"
	 "\ti = 0;\n"
	 "\tif (!s || !f)\n"
	 "\t\treturn ;\n"
	 "\twhile (s[i])\n"
	 "\t{\n"
	 "\t\tf(i, &s[i]);\n"
	 "\t\ti++;\n"
	 "\t}\n"
	 "}\n"},
	{"count_words",
	 "Counts the number of words in s separated by delimiter c.",
	 "Returns the number of words as size_t.",
	 NULL,
	 0,
	 "size_t\tcount_words(const char *s, char c)\n"
	 "{\n"
	 "\tint\t\tin_word;\n"
	 "\tsize_t\tcount;\n"
	 "\n"
	 "\tin_word = 0;\n"
	 "\tcount = 0;\n"
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
	 "}\n"},
	{"word_dup",
	 "Duplicates a substring of length len starting at start.",
	 "Returns a new string or NULL if allocation fails.",
	 NULL,
	 0,
	 "char\t*word_dup(const char *start, size_t len)\n"
	 "{\n"
	 "\tsize_t\ti;\n"
	 "\tchar\t*word;\n"
	 "\n"
	 "\tword = malloc(len + 1);\n"
	 "\ti = 0;\n"
	 "\tif (!word)\n"
	 "\t\treturn (NULL);\n"
	 "\twhile (i < len)\n"
	 "\t{\n"
	 "\t\tword[i] = start[i];\n"
	 "\t\ti++;\n"
	 "\t}\n"
	 "\tword[i] = '\\0';\n"
	 "\treturn (word);\n"
	 "}\n"},
	{"ft_split",
	 "Splits string s by delimiter c into a NULL-terminated array of strings.",
	 "Returns a NULL-terminated array or NULL on failure.",
	 NULL,
	 0,
	 "char\t**ft_split(const char *s, char c)\n"
	 "{\n"
	 "\tsize_t\ti;\n"
	 "\tsize_t\tj;\n"
	 "\tsize_t\tstart;\n"
	 "\tsize_t\tword_count;\n"
	 "\tchar\t**split;\n"
	 "\n"
	 "\ti = 0;\n"
	 "\tj = 0;\n"
	 "\tstart = 0;\n"
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
	 "}\n"},
};

int get_string_function_count(void)
{
	return sizeof(string_functions) / sizeof(LibFunc);
}

LibFunc get_string_function_by_index(int index)
{
	if (index < 0 || index >= get_string_function_count())
	{
		fprintf(stderr, "Invalid string function index.\n");
		exit(1);
	}
	return string_functions[index];
}
