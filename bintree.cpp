#include "bintree.h"
#include "item.h"
#include <string>

//----------------------------------------------------------------
// printBSTree
// prints out bstree in order
//----------------------------------------------------------------
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
//----------------------------------------------------------------
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
// operator <<
// print the elements of the tree in in-order traversal.
//----------------------------------------------------------------
// ostream &operator<<(ostream &output, const BinTree &tree)
// {
//    tree.inorderHelper(tree.root);
//    output << endl;
//    return output;
// }

//----------------------------------------------------------------
// inorderHelper
// used to recursively traverse the tree and print the elements.
//----------------------------------------------------------------
// void BinTree::inorderHelper(Node *current) const
// {

//    if (current == nullptr)
//       return;
//    inorderHelper(current->left);
//    cout << *(current->data) << " ";
//    inorderHelper(current->right);
// }

//----------------------------------------------------------------
// Constructor
//  initializes the root of the tree to be nullptr.
//----------------------------------------------------------------
BinTree::BinTree() : root(nullptr) {}

//----------------------------------------------------------------
// operator =
// overload the assignment operator
// make a current tree empty then make a deep copy the new tree
//----------------------------------------------------------------
// BinTree &BinTree::operator=(const BinTree &other)
// {
//    if (this != &other)
//    {
//       // free the memory allocated
//       makeEmpty();
//       if (other.root == nullptr)
//       {
//          root = nullptr;
//       }
//       else
//       {
//          root = new Node();
//          root->left = root->right = nullptr;
//          // Deep copy the data
//          root->data = new Item(*other.root->data);
//          copyHelper(root, other.root);
//       }
//    }
//    return *this;
// }

//----------------------------------------------------------------
// Copy constructor
// set the root to nullptr and copy using the assignment operator
//----------------------------------------------------------------
// BinTree::BinTree(const BinTree &other)
// {
//    this->root = nullptr;
//    *this = other;
// }

//----------------------------------------------------------------
// copy helper methods
// helper methods use for copy constructor and assignment operator
// recursively copy the elements of the tree
//----------------------------------------------------------------
// void BinTree::copyHelper(Node *newTree, Node *otherTree)
// {
//    if (otherTree->left != nullptr)
//    {
//       newTree->left = new Node();
//       newTree->left->data = new Item(*otherTree->left->data);
//       copyHelper(newTree->left, otherTree->left);
//    }
//    if (otherTree->right != nullptr)
//    {
//       newTree->right = new Node();
//       newTree->right->data = new Item(*otherTree->right->data);
//       copyHelper(newTree->right, otherTree->right);
//    }
// }

//----------------------------------------------------------------
// helper methods for destructor methods
// It recursively deletes the elements of the tree
// and deallocates the memory
//----------------------------------------------------------------
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
//----------------------------------------------------------------
BinTree::~BinTree()
{
   makeEmpty();
}

//----------------------------------------------------------------
// makeEmpty()
//  helper method for the makeEmpty method.
// recursively deletes the elements of the tree
// and frees the memory associated with them.
//----------------------------------------------------------------
void BinTree::makeEmpty()
{
   makeEmptyHelper(root);
}

//----------------------------------------------------------------
// isEmpty()
// checks whether the tree is empty or true
// returns true if the tree is empty
//----------------------------------------------------------------
bool BinTree::isEmpty() const
{
   return (root == nullptr);
}

//----------------------------------------------------------------
// printBSTree()
// prints out the tree in inOrder
//----------------------------------------------------------------
void printBSTree()
{
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
//----------------------------------------------------------------
bool BinTree::operator==(const BinTree &other) const
{
   return isEqual(root, other.root);
}

//----------------------------------------------------------------
// isEqual()
// operator == helper method
// recursively compares the nodes in the tree
// returns true if they are the same otherwise returns false
//----------------------------------------------------------------
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
//----------------------------------------------------------------
bool BinTree::operator!=(const BinTree &other) const
{
   return !(*this == other);
}

//----------------------------------------------------------------
// operator<
// compares two tree
// compares two binary trees and returns true
// if the current tree is "less" than the other tree
bool BinTree::operator<(const BinTree &other) const
{
   if (root == nullptr && other.root != nullptr)
   {
      return true;
   }
   if (root != nullptr && other.root == nullptr)
   {
      return false;
   }
   if (*root->data < *other.root->data)
   {
      return true;
   }
   if (*root->data > *other.root->data)
   {
      return false;
   }
   BinTree leftTree, rightTree, otherLeftTree, otherRightTree;
   leftTree.root = root->left;
   rightTree.root = root->right;
   otherLeftTree.root = other.root->left;
   otherRightTree.root = other.root->right;
   if (leftTree < otherLeftTree)
   {
      return true;
   }
   if (otherLeftTree < leftTree)
   {
      return false;
   }
   return (rightTree < otherRightTree);
}

//----------------------------------------------------------------
// getSibling
// finds the sibling of a given NodeData
// by searching the tree and checking the left and right child
//----------------------------------------------------------------
bool BinTree::getSibling(const Item &nd, Item &sibling) const
{
   Node *current = root;   // start at the root of the tree
   Node *parent = nullptr; // variable to store the parent of the current node
   while (current != nullptr)
   {
      // Compare the search data with the current node's data
      if (*(current->data) == nd)
      {
         // If a match is found, check if the parent
         // has a left or right child that is not the current node
         if (parent != nullptr)
         {
            if (parent->left != nullptr && *(parent->left->data) != nd)
            {
               sibling = *(parent->left->data);
               return true;
            }
            else if (parent->right != nullptr && *(parent->right->data) != nd)
            {
               sibling = *(parent->right->data);
               return true;
            }
            else
            {
               return false;
            }
         }
         else
         {
            return false;
         }
      }
      else if (*(current->data) < nd)
      {
         parent = current;
         current = current->right; // search the right subtree
      }
      else
      {
         parent = current;
         current = current->left; // search the left subtree
      }
   }
   return false;
}

//----------------------------------------------------------------
// getParent finds the parent of a given NodeData by searching the tree
// and keeping track of the parent node.
// It returns false if the node has no parent.
bool BinTree::getParent(const Item &nd, Item &parent) const
{
   Node *current = root;       // start at the root of the tree
   Node *parentNode = nullptr; // keep track of the parent node
   while (current != nullptr)
   {
      if (*(current->data) == nd)
      {
         // If a match is found, store the parent node's
         // data in the parent parameter
         if (parentNode != nullptr)
         {
            parent = *(parentNode->data);
            return true;
         }
         else
         {
            return false; // if the node is the root, it has no parent
         }
      }
      else if (*(current->data) < nd)
      {
         parentNode = current;     // store the current node as the parent node
         current = current->right; // search the right subtree
      }
      else
      {
         parentNode = current;    // store the current node as the parent node
         current = current->left; // search the left subtree
      }
   }
   delete current;
   return false; // if the node is not found, return false
}

//----------------------------------------------------------------
// bstreeToArray()
// fill an array of NodeData* by using an inorder traversal of the tree
// The method leaves the tree empty after it is done
// traversing through the tree and filling the array.
//
void BinTree::bstreeToArray(Item *ndArray[])
{
   int i = 0;
   bstreeToArrayHelper(root, ndArray, i);
   makeEmpty(); // Clear the tree
}

void BinTree::bstreeToArrayHelper(Node *current, Item *ndArray[], int &index)
{
   if (current == nullptr)
      return;
   if (index >= 100)
      return; // add this
   bstreeToArrayHelper(current->left, ndArray, index);
   ndArray[index++] = current->data;
   current->data = nullptr;
   bstreeToArrayHelper(current->right, ndArray, index);
}

//----------------------------------------------------------------
// arrayToBStree
// to build a balanced binary search tree (BST)
// from a sorted array of NodeData*, leave the array with nullptr
//----------------------------------------------------------------
void BinTree::arrayToBSTree(Item *arr[])
{
   makeEmpty();
   int n = 0;
   while (arr[n] != nullptr)
   {
      n++;
   }
   root = arrayToBSTreeHelper(arr, 0, n - 1);
}

//----------------------------------------------------------------
// arrayToBStreeHelper
// help  to build a balanced binary search tree (BST)
// from a sorted array of NodeData*, leave the array with nullptr
//----------------------------------------------------------------
BinTree::Node *BinTree::arrayToBSTreeHelper(Item *sortedArray[], int low, int high)
{
   // checks if the low index is greater than the high index,
   // if it is, it returns a nullptr
   if (low > high)
   {
      return nullptr;
   }
   // find the middle index
   int mid = (low + high) / 2;
   // create a newNode to hold the ptr from arr to newNode data
   Node *newNode = new Node();
   newNode->data = sortedArray[mid];
   // recursively assign the newNode left and right
   newNode->left = arrayToBSTreeHelper(sortedArray, low, mid - 1);
   newNode->right = arrayToBSTreeHelper(sortedArray, mid + 1, high);
   return newNode;
}

//---------------------------------------------------------------------------
// displaySideways
// Displays a binary tree as though you are viewing it from the side.
// Turn head 90 degrees counterclockwise (to the left) to see tree structure.
// Hard coded displaying to standard output.
// void BinTree::displaySideways() const
// {
//    sidewaysHelper(root, 0);
// }

// void BinTree::sidewaysHelper(Node *current, int level) const
// {
//    if (current != nullptr)
//    {
//       level++;
//       sidewaysHelper(current->right, level);

//       // indent for readability, same number of spaces per depth level
//       for (int i = level; i >= 0; i--)
//       {
//          cout << "        ";
//       }

//       cout << *current->data << endl; // display information of object
//       sidewaysHelper(current->left, level);
//    }
// }

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
         // If the data is already in the tree, delete the new node and return false
         delete newNode;
         newNode = nullptr;
         cout << "Item already exists in library." << endl;
         return false;
      }
      else if (*newNode->data < *current->data)
      {
         if (current->left == nullptr)
         {
            // If the left child of the current node is null, insert the new node here
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
            // If the right child of the current node is null, insert the new node here
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

bool BinTree::remove(const Item &target, Item *&item)
{
   return removeHelper(root, target, item);
}

bool BinTree::removeHelper(Node *&current, const Item &target, Item *&item)
{
   if (current == nullptr)
   {
      return false;
   }

   // found item to remove
   if (target == *current->data)
   {
      deleteCurrent(current, item);
      return true;
   }
   if (target < *current->data)
   {
      return removeHelper(current->left, target, item);
   }

   // target >= *current->data
   return removeHelper(current->right, target, item);
}

void BinTree::deleteCurrent(Node *&current, Item *&item)
{
   // current has no children
   if (current->left == nullptr && current->right == nullptr)
   {
      item = current->data;
      delete current;
      current = nullptr;
   }

   // current has only right child
   else if (current->left == nullptr)
   {
      Node *temp = current;
      current = current->right;
      item = temp->data;
      delete temp;
   }

   // current has only left child
   else if (current->right == nullptr)
   {
      Node *temp = current;
      current = current->left;
      item = temp->data;
      delete temp;
   }

   // current has two children
   else
   {
      // find node with smallest value in right subtree
      Node *successor = current->right;
      while (successor->left != nullptr)
      {
         successor = successor->left;
      }

      // replace current node's value with successor's value
      item = current->data;
      current->data = successor->data;

      // remove successor node
      Node *parent = current;
      Node *temp = successor->right;
      if (temp != nullptr)
      {
         if (successor == parent->right)
         {
            parent->right = temp;
         }
         else
         {
            parent->left = temp;
         }
      }
      else
      {
         if (successor == parent->right)
         {
            parent->right = nullptr;
         }
         else
         {
            parent->left = nullptr;
         }
      }
      delete successor;
   }
}

//---------------------------------------------------------------------------//
// findAndDeleteJustBigger
// Pre-condition: current is not nullptr
Item *BinTree::findAndDeleteJustBigger(Node *&current)
{
   if (current->left == nullptr)
   {
      Item *item = current->data;
      Node *junk = current;
      current = current->right;
      delete junk;
      return item;
   }
   return findAndDeleteJustBigger(current->left);
}