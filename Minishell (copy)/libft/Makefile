# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/11 12:40:14 by quvan-de          #+#    #+#              #
#    Updated: 2024/08/26 13:47:20 by quvan-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Standard

NAME		=	libft.a
INCLUDES	=	../include
SRCS_DIR 	=	src/
OBJS_DIR	=	obj/
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -I
RM			=	rm -f
AR			=	ar rcs

#Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#Sources

FTIS_DIR	=	checkers/
FTIS		=	ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint ft_arrlen \
				ft_isspace

FTMEM_DIR	=	mem/
FTMEM		=	ft_bzero ft_calloc ft_memchr ft_memcmp ft_memmove ft_memset \
				ft_free_2d_array

FTPUT_DIR	=	fd/
FTPUT		=	ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd

FTTO_DIR	=	conversions/
FTTO		=	ft_atoi ft_itoa ft_tolower ft_toupper

FTSTR_DIR	=	str/
FTSTR		=	ft_split ft_strchr ft_strdup ft_striteri ft_strjoin \
				ft_strlcat ft_strlcpy ft_strlen ft_strmapi ft_strncmp \
				ft_strnstr ft_strrchr ft_strtrim ft_substr ft_strcmp

FTLST_DIR	=	lists/
FTLST		=	ft_lstadd_back ft_lstadd_front ft_lstclear ft_lstdelone \
				ft_lstiter ft_lstlast ft_lstmap ft_lstnew ft_lstsize

SRC_FILES+=$(addprefix $(FTIS_DIR),$(FTIS))
SRC_FILES+=$(addprefix $(FTMEM_DIR),$(FTMEM))
SRC_FILES+=$(addprefix $(FTPUT_DIR),$(FTPUT))
SRC_FILES+=$(addprefix $(FTTO_DIR),$(FTTO))
SRC_FILES+=$(addprefix $(FTSTR_DIR),$(FTSTR))
SRC_FILES+=$(addprefix $(FTLST_DIR),$(FTLST))

SRCS 		= 	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS 		= 	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

###

OBJSF		=	.cache_exists

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(AR) $(NAME) $(OBJS)
			@ranlib $(NAME)
			@echo "$(GREEN)Libft compiled!$(DEF_COLOR)"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c | $(OBJSF)
	@printf "$(YELLOW)Compiling: $< $(DEF_COLOR)\r"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "\033[K"  # Clears the line after completion


$(OBJSF):
			@mkdir -p $(OBJS_DIR)
			@mkdir -p $(OBJS_DIR)$(FTIS_DIR)
			@mkdir -p $(OBJS_DIR)$(FTMEM_DIR)
			@mkdir -p $(OBJS_DIR)$(FTPUT_DIR)
			@mkdir -p $(OBJS_DIR)$(FTTO_DIR)
			@mkdir -p $(OBJS_DIR)$(FTSTR_DIR)
			@mkdir -p $(OBJS_DIR)$(FTLST_DIR)

clean:
			@$(RM) -rf $(OBJS_DIR)
			@$(RM) -f $(OBJSF)
			@echo "$(BLUE)libft objects files cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) -f $(NAME)
			@echo "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(GREEN)Cleaned and rebuilt everything for libft!$(DEF_COLOR)"

.PHONY:		all clean fclean re
