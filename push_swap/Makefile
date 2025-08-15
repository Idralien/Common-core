# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 08:30:04 by brsantsc          #+#    #+#              #
#    Updated: 2024/06/18 08:40:23 by brsantsc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# 								NAME										   #
# **************************************************************************** #

NAME = push_swap

# **************************************************************************** #
# 								DIRECTORIES									   #
# **************************************************************************** #

INCLUDES = includes
SRCS_DIR = src
OBJS_DIR = objs
LIBFT = libft

# **************************************************************************** #
# 								COMPILER AND CFLAGS							   #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

# **************************************************************************** #
# 								COLOURS										   #
# **************************************************************************** #

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m


# **************************************************************************** #
# 								SOURCES										   #
# **************************************************************************** #

SOURCES = big_sort.c checks.c cost_utils.c free.c input.c \
	  move_utils.c push.c push_swap.c rev_rotate.c \
	  rotate.c sort_three.c stack.c swap.c libft_functions.c


# **************************************************************************** #
# 								COMMANDS									   #
# **************************************************************************** #

SRCS = $(addprefix $(SRCS_DIR)/,$(SOURCES))
OBJS = $(addprefix $(OBJS_DIR)/,$(SOURCES:.c=.o))

all: lib tmp $(NAME)

lib:
	@echo "$(GREEN)Creating library$(BLUE)"
	@make -C $(LIBFT)

tmp:
	@mkdir -p objs

 $(NAME): $(OBJS)
	$(CC) $(FLAGS) -L $(LIBFT) -o $@ $^ -lft -lm
	@echo "$(GREEN)Project successfully compiled"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCLUDES)/$(NAME).h
	@$(CC) $(FLAGS) -c -o $@ $<
	@echo "$(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(RED)[Done]$(WHITE)"

clean:
	@echo "$(RED)Deleting Objects$(BLUE)"
	@make clean -C $(LIBFT)
	@rm -rf $(OBJS_DIR)
	@echo "$(Green)DONE"

fclean:
	@echo "$(RED)Deleting with fclean$(BLUE)"
	@rm -rf $(OBJS_DIR)
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)
	@echo "$(RED)All the files are cleaned"

re: fclean all

.PHONY: tmp, re, fclean, clean
