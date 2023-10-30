/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:50:24 by aklein            #+#    #+#             */
/*   Updated: 2023/10/30 01:02:07 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "libft/libft.h"
# include <stdarg.h>

# define SPECS "cspdiuxX%"
# define FLAGS "+ #0*-."

typedef struct s_print
{
	const char	*frm;
	va_list		ap;
	char		spec;
	int			printed;
	int			fd;
	int			spec_i;
	char		pad_c;

}				t_print;

typedef struct s_flags
{
	int			plus_sign;
	int			justify;
	int			space_sign;
	int			hashtag;
	int			width;
	int			perc;
}				t_flags;

size_t			count_digits(int n);
int				abs_val(int n);
void			init_flags(t_flags *flags);
void			init_print(t_print *print);
int				parse_spec(t_print *print);
int				get_width(t_print *print, t_flags *flags, size_t i);
int				parse_flags(t_print *print, t_flags *flags);
int				abs_val(int n);
size_t			count_digits(int n);
int				print_d(t_print *print, t_flags *flags);

#endif