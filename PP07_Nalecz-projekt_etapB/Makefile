#  Tomasz Nalecz
#  Grupa U2
#  04.06.2020r.
CC = gcc
CFLAGS=-Wall -pedantic -std=c11 -O2
LIBS=-lm

all: program

program: main.o funkcje.o
	$(CC) -o program main.o funkcje.o $(CFLAGS) $(LIBS)

main.o: main.c biblioteka.h
	$(CC) -o main.o -c main.c $(CFLAGS)

funkcje.o: funkcje.c biblioteka.h
	$(CC) -o funkcje.o -c funkcje.c $(CFLAGS)

clean:
	rm -f *.o
