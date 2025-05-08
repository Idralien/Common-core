# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/27 14:52:31 by brsantsc          #+#    #+#              #
#    Updated: 2025/03/27 16:30:54 by brsantsc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	Polymorph

CC				=	g++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98
RM				=	rm -f

SRCS			=	main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp	
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
