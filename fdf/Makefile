# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/22 14:32:54 by brsantsc          #+#    #+#              #
#    Updated: 2024/08/23 11:11:29 by brsantsc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME
NAME = fdf

SRC_DIR = src
OBJS_DIR = objs

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

HEADER = $(wildcard includes/*.h)

INCS = -I includes

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

MINILIBX = minilibx-linux

FMS = -L $(MINILIBX) -lmlx -L/usr/X11R6/lib -lXext -lX11 -lm

# COLOURS
GREEN = \033[0;92m
BLUE = \033[0;94m
RED = \033[0;91m
WHITE = \033[0;97m

.SILENT:

# COMMANDS
all: mlx tmp $(NAME)

mlx:
	@echo "$(BLUE)Building minilibx-linux$(WHITE)"
	@make -C $(MINILIBX)

tmp:
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	@$(CC) $(CFLAGS) $(INCS) -c -o $@ $<
	@echo "$(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(GREEN)[Done]$(WHITE)"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^ $(FMS)
	@echo "$(GREEN)Project successfully compiled$(WHITE)"

clean:
	@echo "$(RED)Deleting object files$(WHITE)"
	@$(RM) -rf $(OBJS_DIR)
	@make clean -C $(MINILIBX)

fclean: clean
	@echo "$(RED)Deleting executable$(WHITE)"
	@$(RM) -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re mlx tmp
