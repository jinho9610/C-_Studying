CC = g++
CXXFLAGS = -Wall -O2
OBJS = Marine.o main.o

Marine.o : MyString.hpp MyString.cpp
	$(CC) $(CXXFLAGS) -c MyString.cpp

main.o : main.cpp

main : MyString.o main.o
	$(CC) MyString.o main.o -o main

.PHONY: clean
clean:
	rm -f $(OBJS) main