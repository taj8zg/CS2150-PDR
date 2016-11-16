//Ashley Nguyen - apn2my
//PreLab09 - threexinput.cpp
// 4.10.16 

#include <iostream>
#include <cstdlib>
#include "timer.h"

using namespace std;

extern "C" int threexplusone(int);

int main(){
  
  int userInput;
  cout << "Please enter a number: " << endl;
  cin >> userInput;

  int count;
  cout << "Please enter number times run: " << endl;
  cin >> count; 

  timer time;
  time.start();

  for( int i = 0; i < count; i++ ){
    threexplusone(userInput);
  }
  time.stop();
  
  double total; 
  total = time.getTime()*1000;
  
  double avg;
  avg = total/count;

  cout << "Total steps for value of " << userInput << ", given " << count << " total calls is: " << threexplusone(userInput) << endl;

  cout << "Average time for each call is: " << avg << " ms" << endl;

  return 0;
}
