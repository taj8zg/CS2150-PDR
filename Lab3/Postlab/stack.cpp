//Name: Ashley Nguyen - apn2my
//PostLab03 - stack.cpp
//2.9.16

#include <iostream>
#include <cstdlib>
#include "ListNode.h"
#include "List.h"
#include "ListItr.h"
#include "stack.h"

using namespace std; 

//Default constructor 
stack::stack(){
  theStack = new List(); 
}

//Destructor 
stack::~stack(){
  delete theStack; 
}

//push()
void stack::push( int n ){
    theStack->insertBefore( n, theStack->first()); 
}

//pop()
void stack::pop(){
  
  if(theStack->size() == 0){
    errorMessage();
  }
  else{
    int i = theStack->first().retrieve();
    theStack->remove(i);
  }
}

//top()
int stack::top() const{

  if(theStack->isEmpty()){
    errorMessage();
  }
  else{
    return theStack->first().retrieve();
  }
  return theStack->first().retrieve();
}

//empty() 
bool stack::empty() const{
  if(theStack->size() == 0 )
    return true; 
  else
    return false; 
}

//add()
void stack::add(){
  int a = this->top();
  this->pop();
  int b = this->top();
  this->pop(); 
  this->push( a + b );
}

//subtract()
void stack::subtract(){
  int a = this->top();
  this->pop();
  int b = this->top();
  this->pop();
  this->push( b - a );
}

//multiply()
void stack::multiply(){
  int a = this->top();
  this->pop();
  int b = this->top();
  this->pop();
  this->push( a * b);
}

//divide()
void stack::divide(){
  int a = this->top();
  this->pop();
  int b = this->top();
  this->pop();
  this->push( b / a );
}

//negate()
void stack::negate(){
  int a = this->top();
  this->pop();
  this->push( a * -1 );
}

//errorMessage non member function 
void errorMessage(){
  cout << "ERROR: Now exiting..." << endl;
  exit(-1);
}
