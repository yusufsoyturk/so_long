NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRCS = gnl/get_next_line.c \
	gnl/get_next_line_utils.c \
	src/main.c \
	src/controls_for_map.c \
	src/controls_in_map.c \
	src/create_char_map.c \
	src/create_map.c \
	src/free.c \
	src/fill_map.c \
	src/flood_fill.c \
	src/unreachable_exit.c \
	src/map_mlx.c \
	src/key_press.c \
	src/movement.c 

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a
PRINTF = ft_printf/ft_printf.a
MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

LIBS = $(PRINTF) $(LIBFT) $(MLX)

all: $(NAME)

$(LIBFT):
	make -C libft

$(PRINTF):
	make -C ft_printf

$(MLX):
	@echo "Compiling MiniLibX..."
	cd $(MLX_DIR) && ./configure && make

$(NAME): $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME) -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd

clean:
	$(RM) $(OBJS)
	make -C libft clean
	make -C ft_printf clean
	[ -f $(MLX) ] && make -C $(MLX_DIR) clean || true

fclean: clean
	make -C libft fclean
	make -C ft_printf fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
