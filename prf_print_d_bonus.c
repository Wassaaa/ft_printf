/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_print_d_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 01:27:37 by aklein            #+#    #+#             */
/*   Updated: 2023/11/12 04:53:56 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_d(t_print *print, t_flags *flags)
{
	int	my_n;
	int	digit_count;

	my_n = va_arg(print->ap, int);
	digit_count = count_digits(my_n);
	if (flags->plus_sign)
		flags->space_sign = 0;
	if (flags->perc >= flags->width)
	{
		flags->pad_c = ' ';
		flags->width = 0;
		flags->width += flags->space_sign + (my_n > -1);
	}
	else
		flags->width = (flags->width - flags->perc) + flags->space_sign + (my_n > 1);
	if (!flags->justify)
		handle_pad(print, flags);
	if (my_n < 0)
	{
		ft_putchar_fd('-', print->fd);
		print->printed++;
	}
	else if (flags->plus_sign)
	{
		ft_putchar_fd('+', print->fd);
		print->printed++;
	}
	if (flags->perc > digit_count)
	{
		while (flags->perc > digit_count)
		{
			ft_putchar_fd('0', print->fd);
			print->printed++;
			flags->perc--;
		}
	}
	ft_putnbr_fd(abs(my_n), print->fd);
	if (flags->justify)
		handle_pad(print, flags);
	print->printed += digit_count;
	return (1);
}
