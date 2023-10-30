/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_width_perc_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 01:16:31 by aklein            #+#    #+#             */
/*   Updated: 2023/10/30 01:17:19 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	get_width(t_print *print, t_flags *flags, size_t i)
{
	int	width;

	width = 0;
	if (print->frm[i] == '*')
	{
		flags->width = va_arg(print->ap, int);
		return (++i);
	}
	while (ft_isdigit(print->frm[i]))
	{
		width = (width * 10) + (print->frm[i] - '0');
		i++;
	}
	flags->width = width;
	return (i);
}

int	get_perc(t_print *print, t_flags *flags, size_t i)
{
	int perc;

	i++;
	perc = 0;
	if (print->frm[i] == '*')
	{
		flags->perc = va_arg(print->ap, int);
		return (++i);
	}
	while (ft_isdigit(print->frm[i]))
	{
		perc = (perc * 10) + (print->frm[i] - '0');
		i++;
	}
	flags->perc = perc;
	return (i);
}