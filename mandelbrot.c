#include "MLX42.h"
#include "fractol.h"
#include "defines.h"
#include "libft.h"
#include <signal.h>

// int mandelcalc_and_color(int a, int b, long double scaled_x, t_fol *f)
int mandelcalc_and_color(int a, int b, t_fol *f)
{
	t_cpx z;
	long double retmp;
	long double scaled_x;
	long double scaled_y;
	int iteration;

	if (f->itermap[a][b] != 0)
			return f->itermap[a][b];
	z.re = 0;
	z.im = 0;
	iteration = 0;
	scaled_x = scaled_pixel(a, 'x', f);
	scaled_y = scaled_pixel(b, 'y', f);
	while (powl(z.re, 2) + powl(z.im, 2) <= 4.0 && iteration < f->max_iter)
	{
		retmp = powl(z.re, 2) - powl(z.im, 2) + scaled_x;
		z.im = 2 * z.re * z.im + scaled_y;
		z.re = retmp;
		iteration++;
	}
	f->itermap[a][b] = iteration;
	if (iteration == f->max_iter)
		mlx_put_pixel(f->image, a, b, 0x000000ff);
	else
		mlx_put_pixel(f->image, a, b, 0x00ff00ff);
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

	// if (debug >= 10)
	// 	return ;
	flagok = 1;
	x = start_x;
	width = end_x - start_x;
	height = end_y - start_y;
		// ft_printf("%-2d : %3d %3d %3d %3d\n, isbr : %d\n", debug, start_x, start_y, end_x, end_y, isbr);
	startiter = mandelcalc_and_color(start_x, start_y, f);
	if (height <= 4 || width <= 4)
	{
		while (++x < end_x)
		{
			y = start_y;
			while (++y < end_y)
			{
				// mandelcalc_and_color(x, y, f);
				mlx_put_pixel(f->image, x, y, 0xff00ffff);
				f->itermap[x][y] = 100;
			}
		}
		return ;
	}
	while (++x < end_x)
	{
		y = start_y;
		while (++y < end_y)
		{
			if (x == start_x + 1 || x == end_x - 1 || y == start_y + 1 || y == end_y - 1)
			{
				if (mandelcalc_and_color(x, y, f) != startiter)
					flagok = 0;
			}
		}
	}
	if (flagok == 1)
	{
		x = start_x;
		y = start_y;
		while (++x < end_x)
		{
			y = start_y;
			while (++y < end_y)
			{
				mlx_put_pixel(f->image, x, y, BLU);
				f->itermap[x][y] = 100;
			}
		}
		return ;
	}
	// ft_printf("flagok : %d\n", flagok);
	if (flagok == 0)
	{
		// debug++;
		// ft_printf("%-2d : %3d %3d %3d %3d\n, isbr : %d\n", debug, start_x, start_y, end_x, end_y, isbr);
		// mandelboxes(start_x, start_y, (end_x + start_x) / 2, (end_y + start_y) / 2, f);
		// mandelboxes((start_x + end_x) / 2, start_y, end_x, end_y / 2, f);
		mandelboxes(start_x, (start_y + end_y) / 2, end_x / 2, end_y, f);
		mandelboxes((end_y + start_x) / 2, (end_y + start_y) / 2, end_x, end_y, f);
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
	// bruteforce(f);
	/* for (int i = 0; i < f->win_width; i++)
	{
		for(int j = 0; j < f->win_heigth; j++)
		{
			ft_printf("%2d", f->itermap[i][j]);
		}
		ft_printf("\n");
	} */
}
