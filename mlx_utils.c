#include "MLX42.h"
#include "fractol.h"
#include "defines.h"

//workaround for not having access to a wait function in the project
void	mlx_wait(double seconds, t_fol *f)
{
	double start_time;

	start_time = mlx_get_time();
	while (1)
	{
		if (mlx_get_time() >= start_time + seconds)
			return ;
	}
}
