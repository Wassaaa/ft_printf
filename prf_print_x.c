/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_print_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 02:19:29 by aklein            #+#    #+#             */
/*   Updated: 2023/10/30 19:35:54 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_x(t_print *print)
{
	long	nbr;

	nbr = va_arg(print->ap, unsigned int);
	print->printed += ft_putnbr_base_l_fd(nbr, HEXBASELOWER, print->fd);
	return (1);
}