#include "fractol.h"
#include "defines.h"

uint32_t	get_color(t_scaled_pixel spx, t_fol *f)
{
	if (f->cur_color == LSD)
		return (lsd_palette(spx, f));
	if (f->cur_color == VANDETTA)
		return (vandetta_palette(spx, f));
	if (f->cur_color == MUSEUM)
		return (museum_palette(spx, f));
	if (f->cur_color == ARROWS)
		return (arrows_palette(spx, f));
	// if (f->cur_color == LSD)
	// 	return (lsd_palette(spx, f));
	// if (f->cur_color == LSD)
	// 	return (lsd_palette(spx, f));
	// if (f->cur_color == LSD)
	// 	return (lsd_palette(spx, f));
	// if (f->cur_color == LSD)
	// 	return (lsd_palette(spx, f));
	// if (f->cur_color == LSD)
	// 	return (lsd_palette(spx, f));
	// if (f->cur_color == LSD)
	// 	return (lsd_palette(spx, f));
	else
		return 0;;
}
