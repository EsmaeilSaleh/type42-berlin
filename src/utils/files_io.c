#include "core.h"

void save_score_log(const char *func_name, int score, const char *mode)
{
    FILE *log = fopen("score_log.txt", "a");
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