#include "ft_printf_bonus.h"
#include <stdio.h>

int test_d(char *str, int arg, char *desc)
{
    int ft;
    int std;

    printf("%s\n", desc);

    ft = ft_printf(str, arg);
    std = printf(str, arg);

    printf("ft: %d\nstd %d\n", ft, std);
}

int	main()
{
    test_d("testing% 10.18d \n", 42, "percision > width POS, space flag");
    test_d("testing% 10.18d \n", -42, "percision > width NEG, space flag");
    test_d("testing% 10.8d \n", 42, "percision < width POS, space flag");
    test_d("testing% 10.8d \n", -42, "percision < width NEG, space flag");

    test_d("testing% -10.18d \n", 42, "percision > width POS, just and space flag");
    test_d("testing% -10.18d \n", -42, "percision > width NEG, just and space flag");
    test_d("testing% -10.8d \n", 42, "percision < width POS, just and space flag");
    test_d("testing% -10.8d \n", -42, "percision < width NEG, just and space flag");

    test_d("testing%+ 10.18d \n", 42, "percision > width POS, + and space flag");
    test_d("testing%+ 10.18d \n", -42, "percision > width NEG, + and space flag");
    test_d("testing%+ 10.8d \n", 42, "percision < width POS, + and space flag");
    test_d("testing%+ 10.8d \n", -42, "percision < width NEG, + and space flag");

    return (0);
}