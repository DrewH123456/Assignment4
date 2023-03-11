//-----------------------------------------------------------------------------
// The BinTree class is a binary search tree that stores NodeData objects.
// The class provides methods for inserting, removing,
// and retrieving NodeData objects from the tree.
// The class also provides methods for checking if the tree is empty,
// displaying the tree
// sideways, and getting the sibling and parent of a NodeData object in the tree.
// The class also has a copy constructor, assignment operator,
// and methods for converting
// the tree to an array and vice versa.
#ifndef BINTREE_H
#define BINTREE_H
#include <iostream>
#include <string>
using namespace std;

class Item;

class BinTree
{

    friend ostream &operator<<(ostream &output, const BinTree &);

public:
    // constructor
    // Initializes an empty binary search tree.
    BinTree();
    // copy constructor
    // Initializes a new binary search tree as a deep copy of the provided tree.
    BinTree(const BinTree &);
    // Destructor
    // Deletes all memory associated with the binary search tree
    // and calls makeEmpty() to ensure the tree is empty
    ~BinTree(); // calls makeEmpty()
    // check whether the tree is empty
    bool isEmpty() const;
    // make the tree empty
    void makeEmpty(); // delete all memory so isEmpty() returns true
    // set this tree equal to the other tree
    BinTree &operator=(const BinTree &);

    // Comparison operator
    bool operator==(const BinTree &) const;
    bool operator<(const BinTree &) const;
    bool operator!=(const BinTree &) const;
    // insert a new node to the tree
    bool insert(Item *);
    // retrieve the node data
    bool retrieve(const Item &, Item *&) const;
    // remove a node from the tree
    // Remove have 3 case, when no child, 1 child and 2 childs
    bool remove(const Item &, Item *&);
    void displaySideways() const; // displays the tree sideways, root is leftmost
    // get the sibling nodes
    bool getSibling(const Item &, Item &) const;
    // get the parent nodes
    bool getParent(const Item &, Item &) const;
    // turn bstree to array
    void bstreeToArray(Item *[]);
    // turn array to bstree
    void arrayToBSTree(Item *[]);
    // print bstree
    void printBSTree() const;

private:
    struct Node
    {
        Item *data;  // pointer to data object
        Node *left;  // left subtree pointer
        Node *right; // right subtree pointer
    };
    Node *root; // root of the tree

    bool retrieveHelper(const Node *current, const Item &target,
                        Item *&foundItem) const;

    // utility functions
    // printBSTree helper
    void printBSTreeHelper(Node *current) const;
    // void inorderHelper(Node *) const; // recursive helper for operator<<
    void inorderHelper(Node *) const;
    // helper method for viewing the tree side way
    void sidewaysHelper(Node *, int) const;
    // copy helper method, recurively help copy helper
    void copyHelper(Node *current, Node *otherCurrent);
    // makeEmpty helper method
    void makeEmptyHelper(Node *&);
    // isEmpty helper method
    bool isEqual(Node *, Node *) const;
    // bstreeToArray Helper
    void bstreeToArrayHelper(Node *current, Item *ndArray[], int &index);
    // arrayToBSTree Helper
    Node *arrayToBSTreeHelper(Item *sortedArray[], int low, int high);
    // remove helper method
    bool removeHelper(Node *&current, const Item &target, Item *&item);
    // delete helper
    void deleteCurrent(Node *&current, Item *&);
    // remove helper
    Item *findAndDeleteJustBigger(Node *&current);
    // printBSTree helper
};
#endif