CC = g++ # 컴파일러
CXXFLAGS = -Wall -O2 # 컴파일 옵션
OBJS = Date.o main.o

Date.o : Date.hpp Date.cpp
	$(CC) $(CXXFLAGS) -c Date.cpp

main.o : main.cpp
	$(CC) $(CXXFLAGS) -c main.cpp

main : Date.o main.o
	$(CC) Date.o main.o -o main

.PHONY: clean
clean:
	rm -f $(OBJS) main