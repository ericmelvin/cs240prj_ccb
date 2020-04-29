CXXFLAGS = -g -Wall -std=c++17
CXX = g++

CXX_FILES = $(wildcard *.cc)
OFILES = $(CXX_FILES::cc=o)

all:	bst

main:	$(OFILES)
	$(CXX) $(OFILES) -o main

bst:	bst.hh bst.cc main.cc
	$(CXX) bst.hh bst.cc main.cc -o bst

.phony:		clean
clean:
		rm -f *~ *.o main bst