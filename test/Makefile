CXXFLAGS = -g -Wall -std=c++17
CXX = g++

CXX_FILES = $(wildcard *.cc)
OFILES = $(CXX_FILES::cc=o)

all:	main

main:	$(OFILES)
	$(CXX) $(OFILES) -o main

clean: rm -rf *.o *~ main
