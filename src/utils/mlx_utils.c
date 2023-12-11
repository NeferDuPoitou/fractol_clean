/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achatzit <achatzit@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:46:28 by achatzit          #+#    #+#             */
/*   Updated: 2023/12/11 13:23:31 by achatzit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

//workaround for not having access to a wait function in the project
void	mlx_wait(double seconds)
{
	double	start_time;

	start_time = mlx_get_time();
	while (1)
	{
		if (mlx_get_time() >= start_time + seconds)
			return ;
	}
}
