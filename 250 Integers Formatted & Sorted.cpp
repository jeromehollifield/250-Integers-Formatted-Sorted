// Write a program that will randomly populate an array of
// 250 integers and print them out in a formatted way to 
// the console. Once printed, call a quicksort algorithm 
// to sort the array and print it out again, this time in order.
// Include the worst case running time in your output.



// Jerome Hollifield

#include <iostream>
#include <cstdlib>       // Header file needed to use srand and rand
#include <iomanip>
using namespace std;

// Driver the users number for the area
void getNumber();

// Function prototypes
void quickSort(int[], int, int);
int partition(int[], int, int);

/****************************************************************
*                        class Menu                             *
* This class displays the user's menu on the screen.            *
****************************************************************/
class Menu
{
public:
	void displayMenu();
};

void Menu::displayMenu()
{

	cout << "\n\n             MENU\n\n";
	cout << "The program displays the following menu:\n";
	cout << "1) Run program\n";
	cout << "2) Exit the program\n\n";
	cout << "Enter your choice: ";
}

/*****************************************************************
*                            class Choice                        *
* This class gets, validates, and returns the user's choice.     *
*****************************************************************/
class Choice
{
public:
	char getChoice();
};

char Choice::getChoice()
{


	char number;
	cin >> number;

	while (number != '1' && number != '2')
	{
		cout << "Enter 1 or 2: ";
		cin >> number;
	}
	return number;

}


/***********************************************************
*                            class Body                    *
This class gets the choice and provides the display.       *
********************************************************** */
class Body
{
public:
	int program();
};

int Body::program()
{
	Menu Test;          // Menu object
	Choice Pick;		// Choice object
	cout << "\n\n      Week 9: Assignment - Quicksort, Merge Sort\n\n"
		<< "      Write a recursive algorithm to output the\n"
		<< "      hexadecimal representation of an integer.\n";

	char selection;
	do
	{
		Test.displayMenu();				// This displays the menu
		selection = Pick.getChoice();  // This returns only '1' - '2'
		cin.ignore();					// Clears screen

		switch (selection)
		{
		case '1':getNumber(); break;
		}
	} while (selection != '2');
	cout << "\nGoodbye\n";

	return 0;
}

int main()
{
	Body Run;
	Run.program();
}

/*****************************************************************
*                            getNumber                           *
* Driver function gets and returns the results of the converter  *
*****************************************************************/
void getNumber()
{
	// Random generator seed
	// Use the time function to get a "seed" value for srand
	srand((unsigned)time(NULL));


	const int SIZE = 250;
	int GetRandomArray[SIZE];

	// Get the random numbers
	for (int i = 0; i < SIZE; i++)
	{
		GetRandomArray[i] = rand();
	}

	// Format the output
	cout << showpoint << fixed << setprecision(2);

	// Display the random numbers in the array
	cout << "\nTHE RANDOM NUMBERS ARE:\n";
	for (int i = 0; i < SIZE; i++)
	{
		cout << setw(10) << GetRandomArray[i];
	}
	cout << endl;

	// Sort the array using Quicksort
	quickSort(GetRandomArray, 0, SIZE - 1);

	// Print the sorted array
	cout << "\nTHE RANDOM NUMBERS SORTED ARE:\n";
	for (int k = 0; k < SIZE; k++)
		cout << setw(10) << GetRandomArray[k];
	cout << endl;
}



//************************************************
// quickSort uses the QuickSort algorithm to     *
// sort arr from arr[start] through arr[end].    *
//************************************************
void quickSort(int arr[], int start, int end)
{
	if (start < end)
	{
		// Partition the array and get the pivot point
		int p = partition(arr, start, end);

		// Sort the portion before the pivot point
		quickSort(arr, start, p - 1);

		// Sort the portion after the pivot point
		quickSort(arr, p + 1, end);
	}
}

//***********************************************************
// partition rearranges the entries in the array arr from   *
// start to end so all values greater than or equal to the  *
// pivot are on the right of the pivot and all values less  *
// than are on the left of the pivot.                       *
//***********************************************************
int partition(int arr[], int start, int end)
{
	// The pivot element is taken to be the element at
	// the start of the subrange to be partitioned
	int pivotValue = arr[start];
	int pivotPosition = start;

	// Rearrange the rest of the array elements to 
	// partition the subrange from start to end
	for (int pos = start + 1; pos <= end; pos++)
	{
		if (arr[pos] < pivotValue)
		{
			// arr[scan] is the "current" item.
			// Swap the current item with the item to the
			// right of the pivot element
			swap(arr[pivotPosition + 1], arr[pos]);
			// Swap the current item with the pivot element
			swap(arr[pivotPosition], arr[pivotPosition + 1]);
			// Adjust the pivot position so it stays with the
			// pivot element
			pivotPosition++;
		}
	}
	return pivotPosition;
}



