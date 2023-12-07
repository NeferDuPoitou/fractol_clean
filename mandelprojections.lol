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
	{
		if (f->itermap[a][b] == f->max_iter)
			return f->max_iter;
		else
			return 1;
	}
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

static void color_island(int **itermap, t_fol *f)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < f->win_width)
	{
		y = 0;
		while (y < f->win_heigth)
		{
			if (itermap[x][y] == f->max_iter)
			{
				mlx_put_pixel(f->image, x, y, 0xff0000ff);
					itermap[x][y] = f->max_iter;
				y++;
				while (y < f->win_heigth && itermap[x][y] == 0)
				{
					mlx_put_pixel(f->image, x, y, 0xff0000ff);
					itermap[x][y] = f->max_iter;
					y++;
				}

			}
			y++;
		}
		x++;
	}
}

static void last_pass(int **itermap, t_fol *f)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < f->win_width)
	{
		y = 0;
		while (y < f->win_heigth)
		{
			if (itermap[x][y] == 0)
				mlx_put_pixel(f->image, x, y, BLU);
				// mandelcalc_and_color(x, y, f);
			y++;
		}
		x++;
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
			if(mandelcalc_and_color(px.x, px.y, f) == f->max_iter)
				break ;
			px.y++;
		}
		px.x++;
	}
	px.x = 0;
	while (px.x < f->win_width)
	{
		px.y = f->win_heigth;
		while (px.y > 0)
		{
			px.y--;
			if(mandelcalc_and_color(px.x, px.y, f) == f->max_iter)
				break ;
		}
		px.x++;
	} 
	px.y = 0;
	while (px.y < f->win_heigth)
	{
		px.x = 0;
		while (px.x < f->win_width)
		{
			if(mandelcalc_and_color(px.x, px.y, f) == f->max_iter)
				break ;
			px.x++;
		}
		px.y++;
	}
	px.y = 0;
	 while (px.y < f->win_heigth)
	{
		px.x = f->win_width;
		while (px.x > 0)
		{
			px.x--;
			if(mandelcalc_and_color(px.x, px.y, f) == f->max_iter)
				break ;
		}
		px.y++;
	}


	 while (px.y < f->win_heigth)
	{
		px.x = f->win_width;
		while (px.x > 0)
		{
			px.x--;
			if(mandelcalc_and_color(px.x, px.y, f) == f->max_iter)
				break ;
		}
		px.y++;
	}
	/* px.y = 0;
	 while (px.y < f->win_heigth)
	{
		px.x = f->win_width;
		while (px.x > 0)
		{
			px.x--;
			if(mandelcalc_and_color(px.x, px.y, f) == f->max_iter)
				break ;
		}
		px.y++;
	} */

	for (int i = 0; i < f->win_width; i++)
    {
        px.x = i;
        px.y = 0;
        while (px.x < f->win_width && px.y < f->win_heigth)
        {
            if (mandelcalc_and_color(px.x, px.y, f) == f->max_iter)
                break;
            px.x++;
            px.y++;
        }
    }

    // Check top-right to bottom-left diagonal
    for (int i = 0; i < f->win_width; i++)
    {
        px.x = i;
        px.y = 0;
        while (px.x >= 0 && px.y < f->win_heigth)
        {
            if (mandelcalc_and_color(px.x, px.y, f) == f->max_iter)
                break;
            px.x--;
            px.y++;
        }
    }

    // Check bottom-left to top-right diagonal
    for (int i = 0; i < f->win_heigth; i++)
    {
        px.x = 0;
        px.y = i;
        while (px.x < f->win_width && px.y < f->win_heigth)
        {
            if (mandelcalc_and_color(px.x, px.y, f) == f->max_iter)
                break;
            px.x++;
            px.y++;
        }
    }

    // Check bottom-right to top-left diagonal
    for (int i = 0; i < f->win_heigth; i++)
    {
        px.x = f->win_width - 1;
        px.y = i;
        while (px.x >= 0 && px.y < f->win_heigth)
        {
            if (mandelcalc_and_color(px.x, px.y, f) == f->max_iter)
                break;
            px.x--;
            px.y++;
        }
    }



	color_island(f->itermap, f);	
	last_pass(f->itermap, f);
	/* for (int i = 0; i < f->win_width; i++)
	{
		for(int j = 0; j < f->win_heigth; j++)
		{
			ft_printf("%2d", f->itermap[i][j]);
		}
		ft_printf("\n");
	} */
}
