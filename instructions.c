#include "fractol.h"
#include "defines.h"
#include <stdlib.h>

void	general_instructions(void)
{
	ft_printf("Welcome to my Fractol ! here are some helpful instructions to \
get started :\n\nThe program takes the fractal name as parameter, \n \
followed by optional constants for the Julia ensembles.\n\
Set names are : \n.mandelbrot\n.julia\n.burningjulia\n.buddhabrot\n \
The 2 Julia ensembles can receive 2 constants as args.");
	exit(EXIT_SUCCESS);
}
