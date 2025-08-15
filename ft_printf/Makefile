# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 12:06:13 by brsantsc          #+#    #+#              #
#    Updated: 2024/05/02 09:45:49 by brsantsc         ###   ########.fr        #
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

HEADER = ft_printf.h
SRCS = ft_print_unsigned.c ft_print_hex.c \
       ft_print_str.c ft_print_ptr.c ft_print_char.c \
       ft_print_nbr.c ft_printf.c

OBJS = ${SRCS:.c=.o}

# **************************************************************************** #
#                                COMMANDS                                      #
# **************************************************************************** #

all: ${LIBFT} ${NAME}

%.o: %.c ${HEADER}
	@${CC} -c ${CFLAGS} -I ./ $< -o $@

${LIBFT}:
	@make -C ${LIBFT_PATH} all

${NAME}: ${OBJS}
	@cp libft/libft.a ${NAME}
	@${AR} ${NAME} ${OBJS}
	@echo "ft_printf Compiling SUCCESS!"

clean:
	@${RM} ${OBJS}
	@make -C ${LIBFT_PATH} clean
	@echo "ft_printf objects cleaned SUCCESS"

fclean: clean
	@make -C ${LIBFT_PATH} fclean
	@${RM} ${OBJS}
	@echo "ft_printf executable files cleaned SUCCESS"

re: fclean all

.PHONY: all clean fclean re
