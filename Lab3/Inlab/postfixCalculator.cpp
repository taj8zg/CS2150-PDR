//Name: Ashley Nguyen - apn2my 
//InLab03 - postfixCalculator.cpp 
//2.9.16 

#include <iostream> 
#include <stack> 
#include <cstdlib>
#include "postfixCalculator.h"

using namespace std;

//Default Constructor 
postfixCalculator::postfixCalculator(){
  theStack = new stack<int>;
  sizeOfStack = 0;
}

//Destructor
postfixCalculator::~postfixCalculator(){
  delete theStack;
}
 
//push(int e)
void postfixCalculator::push( int e ){
  theStack->push( e );
  sizeOfStack++;
}

//top()
int postfixCalculator::top() const {
  if( theStack->empty() ){
    errorExit();
  }
  else{
    return theStack->top();
  }
  return theStack->top();
}

//pop()
void postfixCalculator::pop() { 

  if( theStack->empty() )
    errorExit();
  else
    theStack->pop();
    sizeOfStack--;
 
}

//empty() 
bool postfixCalculator::empty() const {
  if( sizeOfStack == 0 )
    return true;
  else
    return false; 
}

//add()
void postfixCalculator::add(){
  int a = theStack->top();
  theStack->pop();
  
  int b = theStack->top();
  theStack->pop();

  theStack->push( a + b);
}

//subtract()
void postfixCalculator::subtract(){
  int a = theStack->top();
  theStack->pop();

  int b = theStack->top();
  theStack->pop();
  
  theStack->push( b - a);
}

//multiply()
void postfixCalculator::multiply(){
  int a = theStack->top();
  theStack->pop();

  int b = theStack->top();
  theStack->pop();

  theStack->push( a * b );
}

//divide()
void postfixCalculator::divide(){
  int a = theStack->top();
  theStack->pop();

  int b = theStack->top();
  theStack->pop();
  
  theStack->push( b / a );
}

//negate()
void postfixCalculator::negate(){
  int a = theStack->top();
  theStack->pop();
  a = a * -1; 
  theStack->push( a );
}

//Error Message 
void errorExit(){

  cout << "ERROR: Now exiting..." << endl;
  exit(-1);

}
