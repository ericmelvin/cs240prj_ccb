all: 		io

io:			io.o graph.o
			g++ io.o graph.o -I/usr/include/python2.7 -lpython2.7 -o i

graph.o:	graph.cc graph.hh
			g++ -c graph.cc -I/usr/include/python2.7 -lpython2.7

io.o:	io.cc io.hh
		g++ -c io.cc