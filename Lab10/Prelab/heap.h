//Ashley Nguyen - apn2my 
//Prelab10 - heap.h
//4/18/16
//Referenced Aaron Bloomfield's binary_heap.cpp examples in the repo

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <string>
#include <vector>
#include "huffmanNode.h"

using namespace std;

class heap {
 public:
  heap();
  ~heap();
  void makeEmpty();
  bool isEmpty();
  vector<huffmanNode*> getVector();
  int getSize();
  void insert(huffmanNode* theNode);
  huffmanNode* findMin() const;
  void deleteMin();
  unsigned int size;
  vector<huffmanNode*> heap1;  
  void percolateUp(int hole, huffmanNode* node1);
  void percolateDown(int hole);
};
#endif
