# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/13 14:04:05 by brsantsc          #+#    #+#              #
#    Updated: 2025/02/17 10:49:04 by brsantsc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D
CC			=	gcc
CFLAGS	=	-Wall -Wextra -Werror -fsanitize=address -g
MLX			=	minilibx-linux
LIB			=	-L $(MLX) -lmlx -L/usr/X11R6/lib -lXext -lX11 -lm

SRCS		= main.c image.c keys.c player.c render.c init.c libft.c ft_split.c

OBJS		=	$(SRCS:.c=.o)

all:	$(NAME)

mlx:
	@echo "Building mlx-linux"
	@make -C $(MLX)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
