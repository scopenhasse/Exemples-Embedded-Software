CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c99

all : passByValue passByAddress struct-Union

passByValue : passByValue.o
	$(CC) -o passByValue.o passByValue.c

passByAddress : passByAddress.o
	$(CC) -o passByAddress.o passByAddress.c

struct-Union : struct-Union.o
	$(CC) -o struct-Union.o struct-Union.c

clean :
	rm -f passByValue*.o passByAddress*.o struct-Union*.o