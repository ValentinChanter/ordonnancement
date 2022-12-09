CC = gcc
CFLAGS = -W -Wall
EXEC = ordonnancement

all: $(EXEC)

$(EXEC): ordonnancement.o main.o
	$(CC) -o $(EXEC) ordonnancement.o main.o $(CFLAGS)

ordonnancement.o: ordonnancement.c ordonnancement.h
	$(CC) -o ordonnancement.o -c ordonnancement.c $(CFLAGS)

main.o: main.c ordonnancement.h
	$(CC) -o main.o -c main.c $(CFLAGS)

clean:
	rm -rf *.o