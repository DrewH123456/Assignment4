/*
 * This is a class that contains all of the books in the library
 * It stores each type of book in a separate binary search tree
 * All of the binary search trees are stored in a map
 */

#include "itemcontainer.h"
#include "nodedata.h"
#include <unordered_map>
using namespace std;

ItemContainer::ItemContainer()
{
    addTree('C');
    addTree('F');
    addTree('P');
}

ItemContainer::~ItemContainer()
{
    for (const auto &pair : itemTrees)
    {
        delete pair.second;
    }
}

void ItemContainer::addTree(char ch)
{
    itemTrees.insert(make_pair(ch, new BinTree()));
}

void ItemContainer::removeTree(char ch)
{
    itemTrees.erase(ch);
}

void ItemContainer::addItem(char ch, Item *addItem)
{
    NodeData *data = new NodeData(addItem);
    itemTrees.at(ch)->insert(data);
}

void ItemContainer::printTrees() const
{
    for (const auto &pair : itemTrees)
    {
        pair.second->printBSTree();
    }
}