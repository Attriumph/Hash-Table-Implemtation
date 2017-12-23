// Name:Lingquan Han
// USC NetID:lingquah
// CSCI 455 PA5
// Fall 2017

/*
 * grades.cpp
 * A program to test the Table class.
 * How to run it:
 *      grades [hashSize]
 * 
 * the optional argument hashSize is the size of hash table to use.
 * if it's not given, the program uses default size (Table::HASH_SIZE)
 *
 */

#include "Table.h"

// cstdlib needed for call to atoi
#include <cstdlib>
#include <iostream>
using namespace std;

//allow users to insert new entry into table
//@param grades 
//               the current table  
//@param name
//               the name that the user want to insert
//@param score
//                the corresponding score of the student
void wantInsert(Table * grades, const string &name, string score);

//allow users to update the score for a student
//@param grades 
//               the current table  
//@param name
//               the name that the user want to change score for 
//@param score
//                the corresponding score of the student
void wantChangeScore(Table * grades,const string &name,string newScore);

//allow users to lookup a student in the table
//@param grades 
//               the current table  
//@param name
//               the name that the user want to serach
void wantLookup(Table * grades, const string &name);

//allow users to delete a existing entry in the table
//@param grades 
//               the current table  
//@param name
//               the name that the user want to delete
void wantRemove(Table * grades, const string &name);

//allow users to print all entries in the table
//@param grades 
//               the current table  
void wantPrint(Table * grades);

//allow users to get the number of entries in the table
//@param grades 
//               the current table  
void wantSize(Table * grades);

//allow users to know statistics about the hash table at this point
//@param grades 
//               the current table  
void wantStats(Table * grades);

//allow users to know the command of the program
void wantHelp();

//the interaction between users and the program
//@param grades 
//               the current table  
//@param cmd
//               the command that users input
void interact(Table * grades,string & cmd);


int main(int argc, char * argv[]) {

  // gets the hash table size from the command line

  int hashSize = Table::HASH_SIZE;

  Table * grades;  // Table is dynamically allocated below, so we can call
                   // different constructors depending on input from the user.

  if (argc > 1) {
    hashSize = atoi(argv[1]);  // atoi converts c-string to int


    if (hashSize < 1) {
      cout << "Command line argument (hashSize) must be a positive number" 
	   << endl;
      return 1;
    }

    grades = new Table(hashSize);

  }
  else {   // no command line args given -- use default table size
    grades = new Table();
  }


  grades->hashStats(cout);
  
  string cmd;
  cout << "cmd>" << endl;
  cin >> cmd;
  while (cmd != "quit") {
  interact(grades, cmd);
  cout << "cmd>" << endl;
  cin >> cmd;
  }
  return 0;
}


void interact(Table * grades, string & cmd) {
	string name;
	string score;
	string newScore;
	if (cmd == "insert") {
		cout << "name" << "score:";
		cin >> name >> score ;
		wantInsert(grades, name, score);
	}
	else if (cmd == "change") {
		cout << "name" << "new score:";
		cin >> name >> newScore ;
		wantChangeScore(grades, name, newScore);
	}
	else if (cmd == "lookup") {
		cout << "name:";
		cin >> name ;
		wantLookup(grades, name);
	}
	else if (cmd == "remove") {
		cout << "name:";
		wantRemove(grades, name);
	}
	else if (cmd == "print") {
		wantPrint(grades);
	}
	else if (cmd == "size") {
		wantSize(grades);
	}
	else if (cmd == "stats") {
		wantStats(grades);
	}
	else if (cmd == "help") {
		wantHelp();
	}
	else {
		cout << "Error:invalid command!" << endl;

	}
}

	void wantInsert(Table * grades, const string &name, string score) {
		
		bool result = grades->insert(name, atoi(score.c_str()));
			if (result == false) {
				cout << "Error:The student is alreay in the table." << endl;
			}
	}


	void wantChangeScore(Table * grades, const string &name, string newScore){
	
		if (grades->lookup(name) != NULL) {
			grades->remove(name);
			grades->insert(name, atoi(newScore.c_str()));
		}
		else {
			cout << "Warning:The student is not in the table, so the entry is inserted into table;" << endl;
		}
	

	}
		
	void wantLookup(Table *grades, const string &name) {
		cout << "wantLookup 's nanme is "<<name;
		int * pointerScore = grades->lookup(name);
		cout << "wantLookup 's nanme's pointerScore is  " << pointerScore;
		if (pointerScore != NULL) {
			cout << "The student's score is " << *pointerScore << endl;
      
		}else {
			cout << "Error: no such a student!" << endl;
		}
		

    }

	void wantRemove(Table *grades, const string &name) {
		if (grades->lookup(name) != NULL) {
			grades->remove(name);
		}
		else {
		cout << "Error:The student is not in the table！" << endl;
		}


	}

	void wantPrint(Table *grades) {
		grades->printAll();
	
	}
	
	void wantSize(Table *grades) {
		cout << grades->numEntries() << endl;
	}

	void wantStats(Table *grades) {
		grades->hashStats(cout);
	}

	void wantHelp() {
		cout << "insert name score    : Insert this name and score in the grade table." << endl;
		cout << "change name newscore : Change the score for name. " << endl;
		cout << "lookup name          : Lookup the name, and print out his or her score." << endl;
		cout << "remove name          : Remove this student." << endl;
		cout << "print                : Prints out all names and scores in the table." << endl;
		cout << "size                 : Prints out the number of entries in the table." << endl;
		cout << "stats                : Prints out statistics about the hash table at this point." << endl;
		cout << "quit                 : Exits the program." << endl;
	}
