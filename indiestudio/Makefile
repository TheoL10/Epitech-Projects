CC	= g++

RM	= rm -f

NAME1	= bomberman

SRC1	= $(wildcard src/*.cpp)

OBJS1	= $(SRC1:.cpp=.o)

all: $(NAME1)

$(NAME1): $(OBJS1)
	$(CC) -o $(NAME1) $(OBJS1) -g -L ../include/ -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

clean:
	$(RM) $(OBJS1)

fclean: clean
	$(RM) $(NAME1)

re:	fclean all

.PHONY: all clean fclean re