/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_print_p_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 02:17:04 by aklein            #+#    #+#             */
/*   Updated: 2023/11/10 19:17:09 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_p(t_print *print)
{
	unsigned long	ptr;

	ptr = va_arg(print->ap, unsigned long);
	ft_putstr_fd("0x", print->fd);
	print->printed += 2;
	print->printed += count_digits_hex(ptr);
	ft_putnbr_base_ul_fd(ptr, HEXBASELOWER, print->fd);
	return (1);
}
