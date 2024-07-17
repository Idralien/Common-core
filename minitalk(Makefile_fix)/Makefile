# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/17 13:53:18 by brsantsc          #+#    #+#              #
#    Updated: 2024/07/17 13:59:38 by brsantsc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER		=	server
CLIENT		=	client

PRINTF		=	ft_printf

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -I$(PRINTF)/headers -L$(PRINTF) -lftprintf
RM			=	rm -rf

all:
		@make -s -C $(PRINTF)
		@$(CC) $(FLAGS) server.c -o $(SERVER)
		@$(CC) $(FLAGS) client.c -o $(CLIENT)
		@echo "Minitalk is ready"

clean:
		@echo "Deleting objects"
		@make clean -s -C $(PRINTF)
		@echo "MINITALK: DONE"

fclean:
		@echo "Deleting zith fclean"
		@$(RM) $(SERVER) $(CLIENT)
		@make fclean -C $(PRINTF)
		@echo "All MINITALK files are cleaned"

re: 	fclean all

.PHONY: re clean fclean all
