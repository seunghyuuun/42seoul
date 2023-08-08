# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/08 14:10:38 by seunghy2          #+#    #+#              #
#    Updated: 2023/08/08 14:10:58 by seunghy2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror
NAME=philo_bonus
SRCS=main_bonus.c

.PHONY: all clean fclean re

all : $(NAME)

$(NAME) : $(SRCS) philo_bonus.h
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

clean :
	rm -f *.o

fclean :
	make clean
	rm -f $(NAME)

re :
	make fclean
	make all
