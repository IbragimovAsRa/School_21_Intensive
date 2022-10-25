
CC = gcc
FLAGS = -Wall -Werror -Wextra

all: clean cipher logging_cipher

# ____________ Quest 5 ___________________
log_cipher.o:
	$(CC) $(FLAGS) -Dloga -c cipher.c
log_logger.o:
	$(CC) $(FLAGS) -Dloga -c logger.c
logging_cipher: log_cipher.o log_logger.o
	$(CC) $(FLAGS) -o ../build/logging_cipher  cipher.o logger.o
#-----------------------------------------

# ____________ Quests 1 2 3 ______________
cipher.o:
	$(CC) $(FLAGS) -c cipher.c

cipher: cipher.o
	$(CC) $(FLAGS) -o ../build/cipher  cipher.o

#-----------------------------------------

clean:
	rm -rf *.o
