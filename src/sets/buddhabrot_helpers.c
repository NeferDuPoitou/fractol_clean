/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddhabrot_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achatzit <achatzit@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:25:44 by achatzit          #+#    #+#             */
/*   Updated: 2023/12/11 14:33:17 by achatzit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

//here to comply with the Norm. merge with malloc_buddhaimg asap
static void	mbi_inner_loop(t_buddha *buddha, t_fol *f, int i)
{
	uint32_t	j;
	uint32_t	k;

	buddha->img[i] = malloc(f->win_width * sizeof(int *));
	if (!buddha->img[i])
		return (error_and_quit(ALLOC_FAIL));
	j = 0;
	while (j < f->win_heigth)
	{
		buddha->img[i][j] = malloc(f->win_width * sizeof(int));
		if (!buddha->img[i][j])
			return (error_and_quit(ALLOC_FAIL));
		k = 0;
		while (k < f->win_width)
		{
			buddha->img[i][j][k] = 0;
			k++;
		}
		j++;
	}
}

void	malloc_buddhaimg(t_buddha *buddha, t_fol *f)
{
	uint32_t	i;

	i = 0;
	buddha->img = malloc(3 * sizeof(int **));
	if (!buddha->img)
		return (error_and_quit(ALLOC_FAIL));
	while (i < 3)
	{
		mbi_inner_loop(buddha, f, i);
		i++;
	}
}

void	free_buddhaimg(t_buddha *buddha, t_fol *f)
{
	uint32_t	i;
	uint32_t	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < f->win_heigth)
		{
			free(buddha->img[i][j]);
			j++;
		}
		free(buddha->img[i]);
		i++;
	}
	free(buddha->img);
}

void	init_buddhacolors(t_buddha_color *b)
{
	b->start_color[0] = 0;
	b->start_color[1] = 0;
	b->start_color[2] = 0;
	b->end_color[0] = 255;
	b->end_color[1] = 105;
	b->end_color[2] = 180;
}

//the line intensity = 0 is here only to satisfy werror and can be 
//safely removed
void	color_buddha(t_fol *f, int ***img)
{
	t_pixel			px;
	t_buddha_color	bcolor;
	long double		intensity;

	px.y = 0;
	f->buddha.img = img;
	while (px.y < (int)f->win_heigth)
	{
		px.x = 0;
		while (px.x < (int)f->win_width)
		{
			intensity = 0;
			calc_color_and_put_pixel(f, px, bcolor, intensity);
			px.x++;
		}
		px.y++;
	}
}
