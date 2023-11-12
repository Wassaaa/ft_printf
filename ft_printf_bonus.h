/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 00:58:39 by aklein            #+#    #+#             */
/*   Updated: 2023/11/12 02:43:10 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "libft/libft.h"
# include <stdarg.h>

# define SPECS "cspdiuxX%"
# define FLAGS "-+ #0*."
# define HEXBASELOWER "0123456789abcdef"
# define HEXBASEUPPER "0123456789ABCDEF"

typedef struct s_print
{
	const char	*frm;
	va_list		ap;
	char		spec;
	int			printed;
	int			fd;
	int			spec_i;
}				t_print;

typedef struct s_flags
{
	int			plus_sign;
	int			justify;
	int			space_sign;
	int			hashtag;
	int			width;
	int			perc;
	char		pad_c;
}				t_flags;

int				ft_printf(const char *frm, ...);
void			init_print(t_print *print, t_flags *flags);
void			reset_print(t_print *print, t_flags *flags);
int				parse_spec(t_print *print);
int				parse_flags(t_print *print, t_flags *flags);
size_t			count_digits(int n);
size_t			count_digits_ui(unsigned int n);
size_t			count_digits_hex(unsigned long nb);
int				print_c(t_print *print, t_flags *flags);
int				print_s(t_print *print);
int				print_p(t_print *print);
int				print_d(t_print *print, t_flags *flags);
int				print_u(t_print *print);
int				print_x(t_print *print);
void			ft_putnbr_base_ul_fd(unsigned long nbr, char *base, int fd);
void			ft_putnbr_ul_fd(unsigned long n, int fd);
void			handle_pad(t_print *print, t_flags *flags);

#endif
