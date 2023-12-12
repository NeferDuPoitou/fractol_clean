/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_fillers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gecko <Gecko@chezmoi.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 11:41:35 by Gecko             #+#    #+#             */
/*   Updated: 2023/08/12 11:41:38 by Gecko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	get_local_len(va_list args, t_flags *flags)
{
	int	local_len;

	if (flags->precision == 0 && flags->is_zero == 0)
	{
		local_len = get_size(args, flags) + flags->pos_spaced + \
		flags->force_sign + (flags->base_prefix * 2) + \
		flags->is_negative - flags->is_zero;
	}
	else if (flags->format != 's')
	{
		local_len = get_size (args, flags) + flags->pos_spaced + \
		flags->force_sign + (flags->base_prefix * 2) + \
		flags->is_negative;
	}
	else
	{
		local_len = get_size(args, flags) + \
		flags->force_sign + (flags->base_prefix * 2) + \
		flags->is_negative;
	}
	return (local_len);
}

void	print_fillers(t_flags *flags, int local_len, int difference, int *len)
{
	while (local_len < flags->min_width - difference)
	{
		if (flags->zero_fill == 1 && flags->period != 1)
			ft_putchar_len('0', len);
		else if (flags->format != 's' || flags->period != 1 || \
		flags->isnull != 1)
			ft_putchar_len(' ', len);
		local_len++;
	}
}

void	get_difference(t_flags *flags, int *difference, int local_len)
{
	*difference = flags->precision - local_len;
	if (*difference < 0)
		*difference = 0;
	if (flags->is_negative == 0 && flags->precision == local_len - 1 && \
	flags->format != 's' && flags->is_zero != 1 && \
	flags->left_justify == 1)
		*difference = 0;
	if (flags->min_width > flags->precision && flags->precision >= \
	local_len && flags->is_negative == 1)
		*difference += 1;
	if (flags->format == 's' && flags->precision > local_len && \
	flags->min_width > local_len)
		*difference -= flags->precision - local_len;
}

void	min_width_right_justify(va_list args, t_flags *flags, int *len)
{
	int	local_len;
	int	difference;

	local_len = get_local_len(args, flags);
	get_difference(flags, &difference, local_len);
	if (flags->format == 's' && flags->period == 1 && flags->isnull == 1 \
	&& flags->precision >= 6 && flags->min_width != 0 \
	&& flags->left_justify == 0)
	{
		while (flags->min_width-- > local_len)
			ft_putchar_len(' ', len);
	}
	else if (flags->format == 's' && flags->period == 1 && flags->isnull == 1 \
	&& flags->precision < 6 && flags->min_width != 0 && \
	flags->left_justify == 0)
		while (flags->min_width--)
			ft_putchar_len(' ', len);
	else if ((flags->min_width > local_len) && flags->format != '%')
	{
		print_base_prefix(flags, len);
		print_fillers(flags, local_len, difference, len);
	}
}

void	min_width_left_justify(va_list args, t_flags *flags, int *len)
{
	int	local_len;
	int	difference;

	local_len = get_local_len(args, flags);
	get_difference(flags, &difference, local_len);
	if (flags->format == 's' && flags->period == 1 && flags->isnull == 1 \
	&& flags->precision >= 6 && flags->min_width != 0 && \
	flags->left_justify == 1)
	{
		while (flags->min_width-- > local_len)
			ft_putchar_len(' ', len);
	}
	else if (flags->format == 's' && flags->period == 1 && flags->isnull == 1 \
	&& flags->precision < 6 && flags->min_width != 0 && \
	flags->left_justify == 1)
		while (flags->min_width--)
			ft_putchar_len(' ', len);
	else if ((flags->min_width > local_len) && flags->format != '%')
	{
		if (flags->period == 1 && flags->is_zero == 1 && flags->precision == 0)
			ft_putchar_len(' ', len);
		print_fillers(flags, local_len, difference, len);
	}
}
