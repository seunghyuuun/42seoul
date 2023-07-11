# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/11 16:27:20 by seunghy2          #+#    #+#              #
#    Updated: 2023/07/11 16:35:30 by seunghy2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror
NAME=so_long
SRCS=main.c
LIBMLX=./minilibx/libmlx.a
LIBFT=./libft/libft.a

.PHONY: all clean fclean re

all : $(NAME)

$(NAME) : $(SRCS) $(LIBMLX) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) -L ./minilibx -lmlx -L ./libft -lft -framework OpenGL -framework AppKit -lz

$(LIBMLX) :
	make -C ./minilibx

$(LIBFT) :
	make -C ./libft

clean :
	make -C ./minilibx clean
	make -C ./libft fclean

fclean :
	make clean
	rm -rf $(NAME)

re :
	make fclean
	make all
