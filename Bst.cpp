// FILE: Bst.cpp
// R England, Transy U
// CS 2444, Fall 2014
//
//      Implementation of Binary Search Tree
//
#include    <iostream>
#include    "Bst.h"
using namespace std;

/////
//// public member functions:
///

// constructor
Bst::Bst () {
    root = 0;
}

// destructor
Bst::~Bst () {
    kill (root);
}

// insert [public wrapper]
bool Bst::insert (const DataType& newItem) {
    return insert (root, newItem);
}

// get [public wrapper]
bool Bst::get (const KeyType& key, DataType& item) const {
    return get (root, key, item);
}

// remove [public wrapper]
bool Bst::remove (const KeyType& key) { 
	return remove(root, key);	
}
 

/////
//// private member functions:
///

bool Bst::remove (Node*& pRoot, const KeyType& key) const {
	
	// CASE: key not found in Table
	if (!pRoot)
		return false;

	// Checks further cases	in Fn call
	if (key == pRoot-> dataItem)
		return removeNode(pRoot, key);
	// Finds key in Table
    	if (key > pRoot -> dataItem) 
        	return remove (pRoot -> right, key);
	if (key < pRoot-> dataItem)
        	return remove (pRoot -> left, key);
		

}

//// Main remove private function, decides which CASE to use

bool Bst::removeNode (Node*& pRoot, const KeyType& key) const {
	// CASE: No kids
	if (!((pRoot-> right) && (pRoot-> left))) {
		return noKids(pRoot);
	}	
	// CASE: 2 kids
	if ( (pRoot-> right) && (pRoot-> left)) {
		return twoKids(pRoot); 
	}
	// CASE: 1 kid
	if ( (pRoot-> right) || (pRoot-> left) ) {
		return oneKid(pRoot);
	}
}


////// Remove private sub-functions //////
	
/// Function for no kids case: deletes node and then sets parent's pointer to 0
bool Bst::noKids(Node*& pRoot) const {
	delete pRoot;
	pRoot = 0;
	return true;
}

/// Function for one kid case: replaces victim with its internal child, and deletes victim
bool Bst::oneKid(Node*& pRoot) const {		
	if (pRoot-> right) {			// if the right node is the internal kid
		delete pRoot;
		pRoot = pRoot-> right;
		return true;
	} else {				// then the left node must be the internal kid
		delete pRoot;
		pRoot = pRoot-> left;
		return true;
	}
}

/// Function for two kid case: Deletes IOS, locates IOS, copies it over victim's label, 
//
bool Bst::twoKids(Node*& pRoot) const {
	Node* temp;
	// Locates In Order Successor by comparing the children of the victim 
	if (pRoot-> right > pRoot-> left) {
		delete pRoot;
		temp = pRoot-> left;		// holds lesser node in temp 
		pRoot = pRoot-> right;		// copies greater node (right) over the victim's label
		pRoot-> left = temp;		// copies lesser node into the left pointer of pRoot
	} else {
		delete pRoot;
		temp = pRoot-> right;		
		pRoot = pRoot-> left;		// copies greater node (left) over the victim's label
		pRoot-> right = temp;
	}
		return true;
}
//// insert [private overload]
///		put <newItem> in the tree, if it's not already there
//
bool Bst::insert (Node*& pRoot, const DataType& newItem) {
// base cases
    if (!pRoot) {
        pRoot = new Node (newItem);
        return true;
    }
    if (newItem == pRoot -> dataItem)
        return false;

// recursive cases
    return (newItem > pRoot -> dataItem) ?
            insert (pRoot -> right, newItem) :
            insert (pRoot -> left, newItem);
}

//// get [private overload]
///		retrieve <item> that matches <key>, if it's here
//
bool Bst::get (Node* pRoot, const KeyType& key, DataType& item) const {
// base cases
    if (!pRoot)
        return false;
    if (key == pRoot -> dataItem) {
        item = pRoot -> dataItem;
        return true;
    }

// recursive cases
    return (key > pRoot -> dataItem) ?
            get (pRoot -> right, key, item) :
            get (pRoot -> left, key, item);
}

//// kill
///     destroy this node and all of its descendants
//		[Q: Which traversal?]
//
void Bst::kill (Node* pRoot) {
    if (pRoot) {
        kill (pRoot -> left);
        kill (pRoot -> right);
        delete pRoot;
    }
}


//// printDEBUG
///     display the current contents of the tree
//      [Q: Which traversal?]
//
void Bst::printDEBUG (Node *pRoot) const {
    if (pRoot) {
        printNode (pRoot);
        printDEBUG (pRoot -> left);
        printDEBUG (pRoot -> right);
    }
}

//// printNode
///		display the current contents of a node
//
void Bst::printNode (Node *pRoot) const {
    cout << endl << "data: " << pRoot -> dataItem;
    cout << endl << "\tleft: ";
    if (pRoot -> left)
        cout << pRoot->left->dataItem;
    else
        cout << "[EXTERNAL]";
    cout << endl << "\tright: ";
    if (pRoot -> right)
        cout << pRoot->right->dataItem;
    else
        cout << "[EXTERNAL]";
    cout << endl;
}
