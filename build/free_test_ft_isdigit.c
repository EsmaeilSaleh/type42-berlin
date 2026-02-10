#include <stdio.h>
#include <ctype.h>

int ft_isdigit(int c);

int main(void)
{
    int i;
    int j;
    int expected;
    int got;
    int extras[3];

    for (i = 0; i <= 255; i++)
    {
        expected = (isdigit((unsigned char)i) != 0);
        got = (ft_isdigit(i) != 0);
        if (got != expected)
        {
            printf("FAIL ft_isdigit: input=%d expected=%d got=%d\n", i, expected, got);
            return (1);
        }
    }
    extras[0] = -1;
    extras[1] = 256;
    extras[2] = 1000;
    for (j = 0; j < 3; j++)
    {
        expected = (isdigit((unsigned char)extras[j]) != 0);
        got = (ft_isdigit(extras[j]) != 0);
        if (got != expected)
        {
            printf("FAIL ft_isdigit: input=%d expected=%d got=%d\n", extras[j], expected, got);
            return (1);
        }
    }
    printf("OK\n");
    return (0);
}
