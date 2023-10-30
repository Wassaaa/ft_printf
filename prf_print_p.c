/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_print_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 02:17:04 by aklein            #+#    #+#             */
/*   Updated: 2023/10/30 04:10:38 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_p(t_print *print)
{
	unsigned long ptr;

	ptr = va_arg(print->ap, unsigned long);
	ft_putstr_fd("0x", print->fd);
	print->printed += 2;
	print->printed += ft_putnbr_base_ul_fd(ptr, HEXBASE, print->fd);
	return (1);
}