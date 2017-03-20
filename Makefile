OBJS = generatecodes.o binaryheap.o 4wayheap.o pairingheap.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

test : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o test

generatecodes.o : generatecodes.cpp
	$(CC) $(CFLAGS) generatecodes.cpp

binaryheap.o : binaryheap.h binaryheap.cpp
	$(CC) $(CFLAGS) binaryheap.cpp


4wayheap.o : 4wayheap.h 4wayheap.cpp
	$(CC) $(CFLAGS) 4wayheap.cpp


pairingheap.o : pairingheap.h pairingheap.cpp
	$(CC) $(CFLAGS) pairingheap.cpp


clean :
	\rm *.o test
