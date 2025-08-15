# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/24 16:50:05 by brsantsc          #+#    #+#              #
#    Updated: 2025/03/24 16:55:20 by brsantsc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	violence

CC			=	g++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98
RM			=	rm -f

SRCS		=	main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJS		=	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
