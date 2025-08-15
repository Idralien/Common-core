# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/27 16:50:54 by brsantsc          #+#    #+#              #
#    Updated: 2025/03/27 17:15:45 by brsantsc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	Brain

CC				=	g++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98
RM				=	rm -f

SRCS			=	main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp
OBJS			=	$(SRCS:.cpp=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
