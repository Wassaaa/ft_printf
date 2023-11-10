/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_ul_fd_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 03:39:12 by aklein            #+#    #+#             */
/*   Updated: 2023/11/10 19:17:09 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	print_base(unsigned long nbr, size_t len, char *base, int fd)
{
	if (nbr >= len)
		print_base(nbr / len, len, base, fd);
	ft_putchar_fd(base[nbr % len], fd);
}

void	ft_putnbr_base_ul_fd(unsigned long nbr, char *base, int fd)
{
	size_t	base_len;

	base_len = ft_strlen(base);
	print_base(nbr, base_len, base, fd);
}
