#include "MLX42.h"
#include "fractol.h"
#include "defines.h"
#include <stdlib.h>

static int	get_fractal_type(char *s)
{
	if (!ft_strcmp(s, ARG_MANDEL))
		return (MANDELBROT);
	if (!ft_strcmp(s, ARG_JULIA))
		return (JULIA);
	if (!ft_strcmp(s, ARG_BURNINGSHIP))
		return (BURNINGSHIP);
	if (!ft_strcmp(s, ARG_BURNINGJULIA))
		return (BURNINGJULIA);
	if (!ft_strcmp(s, ARG_BUDDHA))
		return (BUDDHA);
	return (0);
}

void	struct_init(t_fol *f, int argc, char **argv)
{
	f->fractal_type = get_fractal_type(argv[1]);
	f->wid = 1.5;
	f->heig = 1.2;
	f->zoom = 1.00;
	f->scaled_pixel.im = 0.00;
	f->scaled_pixel.re = 0.00;
	f->win_width = 1600;
	f->win_heigth = 1600;
	f->bailout = 4.0;
	f->max_iter = 500;
	f->cur_color = 0;
	f->buddha.i = 0;
	f->buddha.j = 0;
	f->buddha_iters = 1000;
	f->julia_set = 0;
	if (f->julia_has_consts == 1)
	{
		f->j_consts_static.re = atof(argv[2]);
		f->j_consts_static.re = atof(argv[3]);
	}
}
