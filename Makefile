##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC=	bsq.c \
		my_putstr.c \
		my_putchar.c \

NAME=	bsq

CFLAGS=	$(HEAD) -Wall -Wextra 

HEAD=	-Iinclude

CC=	gcc -g3 $(CFLAGS)

RM=	rm -f

OBJ=  $(SRC:.c=.o)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME)

all: 	$(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: 	fclean all

.PHONY: all clean fclean re
