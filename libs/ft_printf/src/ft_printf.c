/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gecko <Gecko@chezmoi.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:08:23 by Gecko             #+#    #+#             */
/*   Updated: 2023/08/09 23:47:18 by Gecko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	var_parser(const char **format, va_list args, t_flags *flags, int *len)
{
	(*format)++;
	if (**format && flags_parser(format, flags))
	{
		pf_printer(args, flags, len);
		init_flags(flags);
	}
	else if (**format)
	{
		ft_putchar_len(**format, len);
		(*format)++;
	}
}

int	str_parser(const char *format, va_list args, t_flags *flags, int *len)
{
	while (*format)
	{
		if (*format == '%' && *format != '\0')
			var_parser(&format, args, flags, len);
		else
			ft_putchar_len(*format, len);
		if (*format)
			format++;
	}
	return (*len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	t_flags	flags;

	init_flags(&flags);
	len = 0;
	va_start(args, format);
	str_parser(format, args, &flags, &len);
	va_end(args);
	return (len);
}
