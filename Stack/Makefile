all:	x

x:	main.o
	g++ -Wall -o x main.o

main.o:	main.cpp Stack.h
	g++ -Wall -c main.cpp

clean:
	rm -f x *.o