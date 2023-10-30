/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_print_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 02:15:09 by aklein            #+#    #+#             */
/*   Updated: 2023/10/30 02:59:28 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(t_print *print)
{
	char mychar;

	mychar = (char)va_arg(print->ap, int);
	ft_putchar_fd(mychar, print->fd);
	print->printed++;
	return (1);
}