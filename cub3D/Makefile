# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 15:33:45 by brsantsc          #+#    #+#              #
#    Updated: 2025/02/26 11:43:30 by brsantsc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
MLX = minilibx-linux
LIB = -L $(MLX) -lmlx -L/usr/X11R6/lib -lXext -lX11 -lm

SRCS = 	main.c cub_file_parser.c cub_file_parser_2.c \
				cub_file_parser_3.c cub_file_parser_4.c \
				ft_split.c image.c init.c libft.c libft_2.c  map.c player.c \
				render_1.c render_2.c utils.c

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
