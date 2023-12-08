#include "MLX42.h"
#include "fractol.h"
#include "defines.h"

int	burningjuliacalc_and_color(int a, int b, t_fol *f)
{
	t_cpx z;
	long double retmp;
	long double scaled_x;
	long double scaled_y;
	int iteration;
	int color;

	if (f->itermap[a][b] != 0)
			return f->itermap[a][b];
	iteration = 0;
	scaled_x = scaled_pixel(a, 'x', f);
	scaled_y = scaled_pixel(b, 'y', f);
	z.re = scaled_x;
	z.im = scaled_y;
	while (z.re * z.re + z.im * z.im <= 4.0 && iteration < f->max_iter)
	{
		retmp = z.re * z.re - z.im * z.im + f->j_consts.re;
		z.im = fabsl(2 * z.re * z.im) + f->j_consts.im;
		z.re = retmp;
		iteration++;
	}
	f->itermap[a][b] = iteration;
	color = starrynight_palette(iteration, f);
	mlx_put_pixel(f->image, a, b, color);
	return iteration;
}
