#include "fractol.h"
#include "defines.h"

uint32_t starrynight_palette(t_scaled_pixel p, t_fol *f)
{
 /* if (iteration == f->max_iter)
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

    return finalColor; */

	if (p.iteration == f->max_iter)
                return (0 << 24 | 0 << 16 | 0 << 8 | 255);
    // Define gradient colors
    uint32_t color1 = 255 << 24 | 0 << 16 | 0 << 8 | 255;  // Red
    uint32_t color2 = 0 << 24 | 255 << 16 | 0 << 8 | 255;  // Green
    uint32_t color3 = 0 << 24 | 0 << 16 | 255 << 8 | 255;  // Blue

    // Calculate interpolation factors for color blending
    double t1 = (double)p.iteration / (double)f->max_iter;
    double t2 = (double)(p.iteration - f->max_iter) / (double)f->max_iter;

    // Interpolate between colors based on iteration count
    uint8_t r = (1 - t1) * ((color1 >> 16) & 0xFF) + t1 * ((color2 >> 16) & 0xFF);
    uint8_t g = (1 - t1) * ((color1 >> 8) & 0xFF) + t1 * ((color2 >> 8) & 0xFF);
    uint8_t b = (1 - t1) * (color1 & 0xFF) + t1 * (color2 & 0xFF);

    // Interpolate between the second and third colors
    r = (1 - t2) * r + t2 * ((color3 >> 16) & 0xFF);
    g = (1 - t2) * g + t2 * ((color3 >> 8) & 0xFF);
    b = (1 - t2) * b + t2 * (color3 & 0xFF);


    // Create *  the final color``
    uint32_t finalColor = (uint32_t)0 << 24 | (uint32_t)(g * f->zoom) << 16 | (uint32_t)b << 8 | 255;

    return finalColor;
 
}

/* uint32_t lsd_palette(t_pixel pixel)
{
	if (pixel.iteration == max_iteration)
		return (0 << 24 | 0 << 16 | 0 << 8 | 255);
    // Define gradient colors
    uint32_t color1 = 255 << 24 | 0 << 16 | 0 << 8 | 255;  // Red
    uint32_t color2 = 0 << 24 | 255 << 16 | 0 << 8 | 255;  // Green
    uint32_t color3 = 0 << 24 | 0 << 16 | 255 << 8 | 255;  // Blue

    // Calculate interpolation factors for color blending
    double t1 = (double)pixel.iteration / (double)max_iteration;
    double t2 = (double)(pixel.iteration - max_iteration) / (double)max_iteration;

    // Interpolate between colors based on iteration count
    uint8_t r = (1 - t1) * ((color1 >> 16) & 0xFF) + t1 * ((color2 >> 16) & 0xFF);
    uint8_t g = (1 - t1) * ((color1 >> 8) & 0xFF) + t1 * ((color2 >> 8) & 0xFF);
    uint8_t b = (1 - t1) * (color1 & 0xFF) + t1 * (color2 & 0xFF);

    // Interpolate between the second and third colors
    r = (1 - t2) * r + t2 * ((color3 >> 16) & 0xFF);
    g = (1 - t2) * g + t2 * ((color3 >> 8) & 0xFF);
    b = (1 - t2) * b + t2 * (color3 & 0xFF);


    // Create the final color
    uint32_t finalColor = (uint32_t)0 << 24 | (uint32_t)(g * zoom) << 16 | (uint32_t)b << 8 | 255;

    return finalColor;
}

uint32_t razer_palette(t_pixel pixel)
{
	if (pixel.iteration == max_iteration)
		return (0 << 24 | 0 << 16 | 0 << 8 | 255);
    // Define gradient colors
    uint32_t color1 = 255 << 24 | 0 << 16 | 0 << 8 | 255;  // Red
    uint32_t color2 = 0 << 24 | 255 << 16 | 0 << 8 | 255;  // Green
    uint32_t color3 = 0 << 24 | 0 << 16 | 255 << 8 | 255;  // Blue

    // Calculate interpolation factors for color blending
    double t1 = (double)pixel.iteration / (double)max_iteration;
    double t2 = (double)(pixel.iteration - max_iteration) / (double)max_iteration;

    // Interpolate between colors based on iteration count
    uint8_t r = (1 - t1 / 2) * ((color1 >> 16) & 0xFF) + t1 * ((color2 >> 16) & 0xFF);
    uint8_t b = (1 - t1) * ((color1 >> 8) & 0xFF) + t1 * ((color2 >> 8) & 0xFF);
    uint8_t g = (1 - t1 / 3) * (color1 & 0xFF) + t1 * (color2 & 0xFF);

    // Interpolate between the second and third colors
    r = (1 - t2) * r + t2 * ((color3 >> 16) & 0xFF);
    g = (1 - t2) * g + t2 * ((color3 >> 8) & 0xFF);
    b = (1 - t2) * b + t2 * (color3 & 0xFF);


    // Create the final color
    uint32_t finalColor = (uint32_t)0 << 24 | (uint32_t)(g) << 16 | (uint32_t)0 << 8 | 255;

    return finalColor;
}

uint32_t museum_palette(t_pixel pixel)
{
	// if (pixel.iteration == max_iteration)
	// 	return (0 << 24 | 0 << 16 | 0 << 8 | 255);
    // define gradient colors
    uint32_t color1 = 255 << 24 | 0 << 16 | 0 << 8 | 255;  // red
    uint32_t color2 = 0 << 24 | 255 << 16 | 0 << 8 | 255;  // green
    uint32_t color3 = 0 << 24 | 0 << 16 | 255 << 8 | 255;  // blue

    // calculate interpolation factors for color blending
    double t1 = (double)pixel.iteration / (double)max_iteration * (cosl(pixel.re / 3.14));
    double t2 = (double)(pixel.iteration - max_iteration) / (double)max_iteration;

    // interpolate between colors based on iteration count
    uint8_t r = (1 - t1 / 2) * ((color1 >> 16) & 0xff) + t1 * ((color2 >> 16) & 0xff);
    uint8_t b = (1 - t1) * ((color1 >> 8) & 0xff) + t1 * ((color2 >> 8) & 0xff);
    uint8_t g = (1 - t1 / 4) * (color1 & 0xff) + t1 * (color2 & 0xff);

    // interpolate between the second and third colors
    r = (1 - t2) * r + t2 * ((color3 >> 16) & 0xff);
    g = (1 - t2) * g + t2 * ((color3 >> 8) & 0xff);
    b = (1 - t2) * b + t2 * (color3 & 0xff);


    // create the final color
    uint32_t finalcolor = (uint32_t)r << 24 | (uint32_t)(0) << 16 | (uint32_t)g << 8 | 255;

    return finalcolor;
}

uint32_t vandetta_palette(t_pixel pixel)
{
    if (pixel.iteration == max_iteration)
        return 0; // Return black for points inside the set

    // Map iteration count to hue in the range [0, 360)
    double hue = fmod((double)pixel.iteration * 10, 360.0);

    // Set saturation and value to constant values
    double saturation = 1.0;
    double value = 1.0;

    // Convert HSV to RGB
    double C = value * saturation;
    double X = C * (1.0 - fabs(fmod(hue / 60.0, 2.0) - 1.0));
    double m = value - C;
    double Rs, Gs, Bs;

    if (hue >= 0 && hue < 60) {
        Rs = C;
        Gs = X;
        Bs = 0;
    } else if (hue >= 60 && hue < 120) {
        Rs = X;
        Gs = C;
        Bs = 0;
    } else if (hue >= 120 && hue < 180) {
        Rs = 0;
        Gs = C;
        Bs = X;
    } else if (hue >= 180 && hue < 240) {
        Rs = 0;
        Gs = X;
        Bs = C;
    } else if (hue >= 240 && hue < 300) {
        Rs = X;
        Gs = 0;
        Bs = C;
    } else {
        Rs = C;
        Gs = 0;
        Bs = X;
    }

    // Adjust RGB values to fit in the 8-bit range [0, 255]
    uint8_t r = (Rs + m) * 255;
    uint8_t g = (Gs + m) * 255;
    uint8_t b = (Bs + m) * 255;

    // Create the final color
    uint32_t finalColor = (uint32_t)r << 24 | (uint32_t)g << 16 | (uint32_t)b << 8 | 255;

    return finalColor;
}

uint32_t arrows_palette(t_pixel pixel)
{
	float C = pixel.iteration - log2f(logf(abs(pixel.im)) / M_LN2 );
	uint32_t color = ((uint8_t)((1+sin(C*0.89))*127.) << 24) | \
			  (uint8_t)((1+cos(C*0.15))*127.) << 16 | \
			  (uint8_t)((1+sin(C*0.55))*127.) << 8 | \
			   255;
	return (color);
} */


/* uint32_t starrynight_palette(int iterations, t_fol *f)
{
	long double ni = (long double)iterations / (long double)f->max_iter;
	unsigned char r = 9.0 * (1.0 - ni) * powl(ni, 3.0) * 255.0;
	unsigned char g = 15.0 * powl((1.0 - ni), 2.0) * powl(ni, 2.0) * 255.0;
	unsigned char b = 8.5 * powl((1.0 - ni), 3.0) * ni * 255.0;
	return ((b << 24) | (g << 16) | (r << 8) | 255);
} */
