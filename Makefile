# NAME = fractol
# SRC =  fractol.c	\
# 	   mariani_boxes.c	\
# 	   burningjulia.c	\
# 	   burningship.c	\
# 	   check_args.c	\
# 	   colors.c	\
# 	   error.c	\
# 	   inputs.c	\
# 	   instructions.c	\
# 	   julia.c	\
# 	   mandelbrot.c	\
# 	   pixel_scaling.c	\
# 	   struct_init.c	\
#
# OBJDIR = objs
# OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
# CC = gcc
# CFLAGS = -Wall -Wextra -Werror -O3 -fsanitize=address -g3
# LIBS = libft.a libftprintf.a libmlx42.a
# RM = rm -rf
#
# $(NAME): $(OBJS)
# 	$(CC) $(LIBS) $(CFLAGS)  -o $(NAME)  $(OBJS)
#
# $(OBJDIR)/%.o: %.c
# 	@mkdir -p $(@D)
# 	$(CC) $(CFLAGS) -c $^ -o $@
#
# all: $(NAME)
#
# bonus: $(NAME)
#
# clean:
# 	$(RM) $(OBJDIR)
#
# fclean: clean
# 	$(RM) $(NAME) $(NAME2)
#
# re: fclean all
#
# .phony: all clean fclean bonus debug

NAME = fractol
SRC =  fractol.c \
	   mariani_boxes.c \
	   mariani_helpers.c \
	   burningjulia.c \
	   burningship.c \
	   check_args.c \
	   colors.c \
	   error.c \
	   inputs.c \
	   instructions.c \
	   julia.c \
	   mandelbrot.c \
	   pixel_scaling.c \
	   choose_colors.c \
	   struct_init.c

OBJDIR = objs
OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3 -fsanitize=address -g3 -I./MLX42/include/MLX42
LIBS = libft.a libftprintf.a libmlx42.a -lglfw
RM = rm -rf

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(NAME)

bonus: $(NAME)

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean bonus debug
