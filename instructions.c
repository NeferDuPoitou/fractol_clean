/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achatzit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:54:40 by achatzit          #+#    #+#             */
/*   Updated: 2023/12/10 10:54:43 by achatzit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "defines.h"
#include <stdlib.h>

void	general_instructions(void)
{
	ft_printf("Welcome to my Fractol ! here are some helpful instructions to \
get started :\n\nThe program takes the fractal name as parameter, \n \
followed by optional constants for the Julia ensembles.\n\
Set names are : \n.mandelbrot\n.julia\n.burningjulia\n.buddhabrot\n \
The mandelbrot julia ensemble can receive 2 constants as args.");
	exit(EXIT_SUCCESS);
}
