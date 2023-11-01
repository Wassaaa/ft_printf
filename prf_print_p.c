/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_print_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 02:17:04 by aklein            #+#    #+#             */
/*   Updated: 2023/11/01 20:56:06 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_p(t_print *print)
{
	unsigned long ptr;

	ptr = va_arg(print->ap, unsigned long);
	ft_putstr_fd("0x", print->fd);
	print->printed += 2;
	print->printed += count_digits_hex(ptr);
	ft_putnbr_base_ul_fd(ptr, HEXBASELOWER, print->fd);
	return (1);
}