#include <iostream>
#include <string>
#include "ArrayBag.h"

using namespace std;


void sampleProgramFunction(ArrayBag<int>& bag);

int main()
{
	// Array bag to hold integers
	ArrayBag<int> bag;

	// Array to hold initial values to put into the bag
	int initialValues[] = {1, 33, 6, 9, 2, 65, 4, 29, 5, 8, 39, 88, 7, 25, 51, 3, 99, 14, 11, 10};
	
	// Add the initial values to the bag
	cout << "Adding positive integers to the bag: " << endl;
	for (int i = 0; i < 20; i++)
	{
		bag.add(initialValues[i]);
	}  // end for
	
	// Call a funciton that exercises
	// some of the bag methods
	sampleProgramFunction(bag);
	
	// Invoking the new method
	// added as an example
	bag.doSomething();

   return 0;
   
}  // end main

/****************************************************************/
/* Function:   sampleProgramFunction
/* Inputs:     the array bag
/* Outputs:    none
/* Purpose:    This function exercises some of the bag methods
/****************************************************************/
// This function should be deleted from your client program.
void sampleProgramFunction(ArrayBag<int>& bag)
{
	cout << "The bag is not empty; isEmpty: returns " << bag.isEmpty() << endl;

	cout << "The bag contains " << bag.getCurrentSize() << " items\n";
	
}  // end bagTester



