//Ashley Nguyen - apn2my 
//inlab10 - huffmanNode.h
//4/19/16

#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

#include <iostream>

using namespace std;

class huffmanNode {
 public:
  huffmanNode(int frequency, char c);
  ~huffmanNode();
  unsigned int getFreq()const;
  char getChar();
  string getPrefix();
  bool operator<(const huffmanNode& node) const;
  huffmanNode *left, *right;
  int freq;
  char letter;
  string prefix;
};
#endif
