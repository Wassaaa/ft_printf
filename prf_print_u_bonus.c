/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_print_u_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 02:19:06 by aklein            #+#    #+#             */
/*   Updated: 2023/11/10 19:17:09 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_u(t_print *print)
{
	unsigned long	nbr;

	nbr = va_arg(print->ap, unsigned int);
	print->printed += count_digits_ui(nbr);
	ft_putnbr_ul_fd(nbr, print->fd);
	return (1);
}
