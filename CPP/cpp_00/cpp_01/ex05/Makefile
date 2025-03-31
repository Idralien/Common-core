# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/25 16:24:06 by brsantsc          #+#    #+#              #
#    Updated: 2025/03/25 16:36:52 by brsantsc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	Harl

CC				=	g++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98
RM				=	rm -f

SRCS			=	main.cpp Harl.cpp
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
