# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/02 12:55:35 by seunghy2          #+#    #+#              #
#    Updated: 2023/06/09 16:00:03 by seunghy2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror
AR=ar
ARFLAGS=rcs
NAME=libftprintf.a
OBJS=$(SRCS:.c=.o)
SRCS=ft_printf.c argchanger.c flag.c char.c string.c point.c hexa.c \
	 unsigned.c demicalint.c hxtoa.c ft_strlen.c ft_strchr.c \
	 ft_isdigit.c ft_atoi.c ft_memset.c ft_memcpy.c \
	 ft_toupper.c ft_itoa.c

.PHONY: all clean fclean re bonus

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $?

.c.o :
	$(CC) $(CFLAGS) -c $^

bonus : $(NAME)

clean :
	rm -f *.o

fclean :
	make clean
	rm -rf $(NAME)

re :
	make fclean
	make all
