#include "ft_printf.h"

// FILE: test_tests.c
#include <stdio.h>
#include <assert.h>
#include <string.h>

void test_ft_printf()
{
    char buffer[100];
    int ret;

    // Test case 1: flag '-'
    ret = snprintf(buffer, sizeof(buffer), "%-10d", 42);
    assert(ret == ft_printf("%-10d", 42));
    assert(strcmp(buffer, "42        ") == 0);
    putchar('\n');
    // Test case 2: flag '0'
    ret = snprintf(buffer, sizeof(buffer), "%010d", 42);
    assert(ret == ft_printf("%010d", 42));
    assert(strcmp(buffer, "0000000042") == 0);
    putchar('\n');
    // Test case 3: flag '.'
    ret = snprintf(buffer, sizeof(buffer), "%.5d", 42);
    assert(ret == ft_printf("%.5d", 42));
    assert(strcmp(buffer, "00042") == 0);
    putchar('\n');
    // Test case 4: flag '-.'
    ret = snprintf(buffer, sizeof(buffer), "%-.5d", 42);
    assert(ret == ft_printf("%-.5d", 42));
    assert(strcmp(buffer, "00042") == 0);
    putchar('\n');
    printf("All tests passed!\n");
}

int main()
{
    test_ft_printf();
    return 0;
}