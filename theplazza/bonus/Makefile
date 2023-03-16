# #
# # EPITECH PROJECT, 2020
# # make
# # File description:
# # make
# #gcc main.c -o test -L. -lmy_malloc
##export LD_LIBRARY_PATH=$(pwd)

CC	= g++

RM	= rm -f

NAME1	= plazza

SRC1	= $(wildcard *.cpp)

OBJS1	= $(SRC1:.cpp=.o)

all: $(NAME1)

$(NAME1): $(OBJS1)
	$(CC) -o $(NAME1) $(OBJS1) -lpthread -g -lsfml-graphics -lsfml-window -lsfml-system

clean:
	$(RM) $(OBJS1)

fclean: clean
	$(RM) $(NAME1)

re:	fclean all

.PHONY: all clean fclean re