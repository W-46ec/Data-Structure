all:	search

search:	main.o
	g++ -Wall -o search main.o

main.o:	main.cpp Helper.cpp sequentialSearch.o binarySearch.o
	g++ -Wall -c main.cpp

sequentialSearch.o:	sequentialSearch.cpp
	g++ -Wall -c sequentialSearch.cpp

binarySearch.o:	binarySearch.cpp
	g++ -Wall -c binarySearch.cpp

clean:
	rm -f search *.o