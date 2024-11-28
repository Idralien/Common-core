# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 12:14:28 by brsantsc          #+#    #+#              #
#    Updated: 2024/11/28 10:27:03 by brsantsc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = philo

CC = cc
CFLAGS = -Wall -Werror -Wextra -pthread -g
RM = rm -rf

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

SOURCES = main.c memory.c utils.c ft_atol.c \
					init.c routine.c

OBJS = $(SOURCES:.c=.o)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Project successfully compiled$(DEF_COLOR)"

all:		$(NAME)

clean:
	@$(RM) $(OBJS)
	@echo "$(RED)Deleting Objects$(DEF_COLOR)"

fclean:	clean
	@$(RM) $(NAME)
	@echo "$(RED)Deleting with fclean$(DEF_COLOR)"

re: fclean all

.PHONY: re clean fclean all
