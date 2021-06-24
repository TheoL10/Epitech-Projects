##
## EPITECH PROJECT, 2020
## makefile
## File description:
## Makefile
##

NAME   =    libmy.a

CC     = gcc

RM     = rm -rf

CFLAGS += -I include/ -W -Wall -Wextra

SRC    =   $(wildcard *.c)

OBJ    =	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	(cp $(NAME) ..)

clean:
	$(RM) $(OBJ)

fclean:  clean
	 $(RM) $(NAME)
	 $(RM) ../$(NAME)

re: fclean all