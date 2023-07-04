# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/19 19:00:55 by seunghy2          #+#    #+#              #
#    Updated: 2023/07/04 19:44:44 by seunghy2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror
NAME=pipex
LIB=libft/libft.a
SRCS=main.c free.c cmdmkr.c pathmkr.c ex.c error.c
BSRCS=main_bonus.c free.c cmdmkr_bonus.c pathmkr_bonus.c ex_bonus.c \
	  error_bonus.c \
	  get_next_line_bonus.c heredoc_bonus.c tmpfile_bonus.c

.PHONY: all clean fclean re bonus

all : $(NAME)

$(NAME) : manda_flag

manda_flag : $(SRCS) $(LIB) pipex.h
	rm -f $(NAME)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) -L ./libft -lft
	touch manda_flag

bonus : bonus_flag

bonus_flag : $(BSRCS) $(LIB) pipex.h pipex_bonus.h
	rm -f $(NAME)
	$(CC) $(CFLAGS) -o $(NAME) $(BSRCS) -L ./libft -lft
	touch bonus_flag
	touch manda_flag

$(LIB) :
	make -C ./libft

clean :
	make -C ./libft fclean
	rm -f manda_flag
	rm -f bonus_flag

fclean :
	make clean
	rm -f $(NAME)

re :
	make fclean
	make all
