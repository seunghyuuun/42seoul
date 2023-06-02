# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/02 12:55:35 by seunghy2          #+#    #+#              #
#    Updated: 2023/06/02 17:49:12 by seunghy2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror
NAME=libftprintf
OBJS=test.c
LOBJS=libft.a

$(NAME) : $(OBJS) $(LOBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -L ./libft -l ft -I./libft

$(LOBJS) : 
	make -C ./libft bonus

fclean :
	make fclean -C ./libft
	rm -rf $(NAME)
