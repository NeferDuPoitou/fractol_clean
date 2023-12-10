/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achatzit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:53:01 by achatzit          #+#    #+#             */
/*   Updated: 2023/12/10 10:53:04 by achatzit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "fractol.h"
#include "defines.h"

void	choose_color1(t_fol *f)
{
	if (mlx_is_key_down(f->mlx, MLX_KEY_0))
	{
		f->cur_color = LSD;
		fractalise(f);
	}
	if (mlx_is_key_down(f->mlx, MLX_KEY_1))
	{
		f->cur_color = VANDETTA;
		fractalise(f);
	}
	if (mlx_is_key_down(f->mlx, MLX_KEY_2))
	{
		f->cur_color = STARRYNIGHT;
		fractalise(f);
	}
	if (mlx_is_key_down(f->mlx, MLX_KEY_3))
	{
		f->cur_color = RAZER;
		fractalise(f);
	}
	if (mlx_is_key_down(f->mlx, MLX_KEY_4))
	{
		f->cur_color = MUSEUM;
		fractalise(f);
	}
}

void	choose_color2(t_fol *f)
{
	if (mlx_is_key_down(f->mlx, MLX_KEY_5))
	{
		f->cur_color = ARROWS;
		fractalise(f);
	}
	if (mlx_is_key_down(f->mlx, MLX_KEY_6))
	{
		f->cur_color = GREENERY;
		fractalise(f);
	}
}

/* void	choose_colors3(t_fol *f)
{

} */
