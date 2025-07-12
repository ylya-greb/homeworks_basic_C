all: temp_functions

temp_functions: main.o temp_functions.o
	gcc -o temp_functions main.o temp_functions.o

main.o: main.c temp_functions.h
	gcc -c -std=c99 -o main.o main.c

temp_functions.o: temp_functions.c 
	gcc -c -std=c99 -o temp_functions.o temp_functions.c

clean: 
	rm -f *.o temp_functions
	