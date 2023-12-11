/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achatzit <achatzit@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:31:07 by achatzit          #+#    #+#             */
/*   Updated: 2023/12/11 12:42:23 by achatzit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static int	check_julia_const(char *julia_const_str, int type)
{
	float	julia_const;

	if (!ft_isdigit(julia_const_str[0]) && (julia_const_str[0] != '+' \
	&& julia_const_str[0] != '-' && julia_const_str[0] != '.'))
		error_and_quit(DONT_BREAK);
	julia_const = atof(julia_const_str);
	printf("%f\n", julia_const);
	if (type == 'x')
	{
		if ((julia_const > SCALEDX_MAX || julia_const < SCALEDX_MIN))
			return (0);
	}
	else if (type == 'y')
	{
		if ((julia_const > SCALEDY_MAX || julia_const < SCALEDY_MIN))
			return (0);
	}
	return (1);
}

static int	first_arg_validator(char *s)
{
	if ((ft_strcmp(s, ARG_HELP) && ft_strcmp(s, ARG_MANDEL) && \
	ft_strcmp(s, ARG_JULIA) && ft_strcmp(s, ARG_BURNINGSHIP) && \
	ft_strcmp(s, ARG_BURNINGJULIA) && \
	ft_strcmp(s, ARG_BUDDHA)))
		return (0);
	return (1);
}

void	arg_parser(int argc, char **argv, t_fol *f)
{
	if (argc == 1)
		error_and_quit(NO_ARG);
	else if (argc == 2 && (!ft_strcmp(argv[1], ARG_HELP)))
		general_instructions();
	else if (argc == 2 && (!ft_strcmp(argv[1], ARG_CTRL)))
		keybinds_instructions();
	else if (argc > 4)
		error_and_quit(TOO_MANY_ARGS);
	else if (!ft_strcmp(argv[1], ARG_BUDDHA) && argc > 2)
		error_and_quit(BUDDHA_TOO_MANY_ARG);
	else if (argc < 4 && !first_arg_validator(argv[1]))
		error_and_quit(WRONG_ARG);
	else if (argc > 2 && (!ft_strcmp(argv[1], ARG_JULIA) || \
	!ft_strcmp(argv[1], ARG_BURNINGJULIA)))
	{
		ft_printf("argc : %d\n", argc);
		if (argc == 3)
			error_and_quit(TOO_FEW_CONSTS);
		else if ((argc == 4 && !check_julia_const(argv[2], 'x')) || \
		!check_julia_const(argv[3], 'y'))
			error_and_quit(ERR_JULIA_CONST);
		f->julia_has_consts = 1;
	}
	else if (argc == 2 && !ft_strcmp(argv[1], ARG_JULIA))
		f->julia_has_consts = 0;
}
