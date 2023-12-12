/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achatzit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:51:18 by achatzit          #+#    #+#             */
/*   Updated: 2023/10/19 11:35:22 by achatzit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tab;
	size_t	malloc_size;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		malloc_size = 1;
	else if (len > ft_strlen(s) - start)
		malloc_size = ft_strlen(s) - start + 1;
	else
		malloc_size = len + 1;
	tab = malloc(malloc_size * sizeof(char));
	if (!tab)
		return (NULL);
	i = 0;
	while (malloc_size - 1 && s[i])
	{
		tab[i] = *(s + start);
		start++;
		malloc_size--;
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
