/*
 * This is a child class of action, overriding the execute function to display
 * the contents
 */

#include "display.h"
#include "itemfactory.h"

Action *Display::create() const
{
    return new Display();
}

bool Display::setData(ifstream &inputFile, ItemFactory *itemFac)
{
    return true;
}

bool Display::execute(Library *library)
{
    library->displayItems();
    return false;
}

void Display::display() const
{
    cout << "Display  ";
}