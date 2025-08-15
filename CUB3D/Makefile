# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/06 16:29:43 by quvan-de          #+#    #+#              #
#    Updated: 2025/03/06 16:57:59 by quvan-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
INCLUDES = inc
SRCS_DIR = src
OBJS_DIR = objs
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
LIBFT = libft
MLX = mlx_linux

# Colors
DEF_COLOR = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;92m
BLUE = \033[0;94m
WHITE = \033[0;97m

# Find all .c files in the src directory and its subdirectories
SOURCES = $(shell find $(SRCS_DIR) -type f -name "*.c")
OBJS = $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SOURCES))

all: lib mlx tmp $(NAME)

lib:
	@echo "$(GREEN)Creating lib files$(BLUE)"
	@make -C $(LIBFT) > /dev/null

mlx:
	@echo "$(GREEN)Creating mlx files$(BLUE)"
	@make -C $(MLX) > /dev/null 2>&1

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -L $(LIBFT) -L $(MLX) -I $(INCLUDES) -I $(MLX) -o $@ $(OBJS) -lft -lm -lmlx -lXext -lX11
	@echo "$(GREEN)Project successfully compiled$(DEF_COLOR)"

# Ensure objs directory is created
tmp:
	@mkdir -p $(OBJS_DIR)

# Rule to compile object files from sources (handle subdirectories)
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCLUDES)/cub3d.h
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I $(INCLUDES) -c -o $@ $<
	@echo "$(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(RED)[Done]$(WHITE)"

clean:
	@echo "$(RED)Deleting object files$(BLUE)"
	@make clean -C $(LIBFT) > /dev/null
	@make clean -C $(MLX) > /dev/null 2>&1
	@$(RM) $(OBJS_DIR)

fclean: clean
	@echo "$(RED)Deleting binary and library files$(BLUE)"
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT) > /dev/null
	@make clean -C $(MLX) > /dev/null 2>&1

re: fclean all

.PHONY: all lib mlx tmp clean fclean re
