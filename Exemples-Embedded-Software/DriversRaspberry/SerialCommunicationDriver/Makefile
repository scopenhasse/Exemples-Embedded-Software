CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c99

all: serialCommunicationDriver

serialCommunicationDriver: 
	$(CC) $(CFLAGS) -o appSerialCom SerialDriver.h SerialDriver.c appSerialCom.c

clean:
	rm -f appSerialCom