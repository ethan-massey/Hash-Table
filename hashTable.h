/*
Ethan Massey
3/3/19
hashTable.h
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <list>
#include <iostream>
#include <string>

using namespace std;

class hashTable{

public:
	hashTable(int size);
	~hashTable();
	unsigned int hashValue(string x);
	void insert(string x);
	bool contains(string x);
	void resize(int size);
	void addDictionary(string filename);
	void printTable();

private:
	// List implementation
	vector<list<string> > *myTable;
	bool checkprime(unsigned int p);
	int getNextPrime (unsigned int n);

};



#endif