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
	 "\twrite(1, \\\"\\n\\\", 1);\n"
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
	 "\t\t\twrite(1, \\\"fizzbuzz\\\", 8);\n"
	 "\t\telse if (i % 3 == 0)\n"
	 "\t\t\twrite(1, \\\"fizz\\\", 4);\n"
	 "\t\telse if (i % 5 == 0)\n"
	 "\t\t\twrite(1, \\\"buzz\\\", 4);\n"
	 "\t\telse\n"
	 "\t\t\tputnbr(i);\n"
	 "\t\twrite(1, \\\"\\n\\\", 1);\n"
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
	 "\twrite(1, \\\"\\n\\\", 1);\n"
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
	 "\twrite(1, \\\"\\n\\\", 1);\n"
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
	 "\twrite(1, \\\"\\n\\\", 1);\n"
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
	 "\twrite(1, \\\"\\n\\\", 1);\n"
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
	 "\twrite(1, \\\"\\n\\\", 1);\n"
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
	 "\twrite(1, \\\"\\n\\\", 1);\n"
	 "\treturn (0);\n"
	 "}\n",
	 "Expected file: ulstr.c",
	 "level1, string transform"}};

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
	return (1);
}

int exam02_question_count(int level)
{
	if (level != 1)
		return (0);
	return (sizeof(g_exam02_level1_questions) / sizeof(g_exam02_level1_questions[0]));
}

LibFunc exam02_get_question(int level, int index)
{
	if (level != 1)
	{
		fprintf(stderr, "Invalid Exam Rank 02 level.\n");
		exit(1);
	}
	if (index < 0 || index >= exam02_question_count(level))
	{
		fprintf(stderr, "Invalid Exam Rank 02 question index.\n");
		exit(1);
	}
	return (question_to_libfunc(&g_exam02_level1_questions[index]));
}
