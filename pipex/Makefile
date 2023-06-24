# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/19 19:00:55 by seunghy2          #+#    #+#              #
#    Updated: 2023/06/22 15:09:13 by seunghy2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror
NAME=pipex
LIB=libft/libft.a
SRCS=main.c free.c cmdmkr.c pathmkr.c ex.c error.c

.PHONY: all clean fclean re

all : $(NAME)

$(NAME) : $(SRCS) $(LIB)
	$(CC) $(CFLAGS) -o $@ $(SRCS) -L ./libft -lft

$(LIB) :
	make -C ./libft

clean :
	make -C ./libft fclean

fclean :
	make clean
	rm -f $(NAME)

re :
	make fclean
	make all
