# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsarana <vsarana@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 14:28:55 by rukoltso          #+#    #+#              #
#    Updated: 2024/11/28 13:21:17 by vsarana          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_memset.c				\
		ft_bzero.c				\
		ft_memcpy.c				\
		ft_memmove.c 			\
		ft_memchr.c				\
		ft_memcmp.c				\
		ft_strlen.c				\
		ft_isalpha.c 			\
		ft_isdigit.c			\
		ft_isprint.c			\
		ft_isalnum.c			\
		ft_isascii.c			\
		ft_toupper.c			\
		ft_tolower.c			\
		ft_strchr.c				\
		ft_strrchr.c			\
		ft_strncmp.c			\
		ft_strnstr.c			\
		ft_strlcpy.c			\
		ft_strncpy.c            \
		ft_strcpy.c				\
		ft_strlcat.c			\
		ft_atoi.c				\
		ft_calloc.c				\
		ft_strdup.c				\
		ft_substr.c				\
		ft_strjoin.c			\
		ft_strtrim.c			\
		ft_split.c				\
		ft_itoa.c				\
		ft_strmapi.c			\
		ft_putchar_fd.c			\
		ft_putstr_fd.c			\
		ft_putendl_fd.c			\
		ft_putnbr_fd.c			\
		ft_striteri.c			\
		ft_strtok.c				\
		get_next_line.c		\
		get_next_line_utils.c	\
		ft_isspace.c		\

SRCSB =	ft_lstnew_bonus.c		\
		ft_lstadd_front_bonus.c	\
		ft_lstsize_bonus.c		\
		ft_lstlast_bonus.c		\
		ft_lstadd_back_bonus.c	\
		ft_lstdelone_bonus.c	\
		ft_lstclear_bonus.c		\
		ft_lstiter_bonus.c		\
		ft_lstmap_bonus.c		\
		$(SRCS)

NAME = libft.a

OBJS_DIR = objs/
OBJS = $(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

OBJSB = $(SRCSB:.c=.o)
OBJECTS_BONUS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJSB))

CC = clang

CC_FLAGS = -Wall -Wextra -Werror -fPIE

$(OBJS_DIR)%.o : %.c libft.h
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling: $<"
	@clang $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJECTS_PREFIXED)
	@ar r $(NAME) $(OBJECTS_PREFIXED) > /dev/null 2>&1
	@echo "Libft Done !"

all: $(NAME)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJECTS_BONUS_PREFIXED)
	@ar r $(NAME) $(OBJECTS_BONUS_PREFIXED)
	@echo "Libft Bonus Done !"
