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
	return (2);
}

int exam02_question_count(int level)
{
	if (level == 1)
		return (sizeof(g_exam02_level1_questions) / sizeof(g_exam02_level1_questions[0]));
	if (level == 2)
		return (sizeof(g_exam02_level2_questions) / sizeof(g_exam02_level2_questions[0]));
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
	fprintf(stderr, "Invalid Exam Rank 02 level.\n");
	exit(1);
}
