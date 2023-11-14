/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_init_print_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:51:49 by aklein            #+#    #+#             */
/*   Updated: 2023/11/12 17:34:17 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	init_print(t_print *print, t_flags *flags)
{
	print->fd = 1;
	print->printed = 0;
	print->spec_i = 0;
	print->spec = 0;
	flags->hashtag = 0;
	flags->justify = 0;
	flags->pad_c = ' ';
	flags->plus_sign = 0;
	flags->space_sign = 0;
	flags->width = 0;
	flags->perc = 0;
	flags->sign = 0;
	flags->digits = 0;

}

void	reset_print(t_print *print, t_flags *flags)
{
	print->spec_i = 0;
	print->spec = 0;
	flags->hashtag = 0;
	flags->justify = 0;
	flags->pad_c = ' ';
	flags->plus_sign = 0;
	flags->space_sign = 0;
	flags->width = 0;
	flags->perc = 0;
	flags->sign = 0;
	flags->digits = 0;
}
