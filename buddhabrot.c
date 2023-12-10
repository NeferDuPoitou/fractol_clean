/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddhabrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achatzit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:52:33 by achatzit          #+#    #+#             */
/*   Updated: 2023/12/10 10:52:35 by achatzit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "fractol.h"
#include "defines.h"

int first_pass(long double x, double y, t_fol *f)
{
    int iter;
    long double tmp_x;
    long double a;
    long double b;

    a = x;
    b = y;
	iter = 0;
    while (iter < f->buddha_iters)
    {
        tmp_x = pow(x, 2) - pow(y, 2) + a;
        y = 2 * x * y + b;
        x = tmp_x;
        if (x*x + y*y > 4)
            return true;
        iter++;
    }
    return false;
}

void populate_heatmap(long double x, double y, int ***img, t_fol *f)
{
    int iter = 0;
    long double tmp_x;
    long double a;
    long double b;
    int tx;
    int ty;
    unsigned char comp;
    char div = 0;

    a = x;
    b = y;

    while (iter < f->buddha_iters)
    {
        tmp_x = pow(x, 2) - pow(y, 2) + a;
        y = 2 * x * y + b;
        x = tmp_x;

        if (x*x + y*y > 4)
            return ;
        tx = (int)((x + 2.0) * f->win_width) / 3.0 * f->zoom;
        ty = (int)((y + 1.5) * f->win_heigth) / 3.0 * f->zoom;
        if (tx >= 0 && tx < f->win_width && ty >= 0 && ty < f->win_heigth)
        {
                    img[1][ty][tx]++;
        }
        iter++;
    }
}

void draw_buddha(t_fol *f, t_buddha buddha)
{
    int		h;
    int		w;
    long double	imag;
    int		pr = 0;

    for (h = 0; h < f->win_heigth; h++)
    {
        imag = ((long double)(h * (-3)) / f->win_heigth) + 1.5 * f->zoom;
        for (w = 0; w < f->win_width; w++)
        {
            if (first_pass(((long double)(w * 3) / f->win_width) - 2* f->zoom, imag, f))
                populate_heatmap(((long double)(w * 3) / f->win_width) - 2 * f->zoom, imag, buddha.img, f);
        }
        if (h * 100 / f->win_heigth != pr)
        {
            pr = h * 100 / f->win_heigth;
            ft_printf("%d%%\n", pr);
        }
    }
    ft_printf("100%%\n");
}

void    init_buddhacolors(t_buddha_color *b)
{
    b->start_color[0] = 0;
    b->start_color[1] = 0;
    b->start_color[2] = 0;
    b->end_color[0] = 255;
    b->end_color[1] = 105;
    b->end_color[2] = 180;
}

void    calc_color_and_put_pixel(t_fol *f, t_pixel px, t_buddha_color bcolor, long double intensity, int ***img, int buddha_iters)
{
            int comp;
            int final;

            comp = 0;
            init_buddhacolors(&bcolor);
            intensity = (double)img[1][px.x][px.y] / log2(buddha_iters);
            while (comp < 3)
            {
                bcolor.color[comp] = bcolor.start_color[comp] + (int)((bcolor.end_color[comp] - bcolor.start_color[comp]) * intensity);
		if (bcolor.color[comp] > 255)
			bcolor.color[comp] = 255;
                    comp++;
            }
            final = (bcolor.color[0] << 24) | (bcolor.color[1] << 16) | (bcolor.color[2] << 8) | 255;
            mlx_put_pixel(f->image, px.x, px.y, final);
}

void color_buddha(t_fol *f, int ***img)
{
    t_pixel px;
    t_buddha_color  bcolor;
    int final;
    long double intensity;
    int comp;

    px.y = 0;
    while (px.y < f->win_heigth)
    {
        px.x = 0;
        while (px.x < f->win_width)
        {
            calc_color_and_put_pixel(f, px, bcolor, intensity, img, f->buddha_iters);
            px.x++;
        }
        px.y++;
    }
}

void buddhabrot(t_fol *f)
{
	t_buddha	buddha;
	int		i;
	int		j;
	int		k;

	buddha.img = malloc(3 * sizeof(int **));
	for (i = 0; i < 3; i++)
	{
		buddha.img[i] = malloc(f->win_width * sizeof(int *));
		for (j = 0; j < f->win_heigth; j++)
		{
			buddha.img[i][j] = malloc(f->win_width * sizeof(int));
			for (int k = 0; k < f->win_width; k++)
			{
				buddha.img[i][j][k] = 0;
			}
		}
	}
	draw_buddha(f, buddha);
	color_buddha(f, buddha.img);
	mlx_image_to_window(f->mlx,f->image, 0, 0);
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < f->win_heigth; j++)
		{
			free(buddha.img[i][j]);
		}
		free(buddha.img[i]);
	}
	free(buddha.img);
}
