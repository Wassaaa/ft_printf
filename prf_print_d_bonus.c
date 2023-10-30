/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_print_d_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:48:43 by aklein            #+#    #+#             */
/*   Updated: 2023/10/30 01:28:01 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_d(t_print *print, t_flags *flags)
{
	int my_n;
	int digit_count;

	my_n = va_arg(print->ap, int);
	digit_count = count_digits(my_n);
	if (my_n < 0 || flags->plus_sign || flags->space_sign)
		digit_count++;
	if (my_n < 0)
	{
		ft_putchar_fd('-', print->fd);
		print->printed += digit_count;
	}
	else if (flags->plus_sign)
	{
		ft_putchar_fd('+', print->fd);
		print->printed++;
	}
	else if (flags->space_sign)
	{
		ft_putchar_fd(' ', print->fd);
		print->printed++;
	}
	while (flags->width > digit_count)
	{
		ft_putchar_fd(print->pad_c, print->fd);
		print->printed++;
		flags->width--;
	}
	ft_putnbr_fd(abs_val(my_n), print->fd);
	print->printed += digit_count;
	return (1);
}