EXEC=main

all: $(EXEC)

main: maxsubarray.o minmax.o main.o utile.o
	gcc -o main -g maxsubarray.o minmax.o main.o utile.o

utile.o: utile.c
	gcc -o utile.o -g -c utile.c -Wall

maxsubarray.o: maxsubarray.c
	gcc -o maxsubarray.o -g -c maxsubarray.c -Wall

minmax.o: minmax.c
	gcc -o minmax.o -g -c minmax.c -Wall

main.o: main.c minmax.h utile.h maxsubarray.h
	gcc -o main.o -g -c main.c -Wall

clean :
	rm *.o $(EXEC)	
