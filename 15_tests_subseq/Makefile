CC=gcc
CFFLAGS=-ggdb3 -Wall -Werror -pedantic -std=gnu99

all: maxSeq.o test-subseq

test-subseq: test-subseq.c maxSeq.o
	$(CC) -o test-subseq test-subseq.c maxSeq.o $(CFFLAGS)

maxSeq.o: maxSeq.c
	$(CC) -c maxSeq.c $(CFFLAGS)
	# note the option -c, which means: "compile but do not link". Hence this provides us with the object file maxSeq.o


