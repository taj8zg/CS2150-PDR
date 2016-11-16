#Ashley Nguyen - apn2my
#Prelab10 - Makefile
#4/18/16

CXX = clang++

CXXFLAGS = -Wall -g

OFILES = heap.o huffmanNode.o tree.o huffmanenc.o

.SUFFIXES: .o .cpp

main: 	$(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)

clean:
	/bin/rm -f *.o *~ 
	/bin/rm -f *.out

#listing out dependencies 
heap.o: heap.cpp heap.h huffmanNode.h
huffmanNode.o: huffmanNode.cpp huffmanNode.h
tree.o: tree.cpp huffmanNode.h tree.h heap.h
huffmanenc.o: huffmanenc.cpp heap.h huffmanNode.h tree.h
