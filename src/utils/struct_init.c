/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achatzit <achatzit@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:53:47 by achatzit          #+#    #+#             */
/*   Updated: 2023/12/12 11:29:09 by achatzit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static int	get_fractal_type(char *s)
{
	if (!ft_strcmp(s, ARG_MANDEL))
		return (MANDELBROT);
	if (!ft_strcmp(s, ARG_JULIA))
		return (JULIA);
	if (!ft_strcmp(s, ARG_BURNINGSHIP))
		return (BURNINGSHIP);
	if (!ft_strcmp(s, ARG_BURNINGJULIA))
		return (BURNINGJULIA);
	if (!ft_strcmp(s, ARG_BUDDHA))
		return (BUDDHA);
	return (0);
}

void	struct_init(t_fol *f, char **argv)
{
	f->fractal_type = get_fractal_type(argv[1]);
	f->wid = 1.5;
	f->heig = 1.2;
	f->zoom = 0.90;
	f->scaled_pixel.im = 0.00;
	f->scaled_pixel.re = 0.00;
	f->win_width = 1200;
	f->win_heigth = 1200;
	f->bailout = 4.0;
	f->max_iter = 500;
	f->cur_color = 0;
	f->buddha.i = 0;
	f->buddha.j = 0;
	f->buddha_iters = 5000;
	f->julia_set = 0;
	f->cur_color = LSD;
	f->bruteforce = 0;
	if (f->julia_has_consts == 1)
	{
		f->j_consts_static.re = ft_atold(argv[2]);
		f->j_consts_static.im = ft_atold(argv[3]);
	}
}
