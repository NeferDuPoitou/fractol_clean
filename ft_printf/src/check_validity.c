/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gecko <Gecko@chezmoi.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:30:28 by Gecko             #+#    #+#             */
/*   Updated: 2023/08/09 19:19:08 by Gecko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	format_isvalid(char format)
{
	if (format == 'c' || format == 's' || format == 'p' || format == 'd' \
	|| format == 'i' || format == 'u' || format == 'x' || format == 'X' \
	|| format == '%')
		return (1);
	else
		return (0);
}

int	flag_isvalid(char flag)
{
	if (flag == '#' || flag == '-' || flag == ' ' || flag == '0' || \
	flag == '+' || flag == '|')
		return (1);
	else
		return (0);
}
