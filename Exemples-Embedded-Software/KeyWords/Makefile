CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c99

all: staticKeyWord registerKeyWord volatileKeyWord externKeyWord 

staticKeyWord: staticKeyWord.o
	$(CC) -o staticKeyWord.o staticKeyWord.c

registerKeyWord: registerKeyWord.o
	$(CC) -o registerKeyWord.o registerKeyWord.c

volatileKeyWord: volatileKeyWord.o
	$(CC) -o volatileKeyWord.o volatileKeyWord.c

externKeyWord: externKeyWord.o
	$(CC) externKeyWord.c declarationExtern.c -o externKeyWord.o

clean:
	rm -f staticKeyWord*.o registerKeyWord*.o volatileKeyWord*.o externKeyWord*.o
