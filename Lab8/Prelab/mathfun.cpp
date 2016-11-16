// Ashley Nguyen - apn2my
// PreLab08 - mathfun.cpp
// 3.28.16 

#include <iostream>
#include <cstdlib>

using namespace std; 

extern "C" int product (int, int);
extern "C" int power (int, int);

int main(){
  int n1;
  int n2;

  cout << "Please enter the first integer: " << endl;
  cin >> n1; 
  cout << "Please enter the second integer: " << endl; 
  cin >> n2; 
  
  int pr;
  pr = product( n1, n2 );
  int pow;
  pow = power( n1, n2 );

  cout << "Product result: "<< pr << endl; 
  cout << "Power result: " << pow << endl; 

  return 0;
}
