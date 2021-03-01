CXXFLAGS=-g -O2 -Wall -Wextra -std=c++11
CXX=g++

all: main

main: main.o 
	${CXX} $^ -o $@

main.o: main.cpp grille.hpp

clean:
	rm -f *.o *~ main