CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: strlen_tests strcmp_tests strcpy_tests strcat_tests strchr_tests clean

s21_string.o:
	$(CC) $(CFLAGS) -c s21_string.c


s21_string_test1.o:
	$(CC) $(CFLAGS) -DStrlen_tests -c s21_string_test.c
s21_string_test2.o:
	$(CC) $(CFLAGS) -DStrcmp_tests -c s21_string_test.c
s21_string_test3.o:
	$(CC) $(CFLAGS) -DStrcpy_tests -c s21_string_test.c
s21_string_test4.o:
	$(CC) $(CFLAGS) -DStrcat_tests -c s21_string_test.c
s21_string_test5.o:
	$(CC) $(CFLAGS) -DStrchr_tests -c s21_string_test.c


strlen_tests: s21_string.o s21_string_test1.o
	$(CC) $(CFLAGS) -o ../build/Quest_1 s21_string.o s21_string_test.o

strcmp_tests: s21_string.o s21_string_test2.o
	$(CC) $(CFLAGS) -o ../build/Quest_2 s21_string.o s21_string_test.o

strcpy_tests: s21_string.o s21_string_test3.o
	$(CC) $(CFLAGS) -o ../build/Quest_3 s21_string.o s21_string_test.o

strcat_tests: s21_string.o s21_string_test4.o
	$(CC) $(CFLAGS) -o ../build/Quest_4 s21_string.o s21_string_test.o

strchr_tests: s21_string.o s21_string_test5.o
	$(CC) $(CFLAGS) -o ../build/Quest_5 s21_string.o s21_string_test.o

clean:
	rm -rf *.o
all_clean:
	rm -rf *.o
	rm -rf *.out
	rm -rf ../build/Quest*