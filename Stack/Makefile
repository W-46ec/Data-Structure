all:	stack

stack:	main.o
	g++ -Wall -o stack main.o

main.o:	main.cpp Stack.h
	g++ -Wall -c main.cpp

clean:
	rm -f stack *.o