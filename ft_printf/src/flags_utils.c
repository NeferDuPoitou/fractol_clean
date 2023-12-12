/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gecko <Gecko@chezmoi.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:16:29 by Gecko             #+#    #+#             */
/*   Updated: 2023/11/01 22:31:35 by Gecko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	init_flags(t_flags *flags)
{
	flags->min_width = 0;
	flags->left_justify = 0;
	flags->zero_fill = 0;
	flags->base_prefix = 0;
	flags->force_sign = 0;
	flags->pos_spaced = 0;
	flags->period = 0;
	flags->precision = -1;
	flags->isnull = 0;
	flags->is_negative = 0;
	flags->is_zero = 0;
}

void	flag_error(t_flags *flags, int *len)
{
	ft_putstr("wrong format specifier.", -1, len);
	init_flags(flags);
}
