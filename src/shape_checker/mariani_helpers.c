/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mariani_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achatzit <achatzit@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:54:03 by achatzit          #+#    #+#             */
/*   Updated: 2023/12/11 13:16:53 by achatzit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

t_scaled_pixel	compute_fractal(int x, int y, t_fol *f)
{
	t_scaled_pixel	werror;

	if (f->fractal_type == MANDELBROT)
		return (mandelcalc_and_color(x, y, f));
	if (f->fractal_type == JULIA && f->julia_has_consts == 0)
		return (juliacalc_and_color(x, y, f));
	if (f->fractal_type == JULIA && f->julia_has_consts == 1)
		return (juliacalc_and_color_static(x, y, f));
	if (f->fractal_type == BURNINGSHIP)
		return (burningshipcalc_and_color(x, y, f));
	if (f->fractal_type == BURNINGJULIA)
		return (burningjuliacalc_and_color(x, y, f));
	else
		return (werror);
}

void	bruteforce(t_box box, int x, int y, t_fol *f)
{
	while (x < box.end_x)
	{
		y = box.start_y;
		while (y < box.end_y)
		{
			f->itermap[x][y] = compute_fractal(x, y, f).iteration;
			y++;
		}
		x++;
	}
}

void	calloc_itermap(t_fol *f)
{
	uint32_t	i;

	i = 0;
	f->itermap = calloc(f->win_width, sizeof(int *));
	while (i < f->win_width)
	{
		f->itermap[i] = calloc(f->win_heigth, sizeof(int));
		i++;
	}
}

void	free_itermap(t_fol *f)
{
	uint32_t	i;

	i = 0;
	while (i < f->win_width)
	{
		free(f->itermap[i]);
		i++;
	}
	free(f->itermap);
}
