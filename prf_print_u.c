/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_print_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 02:19:06 by aklein            #+#    #+#             */
/*   Updated: 2023/11/01 21:44:39 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_u(t_print *print)
{
	unsigned long nbr;

	nbr = va_arg(print->ap, unsigned int);
	print->printed += count_digits_ui(nbr);
	ft_putnbr_ul_fd(nbr, print->fd);
	return (1);
}