#include <stdio.h>
#include <string.h>
#include "core.h"

void run_tests(void)
{
    const char *test_cases[] = {
        "",
        "42",
        "Hello, world!",
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
        "\n\t"};

    for (int i = 0; i < 5; ++i)
    {
        size_t expected = strlen(test_cases[i]);
        size_t actual = ft_strlen(test_cases[i]);
        if (expected == actual)
            printf("✅ Test %d passed: \"%s\" → %lu\n", i + 1, test_cases[i], actual);
        else
            printf("❌ Test %d failed: \"%s\" → got %lu, expected %lu\n",
                   i + 1, test_cases[i], actual, expected);
    }
}

int main(void)
{
    run_tests();
    return 0;
}