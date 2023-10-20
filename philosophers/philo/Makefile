# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/24 14:50:53 by seunghy2          #+#    #+#              #
#    Updated: 2023/10/20 14:45:47 by seunghy2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror
NAME=philo
SRCS=main.c init.c end.c schedul.c utils.c mutex.c

.PHONY: all clean fclean re

all : $(NAME)

$(NAME) : $(SRCS) philo.h
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

clean :
	rm -f *.o

fclean :
	make clean
	rm -f $(NAME)

re :
	make fclean
	make all
