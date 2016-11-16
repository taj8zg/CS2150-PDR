//Name: Ashley Nguyen - apn2my
//PostLab04 - bitCounter.cpp
//2.17.16

#include <iostream>
#include <stdlib.h>

using namespace std;

//prototyping counter function
int counter(int n);

//main()
int main (int argc, char* argv[]) {

int result = atoi(argv[1]);

cout << "Bit Count result: " << counter(result) << endl;

return 0;
}

//counter function
int counter(int n){
  if( n == 0 ){
    return 0;
  }
  if( n == 1 ){
    return 1;
  }
  else{
return (counter(n/2))+ (n%2);
  }
}
