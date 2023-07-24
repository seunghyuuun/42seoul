# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/24 14:50:53 by seunghy2          #+#    #+#              #
#    Updated: 2023/07/24 18:48:28 by seunghy2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror
NAME=philo
SRCS=main.c init.c end.c schedul.c
BSRCS=a

.PHONY: all clean fclean re bonus

all : $(NAME)

$(NAME) : manda_flag

manda_flag : $(SRCS) $(LIB) philo.h
	rm -f $(NAME)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)
	touch manda_flag

bonus : bonus_flag

bonus_flag : $(BSRCS) $(LIB) philo.h philo_bonus.h
	rm -f $(NAME)
	$(CC) $(CFLAGS) -o $(NAME) $(BSRCS)
	touch bonus_flag
	touch manda_flag

clean :
	rm -f manda_flag
	rm -f bonus_flag

fclean :
	make clean
	rm -f $(NAME)

re :
	make fclean
	make all
