// ItemContainer contains all binTrees of each item in library
// Drew Higginbotham

#include "itemcontainer.h"
#include "item.h"
#include <unordered_map>
using namespace std;

// Constructor, creating a tree for every type of item binTree being used
ItemContainer::ItemContainer()
{
    addTree('C');
    addTree('F');
    addTree('P');
}

// Destructor, deleting all the binTrees stored in the itemTrees map
ItemContainer::~ItemContainer()
{
    for (const auto &pair : itemTrees)
    {
        delete pair.second;
    }
}

// inserts a new binTree and associates character with it
void ItemContainer::addTree(char ch)
{
    itemTrees.insert(make_pair(ch, new BinTree()));
}

// erases binTree given a letter
void ItemContainer::removeTree(char ch)
{
    itemTrees.erase(ch);
}

// given an item, stores it into its respective binTree
void ItemContainer::addItem(char ch, Item *addItem)
{
    itemTrees.at(ch)->insert(addItem);
}

// displays the contents of each binTree, calling binTree's displayTree
void ItemContainer::printTrees() const
{
    cout << "Displaying Items:" << endl;
    for (const auto &pair : itemTrees)
    {
        pair.second->printBSTree();
        cout << endl;
    }
}

// retrieves item from respective binTree, calling binTree's retrieve
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