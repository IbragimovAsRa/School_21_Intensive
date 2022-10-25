all: test

test:
	gcc -Wall -Werror -Wextra graph.c input.c list.c polish_notation.c draw.c stack.c calculations.c -o main

clean:
	rm -rf main

rebuild: clean all