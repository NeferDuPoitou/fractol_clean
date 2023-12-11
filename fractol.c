/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achatzit <achatzit@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:53:33 by achatzit          #+#    #+#             */
/*   Updated: 2023/12/11 12:47:17 by achatzit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

static void	init_mlx_and_image(t_fol f, mlx_t **mlx, mlx_image_t **image)
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

static void	image_to_window(mlx_t *mlx, mlx_image_t *image, int x, int y)
{
	if (mlx_image_to_window(mlx, image, x, y) == -1)
	{
		mlx_close_window(mlx);
		ft_printf("%s", mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
}

void	fractalise(t_fol *f)
{
	t_box	box;

	if (f->fractal_type == BUDDHA)
		buddhabrot(f);
	else
	{
		box = (t_box){0, 0, f->win_width - 1, f->win_heigth - 1};
		mandelflood(box, f);
	}
}

int main(int argc, char **argv)
{
	t_fol	f;
	mlx_t	*mlx;
	mlx_image_t *image;

	if (argc == 1)
		general_instructions();
	arg_parser(argc, argv, &f);
	struct_init(&f, argv);
	init_mlx_and_image(f, &mlx, &image);
	f.mlx = mlx;
	f.image = image;
	image_to_window(mlx, image, 0, 0);
	fractalise(&f);
	mlx_loop_hook(mlx, keys_actions, &f);
	mlx_loop(mlx);
	
	//clean exit
	//return EXIT_SUCCESS
}
