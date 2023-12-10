#include "fractol.h"
#include "defines.h"
#include <math.h>
#include <stdint.h>

uint32_t	museum_palette(t_scaled_pixel spx, t_fol *f)
{
	t_rgb		rgb;
	uint32_t	final_color;
	double		t1;
	double		t2;

	if (spx.iteration == f->max_iter || spx.iteration == 1 || spx.iteration == 2)
		return (255);
	t1 = (double)spx.iteration / (double)f->max_iter * (cosl(spx.re / 3.14));
	t2 = (double)(spx.iteration - f->max_iter) / (double)f->max_iter;
	rgb.r = (1 - t1 / 2) * ((RED >> 16) & 0xff) + t1 * ((GRN >> 16) & 0xff);
	rgb.b = (1 - t1) * ((RED >> 8) & 0xff) + t1 * ((GRN >> 8) & 0xff);
	rgb.g = (1 - t1 / 4) * (RED & 0xff) + t1 * (GRN & 0xff);
	rgb.r = (1 - t2) * rgb.r + t2 * ((BLU >> 16) & 0xff);
	rgb.g = (1 - t2) * rgb.g + t2 * ((BLU >> 8) & 0xff);
	rgb.b = (1 - t2) * rgb.b + t2 * (BLU & 0xff);
	final_color =	(uint32_t)rgb.r << 24 | 
					(uint32_t)(0) << 16 | 
					(uint32_t)(rgb.g) << 8 | 255;
	return final_color;
}

uint32_t	arrows_palette(t_scaled_pixel spx, t_fol *f)
{
	float		C;
	uint32_t	color;

	(void)f;
	C = spx.iteration - log2f(logf(fabsl(spx.im)) / M_LN2 );
	color = ((uint8_t)((1+sin(C*0.89))*127.) << 24) | \
			(uint8_t)((1+cos(C*0.15))*127.) << 16 | \
			(uint8_t)((1+sin(C*0.55))*127.) << 8 | \
			255;
	return (color);
} 

uint32_t	starrynight_palette(t_scaled_pixel spx, t_fol *f)
{
	t_rgb		rgb;
	uint32_t	final_color;
	double		t1;
	double		t2;

	if (spx.iteration == f->max_iter || spx.iteration == 1)
		return (255);
    t1 = (double)spx.iteration / (double)f->max_iter;
    t2 = (double)(spx.iteration - f->max_iter) / (double)f->max_iter;
    rgb.r = (1 - t1 / 2) * ((RED >> 16) & 0xFF) + t1 * ((GRN >> 16) & 0xFF);
    rgb.g = (1 - t1) * ((RED >> 8) & 0xFF) + t1 * ((GRN >> 8) & 0xFF);
    rgb.b = (1 - t1 / 3) * (RED & 0xFF) + t1 * (GRN & 0xFF);
    rgb.r = (1 - t2) * rgb.r + t2 * ((BLU >> 16) & 0xFF);
    rgb.g = (1 - t2) * rgb.g + t2 * ((BLU >> 8) & 0xFF);
    rgb.b = (1 - t2) * rgb.b + t2 * (BLU & 0xFF);
    final_color = (uint32_t)0 << 24 | (uint32_t)(0) << 16 | (uint32_t)rgb.b << 8 | 255;
    return (final_color);
}

uint32_t	red_dawn_palette(t_scaled_pixel spx, t_fol *f)
{
	t_rgb	rgb;
	long double ni;

	ni = (long double)spx.iteration / (long double)f->max_iter;
	rgb.r = 9.0 * (1.0 - ni) * pow(ni, 3.0) * 255.0;
	rgb.g = 15.0 * pow((1.0 - ni), 2.0) * pow(ni, 2.0) * 255.0;
	rgb.b = 8.5 * pow((1.0 - ni), 3.0) * ni * 255.0;
	return ((rgb.b << 24) | (rgb.g << 16) | (rgb.r << 8)|255);
}

uint32_t	greenery_palette(t_scaled_pixel spx, t_fol *f)
{
	t_rgb		rgb;
	uint32_t	final_color;
	double		t1;
	double		t2;

	if (spx.iteration == f->max_iter || spx.iteration == 1)
		return (255);
    t1 = (double)spx.iteration / (double)f->max_iter;
    t2 = (double)(spx.iteration - f->max_iter) / (double)f->max_iter;
    rgb.r = (1 - t1 / 2) * ((RED >> 16) & 0xFF) + t1 * ((GRN >> 16) & 0xFF);
    rgb.g = (1 - t1) * ((RED >> 8) & 0xFF) + t1 * ((GRN >> 8) & 0xFF);
    rgb.b = (1 - t1 / 3) * (RED & 0xFF) + t1 * (GRN & 0xFF);
    rgb.r = (1 - t2) * rgb.r + t2 * ((BLU >> 16) & 0xFF);
    rgb.g = (1 - t2) * rgb.g + t2 * ((BLU >> 8) & 0xFF);
    rgb.b = (1 - t2) * rgb.b + t2 * (BLU & 0xFF);
    final_color = (uint32_t)0 << 24 | (uint32_t)(rgb.g * f->zoom) << 16 | (uint32_t)rgb.b << 8 | 255;
    return (final_color);
}
