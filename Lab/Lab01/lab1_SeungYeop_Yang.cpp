/********1*********2*********3*********4*********5*********6*********7*********8
 *
 * Seung Yeop Yang
 * COSC 2436 Programming Fundamentals III
 *
 * Lab 1: "Arrays and Recursion"
 *
 * Use a Bag Object of Integers
 * 	Your client program will use integers as the data type for the items in
 a
 * 	Bag.
 * 	Load each of two Bags with 10 random integers ranging from 1 to 10 when
 * 	your program begins. You will allow duplicates in the Bags.
 *
 * User Interface
 * 	You will give the user the option to play the Most Dups game, display
 the
 * 	product of the integers in each bag, load the Bags with new values, and
 * 	quit. Allow the user to keep doingthese things until they choose to
 quit.
 *
 *



 *
 ********1*********2*********3*********4*********5*********6*********7*********/
#include "ArrayBag.h"
#include <iostream>
#include <limits>
#include <string>

using namespace std;

const int QUIT_GAME = 4; // const int (4) to quit the game

int displayMenu(); // display main menu
void playMostDups();
void findProducts();
void loadNewValues();
void tests();
void sampleProgramFunction(ArrayBag<int>& bag);

int main()
{

    int choice; // the choice out of menu

    do {
        choice = displayMenu();
        switch (choice) {

        case 1:
            playMostDups();
            break;
        case 2:
            findProducts();
            break;
        case 3:
            loadNewValues();
            break;
        case QUIT_GAME:
            cout << "Thanks for playing the game. Bye!!!" << endl;
            break;
        case 5:
            tests(); // my own test suite
            cout << "---------------------------------------" << endl;
            break;
        default:
            cout << "Out of Range of the Choices; please try again." << endl;
            break;
        };

    } while (choice != QUIT_GAME);

    return 0;

} // end main

/****************************************************************/
// Function:   sampleProgramFunction
// Inputs:     the array bag
// Outputs:    none
// Purpose:    This function exercises some of the bag methods
/****************************************************************/
// This function should be deleted from your client program.
void sampleProgramFunction(ArrayBag<int>& bag)
{
    cout << "The bag is not empty; isEmpty: returns " << bag.isEmpty() << endl;

    cout << "The bag contains " << bag.getCurrentSize() << " items\n";

} // end bagTester

int displayMenu()
{
    int choice;
    cout << "---------------------------------------" << endl;
    cout << "Array and Recursion Game" << endl;
    cout << "\t" << "1. Play Most Dups" << endl;
    cout << "\t" << "2. Find Products" << endl;
    cout << "\t" << "3. Load New Values" << endl;
    cout << "\t" << "4. Quit" << endl;
    cout << "\t" << "5. Test if any" << endl;

    cout << "Enter a number (1-" << QUIT_GAME << "): ";
    // Keep asking until the user enters a valid number
    while (!(cin >> choice)) {
        cout << "Invalid input. Please enter an integer: ";
        cin.clear(); // Clear the error flags
        // Discard invalid input from the buffer up to the newline character
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    }
    cout << "---------------------------------------" << endl;

    return choice;
}
void playMostDups() {}
void findProducts() {}
void loadNewValues() {}
void tests() {}
