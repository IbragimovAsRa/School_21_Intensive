CC = gcc

CFLAGS = -Wall -Werror -Wextra


all: rebuild
build:	decision.o\
		data_stat.o\
		data_io.o\
		data_sort.o\
		main_executable_module.o\
		data_process.o

	$(CC) -o ../../build/Quest_3 main_executable_module.o decision.o data_stat.o data_io.o data_sort.o data_process.o

rebuild: build clean

data_sort.o:
	$(CC) $(CFLAGS) -c data_sort.c
decision.o:
	$(CC)  $(CFLAGS) -c ../yet_another_decision_module/decision.c
data_stat.o:
	$(CC)  $(CFLAGS) -c ../data_libs/data_stat.c
data_io.o: 
	$(CC) $(CFLAGS) -c ../data_libs/data_io.c
main_executable_module.o:
	$(CC) $(CFLAGS) -c  main_executable_module.c
data_process.o:
	$(CC) $(CFLAGS) -c ../data_module/data_process.c
data_stat.a: data_stat.o
	ar -rcs libdata_stat.a data_stat.o

build_with_static:	decision.o\
		data_io.o\
		data_sort.o\
		main_executable_module.o\
		data_process.o\
		data_stat.a\

	$(CC) $(CFLAGS) -o ../../build/Quest_5 -L. -ldata_stat main_executable_module.o decision.o  data_io.o data_sort.o data_process.o 

dynamic_data_stat.o:
	$(CC) $(CFLAGS) -fPIC -c ../data_libs/data_stat.c
dynamic_data_process.o:
	$(CC) $(CFLAGS) -fPIC -c ../data_module/data_process.c

data_process.so: dynamic_data_process.o dynamic_data_stat.o
	gcc -shared  -o libdata_process.so data_process.o data_stat.o
	cp libdata_process.so ../../build

build_with_dynamic:	decision.o\
		dynamic_data_stat.o\
		data_io.o\
		data_sort.o\
		main_executable_module.o\
		dynamic_data_process.o\
		data_process.so

	$(CC) -o ../../build/Quest_6 -DDynamic libdata_process.so main_executable_module.o  decision.o data_io.o data_sort.o 

clean:
	rm -rf *.o
