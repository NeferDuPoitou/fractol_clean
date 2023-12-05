#include "MLX42.h"
#include "fractol.h"
#include "defines.h"
#include <stdlib.h>

void	error_and_quit(char *error_str)
{
	ft_printf("%s\n", error_str);
	exit(EXIT_SUCCESS);
}
