/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_fillers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gecko <Gecko@chezmoi.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 23:14:39 by Gecko             #+#    #+#             */
/*   Updated: 2023/08/12 23:14:40 by Gecko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	precision_filler_right_justify(va_list args, t_flags *flags, int *len)
{
	int	precision_filler;
	int	local_len;

	local_len = get_local_len(args, flags);
	if ((flags->format == 'd' || flags->format == 'i' || \
	flags->format == 'u' || flags->format == 'x' || flags->format == 'X') \
	&& flags->period == 1 && flags->left_justify == 0)
	{
		if (flags->is_negative == 1)
		{
			ft_putchar_len('-', len);
			precision_filler = 0;
		}
		else
			precision_filler = 1;
		local_len = get_local_len(args, flags);
		while (precision_filler <= flags->precision - local_len)
		{
			ft_putchar_len('0', len);
			precision_filler++;
		}
	}
}

void	precision_filler_left_justify(va_list args, t_flags *flags, int *len)
{
	int	local_len;
	int	precision_filler;

	local_len = get_local_len(args, flags);
	if ((flags->format == 'd' || flags->format == 'i' || \
	flags->format == 'u' || flags->format == 'x' || flags->format == 'X') \
	&& flags->period == 1 && flags->left_justify == 1)
	{
		if (flags->is_negative == 1)
		{
			ft_putchar_len('-', len);
			precision_filler = 0;
		}
		else
			precision_filler = 1;
		local_len = get_local_len(args, flags);
		while (precision_filler <= flags->precision - local_len)
		{
			ft_putchar_len('0', len);
			precision_filler++;
		}
	}
}
