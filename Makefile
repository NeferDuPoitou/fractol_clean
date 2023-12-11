NAME = fractol
SRC =  fractol.c \
	   src/shape_checker/mariani_boxes.c \
	   src/shape_checker/mariani_helpers.c \
	   src/sets/burningjulia.c \
	   src/sets/burningship.c \
	   src/args/check_args.c \
	   src/colors/colors.c \
	   src/colors/colors2.c \
	   src/args/error.c \
	   src/inputs/inputs.c \
	   src/inputs/inputs2.c \
	   src/args/instructions.c \
	   src/sets/julia.c \
	   src/sets/mandelbrot.c \
	   src/utils/pixel_scaling.c \
	   src/inputs/choose_colors.c \
	   src/colors/get_color_palette.c \
	   src/utils/mlx_utils.c \
	   src/sets/buddhabrot.c \
	   src/sets/buddhabrot_helpers.c \
	   src/utils/struct_init.c

OBJDIR = objs
OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
CC = gcc
CFLAGS = -O3 -Wall -Wextra -Werror -fsanitize=address -g3 -I./MLX42/include/MLX42
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
