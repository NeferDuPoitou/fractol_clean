#include "MLX42.h"
#include "fractol.h"
#include "defines.h"

uint32_t starrynight_palette(int iteration, t_fol *f)
{
	if (iteration == f->max_iter)
		return (0 << 24 | 0 << 16 | 0 << 8 | 255);
    // Define gradient colors
    uint32_t color1 = 255 << 24 | 0 << 16 | 0 << 8 | 255;  // Red
    uint32_t color2 = 0 << 24 | 255 << 16 | 0 << 8 | 255;  // Green
    uint32_t color3 = 0 << 24 | 0 << 16 | 255 << 8 | 255;  // Blue

    // Calculate interpolation factors for color blending
    double t1 = (double)iteration / (double)f->max_iter;
    double t2 = (double)iteration - f->max_iter / (double)f->max_iter;

    // Interpolate between colors based on iteration count
    uint8_t r = (1 - t1 / 2) * ((color1 >> 16) & 0xFF) + t1 * ((color2 >> 16) & 0xFF);
    uint8_t g = (1 - t1) * ((color1 >> 8) & 0xFF) + t1 * ((color2 >> 8) & 0xFF);
    uint8_t b = (1 - t1 / 3) * (color1 & 0xFF) + t1 * (color2 & 0xFF);

    // Interpolate between the second and third colors
    r = (1 - t2) * r + t2 * ((color3 >> 16) & 0xFF);
    g = (1 - t2) * g + t2 * ((color3 >> 8) & 0xFF);
    b = (1 - t2) * b + t2 * (color3 & 0xFF);


    // Create the final color
    uint32_t finalColor = (uint32_t)0 << 24 | (uint32_t)(0) << 16 | (uint32_t)b << 8 | 255;

    return finalColor;
}
