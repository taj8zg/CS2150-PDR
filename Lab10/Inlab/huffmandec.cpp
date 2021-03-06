// Ashley Nguyen - apn2my
// inlab10 - huffmandec.cpp
// 4/19/16 
// Modified inlab-skeleton.cpp from Aaron Bloomfield's repo to write this code 

// This program is the skeleton code for the lab 10 in-lab.  It uses
// C++ streams for the file input, and just prints out the data when
// read in from the file.

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "huffmanNode.h"

using namespace std;

void createTree(huffmanNode* node, string prefix, char c);

// main(): we want to use parameters
int main (int argc, char **argv) {
    
  cout << "Decoding the message...what secrets lie before this text file??\n" << endl;
    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }
    // attempt to open the supplied file; must be opened in binary
    // mode, as otherwise whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if ( !file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    // read in the first section of the file: the prefix codes
    char ascii[256];
    huffmanNode *n1 = new huffmanNode(0, '\0');
    while ( true ) {
      string character, code;
      //read in the first token on the line
      file >> character;
      //deal with special cases - new line 
      if( character[0] == '\n' || character[0] == '\r' ){
	continue;
      }
      //read in the second token on the line 
      //char c2 = file.get();

      //did we hit the separator?
      if(character[0] == '-' && (character.length() > 1)){
	file.getline( ascii, 255, '\n');
	break;
      }
      // check for space
      if( character == "space" ){
	character = " ";
      }
  
      //read in the prefix code 
      //file >> prefix;
      //file.getline( ascii, 255, '\n');
      
      //do something with the prefix code - Create tree from it
      code = string(ascii);
      file >> code;
      createTree(n1, code, character[0]);
     }

      // ----------------------------------------------------------

     // read in the second section of the file: the encoded message
      char bits; 
      huffmanNode* n2 = n1; // creating another node 
    
      while((bits = file.get()) != '-'){
	//read in next set of 1's and 0's 
	if( bits != '0' && bits != '1'){
	  continue;
	}
 
	//else read in the bits and perform something on it
	if( n2->left != NULL && bits == '0' ){
	  n2 = n2->left;
	}
	else if( n2->right != NULL && bits == '1' ){
	  n2 = n2->right;
	}
	if( n2->left == NULL && n2->right == NULL ){
	  cout << n2->getChar();
	  n2 = n1;
	}
      }
    
      cout << endl;
      // close the file before exiting
      file.close();
      return 0;
}

//createTree through recursion 
void createTree(huffmanNode* node, string prefix, char c){
  // left child ptr = 0, right child ptr = 1
  // Searching through first part of the file 
  //Hit the leaf case - only one step down from root
  if( prefix.length() == 0 ){
    node->letter = c; 
  }
  
  //call the left child, add a 0 to prefix 
  if(prefix[0] == '0'){
    if(node->left == NULL){
      node->left = new huffmanNode(0, '\0');
    }
    //recursively work down left node
    createTree(node->left, prefix.substr(1, prefix.length()-1), c);
  }
  //call the right child, add a 1 to prefix
  else if(prefix[0] == '1'){
    if(node->right == NULL){
    node->right = new huffmanNode(0, '\0');}
    createTree(node->right,  prefix.substr(1, prefix.length()-1), c);
  }
}
