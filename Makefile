##
## EPITECH PROJECT, 2019
## makefile
## File description:
## project makefile
##

SRC =   src/main.c	\
		src/operations.c

OBJ =   $(SRC:.c=.o)

NAME    =   push_swap

CFLAGS  +=  -I include -Wall -Wextra
LDFLAGS +=  -L lib/my -lmy

all:    $(NAME)

$(NAME):    $(OBJ)
	make -C lib/my/
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	@make clean -C lib/my/ --no-print-directory
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C lib/my/ --no-print-directory
	@rm -f $(NAME)

re: fclean all

run: all
	./$(NAME) 42 28 24 48 1 25 7 18 1 0 5 28 45 -34 -89

.PHONY: all clean fclean