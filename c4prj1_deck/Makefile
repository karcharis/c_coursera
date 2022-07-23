CC=gcc
CFLAGS=-ggdb3 -Werror -Wall -pedantic -std=gnu99

my-test: my-test.c eval.o deck.o cards.o eval.h deck.h cards.h
	$(CC) -o my-test my-test.c eval.o deck.o cards.o  $(CFLAGS)
	
eval.o: eval.c deck.o cards.o eval.h deck.h cards.h
	$(CC) -c eval.c deck.c cards.c  $(CFLAGS)
	
deck.o: deck.c cards.o deck.h cards.h 
	$(CC) -c deck.c cards.c  $(CFLAGS)
	
cards.o: cards.c cards.h
	$(CC) -c cards.c $(CFLAGS)		
