// Ashley Nguyen - apn2my
// PostLab06 - hashTable.cpp
// 3.17.16 

#include "hashTable.h"
#include <vector>
#include <string>

//Constructor 
hashTable::hashTable(int size){
  buckets = new vector< list<string> >;
  list<string> holder;
  maxNumWords = 0;
  size = size + 1;

  //ensuring hash table size is a prime number
  if( !(checkprime(size)) ){
    size = getNextPrime(size) * 2; 
    buckets->resize(size);
    capacity = size;
  
    for(int i = 0; i < size; i++){
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
  list<string> & temp = buckets->at(hashfunction(s));

  return( find(temp.begin(),temp.end(),s ) != temp.end());
}

//insert()
bool hashTable::insert(const string &  s ){
  
  if( this->contains(s) ){
    return false;
  }
  else{
      list<string> & myList = buckets->at(hashfunction(s));
      myList.push_back(s);

      if(s.length() > maxNumWords)
	maxNumWords = s.length();
      return true;
  }
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
unsigned int hashTable::hashfunction(const string & str){
  int hashSpot = 0; 
  
  for( int i = 0; i < str.length(); i++ ){
    hashSpot++;
    hashSpot *= (str[i]*3) % (buckets->size());
  }

  hashSpot %= capacity;
  
  if( hashSpot < 0 ){
    return (hashSpot + capacity + 1); 
  }
  return hashSpot; 
}

