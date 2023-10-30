/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_ul_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 03:39:12 by aklein            #+#    #+#             */
/*   Updated: 2023/10/30 04:10:58 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	print_base(unsigned long nbr, size_t len, char *base, int fd)
{
	static size_t	digits = 0;

	if (nbr >= len)
		print_base(nbr / len, len, base, fd);
	ft_putchar_fd(base[nbr % len], fd);
	digits++;
	return (digits);
}

int	ft_putnbr_base_ul_fd(unsigned long nbr, char *base, int fd)
{
	size_t base_len;

	base_len = ft_strlen(base);
	return (print_base(nbr, base_len, base, fd));
}