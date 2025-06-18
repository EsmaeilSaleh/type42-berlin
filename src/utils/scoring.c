#include "core.h"
#include <stdio.h>

int compute_similarity_score(const char *input, const char *expected)
{
    // Quick shortcut: both are NULL
    if (!input || !expected)
        return 0;

    int matches = 0;
    int total = 0;

    const char *p1 = input;
    const char *p2 = expected;

    while (*p1 && *p2)
    {
        // Skip whitespace
        while (isspace(*p1))
            p1++;
        while (isspace(*p2))
            p2++;

        if (!*p1 || !*p2)
            break;

        if (*p1 == *p2)
            matches++;
        else
        {
            fprintf(stderr, "\033[0;31mMismatch at position %d:\033[0m expected '%c', got '%c'\n", total, *p2, *p1);
        }

        total++;
        p1++;
        p2++;
    }

    // Allow a small mismatch margin
    int expected_len = 0;
    const char *p = expected;
    while (*p)
    {
        if (!isspace(*p))
            expected_len++;
        p++;
    }
    return expected_len ? (matches * 100 / expected_len) : 0;
}