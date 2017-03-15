EXEC = sudoku
LIB = bin/solvermodule.so
CC = gcc
C_FLAGS = -fPIC -I/usr/include/python3.5 
HDR = $(wildcard src/*.h)
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, bin/%.o, $(SRC))

all: $(LIB)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^

$(LIB): $(OBJ)
	$(CC) -shared -o $@ $^

bin/%.o: src/%.c $(HDR)
	@mkdir -p bin
	$(CC) -o $@ -c $< $(C_FLAGS)

.PHONY: clean fclean re

clean:
	@rm -rf bin/

fclean: clean
	@rm -f $(EXEC)

re: fclean all

