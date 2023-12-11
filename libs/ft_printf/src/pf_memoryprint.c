/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_memoryprint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gecko <Gecko@chezmoi.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:08:11 by Gecko             #+#    #+#             */
/*   Updated: 2023/11/02 18:06:51 by Gecko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_memory_adress(const void *ptr, t_flags *flags, int *len)
{
	char				*hex_digits;
	unsigned long long	address;
	int					num_nibbles_and_dgtvalue;
	int					start_index;
	int					i;

	if (ptr == NULL)
	{
		ft_putstr("(nil)", -1, len);
		flags->isnull = 1;
		return ;
	}
	hex_digits = "0123456789abcdef";
	address = (unsigned long long)ptr;
	num_nibbles_and_dgtvalue = sizeof(void *) * 2;
	start_index = num_nibbles_and_dgtvalue - 1;
	while ((address >> (4 * start_index)) == 0 && start_index > 0)
		start_index--;
	ft_putstr("0x", -1, len);
	i = start_index;
	while (i >= 0)
	{
		num_nibbles_and_dgtvalue = (address >> (4 * i--)) & 0xF;
		ft_putchar_len(hex_digits[num_nibbles_and_dgtvalue], len);
	}
}
