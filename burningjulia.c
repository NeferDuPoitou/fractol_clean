#include "MLX42.h"
#include "fractol.h"
#include "defines.h"

t_scaled_pixel	burningjuliacalc_and_color(int a, int b, t_fol *f)
{
	t_cpx			z;
	long double		retmp;
	t_scaled_pixel	spx;
	int				color;

	spx.re = scaled_pixel(a, 'x', f);
	spx.im = scaled_pixel(b, 'y', f);
	spx.iteration = f->itermap[a][b];
	if (f->itermap[a][b] != 0)
		return (spx);
	spx.iteration = 0;
	z.re = spx.re;
	z.im = spx.im;
	while (z.re * z.re + z.im * z.im <= 4.0 && spx.iteration < f->max_iter)
	{
		retmp = z.re * z.re - z.im * z.im + f->j_consts.re;
		z.im = fabsl(2 * z.re * z.im) + f->j_consts.im;
		z.re = retmp;
		spx.iteration++;
	}
	f->itermap[a][b] = spx.iteration;
	color = starrynight_palette(spx, f);
	mlx_put_pixel(f->image, a, b, color);
	return (spx);
}
