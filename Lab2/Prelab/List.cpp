//Name: Ashley Nguyen - apn2my
//Prelab02 - List.cpp
//1.30.16 

#include <iostream>
#include "ListNode.h"
#include "List.h"
#include "ListItr.h"

using namespace std;

//Default constructor implementation 
List::List(){
  head = new ListNode;
  tail = new ListNode;
 
  head->next = tail;
  tail->previous = head;

  count = 0;
}

//Copy Constructor implementation 
List::List(const List& source){
    head = new ListNode;
    tail = new ListNode;

    head->next = tail;
    tail->previous = head;

    count = 0;

    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {       // deep copy of the list
        insertAtTail(iter.retrieve());
        iter.moveForward();
	} 
}

//Destructor 
List::~List(){
  delete head;
  delete tail; 
}

//Equals - assignment operator
List& List::operator=(const List& source){
  if (this == &source){
        return *this;
  }
    else {
        makeEmpty();
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
} 

//isEmpty() 
bool List::isEmpty() const {
  if( head->next == tail && tail->previous == head ){
    return true;
  } 
  //pointee of head's next = tail's data location (pointee), nothing inbetween (isEmpty)
  return false; 
}

//makeEmpty()
void List::makeEmpty() {
  while( !isEmpty() ){ //if it is not empty, delete head's next value (deleting forward)
    remove (head->next->value); //remove head->next->value?? 
  }
  head->next = tail; //ensuring that it is empty by tail pt to head vice versa
  tail->previous = head; 
}

//first()
ListItr List::first(){
  ListItr retVal;
  retVal = head->next; //element after head ListNode
  return retVal; 
}

//last()
ListItr List::last(){
  ListItr retVal;
  retVal = tail->previous; //element before tail ListNode
  return retVal;
}

//insertAfter()
void List::insertAfter(int x, ListItr position){
  ListNode* inside  = new ListNode; //have some node to refer to 
 
  inside->value = x; //to make inside's VALUE get inserted to parameter 

  inside->previous = position.current;   //inside's previous points to current node
  inside->next = position.current->next; //inside's next point to current node's next (after)
  position.current->next = inside;       //current node's next points back to inside (bridge)
  inside->next->previous = inside;       //inside's next pointer, points to a node, that node's previous should pt back to inside 
  
  count++; //inserted a node, update size of list 
}

//insertBefore()
void List::insertBefore(int x, ListItr position){
  ListNode* inside = new ListNode; 

  inside->value = x; 
  
  inside->next = position.current; //next points to current position 
  inside->previous = position.current->previous;//previous points to positions previous (before)
  position.current->previous = inside; //currents previous points to inserted node 
  inside->previous->next = inside;//inserted previous points to next, set equal to inside - bridges the gap 
  
  count++;
}

//insertAtTail()
void List::insertAtTail(int x){
  ListNode* inside = new ListNode;

  inside->value = x; //allocating parameter value x to inside node's value

  inside->previous = tail->previous; //to insert right behind tail 
  inside->next = tail;               //inside's next points to tail node itself 
  tail->previous = inside;           //tail's previous points to inside node itself (bridges tail to inside node R->L)
  inside->previous->next = inside;   //inside's previous pointer, points to next which should equal inside node itself 
                                     //(bridges last node and inside L->R)
 
  count++;
}

//remove()
void List::remove(int x){
  ListItr trash = find(x);

  trash.current->previous->next = trash.current->next; //links node before trash to node after trash
  trash.current->next->previous = trash.current->previous; //links node after trash to node before trash

  count--;
}

//find()
ListItr List::find(int x){
  ListItr header = ListItr(head);
  
  while( !header.isPastEnd() ){
    header.current = header.current->next; //access header's next pointer
    
   if( header.current->value == x) //if Itr's current value is x, return that Itr
      return header;
  }
  return header; //return's the tail if loop has not been reached
}

//size()
int List::size() const{
  return count;
}




