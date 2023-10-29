/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_initiate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:51:49 by aklein            #+#    #+#             */
/*   Updated: 2023/10/29 20:34:46 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flags(t_flags *flags)
{
	flags->hashtag = 0;
	flags->plus_sign = 0;
	flags->space_sign = 0;
	flags->pad_c = ' ';
	flags->width = 0;
	flags->perc = 0;
	flags->justify = 0;
}

void	init_print(t_print *print)
{
	print->fd = 1;
	print->printed = 0;
	print->faulty = 0;
	print->spec_i = 0;
	print->spec = 0;
}