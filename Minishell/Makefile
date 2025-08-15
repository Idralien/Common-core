# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 15:48:37 by quvan-de          #+#    #+#              #
#    Updated: 2024/09/27 00:04:08 by quvan-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Basics
NAME = minishell
INCLUDES = includes
SRCS_DIR = srcs
OBJS_DIR = objs
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

# Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# Source files
BLOCKS = fill_block.c heredoc.c

BUILTINS = cd.c echo.c env.c exit.c export.c pwd.c unset.c

EXECUTION = execution.c fill_env.c get_path.c

LIB_SRC = ft_cat_cpy.c ft_itoa.c ft_split.c lib_utils.c lib_utils1.c

MINISH = exite.c minishell.c signals.c

PARSER = expansion.c parser.c subsplit.c trim_q.c

UTILS = block_u.c block_u1.c builtin_u.c check_input.c error.c \
                expansions.c free.c parser_u.c

SOURCES = $(BLOCKS) $(BUILTINS) $(EXECUTION) $(LIB_SRC) $(MINISH) $(PARSER) $(UTILS)

SRCS = $(addprefix $(SRCS_DIR)/,$(SOURCES))
OBJS = $(addprefix $(OBJS_DIR)/,$(SOURCES:.c=.o))

# Phony targets to avoid name conflicts
.PHONY: all tmp clean fclean re

.SILENT:

all: tmp $(NAME)

tmp:
	@mkdir -p $(OBJS_DIR)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^ -lm -lreadline
	@echo "\n$(GREEN)Project successfully compiled!$(DEF_COLOR)"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/**/%.c $(INCLUDES)
	@echo -n "$(DEF_COLOR) $(GREEN)$(notdir $@)$(DEF_COLOR) "
	printf "\r";
	@spinner='/-\\|';
	$(CC) $(CFLAGS) -c -o $@ $<;

clean:
	@echo "$(RED)Deleting object files...$(DEF_COLOR)"
	@$(RM) $(OBJS_DIR)
	@echo "$(GREEN)Objects cleaned$(DEF_COLOR)"

fclean: clean
	@echo "$(RED)Deleting executable...$(DEF_COLOR)"
	@$(RM) $(NAME)
	@echo "$(GREEN)All files cleaned with fclean$(DEF_COLOR)"

re: fclean all
