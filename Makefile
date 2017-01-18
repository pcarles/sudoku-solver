NAME = sudoku
CC = gcc
FLAGS = -Werror -Wextra -Wall
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, bin/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^

bin/%.o: src/%.c
	$(CC) -o $@ -c $< $(FLAGS)

.PHONY: clean fclean re

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
