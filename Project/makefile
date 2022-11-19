CC=gcc
CFLAGS=-c -Wall -g

all: main

main: main.o 
	$(CC) main.o  -o main

main.o: main.c
	$(CC) $(CFLAGS) main.c

# mem.o: mem.c mem.h
# 	$(CC) $(CFLAGS) mem.c

clean:
	/bin/rm -f main *.o *.gz

run:
	./main

tarball: 
	tar -cvzf everette.tar.gz *