// Author: Cecilia Goss     Course: COSC 1337 Spring 2015 DL  Instructor: Thayer
// Assignment: Lab 02
// This program creates diamond shapes of any size out of spaces and asterisks.

#include <cmath> // Provides abs(double) function
#include <string> // Provides string functions
#include <iostream> // Provides cout, cin, and endl.

using namespace std; // Include standard library items.

int main () // Main function.
{
	cout << "Welcome to diamond draw! You may type '0' or a number less than 0 anytime to quit."; // Make the user feel welcomed.
	while (true) 
	{
		int numRows = 1; // Initialize an int variable with value of 1.
		
		// Get number of rows for diamond and put it in numRows.
		cout << "\nEnter the number of rows for the diamond. "; 
		cin >>  numRows;
		cout << "\n";
		
		if ( numRows <= 0) // If number of rows is less than or equal to 0, quit.
		{
			cout << "Thanks for playing! Program is now terminating.";
			break;
		}
		
		for (int row = 0; row <  numRows; ++row) // For loop that iterates through each row.
		{
			// Math functions that determine the number of asterisks and spaces per row.
			int numAsterisks = (int) ( 2.0 * ( ( ( -1.0 ) * abs( row - ( numRows - 1 ) / 2.0 ) ) + ( numRows / 2.0 ) ) );
			int numSpaces = ( numRows - numAsterisks ) / 2.0;
			
			// Final string concatenation.
			cout << string(numSpaces, ' ') + string(numAsterisks, '*') << endl;
		}
	}
	return 0; // Return null
}

/*
Welcome to diamond draw! You may type '0' or a number less than 0 anytime to quit.
Enter the number of rows for the diamond. 1

*

Enter the number of rows for the diamond. 5

  *
 ***
*****
 ***
  *

Enter the number of rows for the diamond. 6

  *
 ***
*****
*****
 ***
  *

Enter the number of rows for the diamond. 21

          *
         ***
        *****
       *******
      *********
     ***********
    *************
   ***************
  *****************
 *******************
*********************
 *******************
  *****************
   ***************
    *************
     ***********
      *********
       *******
        *****
         ***
          *

Enter the number of rows for the diamond. 0

Thanks for playing! Program is now terminating.
*/