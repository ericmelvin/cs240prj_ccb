CXXFLAGS = -g -Wall -std=c++17
CXX = g++

CXX_FILES = $(wildcard *.cc)
OFILES = $(CXX_FILES::cc=o)

all:	rbt

main:	$(OFILES)
	$(CXX) $(OFILES) -o main

rbt:	RBT.hh main.cc
	$(CXX) RBT.hh main.cc -o rbt

clean: 
	rm -rf *.o *~ main rbt
