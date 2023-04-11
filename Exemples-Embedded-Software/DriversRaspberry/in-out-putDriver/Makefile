CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c99

all : appDriver

appDriver : 
	$(CC) $(CFLAGS) -o appDriver in-out-driver.h in-out-driver.c appDriver.c

clean :
	rm -f appDriver *.o *.s *.i
	