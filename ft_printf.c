/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 00:25:19 by aklein            #+#    #+#             */
/*   Updated: 2023/11/14 21:26:31 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_next(t_print *print)
{
	if (*print->frm != '%')
	{
		if (!ft_safe_putchar_fd(*print->frm, print->fd))
			return (0);
		print->frm++;
		print->printed++;
		return (1);
	}
	return (0);
}

int	print_spec(t_print *print)
{
	if (print->spec == 'c')
		return (print_c(print));
	else if (print->spec == 's')
		return (print_s(print));
	else if (print->spec == 'p')
		return (print_p(print));
	else if (print->spec == 'd' || print->spec == 'i')
		return (print_d(print));
	else if (print->spec == 'u')
		return (print_u(print));
	else if (print->spec == 'x' || print->spec == 'X')
		return (print_x(print));
	else if (print->spec == '%')
	{
		if (!ft_safe_putchar_fd('%', print->fd))
			return (0);
		print->printed++;
		return (1);
	}
	else
		return (0);
}

int	ft_printf(const char *frm, ...)
{
	t_print	print;

	if (!frm)
		return (-1);
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
			if (print_spec(&print))
			{
				reset_print(&print);
				continue ;
			}
		}
	}
	va_end(print.ap);
	return (print.printed);
}
