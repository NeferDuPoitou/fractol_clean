/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achatzit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:40:33 by achatzit          #+#    #+#             */
/*   Updated: 2023/10/19 09:43:17 by achatzit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*p;
	size_t		total_size;
	size_t		size_max;

	size_max = (size_t)-1;
	if (size != 0)
	{
		if (nmemb > size_max / size)
			return (NULL);
	}
	total_size = nmemb * size;
	if ((nmemb == 0 && size != 0) || (nmemb == 0 && size == 0) \
	|| (nmemb != 0 && size == 0))
	{
		p = malloc(0);
		return (p);
	}
	else if (nmemb != 0 && size == 0)
		return (NULL);
	p = malloc(total_size);
	if (!p)
		return (NULL);
	ft_bzero(p, total_size);
	return (p);
}
