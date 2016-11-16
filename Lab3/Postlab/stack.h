//Name: Ashley Nguyen - apn2my
//PostLab03 - stack.h
//2.9.16

#ifndef STACK_H
#define STACK_H 

#include <iostream>
#include <cstdlib>
#include "ListNode.h"
#include "List.h"
#include "ListItr.h"

using namespace std; 

class stack {

 public:
  stack();
  ~stack();
  void push( int n );
  void pop();
  int top() const;
  bool empty() const;
  
  void add();
  void subtract();
  void multiply();
  void divide();
  void negate();

 private: 
  List *theStack;
};

void errorMessage();

#endif
