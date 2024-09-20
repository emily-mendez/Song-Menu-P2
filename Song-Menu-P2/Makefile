CC = g++
CFLAGS = -Wall -Wextra

all: listen_up

listen_up: listen_up.o BinarySearchTree.o Functions.o MaxHeap.o Song.o
	$(CC) $(CFLAGS) listen_up.o BinarySearchTree.o Functions.o MaxHeap.o Song.o -o listen_up

listen_up.o: listen_up.cpp BinarySearchTree.cpp Functions.cpp MaxHeap.cpp Song.cpp
	$(CC) $(CFLAGS) -c listen_up.cpp

BinarySearchTree.o: BinarySearchTree.h BinarySearchTree.cpp
	$(CC) $(CFLAGS) -c BinarySearchTree.cpp

Functions.o: Functions.h Functions.cpp
	$(CC) $(CFLAGS) -c Functions.cpp

MaxHeap.o: MaxHeap.h MaxHeap.cpp
	$(CC) $(CFLAGS) -c MaxHeap.cpp

Song.o: Song.h Song.cpp
	$(CC) $(CFLAGS) -c Song.cpp

clean:
	rm -f *.o listen_up
