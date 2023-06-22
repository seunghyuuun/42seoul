# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/17 11:45:20 by seunghy2          #+#    #+#              #
#    Updated: 2023/06/19 19:01:10 by seunghy2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror
AR=ar
ARFLAGS=rcs
NAME=libft.a
OBJS=$(SRCS:.c=.o)
BOBJS=$(BSRCS:.c=.o)
POBJS=char.o flag.o hxtoa.o string.o argchanger.o demicalint.o \
	  ft_printf.o hexa.o point.o unsigned.o
SRCS=ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	 ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c \
	 ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
	 ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c \
	 ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
	 ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
	 ft_substr.c ft_tolower.c ft_toupper.c
BSRCS=ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
	  ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
	  ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c
PSRCS=printf/char.c printf/flag.c printf/hxtoa.c printf/string.c \
	  printf/argchanger.c printf/demicalint.c printf/ft_printf.c printf/hexa.c \
	  printf/point.c printf/unsigned.c

.PHONY: all clean fclean re bonus

all : $(NAME)

$(NAME) : $(OBJS) $(POBJS)
	@rm -f $@
	$(AR) $(ARFLAGS) $(NAME) $?

$(POBJS) : $(PSRCS)
	$(CC) $(CFLAGS) -c $?

.c.o :
	$(CC) $(CFLAGS) -c $^

bonus : bonus_flag

bonus_flag : $(NAME) $(BOBJS)
	$(AR) $(ARFLAGS) $?
	@touch bonus_flag
	
clean :
	rm -f *.o
	@rm -f bonus_flag

fclean :
	make clean
	rm -f $(NAME)

re :
	make fclean
	make all
