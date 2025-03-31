# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/12 15:56:33 by brsantsc          #+#    #+#              #
#    Updated: 2025/03/19 16:50:00 by brsantsc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Phonebook

CC			= g++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98

SRCS		= main.cpp Contact.cpp PhoneBook.cpp

OBJS		= $(SRCS:.cpp=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CXXFLAGS) -o $(NAME) $(OBJS)

.o: %.cpp
	$(CC) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
