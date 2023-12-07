#include "MLX42.h"
#include "fractol.h"
#include "defines.h"
#include "libft.h"
#include <signal.h>

int mandelcalc_and_color(int a, int b, long double scaled_x, t_fol *f)
{
	t_cpx z;
	long double retmp;
	long double scaled_y;
	int iteration;
	z.re = 0;
	z.im = 0;
	iteration = 0;
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

static int island_finished(int x, int y, int start_x, int start_y)
{
	return (x == start_x && y == start_y);
}

static void color_island(int **itermap, t_fol *f)
{
	int x;
	int y;

	x = 0;
	while (itermap[x++][y] < f->win_width)
	{
		y = 0;
		while (itermap[x][y++] < f->win_heigth)
		{
			if (itermap[x][y] == f->max_iter)
			{
				while (itermap[x][y++] == f->max_iter && itermap[x][y] < f->win_heigth)
				{
					mlx_put_pixel(f->image, x, y, 0x000000ff);
				}
			}
		}
	}
}

static int	escaped_boundary(int x, int y, int **itermap, t_fol *f)
{
	// Check if the current pixel is at the maximum iteration
	if (itermap[x][y] == f->max_iter) {
	// Check if at least one neighboring pixel is not at the maximum iteration
	return (
	(x + 1 < f->win_width && itermap[x + 1][y] != f->max_iter) &&
	(y + 1 < f->win_heigth && itermap[x][y + 1] != f->max_iter) &&
	(x - 1 >= 0 && itermap[x - 1][y] != f->max_iter) &&
	(y - 1 >= 0 && itermap[x][y - 1] != f->max_iter) &&
	(x + 1 < f->win_width && y + 1 < f->win_heigth && itermap[x + 1][y + 1] != f->max_iter) &&
	(x - 1 >= 0 && y + 1 < f->win_heigth && itermap[x - 1][y + 1] != f->max_iter) &&
	(x + 1 < f->win_width && y - 1 >= 0 && itermap[x + 1][y - 1] != f->max_iter) &&
	(x - 1 >= 0 && y - 1 >= 0 && itermap[x - 1][y - 1] != f->max_iter)
	);
	}
	// If the current pixel is not at the maximum iteration, return 0
	return 0;
}

static void	boundary_tracing(int x, int y, long double scaled_x, t_fol *f)
{
	static int	first_time = 1;
	int		iter;
	static int	start_x = -1;
	static int	start_y = -1;

	start_x = -1;
	start_y = -1;
	
	if ((x < 0 || x >= f->win_width || y < 0 || y >= \
	f->win_heigth) || (f->itermap[x][y] != 0))
		return ;
	iter = mandelcalc_and_color(x, y, scaled_x, f);
	if (island_finished(x, y, start_x, start_y))
	{
		first_time = 1;
		ft_printf("youpi :)");
		color_island(f->itermap, f);
		return ;
	}
	if (iter == f->max_iter && !escaped_boundary(x, y, f->itermap, f))
	{
		if (first_time == 1)
		{
			first_time = 0;
			start_x = x;
			start_y = y;
			ft_printf("startx : %d\nstarty : %d\n", start_x, start_y);
		}
		mlx_put_pixel(f->image, x, y, 0xff0000ff);
		boundary_tracing(x + 1, y, scaled_x, f);
		boundary_tracing(x, y + 1, scaled_x, f);
		boundary_tracing(x - 1, y, scaled_x, f);
		boundary_tracing(x, y - 1, scaled_x, f);

		boundary_tracing(x + 1, y + 1, scaled_x, f);
		boundary_tracing(x - 1, y + 1, scaled_x, f);
		boundary_tracing(x + 1, y - 1, scaled_x, f);
		boundary_tracing(x - 1, y - 1, scaled_x, f);
	}
}

void	mandelflood(t_fol *f)
{
	t_pixel px;
	int iterations;

	px.x = 0;
	f->itermap = calloc(f->win_width, sizeof(int*));
	for (int i = 0; i < f->win_width; i++)
	{
		f->itermap[i] = calloc(f->win_heigth, sizeof(int));
	}
        while (px.x < f->win_width)
	{
		px.y = 0;
		f->itermap[px.x] = (int *)calloc(f->win_heigth, sizeof(int));
		while (px.y < f->win_heigth)
		{
			boundary_tracing(px.x, px.y, scaled_pixel(px.x, 'x', f), f);
			px.y++;
		}
		px.x++;
	}
	/* for (int i = 0; i < f->win_width; i++)
	{
		for(int j = 0; j < f->win_heigth; j++)
		{
			ft_printf("%2d", f->itermap[i][j]);
		}
		ft_printf("\n");
	} */
}
