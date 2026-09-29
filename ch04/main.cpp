#include <iostream>

using namespace std;

class Node {
private:
    int item;
    Node* next;

public:
    Node();
    void setItem(int);
    void setNext(Node*);
    int getItem();
    Node* getNext();
};

Node::Node() { next = nullptr; }
void Node::setItem(int i) { item = i; }
void Node::setNext(Node* n) { next = n; }
int Node::getItem() { return item; }
Node* Node::getNext() { return next; }

const int QUIT = 4;

int getMenuOption();
void addValue(Node*& values);
void displayList(Node* values);
void removeValue(Node*& values);
int main()
{
    int menuOption;
    Node* integers = nullptr;

    menuOption = getMenuOption();

    while (menuOption != QUIT) {
        switch (menuOption) {
        case 1:
            addValue(integers);
            cout << "address of first node is " << integers << endl;
            // cout << "in main, first node has valu " << integers->getItem();
            break;
        case 2:
            displayList(integers);
            break;
        case 3:
            removeValue(integers);
            break;
        default:
            break;
        }

        menuOption = getMenuOption();
    }

    return 0;
}

void displayList(Node* values)
{
    Node* curPtr = values;

    cout << "\nList contains:\n";

    while (curPtr) {
        cout << curPtr->getItem() << " ";
        curPtr = curPtr->getNext();
    }
    cout << endl << endl;
}

void addValue(Node*& values)
{
    int num;
    Node* newNodePtr = nullptr;
    // Get value from user

    cout << "\nEnter an integer: ";
    cin >> num;

    newNodePtr = new Node();

    newNodePtr->setItem(num);
    newNodePtr->setNext(values);
    values = newNodePtr;

    cout << num << " has been added\n";
    // cout << "value in first node is " << values->getItem();
    // cout << "address of first node is " << values << endl;
}

void removeValue(Node*& values)
{
    int num;
    Node* curPtr = values;
    Node* prevPtr = nullptr;

    cout << "\nEnter an integer to remove: ";
    cin >> num;

    while (curPtr && curPtr->getItem() != num) {
        prevPtr = curPtr;
        curPtr = curPtr->getNext();
    }

    if (curPtr) {
        if (prevPtr)
            prevPtr->setNext(curPtr->getNext());
        else
            values = curPtr->getNext();

        delete curPtr;
    }
    else
        cout << num << " was not found in the list\n";
}

int getMenuOption()
{
    int option;

    cout << "\n    MENU\n";
    cout << "1. Add value\n"
         << "2. Display values\n"
         << "3. Remove value\n"
         << "4. Quit\n";
    cout << "Enter option: ";
    cin >> option;

    // TODO: add input validation

    return option;
}
