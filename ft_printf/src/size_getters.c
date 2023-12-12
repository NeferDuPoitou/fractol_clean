/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_getters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gecko <Gecko@chezmoi.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:50:24 by Gecko             #+#    #+#             */
/*   Updated: 2023/08/11 12:50:26 by Gecko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	get_digits_count_int(int nb, t_flags *flags)
{
	int	count;

	is_zero(nb, flags);
	if (nb < 0)
	{
		flags->is_negative = 1;
		if (nb == -2147483648)
			return (10);
		else
			nb = -nb;
	}
	count = 0;
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	if (count == 0)
		count = 1;
	return (count);
}

int	get_digits_count_u(unsigned int nb, t_flags *flags)
{
	int	count;

	is_zero(nb, flags);
	count = 0;
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	if (count == 0)
		count = 1;
	return (count);
}

int	get_hex_adress_len(const void *ptr, t_flags *flags)
{
	unsigned long long	address;
	int					len;

	if (ptr == NULL)
	{
		flags->isnull = 1;
		return (5);
	}
	else
	{
		address = (unsigned long long)ptr;
		len = 2;
		while (address > 0)
		{
			len++;
			address /= 16;
		}
		return (len);
	}
}

int	get_hex_digits(int nb, t_flags *flags)
{
	int	shift;
	int	leading_zero;
	int	count;
	int	hex_digit;

	is_zero(nb, flags);
	shift = 28;
	leading_zero = 1;
	count = 0;
	if (nb < 0)
		nb = 0xFFFFFFFF + nb + 1;
	while (shift >= 0)
	{
		hex_digit = (nb >> shift) & 0xF;
		if (hex_digit != 0 || !leading_zero)
		{
			count++;
			leading_zero = 0;
		}
		shift -= 4;
	}
	if (leading_zero)
		count++;
	return (count);
}

int	get_size(va_list args, t_flags *flags)
{
	va_list	va_temp;
	int		local_len;

	local_len = 0;
	va_copy(va_temp, args);
	if (flags->format == 'd' || flags->format == 'i')
		local_len = get_digits_count_int(va_arg(va_temp, int), flags);
	else if (flags->format == 'u')
		local_len = get_digits_count_u(va_arg(va_temp, int), flags);
	else if (flags->format == 'x' || flags->format == 'X')
		local_len = get_hex_digits(va_arg(va_temp, int), flags);
	else if (flags->format == 'p')
		local_len = get_hex_adress_len(va_arg(va_temp, void *), flags);
	else if (flags->format == 's')
		local_len = get_str_size(va_arg(va_temp, char *), flags);
	else if (flags->format == 'c')
		local_len = 1;
	va_end(va_temp);
	return (local_len);
}
