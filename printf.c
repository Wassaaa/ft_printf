/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 00:25:19 by aklein            #+#    #+#             */
/*   Updated: 2023/10/29 05:58:09 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

/*
 * Basic algorithm is to scan the format string for conversion
 * specifications -- once one is found, find out if the field
 * width or precision is a '*'; if it is, gather up value.  Note,
 * format strings are reused as necessary to use up the provided
 * arguments, arguments of zero/null string are provided to use
 * up the format string.
 */

int	print_next(t_print *print)
{
	if (*print->frm != '%')
	{
		ft_putchar_fd(*print->frm, print->fd);
		print->frm++;
		print->printed++;
		return (1);
	}
	return (0);
}
// if this fails just print everytihn even % sign
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

void	init_flags(t_flags *flags)
{
	flags->hashtag = 0;
	flags->plus_sign = 0;
	flags->space_sign = 0;
	flags->pad_c = ' ';
	flags->width = 0;
}

void	init_print(t_print *print)
{
	print->fd = 1;
	print->printed = 0;
	print->faulty = 0;
	print->spec_i = 0;
	print->spec = 0;
}

int	get_width(t_print *print, t_flags *flags, size_t i)
{
	int	width;

	width = 0;
	if (print->frm[i] == '*')
	{
		flags->width = va_arg(print->ap, int);
		return (i++);
	}
	while (ft_isdigit(print->frm[i]))
	{
		width = (width * 10) + (print->frm[i] - '0');
		i++;
	}
	flags->width = width;
	return (i);
}

void	parse_flags(t_print *print, t_flags *flags)
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
		else
			i = get_width(print, flags, i);
		i++;
	}
}

int	ft_printf(const char *frm, ...)
{
	t_print	print;
	t_flags	flags;

	print.frm = frm;
	init_print(&print);
	init_flags(&flags);
	va_start(print.ap, frm);
	while (*print.frm)
	{
		if (print_next(&print))
			continue ;
		parse_spec(&print);
		parse_flags(&print, &flags);
		print.frm += print.spec_i + 1;
	}
	va_end(print.ap);
	return (print.printed);
}

#include <stdio.h>

int	main(void)
{
	ft_printf("testing%#*dagain\n", 85);
	// printf("%d\n", 5);
}