all:	BST

BST:	main.o
	g++ -Wall -o BST main.o

main.o:	main.cpp BST.h
	g++ -Wall -c main.cpp

clean:
	rm -f BST *.o