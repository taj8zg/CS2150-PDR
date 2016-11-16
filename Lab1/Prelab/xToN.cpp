//Ashley Nguyen (apn2my)
//Prelab 01 - xToN.cpp
//1.25.2016
#include <iostream> 
using namespace std; 

//Prototyping xton function
int xton(int x, int n);

//xton function
int xton( int x, int n){
  int sub = x;
  if( n == 0){
    return 1;
  }
  else{
    sub = x * xton( x, n-1);
  }
    return sub; 
}

//main 
int main(){
  int a, b, result; 
  
  cout << "Enter first  integer and hit 'enter': " << endl; 
  cin >> a; 

  cout << "Enter second integer and hit 'enter': " << endl; 
  cin >> b; 

  result = xton(a,b);
  
  cout << a  << " ^ " << b << " = " << result  << endl; 

  return 0; 
}
