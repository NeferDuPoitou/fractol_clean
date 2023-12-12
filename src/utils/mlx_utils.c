/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achatzit <achatzit@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:46:28 by achatzit          #+#    #+#             */
/*   Updated: 2023/12/12 11:47:05 by achatzit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"
#include <stdlib.h>

//workaround for not having access to a wait function in the project
void	mlx_wait(double seconds)
{
	double	start_time;

	start_time = mlx_get_time();
	while (1)
	{
		if (mlx_get_time() >= start_time + seconds)
			return ;
	}
}

void	init_mlx_and_image(t_fol f, mlx_t **mlx, mlx_image_t **image)
{
	*mlx = mlx_init(f.win_width, f.win_heigth, "Fractol", true);
	if (!*mlx)
	{
		ft_printf("%s", mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	*image = (mlx_new_image(*mlx, f.win_width, f.win_heigth));
	if (!*image)
	{
		mlx_close_window(*mlx);
		ft_printf("%s", mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
}

void	new_image(t_fol *f)
{
	f->image = mlx_new_image(f->mlx, f->win_width, f->win_heigth);
	if (!f->image)
	{
		mlx_close_window(f->mlx);
		ft_printf("%s", mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
}

void	image_to_window(mlx_t *mlx, mlx_image_t *image, int x, int y)
{
	if (mlx_image_to_window(mlx, image, x, y) == -1)
	{
		mlx_close_window(mlx);
		ft_printf("%s", mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
}
