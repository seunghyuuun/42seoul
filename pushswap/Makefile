CC=cc
CFLAGS=-Wall -Wextra -Werror
NAME=push_swap
LIB=libft/libft.a
SRCS=main.c abstack.c idata.c free.c initial.c

.PHONY: all clean fclean re

all : $(NAME)

$(NAME) : $(SRCS) $(LIB)
	$(CC) $(CFLAGS) -o $@ $(SRCS) -L ./libft -lft

$(LIB) :
	make -C ./libft

clean :
	make -C ./libft fclean

fclean :
	make clean
	rm -f $(NAME)

re :
	make fclean
	make all