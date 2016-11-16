//Ashley Nguyen - apn2my 
//Prelab10 - huffmanNode.h
//4/18/16
//Referenced Aaron Bloomfield's binary_heap.cpp examples in the repo

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
