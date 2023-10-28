/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:39:46 by aklein            #+#    #+#             */
/*   Updated: 2023/10/28 20:32:24 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	abs_val(int n)
{
	if (n >= 0)
		return (n);
	return (n * -1);
}

void	ft_putnbr_fd(int n, int fd)
{
	static int	iteration = 1;

	if (n < 0)
		ft_putchar_fd('-', fd);
	if (n != 0)
	{
		iteration = 0;
		ft_putnbr_fd(abs_val(n / 10), fd);
		ft_putchar_fd(abs_val(n % 10) + '0', fd);
	}
	else if (iteration)
		ft_putchar_fd('0', fd);
}
