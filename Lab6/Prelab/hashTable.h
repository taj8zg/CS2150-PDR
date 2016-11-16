// Ashley Nguyen - apn2my
// PreLab06 - hashTable.h
// 3.9.16 

#ifndef HASHTABLE_H
#define HASHTABLE_H 

#include <iostream> 
#include <cstdlib> 
#include <vector>
#include <string> 
#include <list>
#include <algorithm>

using namespace std; 

class hashTable{
 public: 
  hashTable(int size);
  ~hashTable();
  bool contains( const string & s );
  bool insert( const string & s );
  bool checkprime( unsigned int p );
  int getNextPrime( unsigned int n );
  int hashfunction( const string & str );
  int capacity; 
  int maxNumWords; 

 private:
  vector< list <string> > *buckets;
};

#endif
