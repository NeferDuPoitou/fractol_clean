/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achatzit <achatzit@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:31:25 by achatzit          #+#    #+#             */
/*   Updated: 2023/12/11 14:24:48 by achatzit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define SCALEDX_MIN -1.00
# define SCALEDX_MAX  1.00
# define SCALEDY_MIN -1.00
# define SCALEDY_MAX  1.00
# define ABS_SCALED_X 2.00
# define ABS_SCALED_Y 2.00

# define LSD 0
# define VANDETTA 1
# define STARRYNIGHT 2
# define RAZER 3
# define MUSEUM 4
# define ARROWS 5
# define GREENERY 6

# define R 0
# define G 1
# define B 2

# define RED 0xff0000ff
# define GRN 0x00ff00ff
# define BLU 0x0000ffff

# define MANDELBROT 0
# define JULIA 1
# define BURNINGSHIP 2
# define BURNINGJULIA 3
# define BUDDHA 4

# define ARG_HELP "-h"
# define ARG_CTRL "-c"
# define ARG_MANDEL "mandelbrot"
# define ARG_JULIA "julia"
# define ARG_BURNINGSHIP "burningship"
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

# define ALLOC_FAIL "failed allocating memory, better call an exorcist"

// box quadrants
# define WHOLE_SCREEN 0
# define TOP_RIGHT 1
# define TOP_LEFT 2
# define BOTTOM_LEFT 3
# define BOTTOM_RIGHT 4

#endif
