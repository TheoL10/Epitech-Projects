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

SRC    =   $(wildcard lib/my/*.c)

OBJ    =	$(SRC:.c=.o)

LIB		= lib/my/libmy.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) $(LIB)

clean:
	$(RM) $(OBJ) $(LIB)

fclean:  clean
	 $(RM) $(NAME)

re: fclean all