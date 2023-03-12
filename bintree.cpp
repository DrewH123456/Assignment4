// A BinTree contains Nodes, which contain Item * pointers
// Drew Higginbotham

#include "bintree.h"
#include "item.h"
#include <string>

//----------------------------------------------------------------
// printBSTree
// prints out bstree in order
void BinTree::printBSTree() const
{
   if (root != nullptr)
   {
      root->data->printHeading();
   }
   printBSTreeHelper(root);
}

//----------------------------------------------------------------
// printBSTreeHelper
// helper for printBSTree, recursively prints out tree
void BinTree::printBSTreeHelper(Node *current) const
{
   if (current != nullptr)
   {
      printBSTreeHelper(current->left);
      current->data->print(cout);
      cout << endl;
      printBSTreeHelper(current->right);
   }
}

//----------------------------------------------------------------
// Constructor
//  initializes the root of the tree to be nullptr.
BinTree::BinTree() : root(nullptr) {}

//----------------------------------------------------------------
// helper methods for destructor methods
// It recursively deletes the elements of the tree
// and deallocates the memory
void BinTree::makeEmptyHelper(Node *&current)
{
   if (current != nullptr)
   {
      makeEmptyHelper(current->left);
      makeEmptyHelper(current->right);
      delete current->data;
      current->data = nullptr;
      delete current;
      current = nullptr;
   }
}

//----------------------------------------------------------------
// ~BinTree()
// Destructor method use the makeEmptyHelper to delete the tree
BinTree::~BinTree()
{
   makeEmpty();
}

//----------------------------------------------------------------
// makeEmpty()
//  helper method for the makeEmpty method.
// recursively deletes the elements of the tree
// and frees the memory associated with them.
void BinTree::makeEmpty()
{
   makeEmptyHelper(root);
}

//----------------------------------------------------------------
// isEmpty()
// checks whether the tree is empty or true
// returns true if the tree is empty
bool BinTree::isEmpty() const
{
   return (root == nullptr);
}

//----------------------------------------------------------------
// retrieve()
// retrieve the give node data
bool BinTree::retrieve(const Item &itemLookingFor, Item *&foundItem) const
{
   foundItem = nullptr;
   return retrieveHelper(root, itemLookingFor, foundItem);
}

bool BinTree::retrieveHelper(const Node *current, const Item &target,
                             Item *&foundItem) const
{
   if (current == nullptr)
   {
      return false;
   }

   if (*current->data == target)
   {
      foundItem = current->data;
      return true;
   }
   if (target < *current->data)
   {
      return retrieveHelper(current->left, target, foundItem);
   }
   else
   {
      return retrieveHelper(current->right, target, foundItem);
   }
}

//----------------------------------------------------------------
// operator ==
// compares two trees, returning true if they are the same
// otherwise returns false
bool BinTree::operator==(const BinTree &other) const
{
   return isEqual(root, other.root);
}

//----------------------------------------------------------------
// isEqual()
// operator == helper method
// recursively compares the nodes in the tree
// returns true if they are the same otherwise returns false
bool BinTree::isEqual(Node *a, Node *b) const
{
   if (a == nullptr && b == nullptr)
      return true;
   if (a == nullptr || b == nullptr)
      return false;
   if (*(a->data) != *(b->data))
      return false;
   return isEqual(a->left, b->left) && isEqual(a->right, b->right);
}

//----------------------------------------------------------------
// operator !=()
// check if the two trees are not equal
// returns true if they are not the same otherwise returns false
bool BinTree::operator!=(const BinTree &other) const
{
   return !(*this == other);
}

// inserts a new Node into the tree, unlesss it already exists in tree
bool BinTree::insert(Item *dataptr)
{
   // Create a new node with the given data pointer
   Node *newNode = new Node();
   newNode->data = dataptr;
   newNode->left = newNode->right = nullptr;

   // Check if the tree is empty
   if (isEmpty())
   {
      root = newNode;
      return true;
   }

   // Start at the root of the tree
   Node *current = root;
   // while true, find the correct spot
   // if (newNode->data == current->data)
   // {
   //    cout << "YOO" << endl;
   // }
   while (true)
   {
      if (*newNode->data == *current->data)
      {
         // If the data is already in the tree, delete the new node and return
         // false
         delete newNode;
         newNode = nullptr;
         cout << "Item already exists in library." << endl;
         return false;
      }
      else if (*newNode->data < *current->data)
      {
         if (current->left == nullptr)
         {
            // If the left child of the current node is null, insert the new
            // node here
            current->left = newNode;
            return true;
         }
         else
         {
            current = current->left;
         }
      }
      else
      {
         if (current->right == nullptr)
         {
            // If the right child of the current node is null, insert the new
            // node here
            current->right = newNode;
            return true;
         }
         else
         {
            current = current->right;
         }
      }
   }
}