# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 12:06:13 by brsantsc          #+#    #+#              #
#    Updated: 2024/04/24 12:04:55 by brsantsc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                VARIABLES                                     #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
RM = rm -f
AR = ar rcs
LIBFT_PATH = ./libft
LIBFT = ${LIBFT_PATH}/libft.a

# **************************************************************************** #
#                                SOURCES                                       #
# **************************************************************************** #

HEADER = printf.h
SRCS = ft_putunsigned.c ft_printhex.c \
       ft_printf_char.c ft_printf_str.c ft_printf_ptr.c \
       ft_printf_nbr.c ft_printf.c

OBJS = ${SRCS:.c=.o}

# **************************************************************************** #
#                                COMMANDS                                      #
# **************************************************************************** #

all: ${LIBFT} ${NAME}

${NAME}: ${OBJS}
	cp libft/libft.a ${NAME}
	${AR} ${NAME} ${OBJS}
	@echo "ft_printf Compiling SUCCESS!"

${LIBFT}:
	make -C ${LIBFT_PATH} all

%.o: %.c ${HEADER}
	${CC} -c ${CFLAGS} -I ./ $< -o $@

clean:
	${RM} ${OBJS}
	make -C ${LIBFT_PATH} clean
	@echo "ft_printf objects cleaned SUCCESS"

fclean: clean
	make -C ${LIBFT_PATH} fclean
	${RM} ${OBJS}
	@echo "ft_printf executable files cleaned SUCCESS"

re: fclean all

.PHONY: all clean fclean re
