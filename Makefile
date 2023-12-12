NAME = fractol
SRC =  src/fractol.c \
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
	   src/inputs/resize.c \
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
LIBS = ./libs/libft.a ./libs/libftprintf.a ./libs/libmlx42.a -lglfw -pthread -lm
RM = rm -rf

LIBFT = ./libs/libft.a
PRINTF = ./libs/libftprintf.a
MLX = ./libs/libmlx42.a

all: $(LIBFT) $(PRINTF) $(MLX) $(NAME)

lft: $(LIBFT)

$(LIBFT):
	@echo "\033[95mBuilding libft\033[0m"
	@make -s -C ./libft/
	@make -s -C ./libft/ clean
	@mv ./libft/libft.a ./libs/

$(PRINTF):
	@echo "\033[93;1mBuilding ft_printf\033[0m"
	@make -s -C ./ft_printf/
	@make -s -C ./ft_printf/ clean
	@mv ./ft_printf/libftprintf.a ./libs/

$(MLX):
	@cmake ./MLX42/ -B ./MLX42/build && make -s -C ./MLX42/build -j4
	@mv ./MLX42/build/libmlx42.a ./libs/
	@$(RM) ./MLX42/build
	@$(RM) ./MLX42/Cmakefiles

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	@printf "\033[93mCompiling $< "
	@printf "\033[0m\r"
	@$(CC) $(CFLAGS) -c $^ -o $@
	@printf "\033[K"

bonus: all

build_msg:
	@echo "\033[43mBuilding Fractol\033[0m"

clean:
	@$(RM) $(OBJDIR)
	@make -s -C ./libft/ clean
	@make -s -C ./ft_printf/ clean

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(MLX)
	@make -s -C ./libft/ fclean
	@make -s -C ./ft_printf/ fclean
	@rm ./libs/libftprintf.a
	@rm ./libs/libft.a

re: fclean all

.PHONY: all clean fclean bonus build_msg re
