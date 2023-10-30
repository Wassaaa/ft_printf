/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 00:25:19 by aklein            #+#    #+#             */
/*   Updated: 2023/10/30 04:30:53 by aklein           ###   ########.fr       */
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
	if (print->spec == 'x')
		print_x(print);
	if (print->spec == 'X')
		print_xx(print);
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

#include <stdio.h>

int	main(void)
{
	int my_int;

	my_int = 55;
	int ft1 = ft_printf("%%testing%d okay%cmore%smore\n", -10, 'c', " tests ");
	int std1 = printf("%%testing%d okay%cmore%smore\n", -10, 'c', " tests ");
	int ft2 = ft_printf("testing %p okay\n", &my_int);
	int std2 = printf("testing %p okay\n", &my_int);

	printf("%d\n%d\n%d\n%d\n", ft1, std1, ft2, std2);

	return (0);
}