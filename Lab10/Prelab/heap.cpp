//Ashley Nguyen - apn2my 
//Prelab10 - heap.cpp
//4/18/16
//Referenced Aaron Bloomfield's binary_heap.cpp examples in the repo

#include <iostream>
#include "heap.h"
#include "huffmanNode.h"

using namespace std;

//Constructor
heap::heap():size(0), heap1(101){
}

//Destructor
heap::~heap(){
  makeEmpty();
}

//makeEmpty - empties heap aka destructing it 
void heap::makeEmpty() {
  if( isEmpty())
    cout << "ERROR! Heap is empty, nothing to make empty" << endl;
  heap1.clear();
  size = 0;
}

//isEmpty()
bool heap::isEmpty() {
  return (size == 0 ? true : false );  
}

//insert and percolateUp()
void heap::insert(huffmanNode* theNode){
  while(size == heap1.size() - 1) {
    heap1.resize(heap1.size() * 2);
  }
  //call Percolate up to move node closer to root
  percolateUp(++size, theNode);
}

void heap::percolateUp(int hole, huffmanNode* node1){
  // while we haven't run off the top and while the
  // value is less than the parent...
  for(; (hole>1) && (*node1 < *heap1[hole/2]); hole/=2) {
    heap1[hole] = heap1[hole/2];
  }
  // correct position found! insert at that spot
  heap1[hole] = node1;
}

//deleteMin() & percolateDown 
void heap::deleteMin(){
  if(isEmpty()) {
    cout << "ERROR! Heap is empty, nothing to delete" << endl; 
  }
  // move the last inserted position into the root
  heap1[1] = heap1[size--];
  int holeTemp = 1;
  percolateDown(holeTemp);
}

void heap::percolateDown(int hole){
  huffmanNode* temp = heap1[hole];
  int child;
 
 // while there is a left child...
  while(hole * 2 <= size) {
    child = (2 * hole); //the left child
   
    // is there a right child? if so, is it lesser?
    if( (*(heap1[child+1])) < (*(heap1[child]))&& (child != size)){
      child++;
    }
    
    // if the child is greater than the node...
    if( (*heap1[child]) < (*temp) ) {
      heap1[hole] = heap1[child]; 
      hole = child;		        
    }
    else 
      break;   
  }
  // correct position found! insert at that spot
  heap1[hole] = temp;
}
 
//findMin()   
huffmanNode* heap::findMin() const{
  return heap1[1];
}

//getSize()
int heap::getSize(){
  return size;
}

//getVector()
vector<huffmanNode*> heap::getVector(){
  return heap1;
}
