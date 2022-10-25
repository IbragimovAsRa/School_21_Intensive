CC = gcc
FLAGS = -Wall -Werror -Wextra

all: clean  door_struct list_test

list.o:
	$(CC) $(FLAGS) -c list.c
dmanager_module.o:
	$(CC) $(FLAGS) -c dmanager_module.c
list_test.o:
	$(CC) $(FLAGS) -c list_test.c

door_struct: 
	$(CC) $(FLAGS) dmanager_module.c -o ../build/Quest_1

list_test: list.o list_test.o
	$(CC) $(FLAGS) list.o list_test.o -o ../build/Quest_2

clean:
	rm -rf *.o
