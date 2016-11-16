//Ashley Nguyen - apn2my
//Prelab10 - tree.h
//4/18/2016

#ifndef TREE_H
#define TREE_H

#include <iostream>
#include "heap.h"
#include "huffmanNode.h"

using namespace std;

class tree{
 public:
  tree();
  ~tree();
  void setPrefix(huffmanNode* root, string bit);
  void printPrefix(huffmanNode* root, string bit);
  heap createTree(heap huff);
  huffmanNode* combine(huffmanNode* n1, huffmanNode* n2);
  huffmanNode *root;
};
#endif
