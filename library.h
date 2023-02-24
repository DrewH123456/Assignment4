/*
 * This is a library class that manages users and books and keeps track
 * their relationship to one another. It performs actions based on what it
 * reads from the text file it receives in readActions() to assign books
 * and users to one another
 */

#ifndef LIBRARY_H
#define LIBRARY_H

#include "actionfactory.h"
#include "usercontainer.h"
#include "bookfactory.h"
#include "bookcontainer.h"
#include "patron.h"
#include "book.h"

class Library
{
private:
    // Factories
    ActionFactory *af;
    BookFactory *bf;

    // Containers
    UserContainer *uc;
    BookContainer *bc;

public:
    // Constructor
    Library();

    // Destructor
    ~Library();

    // processes text files
    void readUsers();
    void readBooks();
    void readActions();

    // retrieves patron based on id
    Patron *retrievePatron(int id) const;

    // retrieves book based on title and author
    Book *retrieveBook(string title, string author) const;
};
#endif