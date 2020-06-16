CC=gcc
CFLAGS=-I. -std=c99
THFLAGS=-pthread -lsum -L.
UTPATH=../../lab3/src/

all: sum

again: clean all

utils2.o : utils.h
	$(CC) -o utils2.o -c utils.c $(CFLAGS)

sum: libsum.so utils2.o utils.h sum_arr.h 
	$(CC) -o sum utils2.o parallel_sum.c $(CFLAGS) $(THFLAGS)

libsum.so: sum.o
	$(CC) -shared sum.o -o libsum.so $(CFLAGS)

sum.o: sum_arr.c sum_arr.h 
	$(CC) -c sum_arr.c -o sum.o -fPIC $(CFLAGS)

clean :
	rm utils2.o sum sum.o libsum.so