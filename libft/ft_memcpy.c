/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achatzit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:46:28 by achatzit          #+#    #+#             */
/*   Updated: 2023/10/19 11:34:21 by achatzit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*p_dest;
	const char	*p_src;

	if (!dest && !src)
		return (NULL);
	p_dest = dest;
	p_src = src;
	while (n--)
	{
		*p_dest = *p_src;
		p_dest++;
		p_src++;
	}
	return (dest);
}
