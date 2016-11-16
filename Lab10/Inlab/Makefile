#Ashley Nguyen - apn2my
#inlab10 - Makefile
#4/19/16 

CXX = clang++

CXXFLAGS = -Wall -g

OFILES: huffmandec.o  huffmanNode.o

.SUFFIXES: .o .cpp

main:	$(OFILES)
	$(CXX) $(OFILES)

clean:
	-rm -f *.o *~ a.out

huffmanNode.o: huffmanNode.cpp huffmanNode.h
huffmandec.o: huffmanNode.h huffmandec.cpp
