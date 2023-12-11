/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achatzit <achatzit@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:53:08 by achatzit          #+#    #+#             */
/*   Updated: 2023/12/11 13:01:38 by achatzit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

uint32_t	lsd_palette(t_scaled_pixel spx, t_fol *f)
{
	t_rgb		rgb;
	uint32_t	final_color;
	double		t1;
	double		t2;

	if (spx.iteration == f->max_iter)
		return (0 << 24 | 0 << 16 | 0 << 8 | 255);
	t1 = (double)spx.iteration / (double)f->max_iter;
	t2 = (double)(spx.iteration - f->max_iter) / (double)f->max_iter;
	rgb.r = (1 - t1) * ((RED >> 16) & 0xFF) + t1 * ((GRN >> 16) & 0xFF);
	rgb.g = (1 - t1) * ((RED >> 8) & 0xFF) + t1 * ((GRN >> 8) & 0xFF);
	rgb.b = (1 - t1) * (RED & 0xFF) + t1 * (GRN & 0xFF);
	rgb.r = (1 - t2) * rgb.r + t2 * ((BLU >> 16) & 0xFF);
	rgb.g = (1 - t2) * rgb.g + t2 * ((BLU >> 8) & 0xFF);
	rgb.b = (1 - t2) * rgb.b + t2 * (BLU & 0xFF);
	final_color = (uint32_t)0 << 24 | \
				(uint32_t)(rgb.g * f->zoom) << 16 | \
				(uint32_t)rgb.b << 8 | 255;
	return (final_color);
}

static t_hsv	setup_struct(int iteration)
{
	t_hsv	hsv;

	hsv.hue = fmod((double)iteration * 10, 360.0);
	hsv.saturation = 1.0;
	hsv.value = 1.0;
	hsv.C = hsv.value * hsv.saturation;
	hsv.X = hsv.C * (1.0 - fabs(fmod(hsv.hue / 60.0, 2.0) - 1.0));
	hsv.m = hsv.value - hsv.C;
	return (hsv);
}

static void	hue_helper1(t_hsv *hsv)
{
	if (hsv->hue >= 0 && hsv->hue < 60)
	{
		hsv->Rs = hsv->C;
		hsv->Gs = hsv->X;
		hsv->Bs = 0;
	}
	else if (hsv->hue >= 60 && hsv->hue < 120)
	{
		hsv->Rs = hsv->X;
		hsv->Gs = hsv->C;
		hsv->Bs = 0;
	}
	else if (hsv->hue >= 120 && hsv->hue < 180)
	{
		hsv->Rs = 0;
		hsv->Gs = hsv->C;
		hsv->Bs = hsv->X;
	}
	else if (hsv->hue >= 180 && hsv->hue < 240)
	{
		hsv->Rs = 0;
		hsv->Gs = hsv->X;
		hsv->Bs = hsv->C;
	}
}

static void	hue_helper2(t_hsv *hsv)
{
	if (hsv->hue >= 240 && hsv->hue < 300)
	{
		hsv->Rs = hsv->X;
		hsv->Gs = 0;
		hsv->Bs = hsv->C;
	}
	else if (hsv->hue >= 300)
	{
		hsv->Rs = hsv->C;
		hsv->Gs = 0;
		hsv->Bs = hsv->X;
	}
}

uint32_t	vandetta_palette(t_scaled_pixel spx, t_fol *f)
{
	t_hsv			hsv;
	t_rgb			rgb;
	uint32_t		final_color;

	if (spx.iteration == f->max_iter)
		return (255);
	hsv = setup_struct(spx.iteration);
	hue_helper1(&hsv);
	hue_helper2(&hsv);
	rgb.r = (hsv.Rs + hsv.m) * 255;
	rgb.g = (hsv.Gs + hsv.m) * 255;
	rgb.b = (hsv.Bs + hsv.m) * 255;
	final_color = (uint32_t)rgb.r << 24 | \
	(uint32_t)(rgb.g) << 16 | (uint32_t)rgb.b << 8 | 255;
	return (final_color);
}
