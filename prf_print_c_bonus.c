/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_print_c_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 02:15:09 by aklein            #+#    #+#             */
/*   Updated: 2023/11/10 19:17:09 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_c(t_print *print)
{
	char	mychar;

	mychar = (char)va_arg(print->ap, int);
	ft_putchar_fd(mychar, print->fd);
	print->printed++;
	return (1);
}
