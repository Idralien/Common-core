# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/17 14:01:31 by brsantsc          #+#    #+#              #
#    Updated: 2024/07/17 14:06:58 by brsantsc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	printf.a

SRCS	=	./src/ft_printf.c \
			./src/ft_printf_chars.c \
			./src/ft_printf_numbers.c \
			./src/libft_utils.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -f
AR		=	ar rcs

all:		$(NAME)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all fclean clean re
