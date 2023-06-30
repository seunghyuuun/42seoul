# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/30 14:12:35 by seunghy2          #+#    #+#              #
#    Updated: 2023/06/30 18:44:25 by seunghy2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror
NAME=push_swap
LIB=libft/libft.a
SRCS=main.c abstack.c idata.c free.c initial.c pivot.c restbig.c restsmall.c end.c ntimes.c

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
