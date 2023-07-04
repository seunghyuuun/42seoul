# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/30 14:12:35 by seunghy2          #+#    #+#              #
#    Updated: 2023/07/04 20:11:26 by seunghy2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror
NAME=push_swap
BNAME=checker
LIB=libft/libft.a
SRCS=main.c abstack.c comcall.c idata.c free.c initial.c pivot.c restbig.c restsmall.c end.c ntimes.c firsttime.c
BSRCS=main_bonus.c initial.c end.c free.c idata.c abstack.c get_next_line_bonus.c comlst_bonus.c

.PHONY: all clean fclean re bonus

all : $(NAME)

$(NAME) : $(SRCS) $(LIB) push_swap.h
	$(CC) $(CFLAGS) -o $@ $(SRCS) -L ./libft -lft

bonus : $(BNAME)

$(BNAME) : $(BSRCS) $(LIB) push_swap.h push_swap_bonus.h
	$(CC) $(CFLAGS) -o $@ $(BSRCS) -L ./libft -lft

$(LIB) :
	make -C ./libft bonus

clean :
	make -C ./libft fclean

fclean :
	make clean
	rm -f $(NAME)
	rm -f $(BNAME)

re :
	make fclean
	make all
