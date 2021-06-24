##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## principal makefile of project
##

SRC	=	$(wildcard src/*.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	dante

CFLAGS	=	-I /include/my.h
CFLAGS	+=	-Wextra -W -Wall -g

LDFLAGS	+=	-Llib/ -lmy

all:
	(cd ./generator/; make)
	(cd ./solver/; make)

clean:
	(cd ./generator/; make clean)
	(cd ./solver/; make clean)

fclean:
	(cd ./generator/; make fclean)
	(cd ./solver/; make fclean)

re:	fclean all