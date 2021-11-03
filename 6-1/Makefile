CC = g++
CXXFLAGS = -Wall -O2
OBJS = Employee.hpp.gch EmployeeList.hpp.gch main.o

main.o : main.cpp

main : main.o
	$(CC) main.o -o main

.PHONY: clean
clean:
	rm -f $(OBJS)