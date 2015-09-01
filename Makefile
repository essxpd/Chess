CC=g++
CFLAGS=-Wall

all: chess

chess: main.o evaluator.o
	$(CC) -o chess main.o evaluator.o

main.o:	main.cpp
	$(CC) $(CFLAGS) -c main.cpp

evaluator.o: evaluator.cpp evaluator.hpp
	$(CC) $(CFLAGS) -c evaluator.cpp

clean:
	rm -f chess *.o
