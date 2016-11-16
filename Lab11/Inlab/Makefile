# Ashley Nguyen - apn2my
# inLab11 - Makefile
# 4/26/16

CXX = clang++

CXXFLAGS = -Wall -g 

OFILES = traveling.o middleearth.o

.SUFFIXES: .o .cpp

main:	$(OFILES)
	$(CXX) $(OFILES)
	doxygen 

traveling.o: traveling.cpp
middleearth.o: middleearth.h middleearth.cpp 

clean:
	/bin/rm -f *.o *~
	/bin/rm -f *.out
