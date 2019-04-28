all:	heap

heap:	main.o
	g++ -Wall -o heap main.o

main.o:	main.cpp Heap.h
	g++ -Wall -c main.cpp

clean:
	rm -f heap *.o