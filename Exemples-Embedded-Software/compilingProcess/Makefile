CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c99

all: SourceFile

SourceFile: SourceFile.o
	$(CC) SourceFile.o -o SourceFile

SourceFile.o: SourceFile.s
	$(CC) $(CFLAGS) -c SourceFile.s

SourceFile.s: SourceFile.i
	$(CC) $(CFLAGS) -S SourceFile.i

SourceFile.i: SourceFile.c
	$(CC) $(CFLAGS) -E SourceFile.c > SourceFile.i

clean:
	rm -f SourceFile *.o *.s *.i


