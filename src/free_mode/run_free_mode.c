#include "core.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void run_free_mode(LibFunc *func)
{
    char command[4096];
    char func_file[256];
    char test_file[256];
    FILE *fp;
    char buffer[1024];

    // Build file paths
    snprintf(func_file, sizeof(func_file), "typed/%s.c", func->name);
    snprintf(test_file, sizeof(test_file), "tests/test_%s.c", func->name);

    // Print header
    printf("\n\033[1;36mFree Mode – Practice: %s\033[0m\n", func->name);
    printf("Type your function below (type END alone in a line to finish):\n");

    fp = fopen(func_file, "w");
    if (!fp)
    {
        perror("Error opening file for writing");
        return;
    }

    // Prepend standard includes
    fprintf(fp, "#include <stddef.h>\n#include <stdlib.h>\n#include <unistd.h>\n\n");

    while (1)
    {
        if (!fgets(buffer, sizeof(buffer), stdin))
            break;
        if (strncmp(buffer, "END\n", 4) == 0)
            break;
        fputs(buffer, fp);
    }
    fclose(fp);

    // Confirm and compile
    printf("\n🛠️  Compiling and running tests...\n\n");

    snprintf(command, sizeof(command),
             "echo '\\n🛠️  Compiling %s and %s...' && gcc -I includes %s %s -o tmp_test 2>&1 | tee .compile_log && echo '\\n🧪 Running tests for %s:' && ./tmp_test && rm .tmp_test",
             func_file, test_file, func_file, test_file, func->name);

    int result = system(command);
    if (result != 0)
        printf("\n\033[1;31mTest failed or compilation error.\033[0m\n");
    else
        printf("\n\033[1;32mTest completed successfully.\033[0m\n");

    printf("\nPress Enter to return to menu...");
    getchar();
}
