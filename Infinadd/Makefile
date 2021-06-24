##
## EPITECH PROJECT, 2020
## makefile
## File description:
## Makefile
##

NAME   =    infin_add

CC     = gcc

RM     = rm -rf

CFLAGS += -I include/ -W -Wall -Wextra -L lib -lmy

SRC    =   $(wildcard *.c)

OBJ    =	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./lib/my
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean:  clean
	 (cd ./lib/my/; make fclean)
	 $(RM) $(NAME)

re: fclean all