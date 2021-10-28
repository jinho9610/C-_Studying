CC = g++
CXXFLAGS = -Wall -O2
OBJS = Marine.o main.o

Marine.o : Marine.hpp Marine.cpp
	$(CC) $(CXXFLAGS) -c Marine.cpp

main.o : main.cpp

main : Marine.o main.o
	$(CC) Marine.o main.o -o main

.PHONY: clean
clean:
	rm -f $(OBJS) main