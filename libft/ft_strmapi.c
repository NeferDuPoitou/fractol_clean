/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achatzit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:49:48 by achatzit          #+#    #+#             */
/*   Updated: 2023/10/19 11:36:44 by achatzit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*tab;
	int		i;

	if (!s || !f)
		return (NULL);
	i = 0;
	tab = ft_strdup(s);
	if (!tab)
		return (NULL);
	while (tab[i])
	{
		tab[i] = f(i, s[i]);
		i++;
	}
	return (tab);
}
