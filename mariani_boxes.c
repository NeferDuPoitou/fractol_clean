#include "MLX42.h"
#include "fractol.h"
#include "defines.h"
#include "libft.h"

int	compute_fractal(int x, int y, t_fol *f)
{
	if (f->fractal_type == MANDELBROT)
		return 	mandelcalc_and_color(x, y, f);
	if (f->fractal_type == JULIA && f->julia_has_consts == 0)
		return 	juliacalc_and_color(x, y, f);
	if (f->fractal_type == JULIA && f->julia_has_consts == 1)
		return 	juliacalc_and_color_static(x, y, f);
	if (f->fractal_type == BURNINGSHIP)
		return 	burningshipcalc_and_color(x, y, f);
	if (f->fractal_type == BURNINGJULIA)
		return 	burningjuliacalc_and_color(x, y, f);
	// if (f->fractal_type == BUDDHA)
		// return 	burningjulia_and_color(x, y, f);
	return -1;
}

void boxes_filter(t_fol *f,int start_x,int start_y,int end_x,int end_y)
{
	int x;
	int y;

	x = start_x;
	y = start_y;
	int iteration = f->itermap[start_x][start_y];
	while (++x < end_x)
	{
		y = start_y;
		while (++y < end_y)
		{
			int new_iter = compute_fractal(x, y, f);
			mlx_put_pixel(f->image, x, y, 0xff00ffff);
		}
	}
}

//		TOP_LEFT = (start_x, start_y, (end_x + start_x) / 2, (end_y + start_y) / 2, f);
// 		TOP_RIGHT = ((start_x + end_x) / 2, start_y, end_x, (end_y + start_y) / 2, f);
// 		BOTTOM_LEFT = (start_x, (start_y + end_y) / 2, (end_x + start_x) / 2, end_y, f);
// 		BOTTOM_RIGHT = ((end_x + start_x) / 2, (end_y + start_y) / 2, end_x, end_y, f);
void	divide_boxes(t_box *box, t_fol *f, int quadrant)
{
	if (quadrant == WHOLE_SCREEN)
	{
		return ;
	}
	if(quadrant == TOP_LEFT)
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

void	bruteforce(t_box box, int x, int y, t_fol *f)
{
	while (x < box.end_x)
	{
		y = box.start_y;
		while (y < box.end_y)
		{
			f->itermap[x][y] = compute_fractal(x, y, f);
			y++;
		}
		x++;
	}
}

void	fill_box(t_box box, t_fol *f, t_pixel p, t_itercheck ic)
{
	p.x = box.start_x;
	p.y = box.start_y;
	int color = starrynight_palette(ic.startiter, f);
	while (++p.x < box.end_x)
	{
		p.y = box.start_y;
		while (++p.y < box.end_y)
		{
			f->itermap[p.x][p.y] = ic.startiter;
			mlx_put_pixel(f->image, p.x, p.y, color);
		}
	}
	// boxes_filter(f, start_x, start_y, end_x, end_y);
	return ;
}

void	check_borders(t_pixel p, t_box box, t_fol *f, t_itercheck *ic)
{
	while (p.x <= box.end_x)
	{
		p.y = box.start_y;
		while (p.y <= box.end_y)
		{
			if (p.x == box.start_x || p.x == box.end_x || p.y == box.start_y || p.y == box.end_y)
			{
				if (compute_fractal(p.x, p.y, f) != ic->startiter)
					ic->flagok = 0;
			}
			p.y++;
		}
		p.x++;
	}

}

void	mandelboxes(t_box box, t_fol *f, int quadrant)
{
	t_itercheck ic;
	t_pixel p;

	divide_boxes(&box, f, quadrant); 
	ic.flagok = 1;
	p.x = box.start_x;
	ic.startiter = compute_fractal(box.start_x, box.start_y, f);
	if (abs(box.end_x - box.start_x) <= 3 || abs(box.start_y - box.end_y) <= 3)
	{
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



void	calloc_itermap(t_fol *f)
{
	int i;

	i = 0;
	f->itermap = calloc(f->win_width, sizeof(int*));
	while (i < f->win_width)
	{
		f->itermap[i] = calloc(f->win_heigth, sizeof(int));
		i++;
	}
}

void	free_itermap(t_fol *f)
{
	int i = 0;

	while (i < f->win_width)
	{
		free(f->itermap[i]);
		i++;
	}
	free(f->itermap);
}

void	mandelflood(t_box box ,t_fol *f)
{
	t_pixel px;
	int iterations;
	int flagok;
	int width;
	int height;
	int startiter;

	px.x = 0;
	calloc_itermap(f);
	mandelboxes(box, f, WHOLE_SCREEN);
	free_itermap(f);
}
