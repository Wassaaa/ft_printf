/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_print_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 01:27:37 by aklein            #+#    #+#             */
/*   Updated: 2023/11/03 19:16:55 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_d(t_print *print)
{
	int	my_n;
	int	digit_count;

	my_n = va_arg(print->ap, int);
	digit_count = count_digits(my_n);
	if (my_n < 0)
		digit_count++;
	ft_putnbr_fd(my_n, print->fd);
	print->printed += digit_count;
	return (1);
}
