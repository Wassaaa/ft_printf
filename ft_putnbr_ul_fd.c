/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ul_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 03:32:23 by aklein            #+#    #+#             */
/*   Updated: 2023/10/30 19:17:34 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_ul_fd(unsigned long n, int fd)
{
	static int	iteration = 0;

	if (n != 0)
	{
		iteration++;
		ft_putnbr_ul_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else if (iteration == 0)
	{
		ft_putchar_fd('0', fd);
		return (1);
	}
	return (iteration);
}
