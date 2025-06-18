#include "core.h"

#include <libgen.h> // برای dirname
#include <string.h>

#include <unistd.h>
#include <stdlib.h>

char g_base_path[PATH_MAX];

void set_base_path(const char *argv0)
{
    char real_path[PATH_MAX];
    if (realpath(argv0, real_path) != NULL)
    {
        char *dir = dirname(real_path);
        strncpy(g_base_path, dir, PATH_MAX);
    }
    else
    {
        // fallback if realpath fails
        strcpy(g_base_path, ".");
    }
}

void save_score_log(const char *func_name, int score, const char *mode)
{
    char full_path[PATH_MAX];
    printf("DEBUG base path: %s\n", g_base_path);
    snprintf(full_path, sizeof(full_path), "%s/score_log.txt", g_base_path);
    printf("Saving log to: %s\n", full_path);
    FILE *log = fopen(full_path, "a");
    if (!log)
    {
        perror("Failed to open score_log.txt");
        return;
    }

    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    fprintf(log, "[%04d-%02d-%02d %02d:%02d:%02d] Mode: %s | Function: %s | Score: %d%%\n",
            t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
            t->tm_hour, t->tm_min, t->tm_sec,
            mode, func_name, score);

    fclose(log);
    system("cd /Users/esmaeil/Documents/Coding/type42-berlin && git add . && git commit -m 'log updated' && git push origin main");
}