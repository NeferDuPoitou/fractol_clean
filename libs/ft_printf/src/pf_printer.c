/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gecko <Gecko@chezmoi.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 22:30:02 by Gecko             #+#    #+#             */
/*   Updated: 2023/08/09 23:09:48 by Gecko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_variable(va_list args, t_flags *flags, int *len)
{
	void	*arg;

	if (!check_isnull_and_print(flags, len))
	{
		if (flags->format == 'c')
			ft_putchar_len(va_arg(args, int), len);
		else if (flags->format == 'd' || flags->format == 'i')
			ft_putnbr((long int)va_arg(args, int), flags, len);
		else if (flags->format == 's')
			ft_putstr(va_arg(args, const char *), flags->precision, len);
		else if (flags->format == 'x' || flags->format == 'X')
			putnbr_base16(va_arg(args, int), flags, len);
		else if (flags->format == 'p')
		{
			arg = va_arg(args, void *);
			print_memory_adress(arg, flags, len);
		}
		else if (flags->format == 'u')
			unsigned_putnbr(va_arg(args, unsigned int), flags, len);
		else if (flags->format == '%')
			ft_putchar_len('%', len);
	}
	else
		va_arg(args, void *);
}

void	prefix_flags_print(va_list args, t_flags *flags, int *len)
{
	int	n;

	if (flags->format == 'd' || flags->format == 'i' || \
	flags->format == 'x' || flags->format == 'X')
		n = va_arg(args, int);
	if ((flags->format == 'd' || flags->format == 'i') && \
	flags->pos_spaced == 1)
	{
		if (n >= 0)
			ft_putchar_len(' ', len);
	}
	if ((flags->format == 'd' || flags->format == 'i') && \
	flags->force_sign == 1 && (flags->min_width == 0 || \
	flags->left_justify == 1))
	{
		if (n >= 0)
			ft_putchar_len('+', len);
	}
	if ((flags->format == 'x' || flags->format == 'X') && \
	flags->base_prefix == 1 && flags->min_width == 0)
	{
		if (n != 0)
			print_base_prefix(flags, len);
	}
}

void	pf_printer(va_list args, t_flags *flags, int *len)
{
	va_list	arg_temp;
	va_list	arg_temp_bis;

	va_copy(arg_temp, args);
	va_copy(arg_temp_bis, args);
	if (flags->left_justify == 0)
		min_width_right_justify(args, flags, len);
	precision_filler_left_justify(args, flags, len);
	prefix_flags_print(arg_temp, flags, len);
	precision_filler_right_justify(args, flags, len);
	print_variable(args, flags, len);
	if (flags->left_justify == 1)
		min_width_left_justify(arg_temp_bis, flags, len);
	va_end(arg_temp);
	va_end(arg_temp_bis);
}
