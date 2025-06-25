#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "core.h"

int handle_plus_flag(int n)
{
    if (n >= 0)
        write(1, "+", 1);
    return (dprintf(1, "%d", n));
}

int handle_field_width(const char *s, int width)
{
    int len = strlen(s);
    int padding = width - len;

    while (padding-- > 0)
        write(1, " ", 1);
    return (write(1, s, len) + (width > len ? width - len : 0));
}