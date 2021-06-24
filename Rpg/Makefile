##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## principal makefile of project
##

SRC	=	$(wildcard src/*.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

CFLAGS	=	-I /include/my.h
CFLAGS	+=	-Wextra -W -Wall -g

LDFLAGS	+=	-Llib/ -lmy

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./lib/my
	gcc $(OBJ) -o $(NAME) $(LDFLAGS) $(CFLAGS) -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

clean:
	rm -f $(OBJ)

fclean: clean
	(cd ./lib/my/; make fclean)
	rm -f $(NAME)

re:	fclean all
