/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_init_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:51:49 by aklein            #+#    #+#             */
/*   Updated: 2023/10/30 01:04:05 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_print(t_print *print)
{
	print->fd = 1;
	print->printed = 0;
	print->spec_i = 0;
	print->spec = 0;
	print->pad_c = ' ';
}