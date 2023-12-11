# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achatzit <achatzit@student.42mulhouse.fr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/16 10:39:52 by Gecko             #+#    #+#              #
#    Updated: 2023/12/11 20:28:40 by achatzit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = src/ft_printf.c           \
      src/pf_hexprint.c         \
      src/pf_putnbrs.c          \
      src/pf_memoryprint.c      \
      src/print_utils.c         \
      src/check_validity.c      \
      src/pf_parser.c           \
      src/size_getters.c        \
      src/size_getters2.c       \
      src/flags_utils.c         \
      src/pf_printer.c	    	\
      src/pf_null_gestion.c     \
      src/width_fillers.c       \
      src/precision_fillers.c   

OBJS = $(SRC:.c=.o)

BONUS = src_bonus/ft_printf_bonus.c         \
      src_bonus/pf_hexprint_bonus.c         \
      src_bonus/pf_putnbrs_bonus.c          \
      src_bonus/pf_memoryprint_bonus.c      \
      src_bonus/print_utils_bonus.c         \
      src_bonus/check_validity_bonus.c      \
      src_bonus/pf_parser_bonus.c           \
      src_bonus/size_getters_bonus.c        \
      src_bonus/size_getters2_bonus.c       \
      src_bonus/flags_utils_bonus.c         \
      src_bonus/pf_printer_bonus.c	      \
      src_bonus/pf_null_gestion_bonus.c     \
      src_bonus/width_fillers_bonus.c       \
      src_bonus/precision_fillers_bonus.c   

LIBS = ../libft.a

BONUS_OBJS = $(BONUS:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
AR = ar crs

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus : $(OBJS) $(BONUS_OBJS)
	 $(AR) $(NAME) $(OBJS)	$(BONUS_OBJS)	

.PHONY: all clean fclean re bonus
