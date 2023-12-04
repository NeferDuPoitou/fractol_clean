#ifndef FRACTOL_H
# define FRACTOL_H

#include <cstdint>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include <time.h>
# include <unistd.h>
# include <stdint.h>
# include <pthread.h>
# include "MLX42.h"

typedef struct s_pixel
{
	long double	re;
	long double	im;
	int			iteration;
}	t_pixel;

typedef struct s_it
{
    int min[3];
    int max[3];
} t_it;


typedef struct s_buddha
{
	struct s_it it;
	int ***img;
	int i;
	int j;
}	t_buddha;

typedef struct s_fol
{
	mlx_t		*mlx;
	mlx_image_t *image;
	uint8_t		fractal_type;	
	uint32_t	win_x;
	uint32_t	win_y;
	long double heig;
	long double wid;
	long double zoom;
	int32_t		max_iter;
	int			cur_color;
	long double	bailout;
	int			shift;
	struct s_pixel pixel;
	struct s_buddha	buddha;
	int			buddha_iters;
	int			buddha_bailout;
}	t_fol;

#endif
