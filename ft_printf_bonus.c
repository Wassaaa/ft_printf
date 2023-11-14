/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 00:25:19 by aklein            #+#    #+#             */
/*   Updated: 2023/11/14 16:26:01 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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

int	print_spec(t_print *print, t_flags *flags)
{
	if (print->spec == 'c')
		print_c(print, flags);
	if (print->spec == 's')
		print_s(print);
	if (print->spec == 'p')
		print_p(print);
	if (print->spec == 'd' || print->spec == 'i')
		print_d(print, flags);
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
	t_flags flags;

	print.frm = frm;
	init_print(&print, &flags);
	va_start(print.ap, frm);
	while ((char)*print.frm)
	{
		if (print_next(&print))
			continue ;
		if (parse_spec(&print))
		{
			if (parse_flags(&print, &flags))
			{
				print.frm += print.spec_i + 1;
				print_spec(&print, &flags);
				reset_print(&print, &flags);
				continue ;
			}
		}
		return (-1);
	}
	va_end(print.ap);
	return (print.printed);
}
