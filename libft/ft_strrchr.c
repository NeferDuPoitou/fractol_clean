/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achatzit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:50:33 by achatzit          #+#    #+#             */
/*   Updated: 2023/10/18 14:50:34 by achatzit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	size;

	size = ft_strlen(s);
	if ((unsigned char)c == 0)
		return ((char *)s + size);
	while (size >= 0)
	{
		if (s[size] == (unsigned char)c)
			return ((char *)s + size);
		size--;
	}
	return (NULL);
}
