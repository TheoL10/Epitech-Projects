##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## task01 d10
##

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp  libmy.a ../
	mkdir ../../include
	cp my.h ../../include

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -rf ../../include
	rm -f ../libmy.a

re:	fclean all
