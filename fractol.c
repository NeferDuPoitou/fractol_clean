#include "MLX42.h"
#include "fractol.h"
#include "defines.h"

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
	if (f->fractal_type == MANDELBROT)
		mandelflood(0, 0, f->win_width, f->win_heigth, f);
	else if (f->fractal_type == JULIA)
		ft_printf("julia en construciton");
	else if (f->fractal_type == BURNINGJULIA)
		ft_printf("burning julia en construciton");
	else if (f->fractal_type == BUDDHA)
		ft_printf("buddhabrot en construciton");
}

int main(int argc, char **argv)
{
	t_fol	f;
	mlx_t	*mlx;
	mlx_image_t *image;

	if (argc == 1)
		general_instructions();
	arg_parser(argc, argv);
	struct_init(&f, argc, argv);
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
