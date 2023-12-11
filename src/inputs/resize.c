/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achatzit <achatzit@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:24:02 by achatzit          #+#    #+#             */
/*   Updated: 2023/12/11 22:10:53 by achatzit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	resize(int w, int h, void *param)
{
	t_fol	*f;

	f = (t_fol *)param;
	if (w != h)
		w = h;
	f->win_width = w;
	f->win_heigth = h;
	if (!mlx_resize_image(f->image, f->win_width, f->win_heigth))
		error_and_quit(RESIZE_FAILED);
	fractalise(f);
}

static void	resize_up(t_fol *f)
{
	f->win_width += 50;
	f->win_heigth += 50;
	if (f->win_width >= 3000 || f->win_heigth >= 3000)
	{
		f->win_width = 2900;
		f->win_heigth = 2900;
	}
	mlx_delete_image(f->mlx, f->image);
	mlx_set_window_size(f->mlx, f->win_width, f->win_heigth);
	new_image(f);
	image_to_window(f->mlx, f->image, 0, 0);
}

static void	resize_down(t_fol *f)
{
	f->win_width -= 50;
	f->win_heigth -= 50;
	if (f->win_width <= 10 || f->win_heigth <= 10)
	{
		f->win_width = 50;
		f->win_heigth = 50;
	}
	mlx_delete_image(f->mlx, f->image);
	mlx_set_window_size(f->mlx, f->win_width, f->win_heigth);
	new_image(f);
	image_to_window(f->mlx, f->image, 0, 0);
}

void	key_resize(t_fol *f)
{
	if (mlx_is_key_down(f->mlx, MLX_KEY_P))
	{
		resize_up(f);
		fractalise(f);
	}
	if (mlx_is_key_down(f->mlx, MLX_KEY_O))
	{
		resize_down(f);
		fractalise(f);
	}
}
