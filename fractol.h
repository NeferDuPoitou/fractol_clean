/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achatzit <achatzit@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:31:35 by achatzit          #+#    #+#             */
/*   Updated: 2023/12/07 02:12:08 by achatzit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

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
# include "libft.h"
#include "ft_printf.h"


typedef struct s_cpx
{
	long double	re;
	long double	im;
}	t_cpx;

typedef struct s_scaled_pixel
{
	long double	re;
	long double	im;
	int		iteration;
}	t_scaled_pixel;

typedef struct s_pixel
{
	int	x;
	int	y;
}	t_pixel;

typedef struct s_box
{
	int	start_x;
	int	start_y;
	int	end_x;
	int	end_y;
}	t_box;

typedef struct s_itercheck
{
	int startiter;
	int flagok;
}	t_itercheck;

typedef struct s_it
{
    int	min[3];
    int	max[3];
} t_it;

typedef struct s_buddha
{
	struct s_it	it;
	int		***img;
	int		i;
	int		j;
}	t_buddha;

typedef struct s_fol
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	uint8_t		fractal_type;	
	uint32_t	win_width;
	uint32_t	win_heigth;
	long double	heig;
	long double	wid;
	long double	zoom;
	int32_t		max_iter;
	int		cur_color;
	long double	bailout;
	int		shift;
	struct s_scaled_pixel	scaled_pixel;
	struct s_buddha	buddha;
	int		buddha_iters;
	int		buddha_bailout;
	int		julia_has_consts;
	t_cpx		j_consts;
	t_cpx		j_consts_static;
	int		julia_set;
	int		**itermap;
}	t_fol;

void	mandelflood(t_box box, t_fol *f);
int	mandelcalc_and_color(int a, int b, t_fol *f);
int	juliacalc_and_color(int x, int y, t_fol *f);
int	juliacalc_and_color_static(int x, int y, t_fol *f);
int	burningshipcalc_and_color(int x, int y, t_fol *f);
int	burningjuliacalc_and_color(int x, int y, t_fol *f);
void	error_and_quit(char *error_str);
void	arg_parser(int argc, char **argv, t_fol *f);
void	general_instructions(void);
void	struct_init(t_fol *f, int argc, char **argv);
long double scaled_pixel(int pixel, int type, t_fol *f);
void	keys_actions(void *fol);
void	fractalise(t_fol *f);
uint32_t starrynight_palette(int iteration, t_fol *f);

#endif
