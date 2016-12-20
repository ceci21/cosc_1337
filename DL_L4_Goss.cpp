// Author: Cecilia Goss     Course: COSC 1337 Spring 2015 DL  Instructor: Thayer
// Assignment: Lab 01
// This program gives the user the option to choose between running a BMI calculator and a restaurant bill calculator.

#include <iostream> // Provides cout, cin, and endl.
#include <iomanip> // Needed for setprecision()
#include <cctype> // Needed for tolower()
#include <string> // String functions included

using namespace std; // Include standard library items.

int main () // Main function.
{
	const int air = 1100;
	const int water = 4900;
	const int steel = 16400;
	string input;
	float someTime;
	string speedName;
	int speed;
	bool firstTime = true;
	
	cout << "Menu (Please choose): \n" 
		<<	"a.)ir \n" 
		<<	"w.)ater \n" 
		<<	"s.)teel \n" 
		<<	"q.)uit\n"
		<<	"Feel free to change your medium any time.\n";
	
	cin >> input;
	
	if (input[0] == 'a') {
		speed = air;
		speedName = "air";
		
	}
	else if (input[0] == 'w') {
		speed = water;
		speedName = "water";
	}
	else if (input[0] == 's') {
		speed = steel;
		speedName = "steel";
	}
	else if (input[0] == 'q') {
		return 0;
	}

	enum material {air='a', water='w', steel='s', quit='q'};
	material input;
	
	cout << "Please enter something.";
	cin >> input;
	
	
	
	while (true) {
		
		
		cout << "\nPlease enter a distance, in feet: \n";
		cin >> input;
		
		switch (input) {
			case 'A':
			case 'a': speed = air;
			case 'W':
			case 'w': speed = water;
			case 'S':
			case 's': speed = steel;
			case 'Q':
			case 'q': return 0;
		}
		
	
		
		if ( input[0] <= 57 && input[0] >= 48 ) {
			double distance;
			distance = strtod(input.c_str(), NULL);
			float time = distance / speed;
			cout << "It takes sound " << time << " seconds to travel " << distance << " feet in " << speedName << ".";
		}
		
		
		
		
		
		
		
		/*
		if (input[0] == 'a') {
			speed = air;
		}
		else if (input[0] == 'w') {
			speed = water;
		}
		else if (input[0] == 's') {
			speed = steel;
		}
		else if (input[0] == 'q') {
			break;
		}
		
		else if (input[0] <= 57 && input[0] >= 48) {
			double distance;
			distance = strtod(input.c_str(), NULL);
			float time = distance / speed;
			cout << "It takes sound " << time << " seconds to travel " << distance << " feet in " << speedName << ".";
		}
		*/
		
		else {
			cout << "This is input I cannot recognize.\n";
		}
		
		/*
		cout << "\nDistance in feet: ";
		
		cin >> input;
		
		if ( input < 0 ) {
			cout << "That is not a valid input! TRY AGAIN.";
			continue;
		}
		
		someTime = distance / speed;
		
		cout << someTime;
		*/
		
	}
	
	return 0; // Return null.
}

