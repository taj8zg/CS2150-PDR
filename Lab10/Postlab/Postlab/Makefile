# Ashley Nguyen - apn2my
# PostLab10 - Makefile
# 4/20/16 

CXX = clang++

CXXFLAGS = -Wall -g -o encoder 
CXXFLAGS1 = -Wall -g -o decoder

PRELAB = heap.o huffmanenc.o huffmanNode.o tree.o

INLAB = huffmandec.o huffmanNode.o 

.SUFFIXES: .o .cpp

main:	PRELAB INLAB

PRELAB:	$(PRELAB)
	$(CXX) $(CXXFLAGS) $(PRELAB)

INLAB:	$(INLAB)
	$(CXX) $(CXXFLAGS1) $(INLAB)

#PRELAB Dependencies 
heap.o: heap.h heap.cpp huffmanNode.h
huffmanenc.o: huffmanenc.cpp huffmanNode.h heap.h tree.h
huffmanNode.o: huffmanNode.h huffmanNode.cpp
tree.o:	tree.h tree.cpp heap.h huffmanNode.h

#INLAB DEPENDENCIES
huffmandec.o: huffmandec.cpp huffmanNode.h
huffmanNode.o: huffmanNode.h huffmanNode.cpp

#clean
clean:
	-rm -f *.o *~ encoder 
	-rm -f *.o *~ decoder
