/*
Ethan Massey
3/3/19
hashTable.cpp
*/

#include <fstream>
#include <stdlib.h>
#include <vector>
#include <list>
#include <iostream>
#include <string>
#include <algorithm>
#include "hashTable.h"

using namespace std;


// Constructor
hashTable::hashTable(int size){
	myTable = new vector<list<string> >;
	this->resize(size);
}

// Destructor
hashTable::~hashTable(){
	delete myTable;
}

// Uses hash function to return hash value for string
unsigned int hashTable::hashValue(string x){
	return ((x[0] * x[1] + x[2]) % myTable->size());
}

// Inserts string into hashTable
void hashTable::insert(string x){
	unsigned int hVal = hashValue(x);
	myTable->at(hVal).push_back(x);
}

// Returns true if string is in hash table
bool hashTable::contains(string x){
	unsigned int hVal = hashValue(x);

	list<string>::iterator it;
	it = find(myTable->at(hVal).begin(), myTable->at(hVal).end(), x);

	if(it != myTable->at(hVal).end()){
		return true;
	}else return false;
}

// Makes size next prime number
void hashTable::resize(int size){
	if(! checkprime(size)){
		myTable->resize(getNextPrime(size));
	}else{
		myTable->resize(size);
	}
}

// Returns true if p is prime
bool hashTable::checkprime(unsigned int p) {
	// 0 and 1 are not primes; the are both special cases
    if( p <= 1 ){
    	return false; 
    } 
    // 2 is prime
    if( p == 2 ){
    	return true;
    } 
    // even numbers other than 2 are not prime
    if( p % 2 == 0 ){
    	return false;
    } 
    // only go up to the sqrt of p
    for( int i = 3; i*i <= p; i += 2 ){
		if( p % i == 0 ){
            return false;
        }
    } 
    return true;
}

// Returns next prime number after n
int hashTable::getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n;
}

// Adds all words in Dictionary to hashTable
void hashTable::addDictionary(string filename){
	string line;

	ifstream myfile (filename);
  	if (myfile.is_open()){

    	while ( getline (myfile,line) ){
      		insert(line);
 		}
    	myfile.close();

  	}else{
  		cout << "Unable to open file." << endl;
  		cout << "Words not added." << endl; 
  	} 
}

// Prints hashTable
void hashTable::printTable(){
	int numWords = 0;
	for(int i=0; i<myTable->size(); i++){
		cout << i << ". ";
		for(auto v : myTable->at(i)){
			cout << v << " -> ";
			numWords++;
		}
		cout << endl;
	}
	cout << "Number of words in table: " << numWords << endl;

}
