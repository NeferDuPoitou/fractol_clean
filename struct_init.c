#include "MLX42.h"
#include "fractol.h"
#include "defines.h"

static int	get_fractal_type(char *s)
{
	if (!ft_strcmp(s, ARG_MANDEL))
		return (MANDELBROT);
	if (!ft_strcmp(s, ARG_JULIA))
		return (JULIA);
	if (!ft_strcmp(s, ARG_BURNINGJULIA))
		return (BURNINGJULIA);
	if (!ft_strcmp(s, ARG_BUDDHA))
		return (BUDDHA);
	return (0);
}

void	init_julia_consts(t_cpx julia[])
{
	julia[0].re = -0.0666; //classic
	julia[0].im = 0.666;
	julia[1].re = -0.8; //dragon curve
	julia[1].im = 0.156;
	julia[2].re = 0.355; //elephant valley
	julia[2].im = 0.355;
	julia[3].re = 0.285; //spiral
	julia[3].im = 0.01;
	julia[4].re = 0.285; //double spiral
	julia[4].im = 0.013;
	julia[5].re = -0.624; //barber pole
	julia[5].im = 0.435;
	julia[6].re = -0.624; //saturn valley
	julia[6].im = 0.435;
}

void	struct_init(t_fol *f, int argc, char **argv)
{
	f->fractal_type = get_fractal_type(argv[1]);
	f->wid = 1.5;
	f->heig = 1.2;
	f->zoom = 1.00;
	f->scaled_pixel.im = 0.00;
	f->scaled_pixel.re = 0.00;
	f->win_width = 400;
	f->win_heigth = 400;
	f->bailout = 4.0;
	f->max_iter = 1000;
	f->cur_color = 0;
	f->buddha.i = 0;
	f->buddha.j = 0;
	f->buddha_iters = 1000;
	f->julia_set = 0;
	init_julia_consts(f->julia_consts);
}
