#include "core.h"

LibFunc ft_printf_utils_functions[] = {
    {"ft_putchar_fd",
     "Outputs the character c to the given file descriptor.",
     "None.",
     NULL,
     0,
     "void\tft_putchar_fd(char c, int fd)\n"
     "{\n"
     "\twrite(fd, &c, 1);\n"
     "}\n"},
    {"ft_putstr_fd",
     "Outputs the string s to the given file descriptor.",
     "None.",
     NULL,
     0,
     "void\tft_putstr_fd(char *s, int fd)\n"
     "{\n"
     "\tint\ti;\n"
     "\n"
     "\tif (!s)\n"
     "\t\treturn ;\n"
     "\ti = 0;\n"
     "\twhile (s[i])\n"
     "\t{\n"
     "\t\twrite(fd, &s[i], 1);\n"
     "\t\ti++;\n"
     "\t}\n"
     "}\n"},
    {"ft_strlen",
     "Returns the length of the string s.",
     "Returns the number of characters before the null terminator.",
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
     "}\n"},
    {"ft_strchr",
     "Locates the first occurrence of c in the string s.",
     "Returns a pointer to the matched character or NULL.",
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
    {"ft_strjoin",
     "Allocates and returns a new string, result of the concatenation of s1 and s2.",
     "Returns the new string. NULL if the allocation fails.",
     NULL,
     0,
     "char\t*ft_strjoin(char const *s1, char const *s2)\n"
     "{\n"
     "\tint\t\ti;\n"
     "\tint\t\tj;\n"
     "\tchar\t*res;\n"
     "\n"
     "\tif (!s1 || !s2)\n"
     "\t\treturn (NULL);\n"
     "\tres = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);\n"
     "\tif (!res)\n"
     "\t\treturn (NULL);\n"
     "\ti = -1;\n"
     "\twhile (s1[++i])\n"
     "\t\tres[i] = s1[i];\n"
     "\tj = 0;\n"
     "\twhile (s2[j])\n"
     "\t\tres[i++] = s2[j++];\n"
     "\tres[i] = '\\0';\n"
     "\treturn (res);\n"
     "}\n"},
    {"ft_uitoa",
     "Converts an unsigned int to a null-terminated string.",
     "Returns a newly allocated string representing the unsigned integer.",
     NULL,
     0,
     "char\t*ft_uitoa(unsigned int n)\n"
     "{\n"
     "\tint\t\t\tlen;\n"
     "\tchar\t\t\t*res;\n"
     "\tunsigned int\ttemp;\n"
     "\n"
     "\tlen = 1;\n"
     "\ttemp = n;\n"
     "\twhile (temp /= 10)\n"
     "\t\tlen++;\n"
     "\tres = malloc(len + 1);\n"
     "\tif (!res)\n"
     "\t\treturn (NULL);\n"
     "\tres[len] = '\\0';\n"
     "\twhile (len--)\n"
     "\t{\n"
     "\t\tres[len] = (n % 10) + '0';\n"
     "\t\tn /= 10;\n"
     "\t}\n"
     "\treturn (res);\n"
     "}\n"},
    {"ft_itoa",
     "Converts an integer to a null-terminated string.",
     "Returns a newly allocated string representing the integer.",
     NULL,
     0,
     "static int\tget_int_len(int n)\n"
     "{\n"
     "\tint\tlen;\n"
     "\n"
     "\tlen = (n <= 0);\n"
     "\twhile (n)\n"
     "\t{\n"
     "\t\tn /= 10;\n"
     "\t\tlen++;\n"
     "\t}\n"
     "\treturn (len);\n"
     "}\n"
     "\n"
     "char\t*ft_itoa(int n)\n"
     "{\n"
     "\tint\tlen;\n"
     "\tlong\tnbr;\n"
     "\tchar\t*res;\n"
     "\n"
     "\tlen = get_int_len(n);\n"
     "\tnbr = n;\n"
     "\tres = malloc(len + 1);\n"
     "\tif (!res)\n"
     "\t\treturn (NULL);\n"
     "\tres[len] = '\\0';\n"
     "\tif (nbr < 0)\n"
     "\t{\n"
     "\t\tnbr = -nbr;\n"
     "\t\tres[0] = '-';\n"
     "\t}\n"
     "\twhile (--len >= 0 && res[len] != '-')\n"
     "\t{\n"
     "\t\tres[len] = (nbr % 10) + '0';\n"
     "\t\tnbr /= 10;\n"
     "\t}\n"
     "\treturn (res);\n"
     "}\n"},
    {"ft_putnbr_fd",
     "Outputs an integer n to the given file descriptor.",
     "None.",
     NULL,
     0,
     "void\tft_putnbr_fd(int n, int fd)\n"
     "{\n"
     "\tchar\tc;\n"
     "\n"
     "\tif (n == -2147483648)\n"
     "\t\treturn (write(fd, \"-2147483648\", 11));\n"
     "\tif (n < 0)\n"
     "\t{\n"
     "\t\twrite(fd, \"-\", 1);\n"
     "\t\tn = -n;\n"
     "\t}\n"
     "\tif (n > 9)\n"
     "\t\tft_putnbr_fd(n / 10, fd);\n"
     "\tc = n % 10 + '0';\n"
     "\twrite(fd, &c, 1);\n"
     "}\n"},
    {"ft_putnbr_base",
     "Outputs an unsigned integer in a given base to the given file descriptor.",
     "None.",
     NULL,
     0,
     "void\tft_putnbr_base(unsigned int nbr, char *base, int fd)\n"
     "{\n"
     "\tunsigned int\tlen;\n"
     "\n"
     "\tlen = ft_strlen(base);\n"
     "\tif (nbr >= len)\n"
     "\t\tft_putnbr_base(nbr / len, base, fd);\n"
     "\twrite(fd, &base[nbr % len], 1);\n"
     "}\n"},
};

int get_ft_printf_utils_functions_count(void)
{
    return sizeof(ft_printf_utils_functions) / sizeof(LibFunc);
}

LibFunc get_ft_printf_utils_functions_by_index(int index)
{
    if (index < 0 || index >= get_ft_printf_utils_functions_count())
    {
        fprintf(stderr, "Invalid printf utils function index.\\n");
        exit(1);
    }
    return ft_printf_utils_functions[index];
}