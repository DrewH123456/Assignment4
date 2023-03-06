/*
 * This is a class that contains all of the books in the library
 * It stores each type of book in a separate binary search tree
 * All of the binary search trees are stored in a map
 */

#ifndef ITEMCONTAINER_H
#define ITEMCONTAINER_H

#include "bintree.h"
#include <unordered_map>

class ItemContainer
{
private:
    unordered_map<char, BinTree *> itemTrees; // stores bintrees of different books

public:
    // Constructor
    ItemContainer();

    // Destructor
    ~ItemContainer();

    // inserts a new binTree and associates character with it
    void addTree(char);
    void removeTree(char);
    void addItem(char, Item *);
    void printTrees() const;
};

#endif