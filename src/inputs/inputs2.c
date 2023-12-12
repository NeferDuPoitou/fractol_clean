/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achatzit <achatzit@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:44:20 by achatzit          #+#    #+#             */
/*   Updated: 2023/12/11 15:01:03 by achatzit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	input_check_bruteforce(t_fol *f)
{
	if (mlx_is_key_down(f->mlx, MLX_KEY_B))
	{
		if (f->bruteforce == 1)
			f->bruteforce = 0;
		else
			f->bruteforce = 1;
		fractalise(f);
		mlx_wait(0.5);
		ft_printf("bruteforce : %d\n", f->bruteforce);
	}
}

void	input_iterations(t_fol *f)
{
	if (mlx_is_key_down(f->mlx, MLX_KEY_M))
	{
		f->max_iter += 20;
		fractalise(f);
	}
	if (mlx_is_key_down(f->mlx, MLX_KEY_N))
	{
		f->max_iter -= 20;
		if (f->max_iter <= 0)
			f->max_iter = 1;
		fractalise(f);
	}
	if (mlx_is_key_down(f->mlx, MLX_KEY_X))
	{
		f->max_iter += 200;
		fractalise(f);
	}
	if (mlx_is_key_down(f->mlx, MLX_KEY_Z))
	{
		f->max_iter -= 200;
		if (f->max_iter <= 0)
			f->max_iter = 1;
		fractalise(f);
	}
}

void	buddha_hook(void *fol)
{
	t_fol	*f;

	f = (t_fol *)fol;
	if (mlx_is_key_down(f->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(f->mlx);
}
