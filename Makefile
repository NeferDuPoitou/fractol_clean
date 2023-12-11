# NAME = fractol
# SRC =  fractol.c \
# 	   src/shape_checker/mariani_boxes.c \
# 	   src/shape_checker/mariani_helpers.c \
# 	   src/sets/burningjulia.c \
# 	   src/sets/burningship.c \
# 	   src/args/check_args.c \
# 	   src/colors/colors.c \
# 	   src/colors/colors2.c \
# 	   src/args/error.c \
# 	   src/inputs/inputs.c \
# 	   src/inputs/inputs2.c \
# 	   src/inputs/scroll.c \
# 	   src/args/instructions.c \
# 	   src/sets/julia.c \
# 	   src/sets/mandelbrot.c \
# 	   src/utils/pixel_scaling.c \
# 	   src/inputs/choose_colors.c \
# 	   src/colors/get_color_palette.c \
# 	   src/utils/mlx_utils.c \
# 	   src/sets/buddhabrot.c \
# 	   src/sets/buddhabrot_helpers.c \
# 	   src/utils/struct_init.c
#
# OBJDIR = objs
# OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
# CC = gcc
# CFLAGS = -O3 -Wall -Wextra -Werror -fsanitize=address -g3 -I./MLX42/include/MLX42
# LIBS = libft.a libftprintf.a libmlx42.a -lglfw -pthread -lm
# RM = rm -rf
#
# $(LIBMLX):
# 		@make -C MLX42/ -B MLX42/build && make -C $ MLX42/build -j4
# 		$(RM) MLX42/build
# 		$(RM) MLX42/CmakeFiles
#
# $(NAME): $(llol) $(OBJS) 
# 	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)
#
# llol:
# 	@make -C ./libft/ all
# 	@make -C ./libft/ clean
#
# DO_LIBS: $(llol)
#
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
# 	$(RM) $(NAME)
#
# re: fclean all
#
# .PHONY: all clean fclean bonus

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
	   src/inputs/scroll.c \
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
LIBS = ./libft/libft.a libftprintf.a libmlx42.a -lglfw -pthread -lm
RM = rm -rf

LIBFT = ./libft/libft.a
MLX = ./libmlx42.a

all: $(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	@make -C ./libft/
	@make -C ./libft/ clean

$(MLX):
	@cmake ./MLX42/ -B ./MLX42/build && make -C ./MLX42/build -j4
	@mv ./MLX42/build/$@ ./
	@$(RM) ./MLX42/build
	@$(RM) ./MLX42/Cmakefiles

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $^ -o $@

bonus: all

clean:
	$(RM) $(OBJDIR)
	@make -C ./libft/ clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(MLX)
	@make -C ./libft/ fclean

re: fclean all

.PHONY: all clean fclean bonus llol
