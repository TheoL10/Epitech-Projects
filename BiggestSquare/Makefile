##
## EPITECH PROJECT, 2020
## makefile
## File description:
## Makefile
##

NAME   =    bsq

CC     = gcc -g -g3

RM     = rm -rf

CFLAGS += -I include/ -W -Wall -Wextra -O2

SRC    =   $(wildcard *.c)

OBJ    =	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:  clean
	 $(RM) $(NAME)

re: fclean all