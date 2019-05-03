all:	sort

sort:	main.o
	g++ -Wall -o sort main.o

main.o:	main.cpp bubbleSort.o InsertionSort.o SelectionSort.o
	g++ -Wall -c main.cpp

bubbleSort.o:	bubbleSort.cpp swap.cpp
	g++ -Wall -c bubbleSort.cpp

InsertionSort.o:	InsertionSort.cpp
	g++ -Wall -c InsertionSort.cpp

SelectionSort.o:	SelectionSort.cpp swap.cpp
	g++ -Wall -c SelectionSort.cpp

clean:
	rm -f sort *.o