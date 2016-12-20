// Author: Cecilia Goss     Course: COSC 1337 Spring 2015 DL  Instructor: Thayer
// Assignment: Lab 07
// This program creates an inventory that holds information about items.

#include <iostream>
#include <iomanip> // setprecision(int)
#include <string> // String functions
#include <sstream> // oss string

using namespace std;

int getInt();
double getDouble();

class Inventory 
{
	private: // Private member functions
		int itemNumber;
		int quantity;
		double cost;
		string output;

	public: // Public member functions
		Inventory(); // Default constructor.
		Inventory(int, int, double); // Secondary constructor.
	
		void setItemNumber(int);
		void setQuantity(int);
		void setCost(double);
		void setOutput();
		int getItemNumber();
		int getQuantity();
		double getCost();
		double getTotalCost();
		string getOutput();
	
};

Inventory::Inventory() // Default constructor.
{ 
	itemNumber = 0;
	quantity = 0;
	cost = 0;
	
}

Inventory::Inventory(int itemNumber, int quantity, double cost) // Secondary constructor.
{
	this->itemNumber = itemNumber;
	this->quantity = quantity;
	this->cost = cost;
}

void Inventory::setItemNumber(int itemNumber) {
	this->itemNumber = itemNumber;
}

void Inventory::setQuantity(int quantity) {
	this->quantity = quantity;
}

void Inventory::setCost(double cost) {
	this->cost = cost;
}

void Inventory::setOutput() {
	ostringstream oss;
	
	// Uses ostream to create string.
	oss << "\nItem ID: " << itemNumber << endl;
	oss << "Quantity of item in stock: " << quantity << endl;
	oss << setprecision(2) << fixed; // Fix the decimal point to 2 decimals.
	oss << "Unit cost: $" << cost << endl;
	oss << "Total cost: $" << getTotalCost() << endl;
	output = oss.str();
}

int Inventory::getItemNumber() {
	return itemNumber;
}

int Inventory::getQuantity() {
	return quantity;
}

double Inventory::getCost() {
	return cost;
}

double Inventory::getTotalCost() {
	return (double)quantity * cost;
}

string Inventory::getOutput() {
	return output;
}


int main() 
{
	int quantityItems;
	double grandTotal = 0;
	
	cout << "How many items are in inventory? Enter between 1 and 5. ";
	cin >> quantityItems;
	
	while (quantityItems > 5 || quantityItems < 1) {
		cout << "Enter within a range of 1 to 5. ";
		cin >> quantityItems;
	}
	
	Inventory *userInventory [quantityItems]; // Creates array containing inventory.
	
	for (int i = 0; i < quantityItems; i++)
	{
		int itemNumber;
		int quantity;
		double cost;
		
		// Create inventory array.
		userInventory[i] = new Inventory();
		
		// Get input from the user.
		cout << "\nEnter item ID: ";
		itemNumber = getInt();
		
		cout << "Enter quantity of item: ";
		quantity = getInt();
		
		cout << "Enter unit cost: $";
		cost = getDouble();
		
		// Set appropriate member variables within the inventory.
		userInventory[i]->setItemNumber(itemNumber);
		userInventory[i]->setQuantity(quantity);
		userInventory[i]->setCost(cost);
		userInventory[i]->setOutput();
		
		// Add to grand total.
		grandTotal += userInventory[i]->getTotalCost();
		
	}
	
	// Display info for each entry in inventory.
	cout << "User's Inventory: " << endl;
	for (int n = 0; n < quantityItems; n++ )
	{
		cout << userInventory[n]->getOutput();
	}
	
	// Display the total cost of everything in the inventory.
	cout << "\nThe total cost of the inventory is: $" << setprecision(2) << fixed << grandTotal;
		
	// Delete array entries.
	for (int n = 0; n < quantityItems; n++ )
	{
		delete userInventory[n];
	}
}

int getInt() // Function for getting int that is nonnegative.
{
	int number;
	cin >> number;
	while (number <= 0) {
		cout << "Please enter a nonnegative number. " << endl;
		cin >> number;
	}
	return number;
}

double getDouble() // Function for getting double that is nonnegative.
{
	double number;
	cin >> number;
	while (number <= 0) {
		cout << "Please enter a nonnegative number. " << endl;
		cin >> number;
	}
	return number;
}

/*
 
 How many items are in inventory? Enter between 1 and 5. 4
 
 Enter item ID: 1
 Enter quantity of item: 5
 Enter unit cost: $2.50
 
 Enter item ID: 2
 Enter quantity of item: 4
 Enter unit cost: $7.00
 
 Enter item ID: 3
 Enter quantity of item: 9
 Enter unit cost: $1.00
 
 Enter item ID: 4
 Enter quantity of item: 2
 Enter unit cost: $6.99
 Inventory list: 
 
 Item ID: 1
 Quantity of item in stock: 5
 Unit cost: $2.50
 Total cost: $12.50
 
 Item ID: 2
 Quantity of item in stock: 4
 Unit cost: $7.00
 Total cost: $28.00
 
 Item ID: 3
 Quantity of item in stock: 9
 Unit cost: $1.00
 Total cost: $9.00
 
 Item ID: 4
 Quantity of item in stock: 2
 Unit cost: $6.99
 Total cost: $13.98
 
 The total cost of the inventory is: $63.48
 
 */

