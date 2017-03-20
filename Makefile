OBJS = HuffmanEncoder.o HuffmanDecoder.o binaryheap.o 4wayheap.o pairingheap.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c -std=c++1y $(DEBUG)
LFLAGS = -Wall -std=c++1y $(DEBUG)

all: encoder decoder

encoder : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) encoder.cpp -o encoder.o

decoder : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) decoder.cpp -o decoder.o

HuffmanEncoder.o : HuffmanEncoder.h HuffmanEncoder.cpp
	$(CC) $(CFLAGS) HuffmanEncoder.cpp

HuffmanDecoder.o : HuffmanDecoder.h HuffmanDecoder.cpp
	$(CC) $(CFLAGS) HuffmanDecoder.cpp

generatecodes.o : generatecodes.cpp
	$(CC) $(CFLAGS) generatecodes.cpp

binaryheap.o : binaryheap.h binaryheap.cpp
	$(CC) $(CFLAGS) binaryheap.cpp


4wayheap.o : 4wayheap.h 4wayheap.cpp
	$(CC) $(CFLAGS) 4wayheap.cpp


pairingheap.o : pairingheap.h pairingheap.cpp
	$(CC) $(CFLAGS) pairingheap.cpp


clean :
	\rm *.o
