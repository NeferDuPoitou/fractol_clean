/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_palette.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achatzit <achatzit@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:43:23 by achatzit          #+#    #+#             */
/*   Updated: 2023/12/11 12:59:43 by achatzit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

uint32_t	get_color(t_scaled_pixel spx, t_fol *f)
{
	if (f->cur_color == LSD)
		return (lsd_palette(spx, f));
	if (f->cur_color == VANDETTA)
		return (vandetta_palette(spx, f));
	if (f->cur_color == MUSEUM)
		return (museum_palette(spx, f));
	if (f->cur_color == ARROWS)
		return (arrows_palette(spx, f));
	if (f->cur_color == STARRYNIGHT)
		return (starrynight_palette(spx, f));
	if (f->cur_color == RAZER)
		return (red_dawn_palette(spx, f));
	if (f->cur_color == GREENERY)
		return (greenery_palette(spx, f));
	else
		return (0);
}
