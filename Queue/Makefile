all:	queue

queue:	main.o
	g++ -Wall -o queue main.o

main.o:	main.cpp Queue.h
	g++ -Wall -c main.cpp

clean:
	rm -f queue *.o