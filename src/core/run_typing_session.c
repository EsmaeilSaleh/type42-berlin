#include "core.h"
#include "terminal_display.h"
#include "line_editor.h"

typedef struct s_session_redraw_ctx
{
	const char *prompt;
} SessionRedrawCtx;

static void redraw_session_input_line(const char *buf, size_t cursor, void *ctx)
{
	SessionRedrawCtx *draw_ctx;
	size_t prompt_len;

	draw_ctx = (SessionRedrawCtx *)ctx;
	prompt_len = strlen(draw_ctx->prompt);
	printf("\r\033[2K%s%s", draw_ctx->prompt, buf);
	printf("\r");
	if (prompt_len + cursor > 0)
		printf("\033[%zuC", prompt_len + cursor);
	fflush(stdout);
}

static int parse_positive_int(const char *s, int *out)
{
	long	val;
	int		i;

	if (!s || !s[0])
		return (0);
	val = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		val = (val * 10) + (s[i] - '0');
		if (val > 2147483647)
			return (0);
		i++;
	}
	*out = (int)val;
	return (1);
}

static int read_session_choice(const char *prompt, int *out)
{
	char				line[64];
	int					status;
	SessionRedrawCtx	draw_ctx;

	draw_ctx.prompt = prompt;
	status = read_line_edit(line, sizeof(line), redraw_session_input_line, &draw_ctx);
	printf("\n");
	if (status != 1)
		return (0);
	return (parse_positive_int(line, out));
}

void run_typing_session(Mode mode,
						LibFunc (*get_func_by_index)(int),
						int (*get_func_count)(void))
{
	int count = get_func_count();
	int func_choice;

	print_function_list(get_func_by_index, count);

	if (!read_session_choice("Select a function to practice: ", &func_choice)
		|| func_choice < 0 || func_choice > count)
	{
		fprintf(stderr, "Invalid function choice.\n");
		return;
	}

	if (func_choice == 0)
	{
		system("clear");
		print_banner();
		longjmp(category_menu_jump, 1);
	}
	LibFunc func = get_func_by_index(func_choice - 1);
	run_mode(mode, &func);
}
