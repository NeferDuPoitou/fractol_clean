/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddhabrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achatzit <achatzit@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:52:33 by achatzit          #+#    #+#             */
/*   Updated: 2023/12/11 14:44:09 by achatzit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

//The principle of the buddhabrot is as follows : map the path that every pixel
//take in the complex plane before reaching the iteration limit, and colorise
//an image based on the number of times a pixel has been stepped on.
//The classic buddhabrot only cares about the points that are part of the 
//mandelbrot set, hence the first_pass function used to determine if a point is 
//part of the set or not.
//removing that step will yield the anti-buddhabrot, where we map the path
//of each points that are not part of the set.

int	first_pass(long double x, long double y, t_fol *f)
{
	int			iter;
	long double	tmp_x;
	long double	a;
	long double	b;

	a = x;
	b = y;
	iter = 0;
	while (iter < f->buddha_iters)
	{
		tmp_x = pow(x, 2) - pow(y, 2) + a;
		y = 2 * x * y + b;
		x = tmp_x;
		if (x * x + y * y > 4)
			return (true);
		iter++;
	}
	return (false);
}

void	populate_heatmap(long double x, long double y, int ***img, t_fol *f)
{
	int				iter;
	long double		tmp_x;
	t_scaled_pixel	spx;
	int				tx;
	int				ty;

	spx.re = x;
	spx.im = y;
	iter = 0;
	while (iter < f->buddha_iters)
	{
		tmp_x = pow(x, 2) - pow(y, 2) + spx.re;
		y = 2 * x * y + spx.im;
		x = tmp_x;
		if (x * x + y * y > 4)
			return ;
		tx = (int)((x + 2.0) * f->win_width) / 3.0 * f->zoom;
		ty = (int)((y + 1.5) * f->win_heigth) / 3.0 * f->zoom;
		if (tx >= 0 && tx < (int)f->win_width && ty >= 0 && \
		ty < (int)f->win_heigth)
			img[1][ty][tx]++;
		iter++;
	}
}

void	draw_buddha(t_fol *f, t_buddha buddha)
{
	int			h;
	int			w;
	long double	imag;

	h = 0;
	while (h < (int)f->win_heigth)
	{
		imag = ((long double)(h * (-3)) / f->win_heigth) + 1.5 * f->zoom;
		w = 0;
		while (w < (int)f->win_width)
		{
			if (first_pass(((long double)(w * 3) / f->win_width) - 2 * \
			f->zoom, imag, f))
				populate_heatmap(((long double)(w * 3) / f->win_width) - \
				2 * f->zoom, imag, buddha.img, f);
			w++;
		}
		ft_printf("%d%%\n", h * 100 / f->win_heigth);
		h++;
	}
	ft_printf("100%%\n");
}

void	calc_color_and_put_pixel(t_fol *f, t_pixel px, t_buddha_color bcolor, \
								long double intensity)
{
	int	comp;
	int	final;

	comp = 0;
	init_buddhacolors(&bcolor);
	intensity = (double)f->buddha.img[1][px.x][px.y] / log2(f->buddha_iters);
	while (comp < 3)
	{
		bcolor.color[comp] = bcolor.start_color[comp] + \
		(int)((bcolor.end_color[comp] - bcolor.start_color[comp]) * intensity);
		if (bcolor.color[comp] > 255)
			bcolor.color[comp] = 255;
		comp++;
	}
	final = (bcolor.color[0] << 24) | (bcolor.color[1] << 16) \
		| (bcolor.color[2] << 8) | 255;
	mlx_put_pixel(f->image, px.x, px.y, final);
}

void	buddhabrot(t_fol *f)
{
	t_buddha	buddha;

	malloc_buddhaimg(&buddha, f);
	draw_buddha(f, buddha);
	color_buddha(f, buddha.img);
	mlx_image_to_window(f->mlx, f->image, 0, 0);
	free_buddhaimg(&buddha, f);
}
