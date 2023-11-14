/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_putstr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:07:09 by aklein            #+#    #+#             */
/*   Updated: 2023/11/14 21:04:58 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_safe_putstr_fd(char *s, int fd)
{
	if (!s || !fd)
		return (0);
	while (*s)
	{
		if (!write(fd, s, 1))
			return (0);
		s++;
	}
return (1);
}
