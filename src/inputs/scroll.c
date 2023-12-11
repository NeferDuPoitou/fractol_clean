/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scroll.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achatzit <achatzit@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:11:18 by achatzit          #+#    #+#             */
/*   Updated: 2023/12/11 18:11:16 by achatzit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"
#include <math.h>
#include <stdint.h>

static void	scroll_in(t_fol *f, int x, int y)
{
	long double	wdist;
	long double	hdist;
	int			wcenter;

	wcenter = f->win_width / 2;
	wdist = ((long double)x / wcenter - 1) / f->zoom;
	hdist = ((long double)y / wcenter - 1) / f->zoom;
	f->wid = f->wid - wdist;
	f->heig = f->heig - hdist;
	f->zoom *= 1.3;
	fractalise(f);
}

static void	scroll_out(t_fol *f, int x, int y)
{
	long double	wdist;
	long double	hdist;
	int			wcenter;

	wcenter = f->win_width / 2;
	wdist = ((long double)x / wcenter - 1) / f->zoom;
	hdist = ((long double)y / wcenter - 1) / f->zoom;
	f->wid = f->wid - wdist;
	f->heig = f->heig - hdist;
	f->zoom *= 0.7;
	fractalise(f);
}

void	scroll_func(double xdelta, double ydelta, void *fl)
{
	t_fol	*f;
	int		mousex;
	int		mousey;

	(void)xdelta;
	f = (t_fol *)fl;
	mlx_get_mouse_pos(f->mlx, &mousex, &mousey);
	if (ydelta > 0)
	{
		scroll_in(f, mousex, mousey);
	}
	else if (ydelta < 0)
	{
		scroll_out(f, mousex, mousey);
	}
}
