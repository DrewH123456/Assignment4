// A BinTree contains nodes, which contain Item * pointers
// Drew Higginbotham

#ifndef BINTREE_H
#define BINTREE_H
#include <iostream>
#include <string>
using namespace std;

// BinTree: The BinTree class is a binary search tree that stores Node objects,
// which contain Item * pointers. This class provides methods for inserting,
// retrieving Nodes and printing Items stored within the Nodes.
// The class also provides methods for checking if the tree is empty, and
// clearing out the contents of the tree.
//
// Implementation and Notes:
//   --Each BinTree has a root Node. This Node has a left and right pointer
//   to other Nodes. Within these Nodes is data member which stores Item *
//   --The only Node that the BinTree directly has access to is the root Node,
//   all other Nodes are accessed through the root node.

class Item;

class BinTree
{
public:
    // default constructor, initializes an empty binary search tree.
    BinTree();

    // destructor, calls makeEmpty()
    ~BinTree();

    // check whether the tree is empty
    bool isEmpty() const;

    // make the tree empty, recursively deleting all Nodes
    void makeEmpty();

    // Comparison operator
    bool operator==(const BinTree &) const;
    bool operator!=(const BinTree &) const;

    // insert a new node to the tree
    bool insert(Item *);

    // retrieve the Item
    bool retrieve(const Item &, Item *&) const;

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

    // makeEmpty helper method
    void makeEmptyHelper(Node *&);
    // isEmpty helper method
    bool isEqual(Node *, Node *) const;
    // bstreeToArray Helper
};
#endif