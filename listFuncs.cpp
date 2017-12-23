// Name:Lingquan Han
// USC NetID:lingquah
// CSCI 455 PA5
// Fall 2017


#include <iostream>

#include <cassert>

#include "listFuncs.h"
#include <string>

using namespace std;

Node::Node(const string &theKey, int theValue) {
  key = theKey;
  value = theValue;
  next = NULL;
}

Node::Node(const string &theKey, int theValue, Node *n) {
  key = theKey;
  value = theValue;
  next = n;
}




//*************************************************************************
// put the function definitions for your list functions below
//initialize list
void initiList(ListType & list) {
	list = NULL;

}

//insert an entry into current list
//@param list
//              current list
//@param name
//              the name of the entry will be inserted 
//@param score
//              the score of the entry will be inserted 
//@return  bool
//              ture if inserted successfully

bool insertEle(ListType & list, const string & name, const int score) {
	
	//if the list is null, insert the entry directly
	if (list == NULL) {
		list = new Node(name, score);
		return true;
	}

	//if the name of the element is same as the list,which means 
	//already exists, return false
	if (list->key == name) {
		return false;
	}
	else {
		//judge if there exist the name in the real list
		ListType temp = list;
		while (temp->next != NULL) {
			if (temp->next->key == name) {
				return false;
			}
			temp = temp->next;
		}
		temp->next = new Node(name, score);
		return true;

	}
}

//search an entry in current list
//@param list
//              current list
//@param target
//              the target of the entry will be searched 
//@return  score
//              the pointer of its corresponding score of the target
int * lookupEle(const ListType & list, const string & name){

	//judge if there exist the name in the real list
	ListType temp = list;
	while (temp != NULL) {
		if (temp->key == name) {
			return & temp->value;
			cout << "LookupEle 's nanme's temp->value is  " << &temp->value;
		}
		temp = temp->next;
	}
	return NULL;
}

//remove an entry in current list
//@param list
//              current list
//@param target
//              the target of the entry will be removed
//@return  bool
//              ture if inserted successfully
bool removeEle(ListType & list, const string & name) {
	//if the list is null,return false;
	if (list == NULL) {
		return false;
	}

	//if the name of the element is same as the list,which means 
	//already exists, return false
		ListType temp = list;
	if (temp->key == name) {
		list = temp->next;
		delete temp;
		return true;
	}
	else {
		//judge if there exist the name in the real list
		while (temp->next != NULL) {
			if (temp->next->key == name) {
				ListType deleteEle = temp->next;
				temp->next = deleteEle->next;
				delete deleteEle ;
				return true;
			}
			temp = temp->next;
		}
		return false;

	}


}

//print out all entries in current list
//@param list
//           the current list
void printList(const ListType & list) {
	
	//judge if there exist the name in the real list
	ListType temp = list;
	while (temp != NULL) {

		cout << temp->key << " " ;
		cout << temp->value << endl;
		temp = temp->next;
	}

}

//get the number of  entries in current list
//@param list
//              current list
//@return  int
//              the number of  entries in current list
int getNumOfEntries(const ListType & list) {
	int counter = 0;
	ListType temp = list;
	while (temp != NULL) {
		counter++;
		temp = temp->next;
	}
	return counter;
}
