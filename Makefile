CC=g++
CFLAGS=-Wall -std=c++0x

all: chess

chess: main.o evaluator.o board.o
	$(CC) -o chess main.o evaluator.o board.o

main.o:	main.cpp
	$(CC) $(CFLAGS) -c main.cpp

evaluator.o: evaluator.cpp evaluator.hpp
	$(CC) $(CFLAGS) -c evaluator.cpp

board.o: board.cpp board.hpp
	$(CC) $(CFLAGS) -c board.cpp

clean:
	rm -f chess *.o
