NAME = cub3D
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
MLX = minilibx-linux
LIB = -L $(MLX) -lmlx -L/usr/X11R6/lib -lXext -lX11 -lm

SRCS = main.c parse.c render.c raycast.c utils.c movement.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

mlx:
		@echo "Building mlx-linux"
		@make	-C $(MLX)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
