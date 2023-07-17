# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/11 16:27:20 by seunghy2          #+#    #+#              #
#    Updated: 2023/07/17 13:02:36 by seunghy2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror
NAME=so_long
SRCS=main.c error.c get_next_line.c plancheck.c pathcheck.c planset.c keyhook.c
BSRCS=main_bonus.c error.c get_next_line.c plancheck.c pathcheck.c planset.c \
	  keyhook.c
LIBMLX=./minilibx/libmlx.a
LIBFT=./libft/libft.a

.PHONY: all clean fclean re bonus

all : $(NAME)

$(NAME) : manda_flag
	
manda_flag : $(SRCS) $(LIBMLX) $(LIBFT) so_long.h
	rm -f $(NAME)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) -L ./minilibx -lmlx -L ./libft -lft -framework OpenGL -framework AppKit -lz
	touch manda_flag

bonus : bonus_flag

bonus_flag : $(BSRCS) $(LIBMLX) $(LIBFT) so_long.h
	rm -f $(NAME)
	$(CC) $(CFLAGS) -o $(NAME) $(BSRCS) -L ./minilibx -lmlx -L ./libft -lft -framework OpenGL -framework AppKit -lz
	touch manda_flag
	touch bonus_flag

$(LIBMLX) :
	make -C ./minilibx

$(LIBFT) :
	make -C ./libft bonus

clean :
	make -C ./minilibx clean
	make -C ./libft fclean
	rm -f manda_flag
	rm -f bonus_flag

fclean :
	make clean
	rm -rf $(NAME)

re :
	make fclean
	make all
