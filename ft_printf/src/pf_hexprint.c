/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_hexprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gecko <Gecko@chezmoi.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:07:10 by Gecko             #+#    #+#             */
/*   Updated: 2023/08/08 12:13:59 by Gecko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_hex_digit(int digit, t_flags *flags, int *len)
{
	char	hex_digit;

	hex_digit = '\0';
	if (digit < 10)
		hex_digit = '0' + digit;
	else
	{
		if (flags->format == 'x')
			hex_digit = 'a' + (digit - 10);
		else if (flags->format == 'X')
			hex_digit = 'A' + (digit - 10);
	}
	ft_putchar_len(hex_digit, len);
}

void	putnbr_base16(int nb, t_flags *flags, int *len)
{
	int	shift;
	int	leading_zero;
	int	hex_digit;

	if (nb == 0 && flags->period == 1 && flags->precision == 0)
	{
		flags->is_zero = 1;
		return ;
	}
	if (nb < 0)
		nb = 0xFFFFFFFF + nb + 1;
	shift = 28;
	leading_zero = 1;
	while (shift >= 0)
	{
		hex_digit = (nb >> shift) & 0xF;
		if (hex_digit != 0 || !leading_zero)
		{
			print_hex_digit(hex_digit, flags, len);
			leading_zero = 0;
		}
		shift -= 4;
	}
	if (leading_zero)
		ft_putchar_len('0', len);
}
