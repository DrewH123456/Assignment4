// A Book is a parent class whose children are books the library lends
// Drew Higginbotham

#ifndef BOOK_H
#define BOOK_H
#include "item.h"
using namespace std;

/*
 * Book: The Book class is an abstract class whose children include checkout, 
 * return, display, and history. Its parent class is Item, and all of the
 * functions passed down from Item remain pure virtual within Book class
 *
 * Implementation and Assumptions:
 *   --All functions must be implemented by children
 *   --Contains a virtual destructor
 *   --Inherits functions and data members from Item class
 */

class Book : public Item
{

public:
    Book(){};

    // Destructor
    virtual ~Book(){};
};

#endif
