//Name: Ashley Nguyen - apn2my
//InLab04 - inlab4.cpp
//2.16.16

#include <iostream>
#include <climits>
#include <limits>

using namespace std; 

int main(){
  
  //Finding values of 0 and 1 for various types
  int o = 0, x = 1;
  double o1= 0.0;
  double x1 = 1.0;
  char o2 = '0', x2 = '1';
  bool o3 = false, x3 = true;
  unsigned int o4 = 0, x4 = 1; 
  int* n_null  = NULL;
  char*  c_null = NULL;
  double* d_null = NULL;
  float o8 = 0.0, x8=1.0;

  //Representation in memory 
  bool b = true;
  char c = '1';
  int n = 0;
  double d = 1.0;   
  int* n2 = NULL;

  cout << b << " " << c << " " << n << " " << d << " " << n2 << endl;
       
  //Primitive Arrays in C++ 
  int IntArray[10];
  IntArray[0] = 0;
  IntArray[1] = 2;
  IntArray[2] = 4;
  IntArray[3] = 6;
  IntArray[4] = 8;
  IntArray[5] = 10;
  IntArray[6] = 12;
  IntArray[7] = 14;
  IntArray[8] = 16;
  IntArray[9] = 18;

  char CharArray[6];
  CharArray[0] = 'A';
  CharArray[1] = 's';
  CharArray[2] = 'h';
  CharArray[3] = 'l';
  CharArray[4] = 'e';
  CharArray[5] = 'y';

  int IntArray2D[6][5];
  IntArray2D[0][0] = 1;
  IntArray2D[0][1] = 3;
  IntArray2D[0][2] = 5;
  IntArray2D[0][3] = 7;
  IntArray2D[0][4] = 9;

  IntArray2D[1][0] = 11;
  IntArray2D[1][1] = 13;
  IntArray2D[1][2] = 15;
  IntArray2D[1][3] = 17;
  IntArray2D[1][4] = 19;

  IntArray2D[2][0] = 21;
  IntArray2D[2][1] = 23;
  IntArray2D[2][2] = 25;
  IntArray2D[2][3] = 27;
  IntArray2D[2][4] = 29;

  IntArray2D[3][0] = 31;
  IntArray2D[3][1] = 33;
  IntArray2D[3][2] = 35;
  IntArray2D[3][3] = 37;
  IntArray2D[3][4] = 39;

  IntArray2D[4][0] = 41;
  IntArray2D[4][1] = 43;
  IntArray2D[4][2] = 45;
  IntArray2D[4][3] = 47;
  IntArray2D[4][4] = 49;

  IntArray2D[5][0] = 51;
  IntArray2D[5][1] = 53;
  IntArray2D[5][2] = 55;
  IntArray2D[5][3] = 57;
  IntArray2D[5][4] = 59;

  char CharArray2D[6][5];
  CharArray2D[0][0] = 'a';
  CharArray2D[0][1] = 'b';
  CharArray2D[0][2] = 'c';
  CharArray2D[0][3] = 'd';
  CharArray2D[0][4] = 'e';

  CharArray2D[1][0] = 'f';
  CharArray2D[1][1] = 'g';
  CharArray2D[1][2] = 'h';
  CharArray2D[1][3] = 'i';
  CharArray2D[1][4] = 'j';

  CharArray2D[2][0] = 'k';
  CharArray2D[2][1] = 'l';
  CharArray2D[2][2] = 'm';
  CharArray2D[2][3] = 'n';
  CharArray2D[2][4] = 'o';

  CharArray2D[3][0] = 'p';
  CharArray2D[3][1] = 'q';
  CharArray2D[3][2] = 'r';
  CharArray2D[3][3] = 's';
  CharArray2D[3][4] = 't';

  CharArray2D[4][0] = 'u';
  CharArray2D[4][1] = 'v';
  CharArray2D[4][2] = 'w';
  CharArray2D[4][3] = 'x';
  CharArray2D[4][4] = 'y';

  CharArray2D[5][0] = 'z';
  CharArray2D[5][1] = '1';
  CharArray2D[5][2] = '2';
  CharArray2D[5][3] = '3';
  CharArray2D[5][4] = '4';

  return 0;
}
