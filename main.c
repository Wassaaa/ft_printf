#include "ft_printf_bonus.h"
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
    test_d("testing '% 10.18d' okay\n", 42, "percision > width POS, space flag");
    test_d("testing '% 10.18d' okay\n", -42, "percision > width NEG, space flag");
    test_d("testing '% 10.8d' okay\n", 42, "percision < width POS, space flag");
    test_d("testing '% 10.8d' okay\n", -42, "percision < width NEG, space flag");

    test_d("testing '% -10.18d' okay\n", 42, "percision > width POS, just and space flag");
    test_d("testing '% -10.18d' okay\n", -42, "percision > width NEG, just and space flag");
    test_d("testing '% -10.8d' okay\n", 42, "percision < width POS, just and space flag");
    test_d("testing '% -10.8d' okay\n", -42, "percision < width NEG, just and space flag");

    test_d("testing '%+ 10.18d' okay\n", 42, "percision > width POS, + and space flag");
    test_d("testing '%+ 10.18d' okay\n", -42, "percision > width NEG, + and space flag");
    test_d("testing '%+ 10.8d' okay\n", 42, "percision < width POS, + and space flag");
    test_d("testing '%+ 10.8d' okay\n", -42, "percision < width NEG, + and space flag");

    test_d("testing '%+-0 10.18d' okay\n", 42, "percision > width POS, +, just, 0 and space flag");
    test_d("testing '%+-0 10.18d' okay\n", -42, "percision > width NEG, +, just, 0 and space flag");
    test_d("testing '%+-0 10.2d' okay\n", 42, "percision < width POS, +, just, 0 and space flag");
    test_d("testing '%+-0 10.2d' okay\n", -42, "percision < width NEG, +, just, 0 and space flag");

    test_d("testing '%05d' okay\n", 42, "width 10 POS, + and 0 flag");
    test_d("testing '%05d' okay\n", -42, "width 10 NEG, + and 0 flag");

    test_d("testing '%+-05d' okay\n", 42, "width 10 POS, + and 0 flag");
    test_d("testing '%+-05d' okay\n", -42, "width 10 NEG, + and 0 flag");




    return (0);
}