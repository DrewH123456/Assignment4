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
    l->readItems();
    // l->displayBooks();

    return 0;
}