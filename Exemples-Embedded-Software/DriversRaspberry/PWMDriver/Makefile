CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c99

all : appDriver

appDriver : 
	$(CC) $(CFLAGS) -o appDriver PWMDriver.h PWMDriver.c appDriver.c

clean :
	rm -f appDriver *.o *.s *.i
