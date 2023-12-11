/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achatzit <achatzit@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:54:40 by achatzit          #+#    #+#             */
/*   Updated: 2023/12/11 12:45:05 by achatzit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	general_instructions(void)
{
	ft_printf("Welcome to my Fractol ! here are some helpful instructions to \
get started :\n\nThe program takes the fractal name as parameter, \n \
followed by optional constants for the Julia ensembles.\n\
Set names are : \n.mandelbrot\n.julia\n.burningjulia\n.buddhabrot\n \
The mandelbrot julia ensemble can receive 2 constants as args.\n\
-c for controls");
	exit(EXIT_SUCCESS);
}

void	keybinds_instructions(void)
{
	ft_printf("QWES/arrow key : move around\n\
K/L : zoom in/out\n\
M/N : increase/decrease the precision by a little bit\n\
X/Z : increase/decrease the precision by a lot\n\
0-9 : switch color palette\n\
B   : switch from Mariani-Silver algorithm to brute force\n\
R   : reset the fractal");
	exit(EXIT_SUCCESS);
}
