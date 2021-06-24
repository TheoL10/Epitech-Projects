##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC     = gcc

RM     = rm -f

CFLAGS += -I include/ -W -Wall -Wextra -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window -g -lm

NAME   =    my_defender

SRC    =   $(wildcard *.c)

OBJ    =	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean:  clean
	 $(RM) $(NAME)

re: fclean all