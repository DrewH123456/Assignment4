#include "childrenbook.h"
#include "fiction.h"
#include "periodical.h"
#include "library.h"
#include "itemfactory.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    Library *l = new Library();
    ifstream infile("data4books.txt");
    if (!infile)
    {
        cout << "File could not be opened." << endl;
        return 1;
    }

    // // Create Fiction book
    // Fiction *f = new Fiction();
    // f->setData(infile);
    // f->print(cout);
    // cout << endl;

    // Create ChildrenBook
    // ChildrenBook *c = new ChildrenBook();
    // c->setData(infile);
    // c->print(cout);
    // cout << endl;

    // // Create Periodical
    // Periodical *p = new Periodical();
    // p->setData(infile);
    // // p->print(cout);
    // cout << endl;
    infile.close();
    return 0;
}