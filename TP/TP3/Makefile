EXEC=main

all: $(EXEC)

main: exo2.o exo3.o main.o utile.o
	gcc -o main -g exo2.o exo3.o main.o utile.o

utile.o: utile.c
	gcc -o utile.o -g -c utile.c -Wall

exo2.o: exo2.c
	gcc -o exo2.o -g -c exo2.c -Wall

exo3.o: exo3.c
	gcc -o exo3.o -g -c exo3.c -Wall

main.o: main.c exo2.h utile.h exo3.h
	gcc -o main.o -g -c main.c -Wall

clean :
	rm *.o $(EXEC)	
