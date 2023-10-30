/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ul_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 03:32:23 by aklein            #+#    #+#             */
/*   Updated: 2023/10/30 04:14:25 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_ul_fd(unsigned long n, int fd)
{
	static int iteration = 1;

	if (n != 0)
	{
		iteration = 0;
		ft_putnbr_ul_fd(abs_val(n / 10), fd);
		ft_putchar_fd(abs_val(n % 10) + '0', fd);
	}
	else if (iteration)
		ft_putchar_fd('0', fd);
}