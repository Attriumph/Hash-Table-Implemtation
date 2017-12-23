// Name:Lingquan Han
// USC NetID:lingquah
// CSCI 455 PA5
// Fall 2017

// pa5list.cpp
// a program to test the linked list code necessary for a hash table chain

// You are not required to submit this program for pa5.

// We gave you this starter file for it so you don't have to figure
// out the #include stuff.  The code that's being tested will be in
// listFuncs.cpp, which uses the header file listFuncs.h

// The pa5 Makefile includes a rule that compiles these two modules
// into one executable.

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

#include "listFuncs.h"

	int main() {

		ListType testList;
		initiList(testList);
		cout << " 1---'listInit()'test, next line should be empty" << endl;
		printList(testList);

		cout << " 2---'insertEle()'test,should be: a 1" << endl;
		insertEle(testList,"a", 1);
		printList(testList);
		cout << " 2---'insertEle()'test,should be: a 1 b 2" << endl;
		insertEle(testList,"b", 2);
		printList(testList);
		cout << " 2---'insertEle()'test,should be: a 1 b 2 c 3" << endl;
		insertEle(testList,"c", 3);
		printList(testList);


		cout << " 3---'listNumEntries()'test, should be: 3" << endl;
		cout << getNumOfEntries(testList) << endl;

		cout << " 4---'removeEle()'test,should be b 2 c 3" << endl;
		removeEle(testList,"a");
		printList(testList);

		cout << " 4---'removeEle()'test,should be empty" << endl;
		removeEle(testList,"b");
		removeEle(testList,"c");
		printList(testList);


		cout << " 5---'listLookup()'test,should be" << endl;
		insertEle(testList,"a", 1);
		int * targetAddr = lookupEle(testList,"a");
		cout << "targetAddr: " << targetAddr << endl;
		printList(testList);
		*targetAddr = 1000;
		printList(testList);


		return 0;
}
