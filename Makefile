all: 		main

main:		main.o io.o graph.o bst.o
			g++ main.o bst.o io.o graph.o -I/usr/include/python2.7 -lpython2.7 -o proj

graph.o:	graph.cc graph.hh
			g++ -c graph.cc -I/usr/include/python2.7 -lpython2.7

io.o:		io.cc io.hh
			g++ -c io.cc

bst.o:		bst.cc bst.hh
			g++ -c bst.cc

main.o:		main.cc
			g++ -c main.cc -I/usr/include/python2.7 -lpython2.7

clean:
		rm -rf *.o *~ proj
