CC=gcc
CFLAGS=-Wall

all: proj05.driver.c
	$(CC) $(CFLAGS) proj05.driver.c proj05.support.c -o proj05

clean:
	-rm -f proj05.driver.o
	-rm -f proj05.support.o
	-rm -f proj05

run: proj05
	./proj05