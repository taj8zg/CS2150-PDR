//Name: Ashley Nguyen - apn2my
//PreLab03 - testPostfixCalc.cpp
//2.7.16 

#include <iostream> 
#include <stack> 
#include <cstdlib>
#include "postfixCalculator.h"

using namespace std;

int main(){

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
 /*cout << "Testing error message for pop(), making empty stack..." << endl;
 postfixCalculator p6; 

 p6.push(55);
 p6.pop();
 p6.pop();*/

 //Error Message Test - top()
 cout << "Testing error message for top(), making empty top..." << endl;
 postfixCalculator p7; 

 p7.push(8);
 p7.pop();
 cout << "Top of stack is: " << p7.top() << endl;

 return 0; 
}
