//Name: Ashley Nguyen - apn2my
//PostLab02 - ListItr.cpp
//2.3.16

#include <iostream> 
#include "List.h"
#include "ListNode.h"
#include "ListItr.h"

using namespace std; 

//Default constructor
ListItr::ListItr(){
  current = NULL;
}

//Copy Constructor
ListItr::ListItr(ListNode* theNode){ 
  current = theNode; 
}

//isPastEnd()
bool ListItr::isPastEnd() const{
  if( current->next == NULL ){
    return true;
  }
  return false; 
}

//isPastBeginning()
bool ListItr::isPastBeginning() const{
  if( current->previous == NULL ){
    return true;
  }
  return false; 
}

//moveForward()
void ListItr::moveForward(){ //in direction of next
  if( !isPastEnd() ){
    current = current->next; //towards the tails reading L->R
  }
}

//moveBackward()
void ListItr::moveBackward(){
  if( !isPastBeginning() ){
    current = current->previous; //moving towards head (pts to prev) R->L
  }
}

//retrieve()
  int ListItr::retrieve() const {
  return current->value;
}

//printList()
void printList(List& source, bool direction){
  ListItr printer;
  
  if( direction ){            //Printing forwards
    printer = source.first(); //can access List's public methods
    
    while( !printer.isPastEnd() ){
      cout << printer.retrieve() << " ";
      printer.moveForward();
    }
  }

  else{
    printer = source.last(); //Printing backwards 

    while( !printer.isPastBeginning() ){
      cout << printer.retrieve() << " ";
      printer.moveBackward();
    }
  }
}
