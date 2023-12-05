#include "MLX42.h"
#include "fractol.h"
#include "defines.h"

void	mandel_julia(t_fol *f)
{
	//mandel / julia.c
}

void	buddhabrot(t_fol *f)
{
	//buddhabrot.c
}

int main(int argc, char **argv)
{
	t_fol	f;
	mlx_t	*mlx;

	if (argc == 1)
		general_instructions();
	arg_parser(argc, argv);
	struct_init(&f, argc, argv);
	mlx = mlx_init();
	// if ()

	//sdl init
	//image init

	//struct init

	//buddhabrot ?
	//	buddhabrot(&f);
	//else 
	//	mandel/julia(&f);
	
	//image to window
	//hooks
	//loop
	
	//clean exit
	//return EXIT_SUCCESS
}
