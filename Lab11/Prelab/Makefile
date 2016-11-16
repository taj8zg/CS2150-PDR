# Ashley Nguyen - apn2my
# PreLab11 - Makefile
# 4/24/16

CXX = clang++

CXXFLAGS = -Wall -g 

OFILES = topological.o 

.SUFFIXES: .o .cpp

main:	$(OFILES)
	$(CXX) $(OFILES)
	doxygen 

topological.o: topological.cpp 

clean:
	/bin/rm -f *.o *~
	/bin/rm -f *.out
