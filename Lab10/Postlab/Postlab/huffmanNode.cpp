//Ashley Nguyen - apn2my 
//inlab10 - huffmanNode.h
//4/19/16
//Referenced Aaron Bloomfield's binary_heap.cpp examples in the repo

#include <iostream>
#include "huffmanNode.h"

using namespace std;

//Constructor 
huffmanNode::huffmanNode(int frequency, char c){
  left = NULL;
  right = NULL;
  freq  = frequency;
  letter = c;
  prefix = "";
}

//Destructor
huffmanNode::~huffmanNode(){
  delete left;
  delete right;
}

//getFreq
unsigned int huffmanNode::getFreq() const{
  return freq;
}

//getChar
char huffmanNode::getChar(){
  return letter;
}

//getPrefix
string huffmanNode::getPrefix(){
  return prefix;
}

//override < operator
bool huffmanNode::operator<(const huffmanNode& node) const{
  return(this->getFreq() < node.getFreq());
}
