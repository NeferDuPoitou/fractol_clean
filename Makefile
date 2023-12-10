NAME = fractol
SRC =  fractol.c \
	   mariani_boxes.c \
	   mariani_helpers.c \
	   burningjulia.c \
	   burningship.c \
	   check_args.c \
	   colors.c \
	   colors2.c \
	   error.c \
	   inputs.c \
	   inputs2.c \
	   instructions.c \
	   julia.c \
	   mandelbrot.c \
	   pixel_scaling.c \
	   choose_colors.c \
	   get_color_palette.c \
	   mlx_utils.c \
	   buddhabrot.c \
	   struct_init.c

OBJDIR = objs
OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
CC = gcc
CFLAGS = -O3 -fsanitize=address -g3 -I./MLX42/include/MLX42
LIBS = libft.a libftprintf.a libmlx42.a -lglfw -pthread -lm
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
