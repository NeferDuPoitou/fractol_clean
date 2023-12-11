/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achatzit <achatzit@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:56:57 by Gecko             #+#    #+#             */
/*   Updated: 2023/12/11 12:39:39 by achatzit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
// pour tests
# include <stdio.h>
#include "libft/libft.h"

////////////////////////////////////////
//           FT_PRINTF                //
////////////////////////////////////////

typedef struct s_flags
{
	int		min_width;
	int		left_justify;
	int		zero_fill;
	int		base_prefix;
	int		force_sign;
	int		pos_spaced;
	int		period;
	int		precision;
	char	format;
	int		isnull;
	int		is_negative;
	int		is_zero;
	int		is_hexa;
	int		write_error;
}	t_flags;

int		ft_printf(const char *format, ...);

//
// FUNCTIONS THAT HANDLE PARSING THE ENTIRE STRING, CALLIG FLAGS PARSER/PRINTER
//
int		str_parser(const char *format, va_list args, t_flags *flags, int *len);
void	var_parser(const char **format, va_list args, t_flags *flags, int *len);

//
// FUNCTIONS HANDLING PRINTING CONVERSIONS
// 
void	print_memory_adress(const void *ptr, t_flags *flags, int *len);
void	print_hex_digits(int digit, int *len);
void	print_hex_digit(int digit, t_flags *flags, int *len);
void	putnbr_base16(int nb, t_flags *flags, int *len);
void	rec_putnbr(int nb, char *case_type, int *len);
void	unsigned_putnbr(unsigned int nb, t_flags *flags, int *len);
void	ft_putnbr(long int nb, t_flags *flags, int *len);
void	print_base_prefix(t_flags *flags, int *len);
void	base_prefix_helper1(t_flags *flags, int *len);
void	base_prefix_helper2(t_flags *flags, int *len);
void	non_s_checker(int *local_len, t_flags *flags, va_list args);
void	print_filler_prefix(t_flags *flags, int local_len, int *len);
//
// PRINT UTILS
//
// PUTSTR : PRECISION = -1 : NORMAL PUTSTR BEHAVIOR 
// OTHERWISE, ONLY PRINTS PRECISION CHARS //
void	ft_putstr(const char *s, int precision, int *len, t_flags *flags);
void	ft_putchar(char c, t_flags *flags);
// LIKE A PUTCHAR, BUT TAKES THE LEN AND UPDATES IT //
void	ft_putchar_len(char c, int *len, t_flags *flags);
// int		ft_strlen(const char *s);

void	init_flags(t_flags *flags);
int		format_isvalid(char format);
int		flag_isvalid(char flag);
int		check_isnull_and_print(t_flags *flags, int *len);

// LOCAL LEN IS THE LEN OF THE VARIABLE AFTER ALL THE SPECIAL CASE
// FLAGS ARE APPLIED
int		get_local_len(va_list args, t_flags *flags);

//
// PRECISION FILLERS (0 and spaces)
//
void	precision_filler_left_justify(va_list args, t_flags *flags, int *len);
void	precision_filler_right_justify(va_list args, t_flags *flags, int *len);

//
// SIZE GETTERS
//
int		get_digits_count_int(int nb, t_flags *flags);
int		get_digits_count_u(unsigned int nb, t_flags *flags);
int		get_hex_adress_len(const void *ptr, t_flags *flags);
int		get_hex_digits(int nb, t_flags *flags);
int		get_str_size(char *s, t_flags *flags);
int		get_size(va_list args, t_flags *flags);
void	get_difference(t_flags *flags, int *difference, int local_len);

//
// FLAGS PARSER 
//
void	check_flags(const char **str, t_flags *flags);
void	check_width(const char **str, t_flags *flags);
void	check_precision(const char **str, t_flags *flags);
int		check_format(char c, t_flags *flags);
int		flags_parser(const char **str, t_flags *flags);

//
// PRINTER
//
//
void	print_fillers(t_flags *flags, int local_len, int difference, int *len);
void	min_width_right_justify(va_list args, t_flags *flags, int *len);
void	min_width_left_justify(va_list args, t_flags *flags, int *len);
void	sign_flags_print(va_list args, t_flags *flags, int *len);
void	print_variable(va_list args, t_flags *flags, int *len);
void	pf_printer(va_list args, t_flags *flags, int *len);

void	flag_error(t_flags *flags, int *len);

// 
// CUTE LITTLE GUY
//
void	is_zero(int nb, t_flags *flags);

#endif
