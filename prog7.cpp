//	FILE: prog7.cpp
//	R England, Transy U
//  CS 2444, Fall 2014
//
//    Test driver for P7 Bst class
//
//    Build command: g++ prog7.cpp Bst.cpp Mp3.cpp -o p7
//          
#include	<iostream>
#include	"DataType.h"
#include	"Bst.h"
using namespace std;

// symbolic constants
const KeyType SENTINEL = (KeyType)(-1);
const int QUIT = 0, INSERT = 1, GET = 2, REMOVE = 3;

// function prototypes
void  testInsert (Bst& t);
void  testGet (Bst& t);
void  testRemove(Bst& t);
int   getMenuResponse (void);


/////
//// main program
///
//
int main (void) {
	Bst  t;
	cout << endl << endl
	     << "TEST DRIVER FOR BST CLASS" << endl << endl;

// see everything?
	char response;
	cout << "Show Bst contents after each operation? [y/n]: ";
	cin >> response;
	bool showTree = (toupper (response) == 'Y');

// loop as long as user wants
	bool stop = false;
	do {
		if (showTree) {
           		cout << endl << endl << "   Current tree contents:" << endl;
           		t.printDEBUG ();
         	}
     
		switch (getMenuResponse ()) {
		case QUIT:		
			stop = true;
			break;
		case INSERT:	
			testInsert (t);
			break;
		case GET:		
			testGet (t);
			break;
		case REMOVE:
			testRemove (t);
			break;
		default:
			cout << "Not a valid response. Try again." << endl;
			break;
		}

	} while (!stop);
	cout << endl << endl;

	return 0;
}

// getMenuResponse
//	display a menu; read response from the keyboard
int getMenuResponse (void) {
	cout << endl << endl
		 << "Type \t" << INSERT << " for insert" << endl
		 << '\t' << GET << " for get" << endl
		 << '\t' << REMOVE << " for remove" << endl
		 << '\t' << QUIT << " to quit" << endl << ": ";		
	int response;
	cin >> response;
	cout << endl;
	return response;
}

// testInsert
//	try out the insert function for a Bst object
void testInsert (Bst& t) {
	DataType value;
	cout << "\nItem to insert: ";
	cin >> value;
	cout << endl << "Insert operation "
             << ((t.insert (value)) ? "" : "NOT ")
             << "successful";
}

// testGet
//	try out the get function for a Bst object
void testGet (Bst& t) {
     KeyType key;
     DataType value;
     cout << endl << endl << "Next key to get: ";
     cin >> key;
     if (t.get (key, value)) {
	     cout << endl << "Success! Got this from tree:" << endl;
	     cout << value;
     }
     else {
	     cout << endl << "Get operation FAILED on tree for key " << key << endl;
     }
}

// testRemove 
//	try out the remove function for a Bst object
void testRemove(Bst& t) { 
	KeyType victim;
	cout << endl << endl << "Item to delete: "; // include table details too? 
	cin >> victim;
	if (t.remove(victim)) {
		cout << endl << "Success! You removed: " << endl;
		cout << victim;
	}
	else  {
	cout << endl << "Oh no! The item was not found in the Table " << endl;
	}
}

