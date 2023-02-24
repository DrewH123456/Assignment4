/*
 * This is a class that contains all of the books in the library
 * It stores each type of book in a separate binary search tree
 * All of the binary search trees are stored in a map
 */

#ifndef BOOKCONTAINER_H
#define BOOKCONTAINER_H

#include "bintree.h"

class BookContainer
{
private:
    map<char, BinTree *> bookTrees; // stores bintrees of different books

public:
    // Constructor
    BookContainer();

    // Destructor
    ~BookContainer();

    // inserts a new binTree and associates character with it
    void addTree(char, BinTree *);
    void removeTree(char);
};

#endif