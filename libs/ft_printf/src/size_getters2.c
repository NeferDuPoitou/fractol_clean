/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_getters2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achatzit <achatzit@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:49:42 by Gecko             #+#    #+#             */
/*   Updated: 2023/12/11 20:32:12 by achatzit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	is_zero(int nb, t_flags *flags)
{
	if (nb == 0)
		flags->is_zero = 1;
}

int	get_str_size(char *s, t_flags *flags)
{
	int	i;
	int	size;
	int	len;

	if (s == NULL)
	{
		flags->isnull = 1;
		return (6);
	}
	len = 0;
	size = 0;
	len = ft_strlien(s);
	if (flags->precision == -1)
		size = len;
	else
	{
		i = 0;
		while (i < flags->precision && i < len)
		{
			size++;
			i++;
		}
	}
	return (size);
}
