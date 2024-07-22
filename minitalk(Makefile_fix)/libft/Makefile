# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/03 10:42:09 by brsantsc          #+#    #+#              #
#    Updated: 2024/07/19 11:51:41 by brsantsc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# 									COLOURS                                    #
# **************************************************************************** #

DEF_COLOR		=	\033[0;39m
GRAY			=	\033[0;90m
RED				=	\033[0;91m
GREEN			=	\033[0;92m
YELLOW			=	\033[0;93m
BLUE			=	\033[0;94m
MAGENTA			=	\033[0;95m
CYAN			=	\033[0;96m
WHITE			=	\033[0;97m

# **************************************************************************** #
# 									NAME                                       #
# **************************************************************************** #

NAME			=	libft.a

# **************************************************************************** #
# 								DIRECTORIES                                    #
# **************************************************************************** #

INCLUDES		=	-Iinclude
SRCS_DIR		=	src/
OBJS_DIR		=	obj/

# **************************************************************************** #
# 							COMPILER AND CFLAGS                        		   #
# **************************************************************************** #

CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra
RM				=	rm -f
AR				=	ar rcs

# **************************************************************************** #
# 									SOURCES                                    #
# **************************************************************************** #

FTCHECK_DIR		=	checkers/
FTCHECK			=	ft_isdigit ft_isalnum ft_isascii ft_isalpha \
					ft_isprint

FTMEM_DIR		=	memory/
FTMEM 			=	ft_bzero ft_calloc ft_memchr ft_memcmp \
					ft_memmove ft_memset

FTFD_DIR		=	fd/
FTFD			=	ft_putchar_fd ft_putendl_fd ft_putnbr_fd \
					ft_putstr_fd

FTCONVERT_DIR	=	converters/
FTCONVERT 		=	ft_atoi ft_itoa ft_tolower ft_toupper

FTSTR_DIR 		=	string/
FTSTR			=	ft_split ft_strchr ft_strdup ft_striteri \
					ft_strjoin ft_strlcat ft_strlcpy ft_strlen \
					ft_strmapi ft_strncmp ft_strnstr ft_strrchr \
					ft_strtrim ft_substr

FTLIST_DIR		=	lists/
FTLIST			=	ft_lstadd_back ft_lstadd_front ft_lstclear \
					ft_lstdelone ft_lstiter ft_lstlast ft_lstmap \
					ft_lstnew ft_lstsize

FTBIT_DIR		=	bit/
FTBIT			=	ft_clearbit ft_isbitset ft_setbit ft_togglebit

FTPRINTF_DIR	=	ft_printf/
FTPRINTF		=	ft_printf_chars ft_printf ft_printf_numbers 

FTNEXT_DIR		=	get_next_line/
FTNEXT			=	get_next_line get_next_line_utils
		
SRC_FILES+=$(addprefix $(FTCHECK_DIR),$(FTCHECK))
SRC_FILES+=$(addprefix $(FTMEM_DIR),$(FTMEM))		
SRC_FILES+=$(addprefix $(FTFD_DIR),$(FTFD))		
SRC_FILES+=$(addprefix $(FTCONVERT_DIR),$(FTCONVERT))		
SRC_FILES+=$(addprefix $(FTSTR_DIR),$(FTSTR))		
SRC_FILES+=$(addprefix $(FTLIST_DIR),$(FTLIST))		
SRC_FILES+=$(addprefix $(FTBIT_DIR),$(FTBIT))		
SRC_FILES+=$(addprefix $(FTPRINTF_DIR),$(FTPRINTF))
SRC_FILES+=$(addprefix $(FTNEXT_DIR),$(FTNEXT))

SRCS 			=	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS			=	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

# **************************************************************************** #
# 									COMMANDS                                   #
# **************************************************************************** #

OBJSF	=	.cache_exists

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(AR) $(NAME) $(OBJS)
			@ranlib $(NAME)
			@echo "$(GREEN)Libft compiled!$(DEF_COLOR)"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c | $(OBJSF)
			@mkdir -p $(@D)
			@echo "$(CYAN)Compiling: $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJSF):
			@mkdir -p $(OBJS_DIR)
			@mkdir -p $(OBJS_DIR)$(FTCHECK_DIR)
			@mkdir -p $(OBJS_DIR)$(FTMEM_DIR)
			@mkdir -p $(OBJS_DIR)$(FTFD_DIR)
			@mkdir -p $(OBJS_DIR)$(FTCONVERT_DIR)
			@mkdir -p $(OBJS_DIR)$(FTSTR_DIR)
			@mkdir -p $(OBJS_DIR)$(FTLIST_DIR)
			@mkdir -p $(OBJS_DIR)$(FTBIT_DIR)
			@mkdir -p $(OBJS_DIR)$(FTPRINTF_DIR)
			@mkdir -p $(OBJS_DIR)$(FTNEXT_DIR)


clean:
			@$(RM) -rf $(OBJS_DIR)
			@$(RM) -f $(OBJSF)
			@echo "$(YELLOW)Libft cleaned!$(DEF_COLOR)"

fclean: 	clean
			@$(RM) -f $(NAME)
			@echo "$(YELLOW)Libft exe files cleaned!$(DEF_COLOR)"

re: 		fclean all
			@echo "$(GREEN)Libft cleaned and rebuilt success!$(DEF_COLOR)"

.PHONY : all clean fclean re include
