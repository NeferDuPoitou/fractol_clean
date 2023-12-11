/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gecko <Gecko@chezmoi.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:39:58 by Gecko             #+#    #+#             */
/*   Updated: 2023/08/09 23:23:58 by Gecko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	check_flags(const char **str, t_flags *flags)
{
	while (flag_isvalid(**str))
	{
		if (**str == '#')
			flags->base_prefix = 1;
		else if (**str == '-')
			flags->left_justify = 1;
		else if (**str == ' ')
			flags->pos_spaced = 1;
		else if (**str == '0')
			flags->zero_fill = 1;
		else if (**str == '+')
			flags->force_sign = 1;
		(*str)++;
	}
}

void	check_width(const char **str, t_flags *flags)
{
	int	width;

	width = 0;
	while (**str >= '0' && **str <= '9')
	{
		width += **str - '0';
		width *= 10;
		(*str)++;
	}
	flags->min_width = width / 10;
}

void	check_precision(const char **str, t_flags *flags)
{
	int	prec;

	prec = 0;
	if (**str == '.')
	{
		flags->period = 1;
		(*str)++;
		while (**str >= '0' && **str <= '9')
		{
			prec += **str - '0';
			prec *= 10;
			(*str)++;
		}
		flags->precision = prec / 10;
	}
	else
		flags->precision = -1;
}

int	check_format(char c, t_flags *flags)
{
	if (format_isvalid(c))
	{
		flags->format = c;
		return (1);
	}
	else
	{
		return (0);
	}
}

int	flags_parser(const char **str, t_flags *flags)
{
	check_flags(str, flags);
	check_width(str, flags);
	check_precision(str, flags);
	if (!check_format(**str, flags))
		return (0);
	return (1);
}
