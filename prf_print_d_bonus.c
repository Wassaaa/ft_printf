/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_print_d_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 01:27:37 by aklein            #+#    #+#             */
/*   Updated: 2023/11/12 18:51:23 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	handle_flags(t_flags *flags, int my_n)
{
	if (flags->space_sign)
		flags->sign = ' ';
	if (flags->plus_sign)
		flags->sign = '+';
	if (my_n < 0)
		flags->sign = '-';
	if (flags->perc > 0 || flags->justify)
		flags->pad_c = ' ';
}

void	handle_padding(t_print *print, t_flags *flags, int my_n)
{
	int padding;
	
	if (flags->sign)
		flags->width--;
	if (flags->perc > 0 && flags->perc > flags->digits)
		padding = flags->width - flags->perc;
	else
		padding = flags->width - flags->digits;
	if (my_n < 0)
		if (flags->width > 0 && flags->perc > 0)
			if (flags->perc > flags->digits)
				padding--;
	if (padding <= 0)
		return ;
	print->printed += padding;
	while (padding--)
		ft_putchar_fd(flags->pad_c, print->fd);
}

int	print_d(t_print *print, t_flags *flags)
{
	int	my_n;

	my_n = va_arg(print->ap, int);
	flags->digits = count_digits(my_n);
	if (flags->perc >= flags->width)
		flags->width = flags->digits;
	else
		flags->width = flags->width - flags->perc;
	handle_flags(flags, my_n);
	if (flags->sign)
	{
		ft_putchar_fd(flags->sign, print->fd);
		print->printed++;
	}
	if (!flags->justify)
		handle_pad(print, flags);
	while (flags->perc > flags->digits)
	{
		ft_putchar_fd('0', print->fd);
		print->printed++;
		flags->perc--;
	}
	ft_putnbr_fd(abs(my_n), print->fd);
	if (flags->justify)
		handle_pad(print, flags);
	print->printed += flags->digits;
	return (1);
}
