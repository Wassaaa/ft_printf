/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_handle_pad.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 02:13:41 by aklein            #+#    #+#             */
/*   Updated: 2023/11/12 03:01:54 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void handle_pad(t_print *print, t_flags *flags)
{
    while (--flags->width > 0)
    {
        ft_putchar_fd(flags->pad_c, print->fd);
        print->printed++;
    }
}