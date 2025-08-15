# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/25 17:29:26 by brsantsc          #+#    #+#              #
#    Updated: 2025/04/21 15:53:36 by brsantsc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= Fixed

CC				=	g++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
RM				=	rm -f

SRCS			=	main.cpp Fixed.cpp
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
