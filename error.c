/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achatzit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:53:25 by achatzit          #+#    #+#             */
/*   Updated: 2023/12/10 10:53:26 by achatzit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "fractol.h"
#include "defines.h"
#include <stdlib.h>

void	error_and_quit(char *error_str)
{
	ft_printf("%s\n", error_str);
	exit(EXIT_SUCCESS);
}
