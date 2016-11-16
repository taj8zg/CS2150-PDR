//Ashley Nguyen - apn2my 
//Prelab10 - huffmanenc.cpp
//4/18/16
//Referenced Aaron Bloomfield's binary_heap.cpp and fileio.cpp examples in the repo

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include "heap.h"
#include "tree.h"
#include "huffmanNode.h"

using namespace std;

int main (int argc, char *argv[]) {
    // Invalid parameter input
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    // File not found 
    if ( fp == NULL ) {
        cout << "File '" << argv[1] << "' does not exist!" << endl;
        exit(2);
    }

    //Initialiazing array of frequencies to 0
    int freq[128];
    for(int i = 0; i < 128;i++){
      freq[i]=0;
    } 
    
    //While we have not hit end of file, increment number of symbols read in
    char g;
    int asVal;
    int numLetters = 0;
    while ((g = fgetc(fp)) != EOF ){
      asVal =(int) g; //cast char to int 
      if(asVal > 31 && asVal < 128){ //range desired 
	++freq[asVal];
        ++numLetters;
      }
    }
    
    //Inserting characters into the heap 
    //huffmanNode* temp = new huffmanNode(0,'0');
    int diffChars = 0;
    heap h1;
    for(int i = 1;i < 128; i++){
      if(freq[i] > 0){
	diffChars++;
        huffmanNode* temp = new huffmanNode(freq[i],(char) i);
	h1.insert(temp);
       }
    }

    //Creating tree based on heap (forming the forest)
    tree* t1 = new tree();
    heap h2;
    h2 = t1->createTree(h1);
    t1->printPrefix(h2.findMin(),"");
    
    // nice pretty separator 
cout << "----------------------------------------" << endl;

    t1->setPrefix(h2.findMin(),"");
    rewind(fp);

    //Calculating compressed value w/ huffman encoding 
    vector<huffmanNode*> v1 = h1.getVector();
    int comp = 0; 
   
    while ((g = fgetc(fp)) != EOF ){

      for(int i = 1; i <= h1.getSize(); i++){

          if(g == v1[i]->getChar()){

	    cout << v1[i]->getPrefix() << " ";
	    comp += v1[i]->getPrefix().size();

	  }
      }
    }
   
    cout << endl;
cout << "----------------------------------------" << endl;
 
// Printing results! 
     int uncomp = 0;
     uncomp = numLetters*8;
     double ratio =(double) uncomp/comp;
     double cost = (double) comp/numLetters;
     cout<<"There are a total of " << numLetters << " symbols that are encoded." << endl;
     cout<<"There are " << diffChars << " distinct symbols used." << endl;
     cout<<"There were " << uncomp << " bits in the original file." << endl;
     cout<<"There were " << comp << " bits in the compressed file." << endl;
     cout<<"This gives a compression ratio of "<< ratio <<"." << endl;
     cout<<"The cost of the Huffman Tree is "<< cost <<" bits per character." << endl;
    
     fclose(fp);
     return 0;
}
