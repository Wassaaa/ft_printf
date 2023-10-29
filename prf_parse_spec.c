/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_parse_spec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:53:12 by aklein            #+#    #+#             */
/*   Updated: 2023/10/29 20:32:30 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	parse_spec(t_print *print)
{
	size_t	i;
	char	*test;

	i = 0;
	print->frm++;
	while (ft_strchr(SPECS, print->frm[i]) == 0)
	{
		test = ft_strchr(FLAGS, print->frm[i]);
		if (!ft_strchr(FLAGS, print->frm[i]) && !ft_isdigit(print->frm[i]))
			return (0);
		i++;
	}
	print->spec_i = i;
	print->spec = print->frm[i];
	return (1);
}

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

int	parse_flags(t_print *print, t_flags *flags)
{
	size_t	i;

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
			flags->pad_c = '0';
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
