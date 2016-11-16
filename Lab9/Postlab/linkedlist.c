// Ashley Nguyen - apn2my
// PostLab09 - linkedlist.c 
// 4.13.16 
// Purpose: This program reads in an int n, reads in n amount of ints and puts these values in a linked list, 
// prints out the linked list, properly deallocates the linked list 
//struct = class 


#include <stdio.h>
#include <stdlib.h>

struct ListNode{
  struct ListNode *next, *previous;
  int value; 
};

struct List {
  struct ListNode *head;
};

int main(){
  struct ListNode *head; 
  struct List *myList;
  int n;
  int num;

  //Prompt user input 
  printf( "Enter how many values to input: " );
  scanf( "%d", &n);

  myList = (struct List*) malloc(sizeof( struct List) ); //allocate list 
  myList->head = (struct ListNode*) malloc(sizeof(struct ListNode)); //allocate node 
  head = myList->head; 
  myList->head->value = 0; //initialize node's val to 0 

  for(int i = 1; i <= n; i++){
    printf( "Enter value %d: ", i );
    scanf( "%d", &num );
    head->next = (struct ListNode*) malloc(sizeof(struct ListNode));
    head->value = num;
    head = head->next; 
  }

  //print the list 
  for( int k = n; k >0; k-- ){
    printf( "%d\n", myList->head->value );
    myList->head = myList->head->next;
    } 

  //Deallocate 
  free(myList);
  return 0;
}
