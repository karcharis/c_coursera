CC=gcc
CFLAGS=-ggdb3 -Werror -Wall -pedantic -std=gnu99
HEADERS=input.h future.h deck.h cards.h

all: test-future test-input

test-input: test-input.c input.o future.o deck.o cards.o $(HEADERS)
	$(CC) -o test-input test-input.c input.o future.o deck.o cards.o $(CFLAGS)

input.o: input.c $(HEADERS)
	$(CC) -c input.c $(CFLAGS)
	
test-future: test-future.c future.o deck.o cards.o $(HEADERS)
	$(CC) -o test-future test-future.c future.o deck.o cards.o $(CFLAGS)

deck.o: deck.c deck.h cards.h
	$(CC) -c deck.c $(CFLAGS)

cards.o: cards.c cards.h
	$(CC) -c cards.c $(CFLAGS)

future.o: future.c future.h deck.h
	$(CC) -c future.c $(CFLAGS)

clean:
	rm *.o

