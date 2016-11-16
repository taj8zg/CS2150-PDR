// Ashley Nguyen - apn2my
// PreLab06 - hashTable.cpp
// 3.9.16 

#include "hashTable.h"
#include <vector>

//Constructor 
hashTable::hashTable(int size){
  buckets = new vector< list<string> >;
  maxNumWords = 0;
  size = size + 1;

  //ensuring hash table size is a prime number
  if( !(checkprime(size)) ){
    int newSize = getNextPrime(size);

    //Resizing buckets to the next highest prime number
    buckets->resize(newSize);
    capacity = newSize;
  
    for(int i = 0; i < newSize; i++){
      list<string> holder;
      buckets->push_back( holder );
    }
  }
}

//Destructor 
  hashTable::~hashTable(){
    delete buckets; 
  }

//contains() 
bool hashTable::contains( const string & s ) {
  list<string> & myList = buckets->at( hashfunction(s) );
  return( find(myList.begin(),myList.end(), s ) != (myList.end()));
}

//insert()
bool hashTable::insert( const string & s ){

  if( !(this->contains(s)) ){

    list<string> & myList = buckets->at( hashfunction(s) );
    myList.push_back( s );

    while(s.length() > maxNumWords){
      maxNumWords = s.length();
      return true;
    }
  }
  return false; 
}

//checkprime()
bool hashTable::checkprime( unsigned int p ){
  if( p <= 1 ){
    return false;
  }
  if( p == 2 ){
    return true; 
  }
  if( p%2 == 0 ){
    return false; 
  }
  for(int i = 3; i*i <= p; i += 2)
    if( p%i == 0 )
      return false;
  return true;
}

//getNextPrime()
int hashTable::getNextPrime(unsigned int n){
  while( !checkprime(++n));
  return n;
}

//hashfunction 
int hashTable::hashfunction(const string & str){
  int hashSpot = 1; 
  int len = str.length();

  for( int i = 0; i < len; i++ ){
    int tableSize = buckets->size();
    hashSpot *= (str[i]*37) % (tableSize);
    hashSpot = hashSpot + 1; 
  }

  hashSpot %= capacity; 
  
  //increasing size of table if index is negative
  if( hashSpot < 0 ){
    return (hashSpot + capacity); 
  } 

  return hashSpot; 
}

