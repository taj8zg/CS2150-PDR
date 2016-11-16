//Name: Ashley Nguyen - apn2my
//PreLab03 - postfixCalculator.h 
//2.7.16 

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream> 
#include <stack> 
#include <cstdlib>

using namespace std; 

class postfixCalculator { 
 
 public: 
  postfixCalculator(); //Default Constructor  
  ~postfixCalculator(); //Destructor  
  void push( int e ); 
  int top() const;
  void pop();
  bool empty() const;

  void add();
  void subtract();
  void multiply();
  void divide();
  void negate();
 
private: 
  stack<int> *theStack;
  int sizeOfStack;
  
}; 

//non-member function errorExit function
void errorExit();

#endif
