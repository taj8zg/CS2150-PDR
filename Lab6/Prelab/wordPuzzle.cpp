// Ashley Nguyen - apn2my
// PreLab06 - wordPuzzle.cpp
// 3.9.16 
// Big Theta Running Time Calculation Result: n^4 (quad-nested for loop)

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include "hashTable.h"
#include "timer.h"

using namespace std; 

//Creating Table 
char table[500][500];
timer t;

//Prototyping 
bool readInTable(string filename, int &rows, int &cols);
char* getWordInTable( int startRow, int startCol, int dir, int len, 
		      int numRows, int numCols);

//main
int main( int argc, char* argv[] ){

  while(1){
    if( argc < 3 ){ //If arguments entered is less than 3, not a valid input
      cout << "Error! Incomplete input, try again" << endl;
      break;
    }
    
    //----------Dealing with 1st arg ---------------- dictionary file 
    //creating hashTable w/ appropriate numLines
    string dFile = argv[1];
    string sTemp;
    int numLines = 0;
    ifstream dict( dFile.c_str() );

    while( getline (dict, sTemp) ){
      numLines++;
    }

    dict.close();

    //Instantiating hashtable object with dictionary file contents
    hashTable *theTable = new hashTable( numLines );
    string current; 
    dict.open( dFile.c_str());

    while( dict.good() ){
      getline( dict, current );
      
      //inserting valid searchable words into table
      if( current.length() >= 3 ){
	theTable->insert( current );
      }
    }

    //----------Dealing with 2nd arg --------------- grid file 
    string gFile = argv[2];
    
    //opening up grid file within dictionary 
    dict.open( gFile.c_str());
    int rows; 
    int cols;
    
    readInTable(gFile.c_str(), rows, cols);

    int numFoundWords = 0;
    string dir;
    
    //beginning timer 
    t.start();

    //performing search 
    for( int r = 0; r < rows; r++ ){
      for( int c = 0; c < cols; c++ ){
	for( int d = 0; d < 8; d++ ){
	  for( int wordLen = 3; wordLen <= theTable->maxNumWords; wordLen++ ){

	    string thisWord = getWordInTable( r, c, d, wordLen, rows, cols );

	    if( thisWord.length() < wordLen ){
	      break;
	    }
	    else if( theTable->contains( thisWord ) ){

	      numFoundWords++;

	      switch( d ){
	      case 0:
		dir = "N";
		break;
	      case 1:
		dir = "NE";
		break;
	      case 2:
		dir = "E";
		break;
	      case 3:
		dir = "SE";
		break;
	      case 4:
		dir = "S";
		break;
	      case 5:
		dir = "SW";
		break;
	      case 6:
		dir = "W";
		break;
	      case 7:
		dir = "NW";
		break;
	      }
	      cout << dir << " (" << r << ", " << c << "): " << thisWord << endl;
	    }
	  }
	}
      }
    }
      //Stop time once finished searching
      t.stop();
      double time = t.getTime();

      //Printing summary Lines
      cout << numFoundWords << " words found" << endl;
      cout << "Found all  words in " << time << " seconds" << endl;

      //Ending while Loop
      break;
  }
    return 0;
}

//----------------readInTable.cpp-----------------------
bool readInTable (string filename, int &rows, int &cols) {
    // a C++ string to hold the line of data that is read in
    string line;
    // set up the file stream to read in the file (takes in a C-style
    // char* string, not a C++ string object)
    ifstream file(filename.c_str());
    // upon an error, return false
    if ( !file.is_open() )
        return false;
    // the first line is the number of rows: read it in
    file >> rows;
    cout << "There are " << rows << " rows." << endl;
    getline (file,line); // eats up the return at the end of the line
    // the second line is the number of cols: read it in and parse it
    file >> cols;
    cout << "There are " << cols << " cols." << endl;
    getline (file,line); // eats up the return at the end of the line
    // the third and last line is the data: read it in
    getline (file,line);
    // close the file
    file.close();
    // convert the string read in to the 2-D grid format into the
    // table[][] array.  In the process, we'll print the table to the
    // screen as well.
    int pos = 0; // the current position in the input data
    for ( int r = 0; r < rows; r++ ) {
        for ( int c = 0; c < cols; c++ ) {
            table[r][c] = line[pos++];
            cout << table[r][c];
        }
        cout << endl;
    }
    // return success!
    return true;
}

//----------------getWordinTable.cpp--------------------
char* getWordInTable (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocataion.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static char output[256];
    // make sure the length is not greater than the array size.
    if ( len >= 255 )
        len = 255;
    // the position in the output array, the current row, and the
    // current column
    int pos = 0, r = startRow, c = startCol;
    // iterate once for each character in the output
    for ( int i = 0; i < len; i++ ) {
        // if the current row or column is out of bounds, then break
        if ( (c >= numCols) || (r >= numRows) || (r < 0) || (c < 0) )
            break;
        // set the next character in the output array to the next letter
        // in the table
        output[pos++] = table[r][c];
        // move in the direction specified by the parameter
        switch (dir) { // assumes table[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }
    // set the next character to zero (end-of-string)
    output[pos] = 0;
    // return the string (a C-style char* string, not a C++ string
    // object)
    return output;
}

