/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achatzit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:31:25 by achatzit          #+#    #+#             */
/*   Updated: 2023/12/05 14:31:26 by achatzit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define WIDTH 1200
# define HEIGHT 1200

# define SCALEDX_MIN -2.00
# define SCALEDX_MAX  0.47
# define SCALEDY_MIN -2.00
# define SCALEDY_MAX  0.24

# define LSD 0
# define VANDETTA 1
# define STARRYNIGHT 2
# define RAZER 3
# define MUSEUM 4
# define ARROWS 5

# define R 0
# define G 1
# define B 2

# define RED (255 << 24 | 0 << 16 | 0 << 8 | 255)
# define GRN (0 << 24 | 255 << 16 | 0 << 8 | 255)
# define BLU (0 << 24 | 0 << 16 | 255 << 8 | 255)

# define MANDELBROT 0
# define JULIA 1
# define BURNINGJULIA 2
# define BUDDHA 3 

# define ARG_HELP "-h"
# define ARG_MANDEL "mandelbrot"
# define ARG_JULIA "julia"
# define ARG_BURNINGJULIA "burningjulia"
# define ARG_BUDDHA "buddhabrot"

# define NO_ARG "You need to specify arguments to the program.\n \
Use ./fractol -h for help"
# define WRONG_ARG "Wrong argument. ./fractol -h for help"
# define TOO_MANY_ARGS "Too many arguments. ./fractol -h for help"
# define ERR_JULIA_CONST "Julia constants needs to be between -2 and 2"
# define TOO_FEW_CONSTS "Julia ensembles need 2 constants"
# define DONT_BREAK "It appears that you might be trying to break my program.\
Good Luck"
# define BUDDHA_TOO_MANY_ARG "The buddha dont need any superfluous arguments"






#endif
