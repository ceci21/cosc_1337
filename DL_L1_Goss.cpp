// Author: Cecilia Goss     Course: COSC 1337 Spring 2015 DL  Instructor: Thayer
// Assignment: Lab 01
// This program gives the user the option to choose between running a BMI calculator and a restaurant bill calculator.

#include <iostream> // Provides cout, cin, and endl.
#include <iomanip> // Needed for setprecision()
#include <cctype> // Needed for tolower()

using namespace std; // Include standard library items.

int main () // Main function.
{	// This code calculates a restaurant bill given the cost of food and the tip percentage.
	
	char option; // char - User's menu option represented by a single character.
	cout << fixed << setprecision(2); // Set a fixed precision of 2 decimal places for numeric values.

	cout << "\n";
	cout << "helloworld";
	cout << endl;
	cout << "bluegreen" << endl;
	while (true) { // Display the user's options.
		
		cout << "Options: a.) Amount of Restaurant Bill; b.) BMI Calculator; q.) Quit" << endl;
		cout << "Type a single character letter for your letter option: ";
		cin >> option; // Get the user's menu option.
		option = tolower(option); /* Take character entered by user and treat it as a lowercase letter so that
								   capital letters may be entered as well as lowercase letters. */

		if (option =='a') { // If option = 'a', compute and display the amount of the restaurant bill.
			double foodCost; // double - Cost of food WITHOUT tax and tip.
			double tip; // double - Percent of bill server was tipped
			double foodBill; // double - Cost of food WITH tax and tip.
			const double tax_rate = 0.0825; // Define a constant tax_rate and assign it the value 0.0825 (8.25%)
			cout << "\nWhat is the cost of the food? $";
			cin >> foodCost; // Get the cost of the food.
			cout << "What is the tip percentage? ";
			cin >> tip; // Get the percentage of the bill that the server was tipped.
			foodBill = foodCost*tax_rate + (tip / 100) * foodCost + foodCost; // Calculate the total cost of the food bill.
			cout << "The total food bill is: $" << foodBill << ".\n"; // Display the total cost of the food bill on the console.
		}
		
		else if (option =='b') { // If option = 'b', compute and display BMI.
			int height; // int - User's total height in inches.
			int weight; // int - User's weight in pounds.
			int feet; // int - User's height in feet.
			int inches; // int - User's remaining height in inches.
			double bmi; // Define variable 'bmi' of type double.
			
			cout << "\nPlease indicate your height in feet and inches, separated by a space: "; 
			cin >> feet; // Get user's height in feet.
			cin >> inches; // Get user's remaining height in inches.
			height = feet*12 + inches; // Convert feet and inches into inches.
			cout << "What is your weight in pounds? ";
			cin >> weight; // Get the weight of the user in pounds.
			bmi = ((double)weight/(height*height))*703; // Calculate the BMI.
			cout << "Your BMI is: " << bmi << "." << endl; // Display the user's BMI on the console.
		}
			
		else if (option == 'q') { // If option = 'q', quit the program.
			cout << "\nThis program has been terminated.\n";
			break; // Exit loop
		}
		else { // For all other options entered by the user, display error message.
			cout << "\nThat is not a valid option!\n";
			continue; // Continue from the top of the loop.
		}
	}
	return 0; // Return null.
}

/*
 Options: a.) Amount of Restaurant Bill; b.) BMI Calculator; q.) Quit
 Type a single character letter for your letter option: A
 
 What is the cost of the food? $6.00
 What is the tip percentage? 20
 The total food bill is: $7.70.
 
 Options: a.) Amount of Restaurant Bill; b.) BMI Calculator; q.) Quit
 Type a single character letter for your letter option: b
 
 Please indicate your height in feet and inches, separated by a space: 5 5
 What is your weight in pounds? 125
 Your BMI is: 20.80.
 
 Options: a.) Amount of Restaurant Bill; b.) BMI Calculator; q.) Quit
 Type a single character letter for your letter option: W
 
 That is not a valid option!
 
 Options: a.) Amount of Restaurant Bill; b.) BMI Calculator; q.) Quit
 Type a single character letter for your letter option: q
 This program has been terminated.
 */
