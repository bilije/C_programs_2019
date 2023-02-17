CC=gcc
CFLAGS=-Wall -pedantic -std=c11 -o2
LIBS=-lm

all:	program9d
program9d:	magazyn.o dodatkowy.o
	$(CC) -o program9d magazyn.o dodatkowy.o $(CFLAGS) $(LIBS)
dodatkowy.o:	dodatkowy.c magazyn.h
		$(CC) -o dodatkowy.o -c dodatkowy.c $(CFLAGS)
magazyn.o: 	magazyn.c magazyn.h
		$(CC) -o magazyn.o -c magazyn.c $(CFLAGS)
clean:
	rm -f *.0

