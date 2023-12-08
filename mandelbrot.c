#include "MLX42.h"
#include "fractol.h"
#include "defines.h"
#include "libft.h"

int mandelcalc_and_color(int a, int b, t_fol *f)
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
	z.re = 0;
	z.im = 0;
	while (z.re * z.re + z.im * z.im <= 4.0 && iteration < f->max_iter)
	{
		retmp = z.re * z.re - z.im * z.im + scaled_x;
		z.im = 2 * z.re * z.im + scaled_y;
		z.re = retmp;
		iteration++;
	}
	f->itermap[a][b] = iteration;
	color = starrynight_palette(iteration, f);
	mlx_put_pixel(f->image, a, b, color);
	return iteration;
}
