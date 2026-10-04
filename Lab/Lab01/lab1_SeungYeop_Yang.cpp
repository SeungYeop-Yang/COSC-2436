/********1*********2*********3*********4*********5*********6*********7*********8
 *
 * Seung Yeop Yang
 * COSC 2436 Programming Fundamentals III
 *
 * Lab 1: "Arrays and Recursion"
 *
 * User Interface
 * 	You will give the user the option to play the Most Dups game, display
 *  the product of the integers in each bag, load the Bags with new values,
 * 	and	quit. Allow the user to keep doing these things until they
 *  choose to quit.
 *
 * playMostDups()
 * 	When this option is chosen you will play a simple game that requires two
 * 	players. Ask each player for their name. Remember that their name may
 * 	contain spaces.
 *
 * 	This game will not need any new methods in the Bag ADT.
 * 	Your program will then examine each bag, finding the integer that
 * 	appears most often. The player that has the largest number of duplicated
 * 	value is the winner. Your program will display the contents of each Bag
 * 	using the "toVector" method, identifying who's bag it is by name.
 *
 * findProducts()
 * 	First display the contents of each Bag using the "toVector" method,
 * 	identifying the Bags as "Bag 1" and "Bag 2" or something similar.
 *
 * 	Adding to the array bag ADT, using the code from the text book, which is
 * 	attached to the assignment, you will add one new public method and one
 * 	new private recursive helper method.
 *
 * 	A private recursive method to calculate and return the product
 * 	of the integers in the bag, with a public method for the client code to
 * 	invoke.
 *
 * 	The client-facing method should not take any input. if you need
 * 	parameters to be able to achieve the recursion, you should have a
 * 	private helper method that the public method calls; you do not require
 * 	the client code to pass additional arguments your recursive method
 * 	requires.
 *
 *
 ********1*********2*********3*********4*********5*********6*********7*********/

#include "ArrayBag.h"
#include <iostream>
#include <limits>
#include <string>

using namespace std;

const int PLAY_MOST_DUPS = 1;
const int FIND_PRODUCTS = 2;
const int LOAD_NEW_VALUES = 3;
const int QUIT_GAME = 4; // const int (4) to quit the game
const int TESTS = 5;

int displayMenu(); // display main menu
void playMostDups(ArrayBag<int>&, ArrayBag<int>&);
void MostDups(ArrayBag<int>&, ArrayBag<int>&, string, string);
void findProducts(ArrayBag<int>&, ArrayBag<int>&);
void loadNewValues(ArrayBag<int>&, ArrayBag<int>&);
void tests(ArrayBag<int>&, ArrayBag<int>&);
void vector_print(vector<int>);
void sampleProgramFunction(ArrayBag<int>& bag);

/********1*********2*********3*********4*********5*********6*********7*********8
 *
 * main()
 * initializes the game by loading each of two Bags with 10 random integers
 * display menu and execute the options based on the user's choice until the
 * user chooses to quit.
 *
 ********1*********2*********3*********4*********5*********6*********7*********/

int main()
{

    // seed the random number generator for the game
    srand(static_cast<unsigned int>(time(nullptr)));

    // Load each of two Bags with 10 random integers ranging from 1 to 10
    // when your program begins. You will allow duplicates in the Bags.
    ArrayBag<int> bag_A, bag_B;

    for (int i = 0; i < 10; i++) {
        bag_A.add((rand() % 10) + 1);
        bag_B.add((rand() % 10) + 1);
    }

    int choice; // the choice out of menu

    do {
        choice = displayMenu();
        switch (choice) {

        case PLAY_MOST_DUPS:
            playMostDups(bag_A, bag_B);
            break;
        case FIND_PRODUCTS:
            findProducts(bag_A, bag_B);
            break;
        case LOAD_NEW_VALUES:
            loadNewValues(bag_A, bag_B);
            break;
        case QUIT_GAME:
            cout << "Thanks for playing the game. Bye!!!" << endl;
            break;
        case TESTS:
            tests(bag_A, bag_B); // my own test suite
            cout << "---------------------------------------" << endl;
            break;
        default:
            cout << "Out of Range of the Choices; please try again." << endl;
            break;
        };

    } while (choice != QUIT_GAME);

    return 0;

} // end main

/********1*********2*********3*********4*********5*********6*********7*********8
 *
 * displayMenu()
 * 	You will give the user the option to play the Most Dups game, display
 *  the product of the integers in each bag, load the Bags with new values,
 * 	and	quit.
 *
 ********1*********2*********3*********4*********5*********6*********7*********/
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

/********1*********2*********3*********4*********5*********6*********7*********8
 *
 * playMostDups()
 * 	When this option is chosen you will play a simple game that requires two
 * 	players. Ask each player for their name. Remember that their name may
 * 	contain spaces.
 *
 * 	This game will not need any new methods in the Bag ADT.
 * 	Your program will then examine each bag, finding the integer that
 * 	appears most often. The player that has the largest number of duplicated
 * 	value is the winner. Your program will display the contents of each Bag
 * 	using the "toVector" method, identifying who's bag it is by name.
 *
 ********1*********2*********3*********4*********5*********6*********7*********/
void playMostDups(ArrayBag<int>& bag_A, ArrayBag<int>& bag_B)
{
    string player_A, player_B;
    // int dup_A[11] = {0}, dup_B[11] = {0};
    // int temp_A, temp_B, mostDup_A, mostDup_B;

    cout << "You chose 'PLAY MOST DUPS' game." << endl << endl;
    cout << "Enter name of player 1: ";
    getline(cin >> ws, player_A);
    cout << "Enter name of player 2: ";
    getline(cin >> ws, player_B);
    cout << endl;

    cout << player_A << " has ";
    vector_print(bag_A.toVector());
    cout << endl;
    cout << player_B << " has ";
    vector_print(bag_B.toVector());
    cout << endl;
    cout << endl;

    MostDups(bag_A, bag_B, player_A, player_B);
}

/********1*********2*********3*********4*********5*********6*********7*********8
 *
 * MostDups()
 *
 * 	This game will not need any new methods in the Bag ADT.
 * 	Your program will then examine each bag, finding the integer that
 * 	appears most often. The player that has the largest number of duplicated
 * 	value is the winner. Your program will display the contents of each Bag
 * 	using the "toVector" method, identifying who's bag it is by name.
 *
 ********1*********2*********3*********4*********5*********6*********7*********/
void MostDups(ArrayBag<int>& bag_A, ArrayBag<int>& bag_B, string player_A,
              string player_B)
{
    int dup_A[11] = {0}, dup_B[11] = {0};
    int temp_A, temp_B, mostDup_A, mostDup_B;

    for (int i = 1; i < 11; i++) {
        dup_A[i] = bag_A.getFrequencyOf(i);
        // debug cout << "dupA[" << i << "]" << "= " << dup_A[i] << endl;
        dup_B[i] = bag_B.getFrequencyOf(i);
        // debug cout << "dupB[" << i << "]" << "= " << dup_B[i] << endl;
    }

    temp_A = temp_B = 0;
    for (int i = 1; i < 11; i++) {
        if (dup_A[i] >= temp_A) {
            temp_A = dup_A[i];
            dup_A[0] = i;
        }
        if (dup_B[i] >= temp_B) {
            temp_B = dup_B[i];
            dup_B[0] = i;
        }
    }
    mostDup_A = dup_A[dup_A[0]];
    mostDup_B = dup_B[dup_B[0]];

    cout << player_A << " got " << mostDup_A << " " << dup_A[0] << "'s" << endl;
    cout << player_B << " got " << mostDup_B << " " << dup_B[0] << "'s" << endl;
    cout << endl;

    if (mostDup_A > mostDup_B) {
        cout << player_A << " wins with " << mostDup_A << " " << dup_A[0]
             << "'s" << endl;
    }
    else if (mostDup_B > mostDup_A) {
        cout << player_B << " wins with " << mostDup_B << " " << dup_B[0]
             << "'s" << endl;
    }
    else {
        cout << player_A << " and " << player_B << " got a tie." << endl;
    }
}

void vector_print(vector<int> v)
{
    for (const auto& element : v) {
        cout << element << " ";
    }
}
/********1*********2*********3*********4*********5*********6*********7*********8
 *
 * findProducts()
 * 	First display the contents of each Bag using the "toVector" method,
 * 	identifying the Bags as "Bag 1" and "Bag 2" or something similar.
 *
 * 	Adding to the array bag ADT, using the code from the text book, which is
 * 	attached to the assignment, you will add one new public method and one
 * 	new private recursive helper method.
 *
 * 	A private recursive method to calculate and return the product
 * 	of the integers in the bag, with a public method for the client code to
 * 	invoke.
 *
 * 	The client-facing method should not take any input. if you need
 * 	parameters to be able to achieve the recursion, you should have a
 * 	private helper method that the public method calls; you do not require
 * 	the client code to pass additional arguments your recursive method
 * 	requires.
 *
 ********1*********2*********3*********4*********5*********6*********7*********/
void findProducts(ArrayBag<int>& bag_A, ArrayBag<int>& bag_B)
{
    cout << "bag_A contains: ";
    vector_print(bag_A.toVector());
    cout << endl << "The product bag_A is " << bag_A.getProduct() << endl;
    cout << "bag_B contains: ";
    vector_print(bag_B.toVector());
    cout << endl << "The product bag_B is " << bag_B.getProduct() << endl;
}
/********1*********2*********3*********4*********5*********6*********7*********8
 *
 * loadNewValues()
 *
 * When this option is chosen, your program will load each of the two Bags with
 * new values following the same rules:
 *   Load each of two Bags with 10 random integers ranging from 1 to 10,
 *   Duplicates are allowed.
 *
 ********1*********2*********3*********4*********5*********6*********7*********/
void loadNewValues(ArrayBag<int>& bag_A, ArrayBag<int>& bag_B)
{
    cout << "The old values of the bags: " << endl;
    cout << "bag_A contains: ";
    bag_A.println();
    cout << "bag_B contains: ";
    bag_B.println();

    bag_A.clear();
    bag_B.clear();

    cout << "    -----------------------------------" << endl;
    cout << "The bags are cleared: " << endl;

    for (int i = 0; i < 10; i++) {
        bag_A.add((rand() % 10) + 1);
        bag_B.add((rand() % 10) + 1);
    }

    cout << "    -----------------------------------" << endl;
    cout << "The new values of the bags: " << endl;
    cout << "bag_A contains: ";
    bag_A.println();
    cout << "bag_B contains: ";
    bag_B.println();
}
/********1*********2*********3*********4*********5*********6*********7*********8
 *
 * my own test suites
 *
 ********1*********2*********3*********4*********5*********6*********7*********/
void tests(ArrayBag<int>& bag_A, ArrayBag<int>& bag_B)
{
    cout << "bag_A contains: ";
    bag_A.println();
    cout << "bag_B contains: ";
    bag_B.println();
    cout << endl;

    cout << "The product of bag_A is " << bag_A.getProduct() << endl;
    cout << "The product of bag_B is " << bag_B.getProduct() << endl;

    MostDups(bag_A, bag_B, "Player A", "Player B");

    loadNewValues(bag_A, bag_B);
    cout << endl;
    cout << "The product of bag_A is " << bag_A.getProduct() << endl;
    cout << "The product of bag_B is " << bag_B.getProduct() << endl;

    MostDups(bag_A, bag_B, "Player A", "Player B");
}
