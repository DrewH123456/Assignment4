// ItemContainer contains all binTrees of each item in library
// Drew Higginbotham

#ifndef ITEMCONTAINER_H
#define ITEMCONTAINER_H

#include "bintree.h"
#include <unordered_map>

/*
 * ItemContainer: ItemContainer is a class that stores every item's binary tree
 * into a map. Has functions such as addTree, removeTree, addItem, printTrees,
 * and retrieveItem.
 *
 * Implementation and Assumptions:
 *   --has map called itemTrees, which has key as item's respective char, such
 *   as 'P' for Periodical and value as its respective binTree that contains it
 *   --assumes there are only 26 types of items, if need be, can be expanded
 *   by changing key from chars to strings of multiple letters
 */

class ItemContainer
{
private:
    // stores bintrees of different items
    unordered_map<char, BinTree *> itemTrees;

public:
    // Constructor, creating a tree for every type of item binTree being used
    ItemContainer();

    // Destructor, deleting all the binTrees stored in the itemTrees map
    ~ItemContainer();

    // inserts a new binTree and associates character with it
    void addTree(char);

    // erases binTree given a letter
    void removeTree(char);

    // given an item, stores it into its respective binTree
    void addItem(char, Item *);

    // displays the contents of each binTree, calling binTree's displayTree
    void printTrees() const;

    // retrieves item from respective binTree, calling binTree's retrieve
    Item *retrieveItem(Item *retrieveObj) const;
};

#endif