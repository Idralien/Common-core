# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/20 15:06:07 by brsantsc          #+#    #+#              #
#    Updated: 2025/03/21 15:34:49 by brsantsc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	zombie

CC					=	g++
CXXFLAGS		= -Wall -Werror -Wextra -std=c++98
RM					=	rm -f

SRCS				=	main.cpp newZombie.cpp randomChump.cpp Zombie.cpp	
OBJS				=	$(SRCS:.cpp=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CXXFLAGS) -o $(NAME) $(OBJS)

.o: %.cpp
	$(CC) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(NAME)

fclean:	clean

re: fclean all

.PHONY:	all clean fclean re
