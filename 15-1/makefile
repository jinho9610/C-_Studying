CC = g++
CXXFLAGS = -Wall -O2
THREADFLAGS = -lpthread
OBJS = main.o

main.o : main.cpp
	$(CC) $(CXXFLAGS) -c main.cpp

main : main.o
	$(CC) $(OBJS) -o main $(THREADFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJS)