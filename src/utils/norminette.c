#include <stdio.h>
#include <string.h>

int check_norminette(const char *filename)
{
    FILE *fp;
    char command[256];
    char buffer[512];
    int passed = 0;
    int in_error_block = 0;

    snprintf(command, sizeof(command), "norminette %s 2>&1", filename);
    fp = popen(command, "r");
    if (!fp)
        return 0;

    while (fgets(buffer, sizeof(buffer), fp))
    {
        if (strstr(buffer, ": OK!"))
        {
            printf("\033[0;32m%s\033[0m", buffer); // green
            passed = 1;
        }
        else if (strstr(buffer, "Error!"))
        {
            in_error_block = 1;
            printf("\033[0;31m%s\033[0m", buffer);
        }
        else if ((strstr(buffer, "Error") || strstr(buffer, "Warning")) && strstr(buffer, "(line:"))
        {
            char *line_ptr = strstr(buffer, "(line:");
            if (line_ptr)
            {
                int line_num = 0;
                sscanf(line_ptr, "(line: %d", &line_num);
                int adjusted_line = line_num - 12;
                if (adjusted_line < 1)
                    adjusted_line = 1;
                char *col_ptr = strstr(buffer, ", col:");
                if (col_ptr)
                {
                    int col_num = 0;
                    sscanf(col_ptr, ", col: %d", &col_num);

                    // Extract error name
                    char *desc_start = strchr(buffer, ')');
                    const char *error_name = desc_start ? desc_start + 2 : "Unknown error";

                    printf("\033[0;31mNorm: line %d (col %d) → Typed: line %d — %s\033[0m\n",
                           line_num, col_num, adjusted_line, error_name);
                }
                else
                {
                    printf("\033[0;31mNorm: line %d → Typed: line %d — %s\033[0m\n", line_num, adjusted_line, buffer);
                }
            }
        }
        else if (in_error_block && strlen(buffer) > 1)
        {
            printf("\033[0;31mNorminette: %s\033[0m", buffer);
            in_error_block = 0;
        }
        else
        {
            printf("%s", buffer);
        }
    }
    pclose(fp);
    return passed ? 100 : 0;
}

void write_norminette_file(const char *filename, const char *func_name, const char *code)
{
    FILE *fp = fopen(filename, "w");
    if (!fp)
        return;

    fprintf(fp,
            "/* ************************************************************************** */\n"
            "/*                                                                            */\n"
            "/*                                                        :::      ::::::::   */\n"
            "/*   %-42s   :+:      :+:    :+:   */\n"
            "/*                       hello                        +:+ +:+         +:+     */\n"
            "/*   By: esaleh <esaleh@student.42berlin.de>        +#+  +:+       +#+        */\n"
            "/*                                                +#+#+#+#+#+   +#+           */\n"
            "/*   Created dddddddddd llllllll by esaleh            #+#    #+#             */\n"
            "/*   Updated: 2025/06/21 09:00:00 by esaleh           ###   ########.fr       */\n"
            "/*                                                                            */\n"
            "/* ************************************************************************** */\n"
            "\n"
            "/*\n"
            "**  type42-berlin — Typing Trainer for 42 Network\n"
            "**  Function: %s — Practice Mode: Copy / Recall\n"
            "*/\n\n",
            func_name, func_name);

    fprintf(fp, "%s", code);
    fclose(fp);
}
