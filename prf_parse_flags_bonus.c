/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_parse_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 01:18:14 by aklein            #+#    #+#             */
/*   Updated: 2023/10/30 01:20:26 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	parse_flags(t_print *print, t_flags *flags)
{
	size_t i;

	i = 0;
	while (print->spec_i > i)
	{
		if (print->frm[i] == '+')
			flags->plus_sign = 1;
		else if (print->frm[i] == ' ')
			flags->space_sign = 1;
		else if (print->frm[i] == '#')
			flags->hashtag = 1;
		else if (print->frm[i] == '0')
			print->pad_c = '0';
		else if (print->frm[i] == '-')
			flags->justify = 1;
		else if (print->frm[i] == '*' || ft_isdigit((int)print->frm[i]))
			i = get_width(print, flags, i) - 1;
		else if (print->frm[i] == '.')
			i = get_perc(print, flags, i);
		i++;
	}
	if (print->spec_i == i)
		return (1);
	return (0);
}