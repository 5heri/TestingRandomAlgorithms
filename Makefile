# Makefile for Randomized Algorithms
CXXFLAGS = -Wall -g
CXX=g++

Main: Main.o SkipList.o
	$(CXX) Main.o  SkipList.o -o main.o -lm -lstdc++

Main.o: Main.cpp

SkipList.o: SkipList.cpp SkipList.hpp

clean:
	rm -f *.o

