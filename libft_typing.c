#include <ncurses.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define MAX_INPUT 2048

typedef struct {
	const char* name;
	const char* description;
	const char* code;
} LibftFunc;

const LibftFunc libft_funcs[] = {
	{
		"ft_strlen",
		"Returns the length of the string `s`, not including the null terminator.",
		"size_t ft_strlen(const char *s) {\n"
			"    size_t i = 0;\n"
			"    while (s[i])\n"
			"        i++;\n"
			"    return i;\n"
			"}"
	}
};

const int FUNC_COUNT = sizeof(libft_funcs) / sizeof(libft_funcs[0]);

// Function to get multiline user input until double Enter (empty line)
void get_multiline_input(char *buffer, int max_size) {
	int ch, pos = 0;
	int y, x;
	int empty_line_count = 0;
	char line[256];
	int line_pos = 0;

	getyx(stdscr, y, x); // current cursor position
	memset(buffer, 0, max_size);

	while (1) {
		ch = getch();
		if (ch == '\n') {
			line[line_pos] = '\0';
			if (line_pos == 0) {
				empty_line_count++;
				if (empty_line_count == 1) break; // finish on first empty line
			} else {
				empty_line_count = 0;
				// Append line + newline to buffer
				int len = strlen(buffer);
				if (len + line_pos + 2 < max_size) {
					strcat(buffer, line);
					strcat(buffer, "\n");
				}
			}
			line_pos = 0;
			move(++y, 0);
			clrtoeol();
		}
		else if (ch == KEY_BACKSPACE || ch == 127 || ch == 8) {
			if (line_pos > 0) {
				line_pos--;
				mvdelch(y, line_pos);
			}
		}
		else if (ch >= 32 && ch <= 126) {
			if (line_pos < 255) {
				line[line_pos++] = ch;
				addch(ch);
			}
		}
		refresh();
	}
}

int main() {
	initscr();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);

	const LibftFunc *func = &libft_funcs[0];

	mvprintw(0, 0, "Typing practice: %s", func->name);
	mvprintw(1, 0, "Description: %s", func->description);
	mvprintw(3, 0, "Type the function implementation. Press Enter on empty line to finish:\n\n%s\n\n", func->code);

	char input[MAX_INPUT];
	get_multiline_input(input, MAX_INPUT);

	clear();
	mvprintw(0, 0, "Your input:\n%s\n", input);

	if (strcmp(input, func->code) == 0) {
		mvprintw(10, 0, "✅ Correct!");
	} else {
		mvprintw(10, 0, "❌ Incorrect!");
	}

	mvprintw(12, 0, "Press any key to exit.");
	getch();

	endwin();
	return 0;
}
