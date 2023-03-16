SRC	=	$(wildcard src/*.cpp)	\
		$(wildcard ../../Game_Engine/cpp/*.cpp)	

OBJ	=	$(SRC:.cpp=.o)

NAME	=	game

CFLAGS	=	-g -Wall -Wextra -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -fpic


all: $(NAME)

$(NAME): $(OBJ)
	g++ $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re