/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achatzit <achatzit@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:04:26 by Gecko             #+#    #+#             */
/*   Updated: 2023/12/11 20:34:01 by achatzit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_strlien(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putchar_len(char c, int *len)
{
	write(1, &c, 1);
	*len += 1;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_base_prefix(t_flags *flags, int *len)
{
	if (flags->format == 'x' && flags->base_prefix == 1)
	{
		write(1, "0x", 2);
		*len += 2;
	}
	else if (flags->format == 'X' && flags->base_prefix == 1)
	{
		write(1, "0X", 2);
		*len += 2;
	}
	else if (flags->force_sign == 1)
		ft_putchar_len('+', len);
	else if (flags->is_negative == 1 && flags->period == 0 && \
	flags->zero_fill == 1)
		ft_putchar_len('-', len);
}

void	ft_putstr(const char *s, int precision, int *len)
{
	int	i;
	int	s_len;

	if (s == NULL)
	{
		write(1, "(null)", 6);
		*len += 6;
		return ;
	}
	s_len = ft_strlien(s);
	if (precision == -1)
	{
		write(1, s, s_len);
		*len += ft_strlien(s);
	}
	else
	{
		i = 0;
		while (i < precision && i < s_len)
		{
			ft_putchar_len(s[i], len);
			i++;
		}
	}
}
