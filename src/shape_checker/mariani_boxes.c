/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mariani_boxes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achatzit <achatzit@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:36:17 by achatzit          #+#    #+#             */
/*   Updated: 2023/12/12 11:47:03 by achatzit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

//this algorithm is called Mariani-Silver, or simply shape checking (with boxes)
//the principle is as follows : there cannot be islands in the mandelbrot set, 
//and every iteration zone is simply connected.
//Which means that, if we can draw a close shape where each border pixel
//share the same iteration count, we can safely assume that every pixel
//inside the shape will be of the same iteration.
//Here i recursively divide a box into 4 box, these are my shapes.
//This improves the base performance to 8* in average, but it can be more or 
//less the same as bruteforcing depending on the iteration and zoom count.
//low iteration counts will yeld results closer to the bruteforce approach.
//
//Another approach at shape checking would be border tracing, where we 
//use kind of a flood fill algorithm (but only on the border pixels) 
//to draw the perfect shape around each iteration zone. this would
//improve the performance bt around 30 times compared to bruteforcing 
//(as we only have to iterate on the border pixels, compared to many
//pixels inside with the Mariani approach), but my first attempt failed
//miserably at finding a clean condition to check if im still at the border
//of the shape.

//	T_L= (start_x, start_y, (end_x + start_x) / 2, (end_y + start_y) / 2, f);
// 	T_R = ((start_x + end_x) / 2, start_y, end_x, (end_y + start_y) / 2, f);
//	B_L = (start_x, (start_y + end_y) / 2, (end_x + start_x) / 2, end_y, f);
// 	B_R = ((end_x + start_x) / 2, (end_y + start_y) / 2, end_x, end_y, f);
void	divide_boxes(t_box *box, int quadrant)
{
	if (quadrant == WHOLE_SCREEN)
		return ;
	if (quadrant == TOP_LEFT)
	{
		box->end_x = (box->end_x + box->start_x) / 2;
		box->end_y = (box->end_y + box->start_y) / 2;
	}
	if (quadrant == TOP_RIGHT)
	{
		box->start_x = (box->start_x + box->end_x) / 2;
		box->end_y = (box->end_y + box->start_y) / 2;
	}
	if (quadrant == BOTTOM_LEFT)
	{
		box->start_y = (box->end_y + box->start_y) / 2;
		box->end_x = (box->end_x + box->start_x) / 2;
	}
	if (quadrant == BOTTOM_RIGHT)
	{
		box->start_x = (box->end_x + box->start_x) / 2;
		box->start_y = (box->end_y + box->start_y) / 2;
	}
}

void	fill_box(t_box box, t_fol *f, t_pixel p, t_itercheck ic)
{
	uint32_t		color;
	t_scaled_pixel	spx;

	p.x = box.start_x;
	p.y = box.start_y;
	spx = (t_scaled_pixel){scaled_pixel(p.x, 'x', f), \
						scaled_pixel(p.y, 'y', f), \
						ic.startiter};
	color = get_color(spx, f);
	while (++p.x < box.end_x)
	{
		p.y = box.start_y;
		while (++p.y < box.end_y)
		{
			f->itermap[p.x][p.y] = ic.startiter;
			mlx_put_pixel(f->image, p.x, p.y, color);
		}
	}
	return ;
}
// boxes_filter(f, start_x, start_y, end_x, end_y);

void	check_borders(t_pixel p, t_box box, t_fol *f, t_itercheck *ic)
{
	while (p.x <= box.end_x)
	{
		p.y = box.start_y;
		while (p.y <= box.end_y)
		{
			if (p.x == box.start_x || p.x == box.end_x || \
				p.y == box.start_y || p.y == box.end_y)
			{
				if (compute_fractal(p.x, p.y, f).iteration != ic->startiter)
					ic->flagok = 0;
			}
			p.y++;
		}
		p.x++;
	}
}

// the line p.y = 0 is here only to satisfy werror, it can be safely
// removed
void	mandelboxes(t_box box, t_fol *f, int quadrant)
{
	t_itercheck		ic;
	t_pixel			p;
	t_scaled_pixel	spx;

	divide_boxes(&box, quadrant);
	ic.flagok = 1;
	p.x = box.start_x;
	spx = compute_fractal(box.start_x, box.start_y, f);
	ic.startiter = spx.iteration;
	if (abs(box.end_x - box.start_x) <= 3 || abs(box.start_y - box.end_y) <= 3)
	{
		p.y = 0;
		bruteforce(box, p.x, p.y, f);
		return ;
	}
	check_borders(p, box, f, &ic);
	if (ic.flagok == 1)
		fill_box(box, f, p, ic);
	if (ic.flagok == 0)
	{
		mandelboxes(box, f, TOP_LEFT);
		mandelboxes(box, f, TOP_RIGHT);
		mandelboxes(box, f, BOTTOM_LEFT);
		mandelboxes(box, f, BOTTOM_RIGHT);
	}
}

void	mandelflood(t_box box, t_fol *f)
{
	if (f->bruteforce == 0 && f->fractal_type != BUDDHA)
	{
		calloc_itermap(f);
		mandelboxes(box, f, WHOLE_SCREEN);
		free_itermap(f);
	}
	else if (f->bruteforce == 1)
	{
		calloc_itermap(f);
		bruteforce(box, 0, 0, f);
		free_itermap(f);
	}
}
