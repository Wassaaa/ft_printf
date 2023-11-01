/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 00:25:19 by aklein            #+#    #+#             */
/*   Updated: 2023/11/01 22:43:39 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_next(t_print *print)
{
	if (*print->frm != '%')
	{
		ft_putchar_fd(*print->frm, print->fd);
		print->frm++;
		print->printed++;
		return (1);
	}
	return (0);
}
// none of those should move the print->frm pointer
int	print_spec(t_print *print)
{
	if (print->spec == 'c')
		print_c(print);
	if (print->spec == 's')
		print_s(print);
	if (print->spec == 'p')
		print_p(print);
	if (print->spec == 'd' || print->spec == 'i')
		print_d(print);
	if (print->spec == 'u')
		print_u(print);
	if (print->spec == 'x' || print->spec == 'X')
		print_x(print);
	if (print->spec == '%')
	{
		ft_putchar_fd('%', print->fd);
		print->printed++;
	}
	return (1);
}

int	ft_printf(const char *frm, ...)
{
	t_print	print;

	print.frm = frm;
	init_print(&print);
	va_start(print.ap, frm);
	while (*print.frm)
	{
		if (print_next(&print))
			continue ;
		if (parse_spec(&print))
		{
			print.frm += print.spec_i + 1;
			print_spec(&print);
			reset_print(&print);
			continue ;
		}
	}
	va_end(print.ap);
	return (print.printed);
}

// #include <stdio.h>
// #include <limits.h>

// int	main(void)
// {
// 	int my_int;

// 	my_int = 55;
// 	int ft1 = ft_printf("%%testing%d okay%cmore%smore\n", -10, 'c', " tests ");
// 	int std1 = printf("%%testing%d okay%cmore%smore\n", -10, 'c', " tests ");
// 	int ft2 = ft_printf("testing %p okay\n", &my_int);
// 	int std2 = printf("testing %p okay\n", &my_int);
// 	int ft3 = ft_printf("testing %u okay\n", UINT_MAX);
// 	int std3 = printf("testing %u okay\n", UINT_MAX);
// 	int ft4 = ft_printf("testing %u okay\n", INT_MIN);
// 	int std4 = printf("testing %u okay\n", INT_MIN);
// 	int ft5 = ft_printf("testing %x okay\n", UINT_MAX);
// 	int std5 = printf("testing %x okay\n", UINT_MAX);
// 	int ft6 = ft_printf("testing %x okay\n", 10);
// 	int std6 = printf("testing %x okay\n", 10);
// 	int ft7 = ft_printf("testing %X okay\n", -5558876);
// 	int std7 = printf("testing %X okay\n", -5558876);

// 	printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", ft1, std1, ft2, std2, ft3, std3, ft4, std4, ft5, std5, ft6, std6, ft7, std7);

// 	return (0);
// }