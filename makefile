all: temp_api

temp_api: main.o temp_api.o
	gcc -o temp_api main.o temp_api.o

main.o: main.c temp_api.h
	gcc -c -std=c99 -o main.o main.c

temp_api.o: temp_api.c 
	gcc -c -std=c99 -o temp_api.o temp_api.c

clean: 
	rm -f *.o temp_api
	