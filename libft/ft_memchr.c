/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achatzit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:46:07 by achatzit          #+#    #+#             */
/*   Updated: 2023/10/18 14:46:08 by achatzit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p_src;
	unsigned char		ch;

	p_src = s;
	ch = c;
	while (n--)
	{
		if (*p_src == ch)
			return ((void *)p_src);
		p_src++;
	}
	return (NULL);
}
