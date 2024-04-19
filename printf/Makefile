# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 12:06:13 by brsantsc          #+#    #+#              #
#    Updated: 2024/04/19 11:01:00 by brsantsc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#variables

CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprint.a
RM = rm -f
AR = ar rcs
LIBFT = libft

#sources

SRCS = ft_putunsigned.c ft_puthex.c ft_format.c ft_printf.c

OBJS = ${SRCS:.c=.o}

#commands

all: ${NAME}

${NAME}: ${OBJS}
	make -C ${LIBFT}
	cp libft/libft.a 
	mv libft.a ${NAME}
	${AR} ${NAME} ${OBJS}
	@echo "ft_printf Compiling SUCCESS!"

clean:
	${RM} ${OBJS}
	make clean -C ${LIBFT}
	@echo "ft_printf objects cleaned SUCCESS"

fclean: clean
	make clean -C ./libft
	${RM} ${NAME}
	@echo "ft_printf executable files cleaned SUCCESS"

re: fclean all

.PHONY: all clean fclean re
