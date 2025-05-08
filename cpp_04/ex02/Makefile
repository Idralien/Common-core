# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/27 17:26:59 by brsantsc          #+#    #+#              #
#    Updated: 2025/03/27 17:46:06 by brsantsc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	Abstract

CC				=	g++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98
RM				=	rm -f

SRCS			= AAnimal.cpp Brain.cpp Cat.cpp Dog.cpp main.cpp	
OBJS			=	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
