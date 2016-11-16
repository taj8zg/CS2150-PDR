#Ashley Nguyen - apn2my
#PostLab06 - Makefile
#3.17.16

CXX = clang++ -O2
CXXFLAGS = -Wall -g

OFILES = wordPuzzle.o hashTable.o timer.o

main: $(OFILES)
	$(CXX) $(OFILES)

clean:
	-rm -f *.o *~

wordPuzzle.o: wordPuzzle.cpp hashTable.h timer.h
hashTable.o: hashTable.cpp hashTable.h
timer.o: timer.cpp timer.h
