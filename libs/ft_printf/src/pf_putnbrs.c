/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gecko <Gecko@chezmoi.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:05:43 by Gecko             #+#    #+#             */
/*   Updated: 2023/08/10 12:45:31 by Gecko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putnbr(long int nb, t_flags *flags, int *len)
{
	if (nb == 0 && flags->period == 1 && flags->precision == 0 && \
	flags->format != 'f')
		return ;
	if (nb < 0)
	{
		if (flags->period == 0 && (flags->zero_fill == 0 || \
		flags->min_width <= get_digits_count_int(nb, flags) + 1))
			ft_putchar_len('-', len);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10, flags, len);
		ft_putchar_len(nb % 10 + '0', len);
	}
	else
		ft_putchar_len(nb + '0', len);
}

void	unsigned_putnbr(unsigned int nb, t_flags *flags, int *len)
{
	if (nb == 0 && flags->period == 1 && flags->precision == 0)
		return ;
	if (nb > 9)
	{
		ft_putnbr(nb / 10, flags, len);
		ft_putchar(nb % 10 + '0');
		(*len)++;
	}
	else
	{
		ft_putchar(nb + '0');
		(*len)++;
	}
}
