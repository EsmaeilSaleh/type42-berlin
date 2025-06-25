#include <stdbool.h>
#include <ctype.h>

bool is_flag_char(char c)
{
    return (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0');
}

int parse_number(const char *format, int *i)
{
    int num = 0;

    while (format[*i] && isdigit(format[*i]))
    {
        num = num * 10 + (format[*i] - '0');
        (*i)++;
    }
    return (num);
}