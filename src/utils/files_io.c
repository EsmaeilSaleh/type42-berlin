#include "core.h"
 #include <limits.h>
#ifndef __BASE_PATH__
#define __BASE_PATH__ "."
#endif

char g_base_path[PATH_MAX] = __BASE_PATH__;

void save_score_log(const char *func_name, int score, const char *mode)
{
    char full_path[PATH_MAX];
    snprintf(full_path, sizeof(full_path), "%s/score_log.txt", g_base_path);
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
    printf("\033[32mFunction\033[0m: %s", func_name);
    char git_cmd[PATH_MAX + 128];
    snprintf(git_cmd, sizeof(git_cmd), "cd %s && git add . && git commit -m 'log updated' && git push origin main", g_base_path);
    system(git_cmd);
}