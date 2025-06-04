LibFunc io_functions[] = {
	{
		"ft_putchar_fd",
		"Writes character c to file descriptor fd.",
		"void\tft_putchar_fd(char c, int fd)\n"
			"{\n"
			"\twrite(fd, &c, 1);\n"
			"}"
	},
	{
		"ft_putstr_fd",
		"Writes string s to file descriptor fd.",
		"void\tft_putstr_fd(char *s, int fd)\n"
			"{\n"
			"\tif (s)\n"
			"\t\twrite(fd, s, ft_strlen(s));\n"
			"}"
	},
	{
		"ft_putendl_fd",
		"Writes string s followed by a newline to file descriptor fd.",
		"void\tft_putendl_fd(char *s, int fd)\n"
			"{\n"
			"\tif (s)\n"
			"\t{\n"
			"\t\tft_putstr_fd(s, fd);\n"
			"\t\twrite(fd, \"\\n\", 1);\n"
			"\t}\n"
			"}"
	},
	{
		"ft_putnbr_fd",
		"Writes integer n to file descriptor fd.",
		"void\tft_putnbr_fd(int n, int fd)\n"
			"{\n"
			"\tchar\tc;\n"
			"\tif (n == -2147483648)\n"
			"\t\treturn (ft_putstr_fd(\"-2147483648\", fd));\n"
			"\tif (n < 0)\n"
			"\t{\n"
			"\t\tft_putchar_fd('-', fd);\n"
			"\t\tn = -n;\n"
			"\t}\n"
			"\tif (n >= 10)\n"
			"\t\tft_putnbr_fd(n / 10, fd);\n"
			"\tc = (n % 10) + '0';\n"
			"\tft_putchar_fd(c, fd);\n"
			"}"
	}
};
int get_io_function_count(void)
{
	return sizeof(io_functions) / sizeof(LibFunc);
}

LibFunc get_io_function_by_index(int index)
{
	if (index < 0 || index >= get_io_function_count())
	{
		fprintf(stderr, "Invalid IO function index.\n");
		exit(1);
	}
	return io_functions[index];
}
