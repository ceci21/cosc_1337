// Author: Cecilia Goss     Course: COSC 1337 Spring 2015 DL  Instructor: Thayer
// Assignment: Lab 06
// This program calculates the distance between characters, numbers, and points.

#include <iostream> // cout, cin
#include <cmath>	// abs, pow, sqrt
#include <string>	// Include string class.

using namespace std; // Use standard library functions. 

// input() for letters
// Gets character from user, checks if it's an alphabetic character and returns
// the character if it is.
char input(string prompt, string error_message) {
	static int whichLetter = 1;
	while (true) {
		char letter;
		cout << prompt << whichLetter << ": ";
		cin >> letter;
		if (isalpha(letter)) { 
			letter = tolower(letter);
			whichLetter++;
			if (whichLetter == 3) whichLetter = 1;
			return letter;
		} else {
			cout << error_message;
		}
	}
}

// input() for numbers
// Gets number from user, checks if it's in range and returns the number if it is.
float input(const float min, const float max, string prompt, string error_message)
{
	while (true) {
		float number; 
		cout << prompt;
		cin >> number;
		if (number > min && number < max) {
			return number; // Returns number.
		} 
		else {
			cout << error_message;
		}
	}
}

// input() for points
// Input function for points that references x & y.
void input(double &x, double &y, string prompt) {
	static int whichPoint = 1;
	cout << prompt << "x value for point " << whichPoint << ": ";
	cin >> x;
	cout << prompt << "y value for point " << whichPoint << ": ";
	cin >> y;
	whichPoint++;
	if(whichPoint == 3) {
		whichPoint = 1;
	}
}

// dist() for letters
// Finds the distance between two letters.
int dist(char a='\0', char b='\0')
{
	int distance = b - a;
	return abs(distance);
}

// dist() for numbers
// Finds the distance between two numbers.
float dist(float a=0, float b=0)
{
	float distance = b - a;
	return abs(distance);
}

// dist() for points
// Finds the distance between two points using the Pythagorean theorem.
double dist(double x1=0, double y1=0, double x2=0, double y2=0)
{
	double distance = sqrt(pow((y2-y1), 2) + pow((x2-x1), 2));
	return distance;
}

// display() for characters
// Displays the results on screen for distance between two characters.
void display(string msg="null", char ch1='\0', char ch2='\0', int d=0) {
	cout << msg << ch1 << " & " << ch2 << " is " << d << ".\n";
}
// display() for numbers
// Displays the results on screen for the distance between two numbers.
void display(string msg="null", float f1=0, float f2=0, float d=0) {
	cout << msg << f1 << " & " << f2 << " is " << d << ".\n";
}

// display() for points
// Displays the results on screen for the distance between two points.
void display(string msg="null", double x1=0, double y1=0, double x2=0, double y2=0, double d=0) {
	cout << msg << "(" << x1 << ", " << y1 << ") & (" << x2 << ", " << y2 << ") is " << d << ".\n"; 
}

int main() // Main function, returns 0.
{
	cout << "Welcome! This is a distance calculator. " << endl; // Make the user feel welcomed.
	cout << "Please choose from the following:";
	while (true) {
		
		// Standard menu for user.
		char userInput;
		cout << endl << "Options: 'l' for letter, 'n' for number, 'p' for point, and 'q' for quit." << endl;
		cin >> userInput;
		
		if (userInput == 'l') { // Find distance between letters.
			string prompt = "Give me letter ";
			string error_message = "That is not a letter! Try again.\n";
			char a = input(prompt, error_message);
			char b = input(prompt, error_message);
			int distance = dist(a, b);
			string msg = "The distance between characters ";
			display(msg, a, b, distance);
			
		} else if (userInput == 'n') { // Find distance between numbers.
			const float min = -32;
			const float max = 8192;
			string prompt = "Give me a number between -32 and 8192: ";
			string error_message = "That is not within the proper range. Try again.\n";
			float j = input(min, max, prompt, error_message);
			float k = input(min, max, prompt, error_message);
			float distance = dist(j, k);
			string msg = "Results:\nThe distance between numbers ";
			display(msg, j, k, distance);
			
		} else if (userInput == 'p') { // Find distance between two points.
			string prompt = "Please enter ";
			double x1, x2, y1, y2;
			input(x1, y1, prompt);
			input(x2, y2, prompt);
			double distance = dist(x1, y1, x2, y2);
			string msg = "The distance between points ";
			display(msg, x1, y1, x2, y2, distance);
			
		} else if (userInput == 'q') { // Quit program.
			cout << "This program has been terminated. ";
			break;
			
		} else { // Display error message & try again.
			cout << "That is not valid input!\n";
			continue;
		}
		
	}
	
	return 0;
}

/*

 Welcome! This is a distance calculator. 
 Please choose from the following:
 Options: 'l' for letter, 'n' for number, 'p' for point, and 'q' for quit.
 l
 Give me letter 1: e
 Give me letter 2: p
 The distance between characters e & p is 11.
 
 Options: 'l' for letter, 'n' for number, 'p' for point, and 'q' for quit.
 l
 Give me letter 1: t
 Give me letter 2: y
 The distance between characters t & y is 5.
 
 Options: 'l' for letter, 'n' for number, 'p' for point, and 'q' for quit.
 l
 Give me letter 1: T
 Give me letter 2: V
 The distance between characters t & v is 2.
 
 Options: 'l' for letter, 'n' for number, 'p' for point, and 'q' for quit.
 p
 Please enter x value for point 1: 6
 Please enter y value for point 1: 9
 Please enter x value for point 2: 3
 Please enter y value for point 2: 0
 The distance between points (6, 9) & (3, 0) is 9.48683.
 
 Options: 'l' for letter, 'n' for number, 'p' for point, and 'q' for quit.
 n
 Give me a number between -32 and 8192: 29
 Give me a number between -32 and 8192: -34
 That is not within the proper range. Try again.
 Give me a number between -32 and 8192: 39
 Results:
 The distance between numbers 29 & 39 is 10.
 
 Options: 'l' for letter, 'n' for number, 'p' for point, and 'q' for quit.
 l
 Give me letter 1: 5
 That is not a letter! Try again.
 Give me letter 1: R
 Give me letter 2: H
 The distance between characters r & h is 10.
 
 Options: 'l' for letter, 'n' for number, 'p' for point, and 'q' for quit.
 g
 That is not valid input!
 
 Options: 'l' for letter, 'n' for number, 'p' for point, and 'q' for quit.
 q
 This program has been terminated. 
*/