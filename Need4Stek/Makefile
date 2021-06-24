##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## principal makefile of project
##

NAME   =    ai

CC     = gcc

RM     = rm -rf

CFLAGS += -I include/ -W -Wall -Wextra

SRC    =   $(wildcard *.c)

OBJ    =	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean:  clean
	 $(RM) $(NAME)

re: fclean all
