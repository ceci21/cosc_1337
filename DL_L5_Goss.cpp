// Author: Cecilia Goss     Course: COSC 1337 Spring 2015 DL  Instructor: Thayer
// Assignment: Lab 05
// This program reads population values from a file and creates a graph.

#include <iostream> // cout, cin
#include <fstream>	// fstream, used to open files
#include <iomanip>	// setw(int), 
#include <vector>	// vector

using namespace std; // Use standard library functions.

// Function: createGraph
// Description: Prints out standard bar graph to screen if given two vectors of the same size containing doubles and a 
//				double by which to increment the y-axis.
// Parameters: (vector<double>) listX, (vector<double>) listY, (double) deltaY
// Returns: (void) none 
void createGraph (vector<double> listX, vector<double> listY, double deltaY) 
{
	// The following block of code finds the largest y value
	// in listY to set the height of the y-axis.
	double maxY = listY[0];
	for (int i = 0; i < listY.size(); i++) {
		if (listY[i] > maxY) { maxY = listY[i]; }
	}
	
	double maxRows = maxY / deltaY;	// Divide the maximum y value by the change in y values to get the number of rows.
	
	for (int row = 0; row < maxRows; row++) {
		
		double yValue = maxY - row * deltaY;	// Current y value
		cout << setw(5) << yValue;				// Create padding for y values
		
		for (int column = 0; column < listX.size(); column++) { // For column data within each 'row'.
			
			cout << "  ";
			
			if (listY[column] >= yValue) { cout << " ** "; } // If data in listY is greater than current y value, create bar.
			else						 { cout << "    "; } // Else, do not create bar.
			
		}
		
		cout << endl; // Create new line.
		
	 }
	
	cout << string(7, ' ');  // Print 7 spaces.
	
	for (int column = 0; column < listX.size(); column++) { // Label each column at the bottom.
		cout << listX[column] << string(2, ' '); 
	}
}

// Function: main
// Description: Gets file "people.txt" and calls function 'createGraph()' to print out graph to screen based on data found in file.
// Parameters: None
// Returns: (int) 0
int main () 
{
	ifstream inFile;
	vector<double> years;		// Create vector 'years' to hold years.
	vector<double> population;	// Create vector 'population' to hold the population per 20 years.
	
	inFile.open("people.txt"); // Open file.
	if (inFile) {
		string entry; 
		double entryAsDouble;
		int lineCount = 0;
		
		while (!inFile.eof()) { 
			inFile >> entry; // Get data from line and store in 'entry'.
			entryAsDouble = strtod(entry.c_str(), NULL);	// Since 'entry' is a string, convert to double.
			population.push_back(entryAsDouble);			// Append 'entryAsDouble' into population vector.
			years.push_back(1900 + (20 * lineCount));		// Start 'years' at 1900 and increment by 20 for every line entry.
			lineCount++; 
		}
		inFile.close(); // Close file.
	}
	
	// Call function to create graph with 'years'
	// on the x-axis, 'population' on the y-axis,
	// and increment the y-axis by 1000.
	createGraph(years, population, 1000);
	
	cout << "\n\nPress enter to terminate the program . . .";
	cin.get(); // Pauses window
	
	return 0;
}

/*
 
 18000                                 **             
 17000                                 **             
 16000                                 **             
 15000                                 **             
 14000                           **    **             
 13000                           **    **             
 12000                           **    **    **       
 11000                           **    **    **       
 10000                           **    **    **       
  9000                     **    **    **    **       
  8000                     **    **    **    **       
  7000                     **    **    **    **       
  6000                     **    **    **    **    ** 
  5000               **    **    **    **    **    ** 
  4000         **    **    **    **    **    **    ** 
  3000         **    **    **    **    **    **    ** 
  2000   **    **    **    **    **    **    **    ** 
  1000   **    **    **    **    **    **    **    ** 
        1900  1920  1940  1960  1980  2000  2020  2040  

*/