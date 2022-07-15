CC=gcc
CFLAGS=-ggdb3 -Wall -Werror -pedantic -std=gnu99

all: main my_atoi.o my_atoiHex.o

my_atoi.o: my_atoi.c
	$(CC) -c my_atoi.c $(CFLAGS)

my_atoiHex.o: my_atoiHex.c
	$(CC) -c my_atoiHex.c $(CFLAGS)

main: main.c my_atoi.o my_atoiHex.o
	$(CC) -o test main.c  my_atoi.o my_atoiHex.o $(CFLAGS)

clean:
	rm *.o
