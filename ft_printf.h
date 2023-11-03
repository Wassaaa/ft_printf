/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 00:58:39 by aklein            #+#    #+#             */
/*   Updated: 2023/11/03 20:30:43 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

# define SPECS "cspdiuxX%"
# define FLAGS "+ #0*-."
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

int				ft_printf(const char *frm, ...);
void			init_print(t_print *print);
void			reset_print(t_print *print);
int				parse_spec(t_print *print);
size_t			count_digits(int n);
size_t			count_digits_ui(unsigned int n);
size_t			count_digits_hex(unsigned long nb);
int				print_c(t_print *print);
int				print_s(t_print *print);
int				print_p(t_print *print);
int				print_d(t_print *print);
int				print_u(t_print *print);
int				print_x(t_print *print);
void			ft_putnbr_base_ul_fd(unsigned long nbr, char *base, int fd);
void			ft_putnbr_ul_fd(unsigned long n, int fd);

#endif
