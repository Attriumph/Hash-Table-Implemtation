// Name:Lingquan Han
// USC NetID:lingquah
// CSCI 455 PA5
// Fall 2017

// Table.cpp  Table class implementation


/*
 * Modified 11/22/11 by CMB
 *   changed name of constructor formal parameter to match .h file
 */

#include "Table.h"

#include <iostream>
#include <string>
#include <cassert>


// listFuncs.h has the definition of Node and its methods.  -- when
// you complete it it will also have the function prototypes for your
// list functions.  With this #include, you can use Node type (and
// Node*, and ListType), and call those list functions from inside
// your Table methods, below.

#include "listFuncs.h"


//*************************************************************************

//construct the default hash table
Table::Table() {
	hashSize = HASH_SIZE;
	table = new ListType[hashSize];

	//initialize the table
	for (int i = 0;i < hashSize;i++) {
		table[i] = NULL;

	}
}

//construct the hash table by the input by users
Table::Table(unsigned int hSize) {
	hashSize = hSize;
	table = new ListType[hashSize];

	//initialize the table
	for (int i = 0;i < hashSize;i++) {
		table[i] = NULL;
	}
}

//lookup a element
int * Table::lookup(const string &key) {
	//compute the hash value of the current key
	int hashValue = hashCode(key);
	int * scorePointer =  lookupEle(table[hashValue], key);
	cout << "Table Lookup 's nanme's scorePointer is  " << scorePointer;
	return scorePointer;   
}
//remove a entry from the table
bool Table::remove(const string &key) {
	//compute the hash value of the current key
	int hashValue = hashCode(key);

	bool result = removeEle(table[hashValue],key);
    return result;  
}
// insert an entry into cuurent table
bool Table::insert(const string &key, int value) {
	//compute the hash value of the current key
	int hashValue = hashCode(key);

	bool result = insertEle(table[hashValue], key, value);
    return result;  
}
//get the total number of current entries in the table
int Table::numEntries() const {
	int totalNum = 0;
	//loop all linked list and compute the total number
	for (int i = 0;i < hashSize;i++) {
		totalNum = totalNum + getNumOfEntries(table[i]);
	}
  return totalNum;      
}

//print out all entires in the table
void Table::printAll() const {
	//loop every list and print them out
	for (int i = 0;i < hashSize;i++) {
		printList(table[i]);
	}
}
//test the cuurent use of the hash table
void Table::hashStats(ostream &out) const {
	out << "number of buckets:" <<  hashSize  << endl;
	out << "number of entries:" <<  numEntries()  << endl;
	out << "number of non-empty buckets:" << getNumOfNonEmptyBucket() << endl;
	out << "longest chain:" << getNumOfLongestChain() << endl;
}




//get the number of longest chain in the table
unsigned int Table::getNumOfLongestChain() const {
	int longest = 0;
	for (int i = 0;i < hashSize;i++) {
		int curLength = 0;
		curLength = getNumOfEntries(table[i]);
		if (curLength > longest) {
			longest = curLength;
		}
	}
	return longest;

}
//get the number of non-empty bucket 
unsigned  int Table::getNumOfNonEmptyBucket()  const{
	int nonEmptyBK = 0;
	for (int i = 0; i < hashSize; i++) {
		if (table[i] != NULL) {
			nonEmptyBK++;
		}
	}
	return nonEmptyBK;
}
