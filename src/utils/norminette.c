#include <stdio.h>
#include <string.h>

int check_norminette(const char *filename)
{
    FILE *fp;
    char command[256];
    char buffer[512];
    int passed = 0;

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
        else if (strstr(buffer, "Error") || strstr(buffer, "Warning"))
        {
            printf("\033[0;31m%s\033[0m", buffer); // red
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
            "/*                                                    +:+ +:+         +:+     */\n"
            "/*   By: type42 <type42@student.42.de>              +#+  +:+       +#+        */\n"
            "/*                                                +#+#+#+#+#+   +#+           */\n"
            "/*   Created: 2025/06/20 20:00:00 by type42            #+#    #+#             */\n"
            "/*   Updated: 2025/06/20 20:00:00 by type42           ###   ########.fr       */\n"
            "/*                                                                            */\n"
            "/* ************************************************************************** */\n\n",
            func_name);

    fprintf(fp, "%s", code);
    fclose(fp);
}
