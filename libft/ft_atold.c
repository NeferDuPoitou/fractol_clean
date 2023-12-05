/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achatzit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:40:00 by achatzit          #+#    #+#             */
/*   Updated: 2023/10/18 14:40:06 by achatzit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

long double ft_atold(const char *nptr)
{
    int neg = 1;
    long double ret = 0.0;

    // Skip leading whitespaces
    while (ft_isspace((unsigned char)*nptr))
        nptr++;

    // Handle the sign
    if (*nptr == '-' || *nptr == '+')
    {
        neg = (*nptr == '-') ? -1 : 1;
        nptr++;
    }

    // Process digits before the decimal point
    while (ft_isdigit((unsigned char)*nptr))
    {
        ret = ret * 10.0 + (*nptr - '0');
        nptr++;
    }

    // Process digits after the decimal point
    if (*nptr == '.')
    {
        nptr++; // Skip the decimal point

        long double decimalMultiplier = 0.1;

        while (ft_isdigit((unsigned char)*nptr))
        {
            ret += (*nptr - '0') * decimalMultiplier;
            decimalMultiplier *= 0.1;
            nptr++;
        }
    }

    // Handle scientific notation if present
    if (*nptr == 'e' || *nptr == 'E')
    {
        int exponent = 0;
        nptr++; // Skip 'e' or 'E'

        // Handle the exponent sign
        if (*nptr == '-' || *nptr == '+')
        {
            exponent = (*nptr == '-') ? -1 : 1;
            nptr++;
        }

        // Process the exponent digits
        while (ft_isdigit((unsigned char)*nptr))
        {
            exponent = exponent * 10 + (*nptr - '0');
            nptr++;
        }

        // Apply the exponent
        ret *= powl(10.0, exponent);
    }

    return ret * neg;
}
