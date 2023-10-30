/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_print_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 02:16:47 by aklein            #+#    #+#             */
/*   Updated: 2023/10/30 03:13:37 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_s(t_print *print)
{
	char *my_str;

	my_str = va_arg(print->ap, char *);
	ft_putstr_fd(my_str, print->fd);
	return (1);
}