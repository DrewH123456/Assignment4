/*
 * This is a factory for class Book
 * The factory will produce different children objects of Book for the library
 * to create
 */

#ifndef BOOKFACTORY_H
#define BOOKFACTORY_H

#include "book.h"
#include "childrenbook.h"
#include "fiction.h"
#include "periodical.h"

class BookFactory
{
private:
    Book *objFactory[10];    // contains array of each object
    int hash(char ch) const; // hash function

public:
    // Factory constructor, initializes objFactory
    BookFactory();

    // Factory destructor, deletes objFactory
    ~BookFactory();

    // Creates a corresponding action based on the information provided
    Book *createIt(char c) const;
};

#endif