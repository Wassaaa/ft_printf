/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_print_c_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 02:15:09 by aklein            #+#    #+#             */
/*   Updated: 2023/11/12 02:20:06 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"



int	print_c(t_print *print, t_flags *flags)
{
	char	mychar;

	flags->pad_c = ' ';
	mychar = (char)va_arg(print->ap, int);
	if (!flags->justify)
	{
		handle_pad(print, flags);
		ft_putchar_fd(mychar, print->fd);
		print->printed++;
	}
	else
	{
		ft_putchar_fd(mychar, print->fd);
		print->printed++;
		handle_pad(print, flags);
	}
	return (1);
}
