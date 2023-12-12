/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achatzit <achatzit@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:53:33 by achatzit          #+#    #+#             */
/*   Updated: 2023/12/11 22:10:37 by achatzit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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

int	main(int argc, char **argv)
{
	t_fol		f;
	mlx_t		*mlx;
	mlx_image_t	*image;

	if (argc == 1)
		general_instructions();
	arg_parser(argc, argv, &f);
	struct_init(&f, argv);
	init_mlx_and_image(f, &mlx, &image);
	f.mlx = mlx;
	f.image = image;
	image_to_window(mlx, image, 0, 0);
	fractalise(&f);
	if (f.fractal_type != BUDDHA)
		mlx_loop_hook(mlx, keys_actions, &f);
	else
		mlx_loop_hook(mlx, buddha_hook, &f);
	mlx_loop(mlx);
	mlx_terminate(f.mlx);
	return (EXIT_SUCCESS);
}
