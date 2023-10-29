/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 00:25:19 by aklein            #+#    #+#             */
/*   Updated: 2023/10/29 20:09:05 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

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
	if (print->spec == 'd')
		print_d(print, flags);
	return (1);
}

int	ft_printf(const char *frm, ...)
{
	t_print	print;
	t_flags	flags;

	print.frm = frm;
	init_print(&print);
	init_flags(&flags);
	va_start(print.ap, frm);
	while (*print.frm)
	{
		if (print_next(&print))
			continue ;
		if (parse_spec(&print))
		{
			if (parse_flags(&print, &flags))
			{
				print.frm += print.spec_i + 1;
				print_spec(&print, &flags);
				continue ;
			}
		}
	}
	va_end(print.ap);
	return (print.printed);
}

#include <stdio.h>

int	main(void)
{
	ft_printf("testing%   05d okay\n", -10);
	printf("testing%   05d okay\n", -10);
	printf("testing%+08c okay\n", 'A');
	// printf("%d\n", 5);
}