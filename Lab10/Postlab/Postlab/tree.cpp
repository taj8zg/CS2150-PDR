//Ashley Nguyen - apn2my 
//Prelab10 - tree.cpp
//4/18/16
//Referenced Aaron Bloomfield's binary_heap.cpp examples in the repo

#include <iostream>
#include "tree.h"
#include "huffmanNode.h"

using namespace std;

//Constructor
tree::tree(){
  root = NULL;
}

//Destructor 
tree::~tree(){
  delete root;
}

//setPrefix recursively sets the children of the root to the bits related to the character
void tree::setPrefix(huffmanNode *root, string bit){
  if (root->left == NULL && root->right == NULL){
    root->prefix = bit;
  }
  if (root->right) {
    setPrefix(root->right, bit+"1");
  }
  if (root->left){
    setPrefix(root->left, bit+"0");
  }
}
   
//printPrefix recursively prints each bit encoded for the character 
void tree::printPrefix(huffmanNode *root, string bit){
  
  //Base case once you have reached a leaf
  if (root->letter == ' '){
    cout << "space" << " " << bit << endl;
  }
  if (root->left == NULL && root->right == NULL && root->letter != ' '){
    cout << root->letter << " "<< bit <<endl;
  }
  if (root->left){
    printPrefix(root->left, bit + "0");
  }
  if (root->right) {
    printPrefix(root->right, bit + "1");
  }
}

//createTree
heap tree::createTree(heap huff){
  while(huff.getSize() >= 2){
    huffmanNode* x = huff.findMin();
    huff.deleteMin();
    huffmanNode* y = huff.findMin();
    huff.deleteMin();
    huffmanNode* combo = combine(x, y);
    huff.insert(combo);
  }
  return huff;
}

//Combine - merges two nodes into one 
huffmanNode* tree::combine(huffmanNode* n1, huffmanNode* n2) {
  int total = 0;
  total +=  n1->getFreq() + n2->getFreq();
  huffmanNode* retVal = new huffmanNode(total, '1');
  
  //creating the combined node by assigning left & right ptrs
  retVal->left = n1; //n1 is smaller so insert left
  retVal->right = n2;
  
  return retVal;
}


