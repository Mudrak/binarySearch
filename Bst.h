// FILE: Bst.h
// R England, Transy U
// CS 2444, Fall 2014
//
//      Interface for Binary Search Tree
//

#ifndef	BST_H
#define	BST_H

#include     "DataType.h"

class Bst {

public:
////// public member functions:	
    Bst (void);
    ~Bst (void);

//// insert
//      put <newItem> in the Table, if it's not already there
    bool insert (const DataType& newItem);

//// get
//      retrieve the <item> that matches <key>, if it's here
    bool get (const KeyType& key, DataType& item) const;

//// printDEBUG
//      display the current contents of the Table
    void printDEBUG (void) const { printDEBUG (root); }

//// remove
//	deletes victim node from the Table based on case # 
    bool remove (const KeyType& key); 


private:
////// private data:
    struct Node {
        DataType    dataItem;
        Node        *left, *right;

    // Node constructor
        Node (const DataType& newItem) {
            dataItem = newItem;
            left = right = 0;
        }
    } *root;

////// private member functions:
    void kill (Node *pRoot);
    bool insert (Node*& pRoot, const DataType& newItem);
    bool get (Node* pRoot, const KeyType& key, DataType& item) const;
    bool remove(Node*& pRoot, const KeyType& key) const;
    bool removeNode(Node*& pRoot, const KeyType& key) const;
    bool noKids(Node*& pRoot) const;
    bool oneKid(Node*& pRoot) const;
    bool twoKids(Node*& pRoot) const;
    void printDEBUG (Node *pRoot) const;
    void printNode (Node *pRoot) const;
};

#endif

