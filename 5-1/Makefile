CC = g++
CXXFLAGS = -Wall -O2
OBJS = MyComplex.o main.o

MyComplex.o : MyComplex.hpp MyComplex.cpp
	$(CC) $(CXXFLAGS) -c MyComplex.cpp

main.o : main.cpp

main : MyComplex.o main.o
	$(CC) MyComplex.o main.o -o main

.PHONY: clean
clean:
	rm -f $(OBJS) main