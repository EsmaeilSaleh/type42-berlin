#include "core.h"
#include "mode_selector.h"
#include "scoring.h"
#include "terminal_display.h"
#include "ui.h"
#include <setjmp.h>

jmp_buf mode_menu_jump;
jmp_buf category_menu_jump;


int main()
{
	system("clear");
	print_banner();
	printf("\n\n");
	if (setjmp(mode_menu_jump) != 0)
		printf("\nReturning to mode selection...\n");

	while (1)
	{
		int mode = select_mode();
		if (mode == 0)
		{
			system("clear");
			print_banner();
			break;
		}

		while (1)
		{
			if (setjmp(category_menu_jump) != 0)
				printf("\nReturning to mode selection...\n");
			system("clear");
			print_banner();
			int category = select_category();
			if (category == 0)
			{
				system("clear");
				print_banner();
				break;
			}
			run_category_loop(mode, category);
		}
	}

	return 0;
}
