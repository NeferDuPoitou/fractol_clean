/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningjulia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achatzit <achatzit@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:52:40 by achatzit          #+#    #+#             */
/*   Updated: 2023/12/11 12:45:34 by achatzit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

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
	color = get_color(spx, f);
	mlx_put_pixel(f->image, a, b, color);
	return (spx);
}
