all:	sort

sort:	main.o
	g++ -Wall -o sort main.o

main.o:	main.cpp Helper.cpp bubbleSort.o InsertionSort.o SelectionSort.o MergeSort.o QuickSort.o HeapSort.o RadixSort.o
	g++ -Wall -c main.cpp

bubbleSort.o:	bubbleSort.cpp swap.cpp
	g++ -Wall -c bubbleSort.cpp

InsertionSort.o:	InsertionSort.cpp
	g++ -Wall -c InsertionSort.cpp

SelectionSort.o:	SelectionSort.cpp swap.cpp
	g++ -Wall -c SelectionSort.cpp

MergeSort.o:	MergeSort.cpp
	g++ -Wall -c MergeSort.cpp

QuickSort.o:	QuickSort.cpp
	g++ -Wall -c QuickSort.cpp

HeapSort.o:	HeapSort.cpp swap.cpp
	g++ -Wall -c HeapSort.cpp

RadixSort.o:	RadixSort.cpp
	g++ -Wall -c RadixSort.cpp

clean:
	rm -f sort *.o