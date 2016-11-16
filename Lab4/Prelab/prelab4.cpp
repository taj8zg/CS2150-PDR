//Name: Ashley Nguyen - apn2my
//PreLab04 - prelab4.cpp
//2.14.16

#include <iostream>
#include <cstdlib>
#include <string>
#include <climits>

using namespace std; 

void sizeOfTest(){
  cout << "Int size: " << sizeof(int) << endl; 
  cout << "Unsigned Int size: " << sizeof(unsigned int) << endl;
  cout << "Float size: " << sizeof(float) << endl;
  cout << "Double size: " << sizeof(double) << endl;
  cout << "Char size: " << sizeof(char) << endl;
  cout << "Bool size:  " << sizeof(bool) << endl;
  cout << "Int* size: " << sizeof(int*) << endl;
  cout << "Char* size: " << sizeof(char*) << endl;
  cout << "Double* size: " << sizeof(double*) << endl;
}

void outputBinary(unsigned int x){

  string out; 

  for( int i = 31; i > -1; i--){
    
    //Inserts a space after every 4 bits
    if( (i+1)%4 == 0 ){
      out += " ";
    }
    
    //compares binary base values of x and the bit to the left of index i
    if( x & (1 << i) ){
      out += "1";
    }

    //fills in all other spaces with 0's 
    else if( out.length() > 0 ){
      out += "0";
    }
  }
cout << "Final Result: " << out << endl; 
}

void overflow(){

  unsigned int max1 = UINT_MAX + 1;
  cout << "Max #: " << UINT_MAX << endl;
  cout << "Max # + 1: " << max1 << endl;
  cout << "Why does this happen? \nThis occurs because the binary form of the unsigned maximum integer is 'filled in' with all 1's - fulfilling the 32-bit requirement.  By attempting to add binary value 1 to the max integer, the binary form is attempting to create a '33-bit'.  Instead of pushing a value into the nonexistent bit-index of 33, the max number + 1 essentially defaults to 0." << endl; 
}

int main(){
  
  int input; 

    cout << "Enter one integer value: " << endl; 
    cin >> input; 
    outputBinary(input);
    
    cout << "\nPrinting byte size of standard types...\n" << endl; 
    sizeOfTest();

    cout << "\nPrinting max values and overflow explanations...\n" << endl; 
    overflow();
  
    return 0;
}
