// Name:Lingquan Han
// USC NetID:lingquah
// CSCI 455 PA5
// Fall 2017


//*************************************************************************
// Node class definition 
// and declarations for functions on ListType

// Note: we don't need Node in Table.h
// because it's used by the Table class; not by any Table client code.


#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H
  
using namespace std;

struct Node {
  string key;
  int value;

  Node *next;

  Node(const string &theKey, int theValue);

  Node(const string &theKey, int theValue, Node *n);
};


typedef Node * ListType;

//*************************************************************************
//add function headers (aka, function prototypes) for your functions
//that operate on a list here (i.e., each includes a parameter of type
//ListType or ListType&).  No function definitions go in this file.


//initialize list
void initiList(ListType & list);

//insert an entry into current list
//@param list
//              current list
//@param name
//              the name of the entry will be inserted 
//@param score
//              the score of the entry will be inserted 
//@return  bool
//              ture if inserted successfully

bool insertEle(ListType & list, const string & name, const int score);

//search an entry in current list
//@param list
//              current list
//@param target
//              the target of the entry will be searched 
//@return  score
//              the pointer of its corresponding score of the target
int *lookupEle(const ListType & list, const string & target);

//remove an entry in current list
//@param list
//              current list
//@param target
//              the target of the entry will be removed
//@return  bool
//              ture if inserted successfully
bool removeEle(ListType & list, const string & target);

//print all entries in current list
//@param list
//           the current list
void printList(const ListType & list);

//get the number of  entries in current list
//@param list
//              current list
//@return  int
//              the number of  entries in current list
int getNumOfEntries(const ListType & list);


// keep the following line at the end of the file
#endif
