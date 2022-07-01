CC = g++
CFLAGS = -g -Wall
TGoL:Source.o Node.o Interface.o
	$(CC) $(CFLAGS) *.o -o ../TGoL
Source.o:Source.cpp Interface.h
	$(CC) $(CFLAGS) Source.cpp -c
Node.o:Node.cpp Node.h
	$(CC) $(CFLAGS) Node.cpp -c
Interface.o:Interface.cpp Interface.h Node.h
	$(CC) $(CFLAGS) Interface.cpp -c