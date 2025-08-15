# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/24 14:17:03 by brsantsc          #+#    #+#              #
#    Updated: 2025/03/24 16:10:36 by brsantsc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	zombies

CC					=	g++
CXXFLAGS		=	-Wall -Werror -Wextra -std=c++98
RM					=	rm -f

SRCS				=	main.cpp Zombie.cpp zombieHorde.cpp 
OBJS				=	$(SRCS:.cpp=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CXXFLAGS) -o $(NAME) $(OBJS)

.o: %.cpp
	$(CC) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
