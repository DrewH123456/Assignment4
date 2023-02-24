/** The Patron class represents a library patron. Each patron has a unique
 * identifier, a name, and a list of books they have checked out. The Patron
 * can check out a book, return a book, and view their checkout history.
 **/
#ifndef PATRON_H
#define PATRON_H
#include <string>
#include <vector>
#include "book.h"
using namespace std;
class Patron
{
private:
    int idNumber;
    string lastName;
    string firstName;
    vector<Book *> books;
    vector<Book *> history;

public:
    // Default constructor
    Patron();

    // Constructor
    // Creates the object setting corresponding data member
    Patron(const string &id, const string &lastName, const string &firstName);

    // Destructor
    ~Patron();

    // Returns the unique identifier for the patron
    string getId() const;

    // Returns the last name of the patron
    string getLastName() const;

    // Returns the first name of the patron
    string getFirstName() const;

    // Adds a book to the list of books checked out by the patron
    void checkOutBook(Book *book);

    // Removes a book from the list of books checked out by the patron
    void returnBook(Book *book);

    // Displays the checkout history for the patron
    void viewHistory() const;
};

#endif