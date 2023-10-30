/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_init_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 01:01:04 by aklein            #+#    #+#             */
/*   Updated: 2023/10/30 01:01:42 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	init_flags(t_flags *flags)
{
	flags->hashtag = 0;
	flags->plus_sign = 0;
	flags->space_sign = 0;
	flags->width = 0;
	flags->perc = 0;
	flags->justify = 0;
}