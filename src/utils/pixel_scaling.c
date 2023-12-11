/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_scaling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achatzit <achatzit@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:53:54 by achatzit          #+#    #+#             */
/*   Updated: 2023/12/11 18:11:37 by achatzit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

long double	scaled_pixel(int pixel, int type, t_fol *f)
{
	long double	ratio;

	if (type == 'x')
	{
		ratio = (long double)pixel / (long double)f->win_width;
		return (ratio * ABS_SCALED_X / f->zoom - f->wid);
	}
	else
	{
		ratio = (long double)pixel / (long double)f->win_heigth;
		return (ratio * ABS_SCALED_Y / f->zoom - f->heig);
	}
}
