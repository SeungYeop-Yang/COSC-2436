#ifndef PLAIN_BOX_
#define PLAIN_BOX_

// typedef double ItemType;
template <class ItemType>

class PlainBox {
private:
    ItemType item;

public:
    // Default constructor
    PlainBox();
    // Parameterized constructor
    PlainBox(const ItemType& theItem);

    // Method to change the value of the data field
    void setItem(const ItemType& theItem);
    // Method to get the value of the data field
    ItemType getItem() const;
};

#include "PlainBox.cpp"
#endif
