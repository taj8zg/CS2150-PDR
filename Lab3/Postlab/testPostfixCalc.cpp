//Name: Ashley Nguyen - apn2my
//PostLab03 - testPostfixCalc.cpp
//2.9.16 

#include <iostream> 
//#include <stack> 
#include <cstdlib>
#include <string>
//#include "postfixCalculator.h"
#include "stack.h"
#include "List.h"
#include "ListNode.h"
#include "ListItr.h"

using namespace std;

int main(){
  
  //Stack -- Input Testing 
  stack stk0;
  
   cout << "Enter a line of valid integers and operators, \nhit ENTER to end line and CTRL + D to get result: " << endl;
 
   while(cin.good()) {
     
     string str;
     cin >> str;
     int anInt;
    
     if( str == "" ){ 
      break;
    }   
 
    const char* cStr = str.c_str(); 
    
    //pushing in + ints
    if( isdigit(cStr[0]) ){
      anInt = atoi(cStr);
      stk0.push(anInt);
    }
    
    //pushing in - ints
    if(str[0] == '-' && str.length() > 1){
      anInt = atoi(cStr);
      stk0.push(-anInt);
    }
    
    //operations 
    if( str[0]  == '+' ){
      stk0.add();
    }
   
    if( str  == "-" ){
      stk0.subtract();
    }
    
    if( str[0]  == '*' ){
      stk0.multiply();
    }

    if( str  == "/" ){
      stk0.divide();
    }

    if( str  == "~" ){
      stk0.negate();
    }
   }
    cout << "Answer: " << stk0.top() << endl; 

  return 0;
}

  /*
  //Stack -- Hard Coded testing 
  stack stk; 
  stk.push(1);
  stk.push(2);
  stk.push(3);
  stk.push(4);
  stk.push(5);
  //stk.pop();
  stk.add();
  stk.add();
  stk.add();
  stk.add();
  
  cout << "Your Answer is..." << stk.top() << endl; 
  
  //PFC - Input Testing 
   postfixCalculator p0;
  
   //Prompting User for Input
   cout << "Enter a line of valid integers and operators, \nhit ENTER to end line and CTRL + D to get result: " << endl;
 
   while(cin.good()) {
     
     string str;
     cin >> str;
     int anInt;
    
     if( str == "" ){ 
      break;
    }   
 
    const char* cStr = str.c_str(); 
    
    //pushing in + ints
    if( isdigit(cStr[0]) ){
      anInt = atoi(cStr);
      p0.push(anInt);
    }
    
    //pushing in - ints
    if(str[0] == '-' && str.length() > 1){
      anInt = atoi(cStr);
      p0.push(-anInt);
    }
    
    //operations 
    if( str[0]  == '+' ){
      p0.add();
    }
   
    if( str  == "-" ){
      p0.subtract();
    }
    
    if( str[0]  == '*' ){
      p0.multiply();
    }

    if( str  == "/" ){
      p0.divide();
    }

    if( str  == "~" ){
      p0.negate();
    }
   }
    cout << "Answer: " << p0.top() << endl; 

//PFC -- Hard Coded Testing 
 
//Addition Test  
 cout << "Testing Addition..." << endl;
 postfixCalculator p1;

 p1.push(1);
 p1.push(2);
 p1.push(3);
 p1.push(4);
 p1.push(5);
 p1.add();
 p1.add();
 p1.add(); 
 p1.add();

 cout << "Add result: " << p1.top() << endl;

 //Subtraction Test 
 cout << "Testing subtract..." << endl;
 postfixCalculator p2; 

 p2.push(20);
 p2.push(10);
 p2.subtract();
 p2.push(-3); 
 p2.push(10); 
 p2.subtract(); 
 p2.subtract();
 p2.push(2); 
 p2.subtract();

 cout << "Subtract result: " << p2.top() << endl;
 
 //Multiplication Test
 cout << "Testing multiply..." << endl;
 postfixCalculator p3;

 p3.push(-1);
 p3.push(-2);
 p3.push(-5);
 p3.push(3);
 p3.multiply();
 p3.push(2);
 p3.push(-2);
 p3.multiply(); 
 p3.multiply(); 
 p3.multiply();
 p3.multiply();

 cout << " Multiply result: " << p3.top() << endl;

 //Division Test 
 cout << "Testing divide..." << endl;
 postfixCalculator p4; 
 
 p4.push(-1512);
 p4.push(-12);
 p4.push(-2);
 p4.divide();
 p4.divide();
 p4.push(-2);
 p4.divide();
 p4.push(3);
 p4.divide();
 
 cout << "Divide result..." << p4.top() << endl; 
 
 //Negation test 
 cout << "Testing negate..." << endl;
 postfixCalculator p5; 

 p5.push(-1);
 p5.negate();
 p5.negate();
 p5.negate();

 cout<< "Negate result: " << p5.top() << endl;
 
 //Error Message Test - pop()
   cout << "Testing error message for pop(), making empty stack..." << endl;
 postfixCalculator p6; 

 p6.push(55);
 p6.pop();
 p6.pop();

 //Error Message Test - top()
 cout << "Testing error message for top(), making empty top..." << endl;
 postfixCalculator p7; 

 p7.push(8);
 p7.pop();
 cout << "Top of stack is: " << p7.top() << endl;
 
 
 //InLab Test Case 1 
 postfixCalculator p8; 
 p8.push(6);
 p8.push(7);
 p8.push(2);
 p8.push(4);
 p8.add();
 p8.subtract();
 p8.divide();

 cout << "Test Case 1 Result: " << p8.top() << endl; */
