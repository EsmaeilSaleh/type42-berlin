#include "core.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_exam02_question
{
	const char *id;
	const char *title;
	const char *description;
	const char *canonical_solution;
	const char *expected_files;
	const char *tags;
} Exam02Question;

static const Exam02Question g_exam02_level1_questions[] = {
	{"first_word",
	 "first_word",
	 "Write a program that takes a string and displays its first word followed by a newline.",
	 "#include <unistd.h>\n"
	 "\n"
	 "int\tmain(int argc, char **argv)\n"
	 "{\n"
	 "\tint\ti;\n"
	 "\n"
	 "\ti = 0;\n"
	 "\tif (argc == 2)\n"
	 "\t{\n"
	 "\t\twhile (argv[1][i] == ' ' || argv[1][i] == '\\t')\n"
	 "\t\t\ti++;\n"
	 "\t\twhile (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\\t')\n"
	 "\t\t\twrite(1, &argv[1][i++], 1);\n"
	 "\t}\n"
	 "\twrite(1, \"\\n\", 1);\n"
	 "\treturn (0);\n"
	 "}\n",
	 "Expected file: first_word.c",
	 "level1, string parsing"},
	{"fizzbuzz",
	 "fizzbuzz",
	 "Write a program that prints numbers 1 to 100 with Fizz/Buzz replacements.",
	 "#include <unistd.h>\n"
	 "\n"
	 "static void\tputnbr(int n)\n"
	 "{\n"
	 "\tchar c;\n"
	 "\n"
	 "\tif (n > 9)\n"
	 "\t\tputnbr(n / 10);\n"
	 "\tc = (n % 10) + '0';\n"
	 "\twrite(1, &c, 1);\n"
	 "}\n"
	 "\n"
	 "int\tmain(void)\n"
	 "{\n"
	 "\tint i;\n"
	 "\n"
	 "\ti = 1;\n"
	 "\twhile (i <= 100)\n"
	 "\t{\n"
	 "\t\tif (i % 3 == 0 && i % 5 == 0)\n"
	 "\t\t\twrite(1, \"fizzbuzz\", 8);\n"
	 "\t\telse if (i % 3 == 0)\n"
	 "\t\t\twrite(1, \"fizz\", 4);\n"
	 "\t\telse if (i % 5 == 0)\n"
	 "\t\t\twrite(1, \"buzz\", 4);\n"
	 "\t\telse\n"
	 "\t\t\tputnbr(i);\n"
	 "\t\twrite(1, \"\\n\", 1);\n"
	 "\t\ti++;\n"
	 "\t}\n"
	 "\treturn (0);\n"
	 "}\n",
	 "Expected file: fizzbuzz.c",
	 "level1, loops"},
	{"ft_putstr",
	 "ft_putstr",
	 "Write a function that displays a string on standard output.",
	 "#include <unistd.h>\n"
	 "\n"
	 "void\tft_putstr(char *str)\n"
	 "{\n"
	 "\twhile (*str)\n"
	 "\t\twrite(1, str++, 1);\n"
	 "}\n",
	 "Expected file: ft_putstr.c",
	 "level1, function"},
	{"ft_strlen",
	 "ft_strlen",
	 "Write a function that returns the length of a string.",
	 "int\tft_strlen(char *str)\n"
	 "{\n"
	 "\tint len;\n"
	 "\n"
	 "\tlen = 0;\n"
	 "\twhile (str[len])\n"
	 "\t\tlen++;\n"
	 "\treturn (len);\n"
	 "}\n",
	 "Expected file: ft_strlen.c",
	 "level1, function"},
	{"rev_print",
	 "rev_print",
	 "Write a program that takes a string and prints it in reverse followed by a newline.",
	 "#include <unistd.h>\n"
	 "\n"
	 "int\tmain(int argc, char **argv)\n"
	 "{\n"
	 "\tint i;\n"
	 "\n"
	 "\tif (argc == 2)\n"
	 "\t{\n"
	 "\t\ti = 0;\n"
	 "\t\twhile (argv[1][i])\n"
	 "\t\t\ti++;\n"
	 "\t\twhile (i > 0)\n"
	 "\t\t\twrite(1, &argv[1][--i], 1);\n"
	 "\t}\n"
	 "\twrite(1, \"\\n\", 1);\n"
	 "\treturn (0);\n"
	 "}\n",
	 "Expected file: rev_print.c",
	 "level1, string parsing"},
	{"repeat_alpha",
	 "repeat_alpha",
	 "Write a program that repeats each alphabetic character according to its index in alphabet.",
	 "#include <unistd.h>\n"
	 "\n"
	 "static void\trepeat_char(char c)\n"
	 "{\n"
	 "\tint\ttimes;\n"
	 "\n"
	 "\tif (c >= 'a' && c <= 'z')\n"
	 "\t\ttimes = c - 'a' + 1;\n"
	 "\telse if (c >= 'A' && c <= 'Z')\n"
	 "\t\ttimes = c - 'A' + 1;\n"
	 "\telse\n"
	 "\t\ttimes = 1;\n"
	 "\twhile (times--)\n"
	 "\t\twrite(1, &c, 1);\n"
	 "}\n"
	 "\n"
	 "int\tmain(int argc, char **argv)\n"
	 "{\n"
	 "\tint i;\n"
	 "\n"
	 "\tif (argc == 2)\n"
	 "\t{\n"
	 "\t\ti = 0;\n"
	 "\t\twhile (argv[1][i])\n"
	 "\t\t\trepeat_char(argv[1][i++]);\n"
	 "\t}\n"
	 "\twrite(1, \"\\n\", 1);\n"
	 "\treturn (0);\n"
	 "}\n",
	 "Expected file: repeat_alpha.c",
	 "level1, string transform"},
	{"rot_13",
	 "rot_13",
	 "Write a program that applies ROT13 to a string and prints it.",
	 "#include <unistd.h>\n"
	 "\n"
	 "int\tmain(int argc, char **argv)\n"
	 "{\n"
	 "\tint\ti;\n"
	 "\tchar\tc;\n"
	 "\n"
	 "\tif (argc == 2)\n"
	 "\t{\n"
	 "\t\ti = 0;\n"
	 "\t\twhile (argv[1][i])\n"
	 "\t\t{\n"
	 "\t\t\tc = argv[1][i];\n"
	 "\t\t\tif ((c >= 'a' && c <= 'm') || (c >= 'A' && c <= 'M'))\n"
	 "\t\t\t\tc += 13;\n"
	 "\t\t\telse if ((c >= 'n' && c <= 'z') || (c >= 'N' && c <= 'Z'))\n"
	 "\t\t\t\tc -= 13;\n"
	 "\t\t\twrite(1, &c, 1);\n"
	 "\t\t\ti++;\n"
	 "\t\t}\n"
	 "\t}\n"
	 "\twrite(1, \"\\n\", 1);\n"
	 "\treturn (0);\n"
	 "}\n",
	 "Expected file: rot_13.c",
	 "level1, string transform"},
	{"rotone",
	 "rotone",
	 "Write a program that shifts each letter by one in the alphabet.",
	 "#include <unistd.h>\n"
	 "\n"
	 "int\tmain(int argc, char **argv)\n"
	 "{\n"
	 "\tint\ti;\n"
	 "\tchar\tc;\n"
	 "\n"
	 "\tif (argc == 2)\n"
	 "\t{\n"
	 "\t\ti = 0;\n"
	 "\t\twhile (argv[1][i])\n"
	 "\t\t{\n"
	 "\t\t\tc = argv[1][i];\n"
	 "\t\t\tif ((c >= 'a' && c <= 'y') || (c >= 'A' && c <= 'Y'))\n"
	 "\t\t\t\tc++;\n"
	 "\t\t\telse if (c == 'z')\n"
	 "\t\t\t\tc = 'a';\n"
	 "\t\t\telse if (c == 'Z')\n"
	 "\t\t\t\tc = 'A';\n"
	 "\t\t\twrite(1, &c, 1);\n"
	 "\t\t\ti++;\n"
	 "\t\t}\n"
	 "\t}\n"
	 "\twrite(1, \"\\n\", 1);\n"
	 "\treturn (0);\n"
	 "}\n",
	 "Expected file: rotone.c",
	 "level1, string transform"},
	{"search_and_replace",
	 "search_and_replace",
	 "Write a program that replaces all occurrences of one character by another in a string.",
	 "#include <unistd.h>\n"
	 "\n"
	 "int\tmain(int argc, char **argv)\n"
	 "{\n"
	 "\tint\ti;\n"
	 "\tchar\tfind;\n"
	 "\tchar\treplace;\n"
	 "\n"
	 "\tif (argc == 4 && !argv[2][1] && !argv[3][1])\n"
	 "\t{\n"
	 "\t\tfind = argv[2][0];\n"
	 "\t\treplace = argv[3][0];\n"
	 "\t\ti = 0;\n"
	 "\t\twhile (argv[1][i])\n"
	 "\t\t{\n"
	 "\t\t\tif (argv[1][i] == find)\n"
	 "\t\t\t\targv[1][i] = replace;\n"
	 "\t\t\twrite(1, &argv[1][i], 1);\n"
	 "\t\t\ti++;\n"
	 "\t\t}\n"
	 "\t}\n"
	 "\twrite(1, \"\\n\", 1);\n"
	 "\treturn (0);\n"
	 "}\n",
	 "Expected file: search_and_replace.c",
	 "level1, string parsing"},
	{"ulstr",
	 "ulstr",
	 "Write a program that swaps lowercase letters to uppercase and uppercase to lowercase.",
	 "#include <unistd.h>\n"
	 "\n"
	 "int\tmain(int argc, char **argv)\n"
	 "{\n"
	 "\tint\ti;\n"
	 "\tchar\tc;\n"
	 "\n"
	 "\tif (argc == 2)\n"
	 "\t{\n"
	 "\t\ti = 0;\n"
	 "\t\twhile (argv[1][i])\n"
	 "\t\t{\n"
	 "\t\t\tc = argv[1][i];\n"
	 "\t\t\tif (c >= 'a' && c <= 'z')\n"
	 "\t\t\t\tc -= 32;\n"
	 "\t\t\telse if (c >= 'A' && c <= 'Z')\n"
	 "\t\t\t\tc += 32;\n"
	 "\t\t\twrite(1, &c, 1);\n"
	 "\t\t\ti++;\n"
	 "\t\t}\n"
	 "\t}\n"
	 "\twrite(1, \"\\n\", 1);\n"
	 "\treturn (0);\n"
	 "}\n",
	 "Expected file: ulstr.c",
	 "level1, string transform"}};

static const Exam02Question g_exam02_level2_questions[] = {
	{"alpha_mirror",
	 "alpha_mirror",
	 "Write a program that replaces each letter by its mirrored alphabet letter.",
	 "#include <unistd.h>\n"
	 "\n"
	 "int\tmain(int argc, char **argv)\n"
	 "{\n"
	 "\tint\ti;\n"
	 "\tchar\tc;\n"
	 "\n"
	 "\tif (argc == 2)\n"
	 "\t{\n"
	 "\t\ti = 0;\n"
	 "\t\twhile (argv[1][i])\n"
	 "\t\t{\n"
	 "\t\t\tc = argv[1][i];\n"
	 "\t\t\tif (c >= 'a' && c <= 'z')\n"
	 "\t\t\t\tc = 'z' - (c - 'a');\n"
	 "\t\t\telse if (c >= 'A' && c <= 'Z')\n"
	 "\t\t\t\tc = 'Z' - (c - 'A');\n"
	 "\t\t\twrite(1, &c, 1);\n"
	 "\t\t\ti++;\n"
	 "\t\t}\n"
	 "\t}\n"
	 "\twrite(1, \"\\n\", 1);\n"
	 "\treturn (0);\n"
	 "}\n",
	 "Expected file: alpha_mirror.c",
	 "level2, string transform"},
	{"camel_to_snake",
	 "camel_to_snake",
	 "Write a program that converts a lowerCamelCase string to snake_case.",
	 "#include <unistd.h>\n"
	 "\n"
	 "int\tmain(int argc, char **argv)\n"
	 "{\n"
	 "\tint\ti;\n"
	 "\n"
	 "\tif (argc == 2)\n"
	 "\t{\n"
	 "\t\ti = 0;\n"
	 "\t\twhile (argv[1][i])\n"
	 "\t\t{\n"
	 "\t\t\tif (argv[1][i] >= 'A' && argv[1][i] <= 'Z')\n"
	 "\t\t\t{\n"
	 "\t\t\t\twrite(1, \"_\", 1);\n"
	 "\t\t\t\targv[1][i] += 32;\n"
	 "\t\t\t}\n"
	 "\t\t\twrite(1, &argv[1][i], 1);\n"
	 "\t\t\ti++;\n"
	 "\t\t}\n"
	 "\t}\n"
	 "\twrite(1, \"\\n\", 1);\n"
	 "\treturn (0);\n"
	 "}\n",
	 "Expected file: camel_to_snake.c",
	 "level2, string transform"},
	{"do_op",
	 "do_op",
	 "Write a program that takes two ints and an operator and prints the result.",
	 "#include <stdlib.h>\n"
	 "#include <unistd.h>\n"
	 "#include <stdio.h>\n"
	 "\n"
	 "int\tmain(int argc, char **argv)\n"
	 "{\n"
	 "\tint\ta;\n"
	 "\tint\tb;\n"
	 "\n"
	 "\tif (argc == 4)\n"
	 "\t{\n"
	 "\t\ta = atoi(argv[1]);\n"
	 "\t\tb = atoi(argv[3]);\n"
	 "\t\tif (argv[2][0] == '+' && argv[2][1] == '\\0')\n"
	 "\t\t\tprintf(\"%d\", a + b);\n"
	 "\t\telse if (argv[2][0] == '-' && argv[2][1] == '\\0')\n"
	 "\t\t\tprintf(\"%d\", a - b);\n"
	 "\t\telse if (argv[2][0] == '*' && argv[2][1] == '\\0')\n"
	 "\t\t\tprintf(\"%d\", a * b);\n"
	 "\t\telse if (argv[2][0] == '/' && argv[2][1] == '\\0')\n"
	 "\t\t\tprintf(\"%d\", a / b);\n"
	 "\t\telse if (argv[2][0] == '%' && argv[2][1] == '\\0')\n"
	 "\t\t\tprintf(\"%d\", a % b);\n"
	 "\t}\n"
	 "\tprintf(\"\\n\");\n"
	 "\treturn (0);\n"
	 "}\n",
	 "Expected file: do_op.c",
	 "level2, parsing"},
	{"ft_atoi",
	 "ft_atoi",
	 "Write a function that converts a string to an integer.",
	 "int\tft_atoi(const char *str)\n"
	 "{\n"
	 "\tint\tsign;\n"
	 "\tint\tres;\n"
	 "\n"
	 "\tsign = 1;\n"
	 "\tres = 0;\n"
	 "\twhile (*str == ' ' || (*str >= '\\t' && *str <= '\\r'))\n"
	 "\t\tstr++;\n"
	 "\tif (*str == '-' || *str == '+')\n"
	 "\t{\n"
	 "\t\tif (*str == '-')\n"
	 "\t\t\tsign = -1;\n"
	 "\t\tstr++;\n"
	 "\t}\n"
	 "\twhile (*str >= '0' && *str <= '9')\n"
	 "\t{\n"
	 "\t\tres = res * 10 + (*str - '0');\n"
	 "\t\tstr++;\n"
	 "\t}\n"
	 "\treturn (res * sign);\n"
	 "}\n",
	 "Expected file: ft_atoi.c",
	 "level2, function"},
	{"ft_strcmp",
	 "ft_strcmp",
	 "Write a function that compares two strings.",
	 "int\tft_strcmp(char *s1, char *s2)\n"
	 "{\n"
	 "\tint i;\n"
	 "\n"
	 "\ti = 0;\n"
	 "\twhile (s1[i] && s1[i] == s2[i])\n"
	 "\t\ti++;\n"
	 "\treturn ((unsigned char)s1[i] - (unsigned char)s2[i]);\n"
	 "}\n",
	 "Expected file: ft_strcmp.c",
	 "level2, function"},
	{"ft_strcspn",
	 "ft_strcspn",
	 "Write a function that computes the length of the initial segment not containing reject chars.",
	 "#include <stddef.h>\n"
	 "\n"
	 "size_t\tft_strcspn(const char *s, const char *reject)\n"
	 "{\n"
	 "\tsize_t i;\n"
	 "\tsize_t j;\n"
	 "\n"
	 "\ti = 0;\n"
	 "\twhile (s[i])\n"
	 "\t{\n"
	 "\t\tj = 0;\n"
	 "\t\twhile (reject[j])\n"
	 "\t\t{\n"
	 "\t\t\tif (s[i] == reject[j])\n"
	 "\t\t\t\treturn (i);\n"
	 "\t\t\tj++;\n"
	 "\t\t}\n"
	 "\t\ti++;\n"
	 "\t}\n"
	 "\treturn (i);\n"
	 "}\n",
	 "Expected file: ft_strcspn.c",
	 "level2, function"},
	{"ft_strdup",
	 "ft_strdup",
	 "Write a function that duplicates a string with malloc.",
	 "#include <stdlib.h>\n"
	 "\n"
	 "char\t*ft_strdup(char *src)\n"
	 "{\n"
	 "\tint\t\tlen;\n"
	 "\tint\t\ti;\n"
	 "\tchar\t*dup;\n"
	 "\n"
	 "\tlen = 0;\n"
	 "\twhile (src[len])\n"
	 "\t\tlen++;\n"
	 "\tdup = (char *)malloc(len + 1);\n"
	 "\tif (!dup)\n"
	 "\t\treturn (NULL);\n"
	 "\ti = 0;\n"
	 "\twhile (src[i])\n"
	 "\t{\n"
	 "\t\tdup[i] = src[i];\n"
	 "\t\ti++;\n"
	 "\t}\n"
	 "\tdup[i] = '\\0';\n"
	 "\treturn (dup);\n"
	 "}\n",
	 "Expected file: ft_strdup.c",
	 "level2, function"},
	{"ft_strpbrk",
	 "ft_strpbrk",
	 "Write a function that locates in s the first occurrence of any character from accept.",
	 "char\t*ft_strpbrk(const char *s, const char *accept)\n"
	 "{\n"
	 "\tint i;\n"
	 "\tint j;\n"
	 "\n"
	 "\ti = 0;\n"
	 "\twhile (s[i])\n"
	 "\t{\n"
	 "\t\tj = 0;\n"
	 "\t\twhile (accept[j])\n"
	 "\t\t{\n"
	 "\t\t\tif (s[i] == accept[j])\n"
	 "\t\t\t\treturn ((char *)&s[i]);\n"
	 "\t\t\tj++;\n"
	 "\t\t}\n"
	 "\t\ti++;\n"
	 "\t}\n"
	 "\treturn (NULL);\n"
	 "}\n",
	 "Expected file: ft_strpbrk.c",
	 "level2, function"},
	{"ft_strrev",
	 "ft_strrev",
	 "Write a function that reverses a string in-place.",
	 "char\t*ft_strrev(char *str)\n"
	 "{\n"
	 "\tint\t\tstart;\n"
	 "\tint\t\tend;\n"
	 "\tchar\ttmp;\n"
	 "\n"
	 "\tstart = 0;\n"
	 "\tend = 0;\n"
	 "\twhile (str[end])\n"
	 "\t\tend++;\n"
	 "\tend--;\n"
	 "\twhile (start < end)\n"
	 "\t{\n"
	 "\t\ttmp = str[start];\n"
	 "\t\tstr[start] = str[end];\n"
	 "\t\tstr[end] = tmp;\n"
	 "\t\tstart++;\n"
	 "\t\tend--;\n"
	 "\t}\n"
	 "\treturn (str);\n"
	 "}\n",
	 "Expected file: ft_strrev.c",
	 "level2, function"},
	{"inter",
	 "inter",
	 "Write a program that prints the intersection of two strings without duplicates.",
	 "#include <unistd.h>\n"
	 "\n"
	 "static int\tin_seen(char *s, char c, int end)\n"
	 "{\n"
	 "\tint i;\n"
	 "\n"
	 "\ti = 0;\n"
	 "\twhile (i < end)\n"
	 "\t{\n"
	 "\t\tif (s[i] == c)\n"
	 "\t\t\treturn (1);\n"
	 "\t\ti++;\n"
	 "\t}\n"
	 "\treturn (0);\n"
	 "}\n"
	 "\n"
	 "static int\tin_str(char *s, char c)\n"
	 "{\n"
	 "\tint i;\n"
	 "\n"
	 "\ti = 0;\n"
	 "\twhile (s[i])\n"
	 "\t{\n"
	 "\t\tif (s[i] == c)\n"
	 "\t\t\treturn (1);\n"
	 "\t\ti++;\n"
	 "\t}\n"
	 "\treturn (0);\n"
	 "}\n"
	 "\n"
	 "int\tmain(int argc, char **argv)\n"
	 "{\n"
	 "\tint i;\n"
	 "\n"
	 "\tif (argc == 3)\n"
	 "\t{\n"
	 "\t\ti = 0;\n"
	 "\t\twhile (argv[1][i])\n"
	 "\t\t{\n"
	 "\t\t\tif (!in_seen(argv[1], argv[1][i], i) && in_str(argv[2], argv[1][i]))\n"
	 "\t\t\t\twrite(1, &argv[1][i], 1);\n"
	 "\t\t\ti++;\n"
	 "\t\t}\n"
	 "\t}\n"
	 "\twrite(1, \"\\n\", 1);\n"
	 "\treturn (0);\n"
	 "}\n",
	 "Expected file: inter.c",
	 "level2, string parsing"},
	{"is_power_of_2",
	 "is_power_of_2",
	 "Write a function that returns 1 if n is a power of 2, otherwise 0.",
	 "int\tis_power_of_2(unsigned int n)\n"
	 "{\n"
	 "\tif (n == 0)\n"
	 "\t\treturn (0);\n"
	 "\treturn ((n & (n - 1)) == 0);\n"
	 "}\n",
	 "Expected file: is_power_of_2.c",
	 "level2, bitwise"},
	{"last_word",
	 "last_word",
	 "Write a program that prints the last word of a string.",
	 "#include <unistd.h>\n"
	 "\n"
	 "int\tmain(int argc, char **argv)\n"
	 "{\n"
	 "\tint i;\n"
	 "\n"
	 "\tif (argc == 2)\n"
	 "\t{\n"
	 "\t\ti = 0;\n"
	 "\t\twhile (argv[1][i])\n"
	 "\t\t\ti++;\n"
	 "\t\ti--;\n"
	 "\t\twhile (i >= 0 && (argv[1][i] == ' ' || argv[1][i] == '\\t'))\n"
	 "\t\t\ti--;\n"
	 "\t\twhile (i >= 0 && argv[1][i] != ' ' && argv[1][i] != '\\t')\n"
	 "\t\t\ti--;\n"
	 "\t\ti++;\n"
	 "\t\twhile (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\\t')\n"
	 "\t\t\twrite(1, &argv[1][i++], 1);\n"
	 "\t}\n"
	 "\twrite(1, \"\\n\", 1);\n"
	 "\treturn (0);\n"
	 "}\n",
	 "Expected file: last_word.c",
	 "level2, string parsing"},
	{"max",
	 "max",
	 "Write a function that returns the maximum value in an int array.",
	 "int\tmax(int *tab, unsigned int len)\n"
	 "{\n"
	 "\tunsigned int\ti;\n"
	 "\tint\t\t\tmax_val;\n"
	 "\n"
	 "\tif (!tab || len == 0)\n"
	 "\t\treturn (0);\n"
	 "\tmax_val = tab[0];\n"
	 "\ti = 1;\n"
	 "\twhile (i < len)\n"
	 "\t{\n"
	 "\t\tif (tab[i] > max_val)\n"
	 "\t\t\tmax_val = tab[i];\n"
	 "\t\ti++;\n"
	 "\t}\n"
	 "\treturn (max_val);\n"
	 "}\n",
	 "Expected file: max.c",
	 "level2, function"},
	{"print_bits",
	 "print_bits",
	 "Write a function that prints the bits of a byte.",
	 "#include <unistd.h>\n"
	 "\n"
	 "void\tprint_bits(unsigned char octet)\n"
	 "{\n"
	 "\tint i;\n"
	 "\tchar bit;\n"
	 "\n"
	 "\ti = 7;\n"
	 "\twhile (i >= 0)\n"
	 "\t{\n"
	 "\t\tbit = ((octet >> i) & 1) + '0';\n"
	 "\t\twrite(1, &bit, 1);\n"
	 "\t\ti--;\n"
	 "\t}\n"
	 "}\n",
	 "Expected file: print_bits.c",
	 "level2, bitwise"},
	{"reverse_bits",
	 "reverse_bits",
	 "Write a function that reverses the bit order of a byte.",
	 "unsigned char\treverse_bits(unsigned char octet)\n"
	 "{\n"
	 "\tint\t\t\ti;\n"
	 "\tunsigned char\tres;\n"
	 "\n"
	 "\ti = 8;\n"
	 "\tres = 0;\n"
	 "\twhile (i--)\n"
	 "\t{\n"
	 "\t\tres = (res << 1) | (octet & 1);\n"
	 "\t\toctet >>= 1;\n"
	 "\t}\n"
	 "\treturn (res);\n"
	 "}\n",
	 "Expected file: reverse_bits.c",
	 "level2, bitwise"},
	{"snake_to_camel",
	 "snake_to_camel",
	 "Write a program that converts a snake_case string to lowerCamelCase.",
	 "#include <unistd.h>\n"
	 "\n"
	 "int\tmain(int argc, char **argv)\n"
	 "{\n"
	 "\tint\ti;\n"
	 "\n"
	 "\tif (argc == 2)\n"
	 "\t{\n"
	 "\t\ti = 0;\n"
	 "\t\twhile (argv[1][i])\n"
	 "\t\t{\n"
	 "\t\t\tif (argv[1][i] == '_' && argv[1][i + 1])\n"
	 "\t\t\t{\n"
	 "\t\t\t\ti++;\n"
	 "\t\t\t\tif (argv[1][i] >= 'a' && argv[1][i] <= 'z')\n"
	 "\t\t\t\t\targv[1][i] -= 32;\n"
	 "\t\t\t}\n"
	 "\t\t\twrite(1, &argv[1][i], 1);\n"
	 "\t\t\ti++;\n"
	 "\t\t}\n"
	 "\t}\n"
	 "\twrite(1, \"\\n\", 1);\n"
	 "\treturn (0);\n"
	 "}\n",
	 "Expected file: snake_to_camel.c",
	 "level2, string transform"},
	{"swap_bits",
	 "swap_bits",
	 "Write a function that swaps the high and low nibbles of a byte.",
	 "unsigned char\tswap_bits(unsigned char octet)\n"
	 "{\n"
	 "\treturn ((octet >> 4) | (octet << 4));\n"
	 "}\n",
	 "Expected file: swap_bits.c",
	 "level2, bitwise"},
	{"union",
	 "union",
	 "Write a program that prints union of two strings without duplicates.",
	 "#include <unistd.h>\n"
	 "\n"
	 "static int\tin_seen(char *s, char c, int end)\n"
	 "{\n"
	 "\tint i;\n"
	 "\n"
	 "\ti = 0;\n"
	 "\twhile (i < end)\n"
	 "\t{\n"
	 "\t\tif (s[i] == c)\n"
	 "\t\t\treturn (1);\n"
	 "\t\ti++;\n"
	 "\t}\n"
	 "\treturn (0);\n"
	 "}\n"
	 "\n"
	 "int\tmain(int argc, char **argv)\n"
	 "{\n"
	 "\tint i;\n"
	 "\n"
	 "\tif (argc == 3)\n"
	 "\t{\n"
	 "\t\ti = 0;\n"
	 "\t\twhile (argv[1][i])\n"
	 "\t\t{\n"
	 "\t\t\tif (!in_seen(argv[1], argv[1][i], i))\n"
	 "\t\t\t\twrite(1, &argv[1][i], 1);\n"
	 "\t\t\ti++;\n"
	 "\t\t}\n"
	 "\t\ti = 0;\n"
	 "\t\twhile (argv[2][i])\n"
	 "\t\t{\n"
	 "\t\t\tif (!in_seen(argv[2], argv[2][i], i))\n"
	 "\t\t\t{\n"
	 "\t\t\t\tint j = 0;\n"
	 "\t\t\t\tint seen = 0;\n"
	 "\t\t\t\twhile (argv[1][j])\n"
	 "\t\t\t\t{\n"
	 "\t\t\t\t\tif (argv[1][j] == argv[2][i])\n"
	 "\t\t\t\t\t{\n"
	 "\t\t\t\t\t\tseen = 1;\n"
	 "\t\t\t\t\t\tbreak ;\n"
	 "\t\t\t\t\t}\n"
	 "\t\t\t\t\tj++;\n"
	 "\t\t\t\t}\n"
	 "\t\t\t\tif (!seen)\n"
	 "\t\t\t\t\twrite(1, &argv[2][i], 1);\n"
	 "\t\t\t}\n"
	 "\t\t\ti++;\n"
	 "\t\t}\n"
	 "\t}\n"
	 "\twrite(1, \"\\n\", 1);\n"
	 "\treturn (0);\n"
	 "}\n",
	 "Expected file: union.c",
	 "level2, string parsing"},
	{"wdmatch",
	 "wdmatch",
	 "Write a program that checks if first string can be found in second in order.",
	 "#include <unistd.h>\n"
	 "\n"
	 "int\tmain(int argc, char **argv)\n"
	 "{\n"
	 "\tint i;\n"
	 "\tint j;\n"
	 "\n"
	 "\ti = 0;\n"
	 "\tj = 0;\n"
	 "\tif (argc == 3)\n"
	 "\t{\n"
	 "\t\twhile (argv[1][i] && argv[2][j])\n"
	 "\t\t{\n"
	 "\t\t\tif (argv[1][i] == argv[2][j])\n"
	 "\t\t\t\ti++;\n"
	 "\t\t\tj++;\n"
	 "\t\t}\n"
	 "\t\tif (argv[1][i] == '\\0')\n"
	 "\t\t\twrite(1, argv[1], i);\n"
	 "\t}\n"
	 "\twrite(1, \"\\n\", 1);\n"
	 "\treturn (0);\n"
	 "}\n",
	 "Expected file: wdmatch.c",
	 "level2, string parsing"}};

static const Exam02Question g_exam02_level3_questions[] = {
	{"add_prime_sum",
	 "add_prime_sum",
	 "Write a program that adds all prime numbers less than or equal to a given number.",
	 "#include <unistd.h>\n"
	 "#include <stdlib.h>\n"
	 "\n"
	 "static int\tis_prime(int n)\n"
	 "{\n"
	 "\tint i;\n"
	 "\n"
	 "\tif (n < 2)\n"
	 "\t\treturn (0);\n"
	 "\ti = 2;\n"
	 "\twhile (i * i <= n)\n"
	 "\t{\n"
	 "\t\tif (n % i == 0)\n"
	 "\t\t\treturn (0);\n"
	 "\t\ti++;\n"
	 "\t}\n"
	 "\treturn (1);\n"
	 "}\n"
	 "\n"
	 "static void\tputnbr(int n)\n"
	 "{\n"
	 "\tchar c;\n"
	 "\n"
	 "\tif (n > 9)\n"
	 "\t\tputnbr(n / 10);\n"
	 "\tc = (n % 10) + '0';\n"
	 "\twrite(1, &c, 1);\n"
	 "}\n"
	 "\n"
	 "int\tmain(int argc, char **argv)\n"
	 "{\n"
	 "\tint n;\n"
	 "\tint sum;\n"
	 "\n"
	 "\tsum = 0;\n"
	 "\tif (argc == 2)\n"
	 "\t{\n"
	 "\t\tn = atoi(argv[1]);\n"
	 "\t\twhile (n > 1)\n"
	 "\t\t{\n"
	 "\t\t\tif (is_prime(n))\n"
	 "\t\t\t\tsum += n;\n"
	 "\t\t\tn--;\n"
	 "\t\t}\n"
	 "\t}\n"
	 "\tputnbr(sum);\n"
	 "\twrite(1, \"\\n\", 1);\n"
	 "\treturn (0);\n"
	 "}\n",
	 "Expected file: add_prime_sum.c",
	 "level3, math"},
	{"epur_str",
	 "epur_str",
	 "Write a program that removes extra spaces and tabs from a string.",
	 "#include <unistd.h>\n"
	 "\n"
	 "int\tmain(int argc, char **argv)\n"
	 "{\n"
	 "\tint i;\n"
	 "\tint in_word;\n"
	 "\n"
	 "\tif (argc == 2)\n"
	 "\t{\n"
	 "\t\ti = 0;\n"
	 "\t\tin_word = 0;\n"
	 "\t\twhile (argv[1][i])\n"
	 "\t\t{\n"
	 "\t\t\tif (argv[1][i] != ' ' && argv[1][i] != '\\t')\n"
	 "\t\t\t{\n"
	 "\t\t\t\tif (in_word)\n"
	 "\t\t\t\t\twrite(1, \" \", 1);\n"
	 "\t\t\t\twhile (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\\t')\n"
	 "\t\t\t\t\twrite(1, &argv[1][i++], 1);\n"
	 "\t\t\t\tin_word = 1;\n"
	 "\t\t\t}\n"
	 "\t\t\telse\n"
	 "\t\t\t\ti++;\n"
	 "\t\t}\n"
	 "\t}\n"
	 "\twrite(1, \"\\n\", 1);\n"
	 "\treturn (0);\n"
	 "}\n",
	 "Expected file: epur_str.c",
	 "level3, string parsing"},
	{"expand_str",
	 "expand_str",
	 "Write a program that replaces spaces/tabs between words by exactly three spaces.",
	 "#include <unistd.h>\n"
	 "\n"
	 "int\tmain(int argc, char **argv)\n"
	 "{\n"
	 "\tint i;\n"
	 "\tint first;\n"
	 "\n"
	 "\tif (argc == 2)\n"
	 "\t{\n"
	 "\t\ti = 0;\n"
	 "\t\tfirst = 1;\n"
	 "\t\twhile (argv[1][i])\n"
	 "\t\t{\n"
	 "\t\t\twhile (argv[1][i] == ' ' || argv[1][i] == '\\t')\n"
	 "\t\t\t\ti++;\n"
	 "\t\t\tif (argv[1][i])\n"
	 "\t\t\t{\n"
	 "\t\t\t\tif (!first)\n"
	 "\t\t\t\t\twrite(1, \"   \", 3);\n"
	 "\t\t\t\twhile (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\\t')\n"
	 "\t\t\t\t\twrite(1, &argv[1][i++], 1);\n"
	 "\t\t\t\tfirst = 0;\n"
	 "\t\t\t}\n"
	 "\t\t}\n"
	 "\t}\n"
	 "\twrite(1, \"\\n\", 1);\n"
	 "\treturn (0);\n"
	 "}\n",
	 "Expected file: expand_str.c",
	 "level3, string parsing"},
	{"ft_atoi_base",
	 "ft_atoi_base",
	 "Write a function that converts a number string in an arbitrary base to int.",
	 "int\tft_atoi_base(const char *str, int str_base)\n"
	 "{\n"
	 "\tint res;\n"
	 "\tint sign;\n"
	 "\tint val;\n"
	 "\n"
	 "\tres = 0;\n"
	 "\tsign = 1;\n"
	 "\tif (!str || str_base < 2 || str_base > 16)\n"
	 "\t\treturn (0);\n"
	 "\twhile (*str == ' ' || (*str >= '\\t' && *str <= '\\r'))\n"
	 "\t\tstr++;\n"
	 "\tif (*str == '-' || *str == '+')\n"
	 "\t\tsign = (*str++ == '-') ? -1 : 1;\n"
	 "\twhile (*str)\n"
	 "\t{\n"
	 "\t\tif (*str >= '0' && *str <= '9')\n"
	 "\t\t\tval = *str - '0';\n"
	 "\t\telse if (*str >= 'a' && *str <= 'f')\n"
	 "\t\t\tval = *str - 'a' + 10;\n"
	 "\t\telse if (*str >= 'A' && *str <= 'F')\n"
	 "\t\t\tval = *str - 'A' + 10;\n"
	 "\t\telse\n"
	 "\t\t\tbreak ;\n"
	 "\t\tif (val >= str_base)\n"
	 "\t\t\tbreak ;\n"
	 "\t\tres = res * str_base + val;\n"
	 "\t\tstr++;\n"
	 "\t}\n"
	 "\treturn (res * sign);\n"
	 "}\n",
	 "Expected file: ft_atoi_base.c",
	 "level3, function"},
	{"ft_list_foreach",
	 "ft_list_foreach",
	 "Write a function that applies a function to each list element.",
	 "void\tft_list_foreach(t_list *begin_list, void (*f)(void *))\n"
	 "{\n"
	 "\twhile (begin_list)\n"
	 "\t{\n"
	 "\t\tf(begin_list->content);\n"
	 "\t\tbegin_list = begin_list->next;\n"
	 "\t}\n"
	 "}\n",
	 "Expected file: ft_list_foreach.c",
	 "level3, list"},
	{"ft_list_size",
	 "ft_list_size",
	 "Write a function that returns the number of elements in a linked list.",
	 "int\tft_list_size(t_list *begin_list)\n"
	 "{\n"
	 "\tint size;\n"
	 "\n"
	 "\tsize = 0;\n"
	 "\twhile (begin_list)\n"
	 "\t{\n"
	 "\t\tsize++;\n"
	 "\t\tbegin_list = begin_list->next;\n"
	 "\t}\n"
	 "\treturn (size);\n"
	 "}\n",
	 "Expected file: ft_list_size.c",
	 "level3, list"},
	{"ft_range",
	 "ft_range",
	 "Write a function that returns an array with values from start to end.",
	 "#include <stdlib.h>\n"
	 "\n"
	 "int\t*ft_range(int start, int end)\n"
	 "{\n"
	 "\tint *arr;\n"
	 "\tint len;\n"
	 "\tint i;\n"
	 "\n"
	 "\tlen = (start <= end) ? (end - start + 1) : (start - end + 1);\n"
	 "\tarr = (int *)malloc(sizeof(int) * len);\n"
	 "\tif (!arr)\n"
	 "\t\treturn (NULL);\n"
	 "\ti = 0;\n"
	 "\twhile (i < len)\n"
	 "\t{\n"
	 "\t\tarr[i] = start;\n"
	 "\t\tstart += (start <= end) ? 1 : -1;\n"
	 "\t\ti++;\n"
	 "\t}\n"
	 "\treturn (arr);\n"
	 "}\n",
	 "Expected file: ft_range.c",
	 "level3, function"},
	{"ft_rrange",
	 "ft_rrange",
	 "Write a function that returns an array with values from end to start.",
	 "#include <stdlib.h>\n"
	 "\n"
	 "int\t*ft_rrange(int start, int end)\n"
	 "{\n"
	 "\tint *arr;\n"
	 "\tint len;\n"
	 "\tint i;\n"
	 "\n"
	 "\tlen = (start <= end) ? (end - start + 1) : (start - end + 1);\n"
	 "\tarr = (int *)malloc(sizeof(int) * len);\n"
	 "\tif (!arr)\n"
	 "\t\treturn (NULL);\n"
	 "\ti = 0;\n"
	 "\twhile (i < len)\n"
	 "\t{\n"
	 "\t\tarr[i] = end;\n"
	 "\t\tend += (start <= end) ? -1 : 1;\n"
	 "\t\ti++;\n"
	 "\t}\n"
	 "\treturn (arr);\n"
	 "}\n",
	 "Expected file: ft_rrange.c",
	 "level3, function"},
	{"hidenp",
	 "hidenp",
	 "Write a program that checks whether s1 is hidden in s2.",
	 "#include <unistd.h>\n"
	 "\n"
	 "int\tmain(int argc, char **argv)\n"
	 "{\n"
	 "\tint i;\n"
	 "\tint j;\n"
	 "\n"
	 "\ti = 0;\n"
	 "\tj = 0;\n"
	 "\tif (argc == 3)\n"
	 "\t{\n"
	 "\t\twhile (argv[1][i] && argv[2][j])\n"
	 "\t\t{\n"
	 "\t\t\tif (argv[1][i] == argv[2][j])\n"
	 "\t\t\t\ti++;\n"
	 "\t\t\tj++;\n"
	 "\t\t}\n"
	 "\t\tif (!argv[1][i])\n"
	 "\t\t\twrite(1, \"1\", 1);\n"
	 "\t\telse\n"
	 "\t\t\twrite(1, \"0\", 1);\n"
	 "\t}\n"
	 "\telse\n"
	 "\t\twrite(1, \"0\", 1);\n"
	 "\twrite(1, \"\\n\", 1);\n"
	 "\treturn (0);\n"
	 "}\n",
	 "Expected file: hidenp.c",
	 "level3, string parsing"},
	{"lcm",
	 "lcm",
	 "Write a function that returns the least common multiple of two unsigned ints.",
	 "unsigned int\tlcm(unsigned int a, unsigned int b)\n"
	 "{\n"
	 "\tunsigned int n;\n"
	 "\n"
	 "\tif (a == 0 || b == 0)\n"
	 "\t\treturn (0);\n"
	 "\tn = (a > b) ? a : b;\n"
	 "\twhile (1)\n"
	 "\t{\n"
	 "\t\tif (n % a == 0 && n % b == 0)\n"
	 "\t\t\treturn (n);\n"
	 "\t\tn++;\n"
	 "\t}\n"
	 "}\n",
	 "Expected file: lcm.c",
	 "level3, math"},
	{"paramsum",
	 "paramsum",
	 "Write a program that displays the number of command line arguments.",
	 "#include <unistd.h>\n"
	 "\n"
	 "static void\tputnbr(int n)\n"
	 "{\n"
	 "\tchar c;\n"
	 "\n"
	 "\tif (n > 9)\n"
	 "\t\tputnbr(n / 10);\n"
	 "\tc = (n % 10) + '0';\n"
	 "\twrite(1, &c, 1);\n"
	 "}\n"
	 "\n"
	 "int\tmain(int argc, char **argv)\n"
	 "{\n"
	 "\t(void)argv;\n"
	 "\tputnbr(argc - 1);\n"
	 "\twrite(1, \"\\n\", 1);\n"
	 "\treturn (0);\n"
	 "}\n",
	 "Expected file: paramsum.c",
	 "level3, parsing"},
	{"pgcd",
	 "pgcd",
	 "Write a program that prints the greatest common divisor of two positive ints.",
	 "#include <stdlib.h>\n"
	 "#include <stdio.h>\n"
	 "\n"
	 "int\tmain(int argc, char **argv)\n"
	 "{\n"
	 "\tint a;\n"
	 "\tint b;\n"
	 "\tint t;\n"
	 "\n"
	 "\tif (argc == 3)\n"
	 "\t{\n"
	 "\t\ta = atoi(argv[1]);\n"
	 "\t\tb = atoi(argv[2]);\n"
	 "\t\twhile (b)\n"
	 "\t\t{\n"
	 "\t\t\tt = b;\n"
	 "\t\t\tb = a % b;\n"
	 "\t\t\ta = t;\n"
	 "\t\t}\n"
	 "\t\tprintf(\"%d\", a);\n"
	 "\t}\n"
	 "\tprintf(\"\\n\");\n"
	 "\treturn (0);\n"
	 "}\n",
	 "Expected file: pgcd.c",
	 "level3, math"},
	{"print_hex",
	 "print_hex",
	 "Write a program that displays an int in hexadecimal.",
	 "#include <unistd.h>\n"
	 "#include <stdlib.h>\n"
	 "\n"
	 "static void\tputhex(unsigned int n)\n"
	 "{\n"
	 "\tchar *base;\n"
	 "\n"
	 "\tbase = \"0123456789abcdef\";\n"
	 "\tif (n >= 16)\n"
	 "\t\tputhex(n / 16);\n"
	 "\twrite(1, &base[n % 16], 1);\n"
	 "}\n"
	 "\n"
	 "int\tmain(int argc, char **argv)\n"
	 "{\n"
	 "\tif (argc == 2)\n"
	 "\t\tputhex((unsigned int)atoi(argv[1]));\n"
	 "\twrite(1, \"\\n\", 1);\n"
	 "\treturn (0);\n"
	 "}\n",
	 "Expected file: print_hex.c",
	 "level3, parsing"},
	{"rstr_capitalizer",
	 "rstr_capitalizer",
	 "Write a program that lowercases all words and uppercases only last letter of each word.",
	 "#include <unistd.h>\n"
	 "\n"
	 "int\tmain(int argc, char **argv)\n"
	 "{\n"
	 "\tint i;\n"
	 "\tchar c;\n"
	 "\n"
	 "\tif (argc > 1)\n"
	 "\t{\n"
	 "\t\tint a = 1;\n"
	 "\t\twhile (a < argc)\n"
	 "\t\t{\n"
	 "\t\t\ti = 0;\n"
	 "\t\t\twhile (argv[a][i])\n"
	 "\t\t\t{\n"
	 "\t\t\t\tc = argv[a][i];\n"
	 "\t\t\t\tif (c >= 'A' && c <= 'Z')\n"
	 "\t\t\t\t\tc += 32;\n"
	 "\t\t\t\tif ((argv[a][i + 1] == ' ' || argv[a][i + 1] == '\\t' || argv[a][i + 1] == '\\0')\n"
	 "\t\t\t\t\t&& (c >= 'a' && c <= 'z'))\n"
	 "\t\t\t\t\tc -= 32;\n"
	 "\t\t\t\twrite(1, &c, 1);\n"
	 "\t\t\t\ti++;\n"
	 "\t\t\t}\n"
	 "\t\t\twrite(1, \"\\n\", 1);\n"
	 "\t\t\ta++;\n"
	 "\t\t}\n"
	 "\t}\n"
	 "\telse\n"
	 "\t\twrite(1, \"\\n\", 1);\n"
	 "\treturn (0);\n"
	 "}\n",
	 "Expected file: rstr_capitalizer.c",
	 "level3, string transform"},
	{"str_capitalizer",
	 "str_capitalizer",
	 "Write a program that capitalizes the first letter of each word and lowercases the rest.",
	 "#include <unistd.h>\n"
	 "\n"
	 "int\tmain(int argc, char **argv)\n"
	 "{\n"
	 "\tint i;\n"
	 "\tchar c;\n"
	 "\n"
	 "\tif (argc > 1)\n"
	 "\t{\n"
	 "\t\tint a = 1;\n"
	 "\t\twhile (a < argc)\n"
	 "\t\t{\n"
	 "\t\t\ti = 0;\n"
	 "\t\t\twhile (argv[a][i])\n"
	 "\t\t\t{\n"
	 "\t\t\t\tc = argv[a][i];\n"
	 "\t\t\t\tif (c >= 'A' && c <= 'Z')\n"
	 "\t\t\t\t\tc += 32;\n"
	 "\t\t\t\tif ((i == 0 || argv[a][i - 1] == ' ' || argv[a][i - 1] == '\\t')\n"
	 "\t\t\t\t\t&& (c >= 'a' && c <= 'z'))\n"
	 "\t\t\t\t\tc -= 32;\n"
	 "\t\t\t\twrite(1, &c, 1);\n"
	 "\t\t\t\ti++;\n"
	 "\t\t\t}\n"
	 "\t\t\twrite(1, \"\\n\", 1);\n"
	 "\t\t\ta++;\n"
	 "\t\t}\n"
	 "\t}\n"
	 "\telse\n"
	 "\t\twrite(1, \"\\n\", 1);\n"
	 "\treturn (0);\n"
	 "}\n",
	 "Expected file: str_capitalizer.c",
	 "level3, string transform"},
	{"tab_mult",
	 "tab_mult",
	 "Write a program that displays the multiplication table of a given number.",
	 "#include <unistd.h>\n"
	 "#include <stdlib.h>\n"
	 "\n"
	 "static void\tputnbr(int n)\n"
	 "{\n"
	 "\tchar c;\n"
	 "\n"
	 "\tif (n > 9)\n"
	 "\t\tputnbr(n / 10);\n"
	 "\tc = (n % 10) + '0';\n"
	 "\twrite(1, &c, 1);\n"
	 "}\n"
	 "\n"
	 "int\tmain(int argc, char **argv)\n"
	 "{\n"
	 "\tint n;\n"
	 "\tint i;\n"
	 "\n"
	 "\tif (argc == 2)\n"
	 "\t{\n"
	 "\t\tn = atoi(argv[1]);\n"
	 "\t\ti = 1;\n"
	 "\t\twhile (i <= 9)\n"
	 "\t\t{\n"
	 "\t\t\tputnbr(i);\n"
	 "\t\t\twrite(1, \" x \", 3);\n"
	 "\t\t\tputnbr(n);\n"
	 "\t\t\twrite(1, \" = \", 3);\n"
	 "\t\t\tputnbr(i * n);\n"
	 "\t\t\twrite(1, \"\\n\", 1);\n"
	 "\t\t\ti++;\n"
	 "\t\t}\n"
	 "\t}\n"
	 "\telse\n"
	 "\t\twrite(1, \"\\n\", 1);\n"
	 "\treturn (0);\n"
	 "}\n",
	 "Expected file: tab_mult.c",
	 "level3, loops"},
	{"rev_wstr",
	 "rev_wstr",
	 "Write a program that prints words in reverse order.",
	 "#include <unistd.h>\n"
	 "\n"
	 "int\tmain(int argc, char **argv)\n"
	 "{\n"
	 "\tint end;\n"
	 "\tint start;\n"
	 "\tint first;\n"
	 "\n"
	 "\tif (argc == 2)\n"
	 "\t{\n"
	 "\t\tfirst = 1;\n"
	 "\t\tend = 0;\n"
	 "\t\twhile (argv[1][end])\n"
	 "\t\t\tend++;\n"
	 "\t\twhile (end > 0)\n"
	 "\t\t{\n"
	 "\t\t\twhile (end > 0 && (argv[1][end - 1] == ' ' || argv[1][end - 1] == '\\t'))\n"
	 "\t\t\t\tend--;\n"
	 "\t\t\tstart = end;\n"
	 "\t\t\twhile (start > 0 && argv[1][start - 1] != ' ' && argv[1][start - 1] != '\\t')\n"
	 "\t\t\t\tstart--;\n"
	 "\t\t\tif (start < end)\n"
	 "\t\t\t{\n"
	 "\t\t\t\tif (!first)\n"
	 "\t\t\t\t\twrite(1, \" \", 1);\n"
	 "\t\t\t\twrite(1, &argv[1][start], end - start);\n"
	 "\t\t\t\tfirst = 0;\n"
	 "\t\t\t}\n"
	 "\t\t\tend = start;\n"
	 "\t\t}\n"
	 "\t}\n"
	 "\twrite(1, \"\\n\", 1);\n"
	 "\treturn (0);\n"
	 "}\n",
	 "Expected file: rev_wstr.c",
	 "level3, string parsing"},
	{"rostring",
	 "rostring",
	 "Write a program that moves the first word of a string to the end.",
	 "#include <unistd.h>\n"
	 "\n"
	 "int\tmain(int argc, char **argv)\n"
	 "{\n"
	 "\tint i;\n"
	 "\tint start;\n"
	 "\tint end;\n"
	 "\tint wrote;\n"
	 "\n"
	 "\tif (argc == 2)\n"
	 "\t{\n"
	 "\t\ti = 0;\n"
	 "\t\twhile (argv[1][i] == ' ' || argv[1][i] == '\\t')\n"
	 "\t\t\ti++;\n"
	 "\t\tstart = i;\n"
	 "\t\twhile (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\\t')\n"
	 "\t\t\ti++;\n"
	 "\t\tend = i;\n"
	 "\t\twrote = 0;\n"
	 "\t\twhile (argv[1][i])\n"
	 "\t\t{\n"
	 "\t\t\twhile (argv[1][i] == ' ' || argv[1][i] == '\\t')\n"
	 "\t\t\t\ti++;\n"
	 "\t\t\twhile (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\\t')\n"
	 "\t\t\t{\n"
	 "\t\t\t\tif (!wrote)\n"
	 "\t\t\t\t\twrote = 1;\n"
	 "\t\t\t\twrite(1, &argv[1][i++], 1);\n"
	 "\t\t\t}\n"
	 "\t\t\tif (argv[1][i] && wrote)\n"
	 "\t\t\t\twrite(1, \" \", 1);\n"
	 "\t\t}\n"
	 "\t\tif (end > start)\n"
	 "\t\t{\n"
	 "\t\t\tif (wrote)\n"
	 "\t\t\t\twrite(1, \" \", 1);\n"
	 "\t\t\twrite(1, &argv[1][start], end - start);\n"
	 "\t\t}\n"
	 "\t}\n"
	 "\twrite(1, \"\\n\", 1);\n"
	 "\treturn (0);\n"
	 "}\n",
	 "Expected file: rostring.c",
	 "level3, string parsing"}};

static const Exam02Question g_exam02_level4_questions[] = {
	{"brainfuck",
	 "brainfuck",
	 "Write a program that prints \"Hello World!\" using brainfuck code output.",
	 "#include <unistd.h>\n"
	 "\n"
	 "int\tmain(void)\n"
	 "{\n"
	 "\twrite(1, \"[>++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..\"\n"
	 "\t\t\"+++.>>.<-.<.+++.------.--------.>>+.>++.]\", 106);\n"
	 "\treturn (0);\n"
	 "}\n",
	 "Expected file: brainfuck.c",
	 "level4, parsing"},
	{"fprime",
	 "fprime",
	 "Write a program that prints the prime factors of a positive integer.",
	 "#include <stdlib.h>\n"
	 "#include <stdio.h>\n"
	 "\n"
	 "int\tmain(int argc, char **argv)\n"
	 "{\n"
	 "\tint n;\n"
	 "\tint p;\n"
	 "\n"
	 "\tif (argc == 2)\n"
	 "\t{\n"
	 "\t\tn = atoi(argv[1]);\n"
	 "\t\tp = 2;\n"
	 "\t\twhile (n > 1)\n"
	 "\t\t{\n"
	 "\t\t\tif (n % p == 0)\n"
	 "\t\t\t{\n"
	 "\t\t\t\tprintf(\"%d\", p);\n"
	 "\t\t\t\tn /= p;\n"
	 "\t\t\t\tif (n > 1)\n"
	 "\t\t\t\t\tprintf(\"*\");\n"
	 "\t\t\t}\n"
	 "\t\t\telse\n"
	 "\t\t\t\tp++;\n"
	 "\t\t}\n"
	 "\t}\n"
	 "\tprintf(\"\\n\");\n"
	 "\treturn (0);\n"
	 "}\n",
	 "Expected file: fprime.c",
	 "level4, math"},
	{"ft_itoa",
	 "ft_itoa",
	 "Write a function that converts an int to a newly allocated string.",
	 "#include <stdlib.h>\n"
	 "\n"
	 "static int\tcount_len(long n)\n"
	 "{\n"
	 "\tint len;\n"
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
	 "char\t*ft_itoa(int nbr)\n"
	 "{\n"
	 "\tlong n;\n"
	 "\tint len;\n"
	 "\tchar *s;\n"
	 "\n"
	 "\tn = nbr;\n"
	 "\tlen = count_len(n);\n"
	 "\ts = (char *)malloc(len + 1);\n"
	 "\tif (!s)\n"
	 "\t\treturn (NULL);\n"
	 "\ts[len] = '\\0';\n"
	 "\tif (n < 0)\n"
	 "\t{\n"
	 "\t\ts[0] = '-';\n"
	 "\t\tn = -n;\n"
	 "\t}\n"
	 "\tif (n == 0)\n"
	 "\t\ts[0] = '0';\n"
	 "\twhile (n)\n"
	 "\t{\n"
	 "\t\ts[--len] = (n % 10) + '0';\n"
	 "\t\tn /= 10;\n"
	 "\t}\n"
	 "\treturn (s);\n"
	 "}\n",
	 "Expected file: ft_itoa.c",
	 "level4, function"},
	{"ft_split",
	 "ft_split",
	 "Write a function that splits a string into words separated by spaces, tabs, or newlines.",
	 "#include <stdlib.h>\n"
	 "\n"
	 "static int\tis_sep(char c)\n"
	 "{\n"
	 "\treturn (c == ' ' || c == '\\t' || c == '\\n');\n"
	 "}\n"
	 "\n"
	 "static int\tword_count(char *s)\n"
	 "{\n"
	 "\tint i;\n"
	 "\tint count;\n"
	 "\n"
	 "\ti = 0;\n"
	 "\tcount = 0;\n"
	 "\twhile (s[i])\n"
	 "\t{\n"
	 "\t\twhile (s[i] && is_sep(s[i]))\n"
	 "\t\t\ti++;\n"
	 "\t\tif (s[i])\n"
	 "\t\t{\n"
	 "\t\t\tcount++;\n"
	 "\t\t\twhile (s[i] && !is_sep(s[i]))\n"
	 "\t\t\t\ti++;\n"
	 "\t\t}\n"
	 "\t}\n"
	 "\treturn (count);\n"
	 "}\n"
	 "\n"
	 "char\t**ft_split(char *str)\n"
	 "{\n"
	 "\tchar\t**tab;\n"
	 "\tint\t\tw;\n"
	 "\tint\t\ti;\n"
	 "\tint\t\tstart;\n"
	 "\n"
	 "\ttab = (char **)malloc(sizeof(char *) * (word_count(str) + 1));\n"
	 "\tif (!tab)\n"
	 "\t\treturn (NULL);\n"
	 "\ti = 0;\n"
	 "\tw = 0;\n"
	 "\twhile (str[i])\n"
	 "\t{\n"
	 "\t\twhile (str[i] && is_sep(str[i]))\n"
	 "\t\t\ti++;\n"
	 "\t\tstart = i;\n"
	 "\t\twhile (str[i] && !is_sep(str[i]))\n"
	 "\t\t\ti++;\n"
	 "\t\tif (i > start)\n"
	 "\t\t{\n"
	 "\t\t\ttab[w] = (char *)malloc(i - start + 1);\n"
	 "\t\t\tif (!tab[w])\n"
	 "\t\t\t\treturn (NULL);\n"
	 "\t\t\tfor (int j = 0; start + j < i; j++)\n"
	 "\t\t\t\ttab[w][j] = str[start + j];\n"
	 "\t\t\ttab[w][i - start] = '\\0';\n"
	 "\t\t\tw++;\n"
	 "\t\t}\n"
	 "\t}\n"
	 "\ttab[w] = NULL;\n"
	 "\treturn (tab);\n"
	 "}\n",
	 "Expected file: ft_split.c",
	 "level4, function"},
	{"ft_list_remove_if",
	 "ft_list_remove_if",
	 "Write a function that removes all elements matching data_ref from a linked list.",
	 "#include <stdlib.h>\n"
	 "\n"
	 "void\tft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())\n"
	 "{\n"
	 "\tt_list *cur;\n"
	 "\tt_list *tmp;\n"
	 "\n"
	 "\twhile (*begin_list && cmp((*begin_list)->data, data_ref) == 0)\n"
	 "\t{\n"
	 "\t\ttmp = *begin_list;\n"
	 "\t\t*begin_list = (*begin_list)->next;\n"
	 "\t\tfree(tmp);\n"
	 "\t}\n"
	 "\tcur = *begin_list;\n"
	 "\twhile (cur && cur->next)\n"
	 "\t{\n"
	 "\t\tif (cmp(cur->next->data, data_ref) == 0)\n"
	 "\t\t{\n"
	 "\t\t\ttmp = cur->next;\n"
	 "\t\t\tcur->next = cur->next->next;\n"
	 "\t\t\tfree(tmp);\n"
	 "\t\t}\n"
	 "\t\telse\n"
	 "\t\t\tcur = cur->next;\n"
	 "\t}\n"
	 "}\n",
	 "Expected file: ft_list_remove_if.c",
	 "level4, list"},
	{"sort_int_tab",
	 "sort_int_tab",
	 "Write a function that sorts an int array in ascending order.",
	 "void\tsort_int_tab(int *tab, unsigned int size)\n"
	 "{\n"
	 "\tunsigned int i;\n"
	 "\tunsigned int j;\n"
	 "\tint tmp;\n"
	 "\n"
	 "\ti = 0;\n"
	 "\twhile (i < size)\n"
	 "\t{\n"
	 "\t\tj = i + 1;\n"
	 "\t\twhile (j < size)\n"
	 "\t\t{\n"
	 "\t\t\tif (tab[j] < tab[i])\n"
	 "\t\t\t{\n"
	 "\t\t\t\ttmp = tab[i];\n"
	 "\t\t\t\ttab[i] = tab[j];\n"
	 "\t\t\t\ttab[j] = tmp;\n"
	 "\t\t\t}\n"
	 "\t\t\tj++;\n"
	 "\t\t}\n"
	 "\t\ti++;\n"
	 "\t}\n"
	 "}\n",
	 "Expected file: sort_int_tab.c",
	 "level4, function"},
	{"sort_list",
	 "sort_list",
	 "Write a function that sorts a linked list using the provided cmp function.",
	 "t_list\t*sort_list(t_list *lst, int (*cmp)(int, int))\n"
	 "{\n"
	 "\tint swapped;\n"
	 "\tint tmp;\n"
	 "\tt_list *cur;\n"
	 "\n"
	 "\tif (!lst)\n"
	 "\t\treturn (NULL);\n"
	 "\tswapped = 1;\n"
	 "\twhile (swapped)\n"
	 "\t{\n"
	 "\t\tswapped = 0;\n"
	 "\t\tcur = lst;\n"
	 "\t\twhile (cur->next)\n"
	 "\t\t{\n"
	 "\t\t\tif (cmp(cur->content, cur->next->content) > 0)\n"
	 "\t\t\t{\n"
	 "\t\t\t\ttmp = (long)cur->content;\n"
	 "\t\t\t\tcur->content = cur->next->content;\n"
	 "\t\t\t\tcur->next->content = (void *)(long)tmp;\n"
	 "\t\t\t\tswapped = 1;\n"
	 "\t\t\t}\n"
	 "\t\t\tcur = cur->next;\n"
	 "\t\t}\n"
	 "\t}\n"
	 "\treturn (lst);\n"
	 "}\n",
	 "Expected file: sort_list.c",
	 "level4, list"},
	{"flood_fill",
	 "flood_fill",
	 "Write a flood fill function that replaces contiguous target area from a start point.",
	 "void\tflood_fill(char **tab, t_point size, t_point begin)\n"
	 "{\n"
	 "\tchar target;\n"
	 "\n"
	 "\ttarget = tab[begin.y][begin.x];\n"
	 "\tif (target == 'F')\n"
	 "\t\treturn ;\n"
	 "\tif (begin.x >= size.x || begin.y >= size.y)\n"
	 "\t\treturn ;\n"
	 "\tif (tab[begin.y][begin.x] != target)\n"
	 "\t\treturn ;\n"
	 "\ttab[begin.y][begin.x] = 'F';\n"
	 "\tif (begin.x > 0)\n"
	 "\t\tflood_fill(tab, size, (t_point){begin.x - 1, begin.y});\n"
	 "\tif (begin.x + 1 < size.x)\n"
	 "\t\tflood_fill(tab, size, (t_point){begin.x + 1, begin.y});\n"
	 "\tif (begin.y > 0)\n"
	 "\t\tflood_fill(tab, size, (t_point){begin.x, begin.y - 1});\n"
	 "\tif (begin.y + 1 < size.y)\n"
	 "\t\tflood_fill(tab, size, (t_point){begin.x, begin.y + 1});\n"
	 "}\n",
	 "Expected file: flood_fill.c",
	 "level4, recursion"}};

static LibFunc question_to_libfunc(const Exam02Question *question)
{
	LibFunc func;

	func.name = question->title;
	func.description = question->description;
	func.return_value = question->expected_files;
	func.variants = NULL;
	func.variant_count = 0;
	func.code = question->canonical_solution;
	(void)question->id;
	(void)question->tags;
	return (func);
}

int exam02_level_count(void)
{
	return (4);
}

int exam02_question_count(int level)
{
	if (level == 1)
		return (sizeof(g_exam02_level1_questions) / sizeof(g_exam02_level1_questions[0]));
	if (level == 2)
		return (sizeof(g_exam02_level2_questions) / sizeof(g_exam02_level2_questions[0]));
	if (level == 3)
		return (sizeof(g_exam02_level3_questions) / sizeof(g_exam02_level3_questions[0]));
	if (level == 4)
		return (sizeof(g_exam02_level4_questions) / sizeof(g_exam02_level4_questions[0]));
	return (0);
}

LibFunc exam02_get_question(int level, int index)
{
	if (index < 0 || index >= exam02_question_count(level))
	{
		fprintf(stderr, "Invalid Exam Rank 02 question index.\n");
		exit(1);
	}
	if (level == 1)
		return (question_to_libfunc(&g_exam02_level1_questions[index]));
	if (level == 2)
		return (question_to_libfunc(&g_exam02_level2_questions[index]));
	if (level == 3)
		return (question_to_libfunc(&g_exam02_level3_questions[index]));
	if (level == 4)
		return (question_to_libfunc(&g_exam02_level4_questions[index]));
	fprintf(stderr, "Invalid Exam Rank 02 level.\n");
	exit(1);
}
