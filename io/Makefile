CXX = g++

CXX_FLAGS = -g -Wall -std=c++17

O_FILES = io.o

TARGET = io

all:			$(TARGET)

$(TARGET):		$(O_FILES)
				$(CXX) $(CXX_FLAGS) $(O_FILES) -o $@

.phony:			clean
clean:
				rm -f *~ *.o $(TARGET)

#dependencies
#none

#dependencies
io.o:	io.cc io.hh

