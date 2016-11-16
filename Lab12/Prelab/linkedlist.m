// Ashley Nguyen - apn2my
// PreLab12 - linkedlist.m
// 4/28/16 

#import <Foundation/NSObject.h>
#import <stdio.h>
#import <stdlib.h>
#import <math.h>

//Interface 
@interface ListNode : NSObject {
@public 
  ListNode* next; 
  int value;
}
-(int) value;
-(ListNode*) next;
@end 

//Implementation 
@implementation ListNode
-(ListNode *) next {
  return next;
}

- (int) value{
  return value;
}
@end

//main()
int main (void){
  //Dynamic allocation of listnode 
  ListNode* head = [ListNode new];
  ListNode* temp = head; 

  int input;
  printf("Enter how many values to input: ");
  scanf("%d",&input);

  //Constructing the list 
  for(int i = 0; i < input; i++){
    int val;
    printf("Enter value %d: ", i+1 );
    scanf("%d", &val);

    ListNode *linkedNode = [ListNode new];
    temp->value = val;
    temp->next = linkedNode;
    temp = temp->next; 
  }

  //Print the List 
  ListNode *print = [ListNode new];
  print = head; 

  for( int i = 0; i < input; ++i){
    int curr = print->value;
    printf("%d", curr);
    print = print->next;
    printf("\n");
  }

  //Deallocate memory 
  ListNode *dNode = [ListNode new];
  dNode = head;
 
  while( dNode != nil ){
    ListNode *removal = [ListNode new];
    removal = dNode; 
    dNode = dNode->next;
    [removal release];
  }
}
