/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_print_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 02:19:29 by aklein            #+#    #+#             */
/*   Updated: 2023/11/01 20:41:49 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_x(t_print *print)
{
	long	nbr;

	if (print->spec == 'x')
	{
		nbr = va_arg(print->ap, unsigned int);
		print->printed += count_digits_hex(nbr);
		ft_putnbr_base_ul_fd(nbr, HEXBASELOWER, print->fd);
		return (1);
	}
	if (print->spec == 'X')
	{
		nbr = va_arg(print->ap, unsigned int);
		print->printed += count_digits_hex(nbr);
		ft_putnbr_base_ul_fd(nbr, HEXBASEUPPER, print->fd);
		return (1);
	}
	return (0);
}