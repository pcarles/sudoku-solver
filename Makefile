NAME = sudoku
CC = gcc
FLAGS = -Werror -Wextra -Wall
HDR = $(wildcard src/*.h)
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, bin/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^

bin/%.o: src/%.c $(HDR)
	@mkdir -p bin
	$(CC) -o $@ -c $< $(FLAGS)

.PHONY: clean fclean re

clean:
	@rm -rf bin/

fclean: clean
	@rm -f $(NAME)

re: fclean all
