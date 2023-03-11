/*
 * This is a class that contains all of the books in the library
 * It stores each type of book in a separate binary search tree
 * All of the binary search trees are stored in a map
 */

#include "itemcontainer.h"
#include "item.h"
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
    itemTrees.at(ch)->insert(addItem);
}

void ItemContainer::printTrees() const
{
    cout << "Displaying Items:" << endl;
    for (const auto &pair : itemTrees)
    {
        cout << pair.first << endl;
        pair.second->printBSTree();
        cout << endl;
    }
}

Item *ItemContainer::retrieveItem(Item *compareToObj) const
{
    char itemType = compareToObj->returnItemType();
    Item *retrieve = nullptr;
    itemTrees.at(itemType)->retrieve(*compareToObj, retrieve);
    if (retrieve == nullptr)
    {
        return nullptr;
    }
    return retrieve;
}