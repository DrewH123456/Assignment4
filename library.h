/*
 * This is a library class that manages users and books and keeps track
 * their relationship to one another. It performs actions based on what it
 * reads from the text file it receives in readActions() to assign books
 * and users to one another
 */

#ifndef LIBRARY_H
#define LIBRARY_H

class ItemFactory;
class ActionFactory;
class UserContainer;
class ItemContainer;
class Patron;
class Book;

class Library
{
private:
    // Factories
    ActionFactory *actionFac;
    ItemFactory *itemFac;

    // Containers
    UserContainer *userContain;
    ItemContainer *ItemContain;

public:
    // Constructor
    Library();

    // Destructor
    ~Library();

    // processes text files
    void readUsers();
    void readItems();
    void readActions();

    // retrieves patron based on id
    Patron *retrievePatron(int id) const;

    // retrieves book based on title and author
    Book *retrieveBook(string title, string author) const;
};
#endif