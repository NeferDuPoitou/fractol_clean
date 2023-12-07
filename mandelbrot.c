#include "MLX42.h"
#include "fractol.h"
#include "defines.h"
#include "libft.h"
#include <signal.h>


/* int check_is_correctly_good(t_fol *f, start_x, start_y, end_x, end_y)
{
	int iteration = f->itermap[start_x][start_y];
	while (++start_x < )
}
*/
// int mandelcalc_and_color(int a, int b, long double scaled_x, t_fol *f)
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
	z.re = 0;
	z.im = 0;
	iteration = 0;
	scaled_x = scaled_pixel(a, 'x', f);
	scaled_y = scaled_pixel(b, 'y', f);
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

void	mandelboxes(int start_x, int start_y, int end_x, int end_y, t_fol *f)
{
	int flagok;
	int width;
	int height;
	int startiter;
	int x;
	int y;
	static int debug = 0;

	flagok = 1;
	x = start_x;
	width = end_x - start_x;
	height = end_y - start_y;
	startiter = mandelcalc_and_color(start_x, start_y, f);
	if (abs(height) <= 2 || abs(width) <= 2)
	{
		while (++x < end_x)
		{
			y = start_y;
			while (++y < end_y)
			{
				f->itermap[x][y] = mandelcalc_and_color(x, y, f);
			}
		}
		return ;
	}
	while (++x < end_x)
	{
		y = start_y;
		while (++y < end_y)
		{
			if (x == start_x || x == end_x - 1 || y == start_y || y == end_y - 1)
			{
				if (mandelcalc_and_color(x, y, f) != startiter)
					flagok = 0;
			}
		}
	}
	if (flagok == 1)
	{
		x = start_x - 1;
		y = start_y - 1;
		int color = starrynight_palette(startiter, f);
		while (++x < end_x)
		{
			y = start_y - 1;
			while (++y < end_y)
			{
				f->itermap[x][y] = startiter;
				mlx_put_pixel(f->image, x, y, color);
			}
		}
		return ;
	}
	if (flagok == 0)
	{
		mandelboxes(start_x, start_y, (end_x + start_x) / 2, (end_y + start_y) / 2, f);
		mandelboxes((start_x + end_x) / 2, start_y, end_x, (end_y + start_y) / 2, f);
		mandelboxes(start_x, (start_y + end_y) / 2, (end_x + start_x) / 2, end_y, f);
		mandelboxes((end_x + start_x) / 2, (end_y + start_y) / 2, end_x, end_y, f);
	}
}

void	bruteforce(t_fol *f)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (++x < f->win_width)
	{
		y = 0;
		while (++y < f->win_heigth)
		{
			mandelcalc_and_color(x, y, f);
		}
	}
}

void	last_pass(t_fol *f)
{
	int x;
	int y;

	x = 0;
	while (++x < f->win_width)
	{
		y = 0;
		while (++y < f->win_heigth)
		{
			if (f->itermap[x][y] == 0)
			{
				f->itermap[x][y] = mandelcalc_and_color(x, y, f);
			}
		}
	}

}

void	mandelflood(int start_x, int start_y, int end_x, int end_y,t_fol *f)
{
	t_pixel px;
	int iterations;
	int flagok;
	int width;
	int height;
	int startiter;

	px.x = 0;
	f->itermap = calloc(f->win_width, sizeof(int*));
	for (int i = 0; i < f->win_width; i++)
	{
		f->itermap[i] = calloc(f->win_heigth, sizeof(int));
	}
	mandelboxes(start_x, start_y, end_x, end_y, f);
	last_pass(f);
	// bruteforce(f);
	/* for (int i = 0; i < f->win_width; i++)
	{
		for(int j = 0; j < f->win_heigth; j++)
		{
			ft_printf("%3d", f->itermap[i][j]);
		}
		ft_printf("\n");
	} */
}
