CFLAGS=-ggdb3 -Wall -Werror -pedantic -std=gnu99
GIVEN_OBJS=  future.o  input.o  main.o
MY_OBJS=cards.o deck.o eval.o

test-eval: deck.o eval.o test-eval.o cards.o input.o future.o
	gcc -o test-eval -ggdb3 deck.o eval.o test-eval.o cards.o input.o future.o
poker: $(GIVEN_OBJS) $(MY_OBJS)
	gcc -o poker -ggdb3  $(MY_OBJS) $(GIVEN_OBJS)

my-test: cards.c deck.c eval.c my-test.c 
	$(CC) -o my-test cards.c deck.c eval.c my-test.c $(CFLAGS)
	
clean:
	rm -f test poker cards.o my-test-main.o *~
