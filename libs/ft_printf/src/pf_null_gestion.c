/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_null_gestion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gecko <Gecko@chezmoi.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 22:07:27 by Gecko             #+#    #+#             */
/*   Updated: 2023/08/11 22:07:29 by Gecko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	check_isnull_and_print(t_flags *flags, int *len)
{
	if (flags->isnull == 1)
	{
		if (flags->format == 's')
		{
			if (flags->precision >= 6)
				ft_putstr("(null)", -1, len);
			else if (flags->period == 1)
				ft_putstr("", -1, len);
			else
				ft_putstr("(null)", -1, len);
		}
		else if (flags->format == 'p')
			ft_putstr("(nil)", -1, len);
		return (1);
	}
	else
		return (0);
}
