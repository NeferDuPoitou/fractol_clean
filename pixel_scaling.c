#include "fractol.h"
#include "defines.h"

long double scaled_pixel(int pixel, int type, t_fol *f)
{
	long double ratio;

	if (type == 'x')
	{
		ratio = (long double)pixel / (long double)f->win_width;
		return ratio * ABS_SCALED_X / f->zoom - f->wid;
	}
	else
	{
		ratio = (long double)pixel / (long double)f->win_heigth;
		return ratio * ABS_SCALED_Y / f->zoom - f->heig;
	}
}
