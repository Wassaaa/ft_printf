/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 00:25:19 by aklein            #+#    #+#             */
/*   Updated: 2023/11/07 02:07:53 by aklein           ###   ########.fr       */
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
		return (-1);
	}
	va_end(print.ap);
	return (print.printed);
}
