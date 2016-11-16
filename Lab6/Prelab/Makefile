#Ashley Nguyen - apn2my
#PreLab06 - Makefile
#3.13.16

CXX = clang++
CXXFLAGS = -Wall -g

OFILES = wordPuzzle.o hashTable.o timer.o

main: $(OFILES)
	$(CXX) $(OFILES)

clean:
	-rm -f *.o *~

wordPuzzle.o: wordPuzzle.cpp hashTable.h timer.h
hashTable.o: hashTable.cpp hashTable.h
timer.o: timer.cpp timer.h
