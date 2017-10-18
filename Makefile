all: bstDemo

CFLAGS=-g -O3

# $@ is the production's target
# $^ are the projuction's prerequisites

bstDemo: BSTree.o BSTreeTest.o
	cc -o $@ $^

BSTree.o: BSTree.c BSTree.h
	cc -c $(CFLAGS) BSTree.c

BSTRreeTest.o: BSTreeTest.c BSTree.h
	cc -c $(CFLAGS) BSTreeTest.c

clean:
	rm -f *.o bstDemo
	rm bstOut.txt
