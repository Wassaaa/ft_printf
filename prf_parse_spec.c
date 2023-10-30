/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_parse_spec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:53:12 by aklein            #+#    #+#             */
/*   Updated: 2023/10/30 01:19:26 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_spec(t_print *print)
{
	size_t	i;

	i = 0;
	print->frm++;
	while (ft_strchr(SPECS, print->frm[i]) == 0)
	{
		if (!ft_strchr(FLAGS, print->frm[i]) && !ft_isdigit(print->frm[i]))
			return (0);
		i++;
	}
	print->spec_i = i;
	print->spec = print->frm[i];
	return (1);
}
