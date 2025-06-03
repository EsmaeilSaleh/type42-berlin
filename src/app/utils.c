#include <stdio.h>
#include <string.h>
#include <time.h>
#include "libft_master.h"

void get_user_input(char *buffer, size_t size) {
	printf("\nStart typing below. End with a single line containing only 'END'\n\n");
	buffer[0] = '\0';
	char line[1024];
	while (fgets(line, sizeof(line), stdin)) {
		if (strcmp(line, "END\n") == 0 || strcmp(line, "END\r\n") == 0)
			break;
		strncat(buffer, line, size - strlen(buffer) - 1);
	}
}

/*
   void run_typing_session(const LibFunc *func, int is_copy_mode) {
   printf("\nFunction: %s\n", func->name);
   printf("Description: %s\n\n", func->description);

   if (is_copy_mode) {
   printf("--- Copy the code below ---\n\n%s\n", func->impl);
   } else {
   printf("--- Type the function from memory ---\n");
   }

   char user_input[MAX_INPUT];
   time_t start = time(NULL);
   get_user_input(user_input, sizeof(user_input));
   time_t end = time(NULL);

   printf("\n--- Your Input ---\n%s", user_input);
   printf("\n--- Typing Time: %ld seconds ---\n", end - start);
   }
   */
