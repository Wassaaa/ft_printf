#include "ft_printf.h"
#include <stdio.h>

int test_d(char *str, int arg, char *desc)
{
    int ft;
    int std;

    printf("%s\n", desc);

    std = printf(str, arg);
    ft = ft_printf(str, arg);

    printf("std: %d\nft %d\n", std, ft);
}

int	main()
{
	TEST(1, print(" %p ", -1));
	TEST(2, print(" %p ", 1));
	TEST(3, print(" %p ", 15));
	TEST(4, print(" %p ", 16));
	TEST(5, print(" %p ", 17));
	TEST(6, print(" %p %p ", LONG_MIN, LONG_MAX));
	TEST(7, print(" %p %p ", INT_MIN, INT_MAX));
	TEST(8, print(" %p %p ", ULONG_MAX, -ULONG_MAX));
	TEST(9, print(" %p %p ", 0, 0));

    return (0);
}