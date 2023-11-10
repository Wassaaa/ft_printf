/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_print_s_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 02:16:47 by aklein            #+#    #+#             */
/*   Updated: 2023/11/10 19:17:09 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_s(t_print *print)
{
	char	*my_str;

	my_str = va_arg(print->ap, char *);
	if (!my_str)
	{
		ft_putstr_fd("(null)", print->fd);
		print->printed += 6;
		return (1);
	}
	ft_putstr_fd(my_str, print->fd);
	print->printed += ft_strlen(my_str);
	return (1);
}
