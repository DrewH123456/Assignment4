/**
 * The Book class represents a collection of a given book in the library system.
 * It contains information about the book's author, title,
 * year of publication, and the number of checked out/available books
 * The Book class serves as the parent class for more specific
 * book types, such as ChildrenBook, FictionBook, and Periodical.
 */

#ifndef BOOK_H
#define BOOK_H

#include "item.h"
using namespace std;

class Book : public Item
{

public:
    Book(){};

    // Destructor
    virtual ~Book(){};
};

#endif