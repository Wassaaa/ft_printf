/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:50:24 by aklein            #+#    #+#             */
/*   Updated: 2023/10/29 05:23:01 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

# define SPECS "cspdiuxX%"
# define FLAGS "+ #0*"

typedef struct s_print
{
	const char	*frm;
	va_list		ap;
	char		spec;
	int			printed;
	int			fd;
	int			spec_i;
	int			faulty;

}				t_print;

typedef struct s_flags
{
	int			plus_sign;
	int			space_sign;
	int			hashtag;
	char		pad_c;
	int			width;
}				t_flags;

#endif