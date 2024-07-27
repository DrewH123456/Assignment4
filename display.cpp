// A Display prints out all of the items in the library in sorted order
// Drew Higginbotham 

#include "display.h"
#include "itemfactory.h"

//----------------------------------------------------------------------------
// create
// allows actionFactory to create Action pointer to Display object
Action *Display::create() const
{
    return new Display();
}

//----------------------------------------------------------------------------
// setData
// returns true, allowing execute to be called in library's readActions
bool Display::setData(ifstream &inputFile, ItemFactory *itemFac)
{
    return true;
}

//----------------------------------------------------------------------------
// execute
// calls on library->displayItems, displaying each category of itemContainer
// where each category's items are displayed in sorted order
bool Display::execute(Library *library)
{
    library->displayItems();
    return false;
}

//----------------------------------------------------------------------------
// displayCommandType
// displays the type of action it is, "Display"
void Display::displayCommandType() const
{
    cout << "Display  ";
}
