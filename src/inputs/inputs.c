/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achatzit <achatzit@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:54:49 by achatzit          #+#    #+#             */
/*   Updated: 2023/12/11 21:39:51 by achatzit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static void	zoom(t_fol *f)
{
	if (mlx_is_key_down(f->mlx, MLX_KEY_L))
	{
		f->zoom *= 1.1;
		f->wid -= (0.1 / f->zoom * ((long double)f->win_width / f->win_heigth));
		f->heig -= 0.1 / f->zoom;
		fractalise(f);
	}
	if (mlx_is_key_down(f->mlx, MLX_KEY_K))
	{
		f->zoom *= 0.8;
		fractalise(f);
	}
}

static void	pan(t_fol *f)
{
	if (mlx_is_key_down(f->mlx, MLX_KEY_W))
	{
		f->heig += 0.1 / f->zoom;
		fractalise(f);
	}
	if (mlx_is_key_down(f->mlx, MLX_KEY_S))
	{
		f->heig -= 0.1 / f->zoom;
		fractalise(f);
	}
	if (mlx_is_key_down(f->mlx, MLX_KEY_Q))
	{
		f->wid += 0.1 / f->zoom;
		fractalise(f);
	}
	if (mlx_is_key_down(f->mlx, MLX_KEY_E))
	{
		f->wid -= 0.1 / f->zoom;
		fractalise(f);
	}
}

void	choose_colors(t_fol *f)
{
	(void)f;
	choose_color1(f);
	choose_color2(f);
}

void	burningjulia_consts(t_fol *f)
{
	int	mousex;
	int	mousey;

	if (mlx_is_mouse_down(f->mlx, 0))
	{
		mlx_get_mouse_pos(f->mlx, &mousex, &mousey);
		f->j_consts.re = scaled_pixel(mousex, 'x', f);
		f->j_consts.im = scaled_pixel(mousey, 'y', f);
		fractalise(f);
	}
}

void	keys_actions(void *fol)
{
	t_fol	*f;

	f = (t_fol *)fol;
	if (mlx_is_key_down(f->mlx, MLX_KEY_R))
	{
		f->zoom = 1;
		f->wid = 1.2;
		f->heig = 1.5;
		fractalise(f);
	}
	if (mlx_is_key_down(f->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(f->mlx);
	input_check_bruteforce(f);
	input_iterations(f);
	zoom(f);
	pan(f);
	mlx_scroll_hook(f->mlx, scroll_func, f);
	mlx_resize_hook(f->mlx, resize, f);
	key_resize(f);
	choose_colors(f);
	burningjulia_consts(f);
}
