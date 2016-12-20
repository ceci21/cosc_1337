// Author:                      Cecilia Goss
// Assignment Number:           Lab 10
// File Name:                   DL_L10_Goss.cpp
// Course/Section:              COSC 1337 Section MW10
// Due Date:                    29 April 2015
// Instructor:                  Thayer

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int lab10() {
	// Regular variables
	float price; // = 19.95;
	int maxSize; // = 752;
	double PI; // = 3.141592;
	double PI_div_2; // = PI / 2;
	string NameFirst; // = "firstname";
	string NameLast; // = "lastname";

	// Pointer variables
	float *p_price;
	int *pArray = new int[3];
	int *p_amount = new int;
	int *p_size;
	double *p_PI;
	string *firstPerson;
	string *next1;
	string *next2;


	// Storing addresses in pointers
	p_price = &price;
	p_size = &maxSize;
	p_PI = &PI;
	firstPerson = &NameFirst;
	next1 = &NameLast;
	next2 = NULL;

	// Giving value to regular variables through pointers
	*p_price = 19.95f;
	*p_size = 752;
	*p_amount = 34;
	*p_PI = 3.141592;
	*firstPerson = "firstName";
	*next1 = "lastname";

	PI_div_2 = PI/2;
	pArray[0] = 10;
	pArray[1] = 20;
	pArray[2] = 30;

	// Print statements
	cout << "The address of price is: " << &price << endl;
	cout << "The contents of price is: " << price << endl;
	cout << "The address of p_price is: " << &p_price << endl;
	cout << "The contents of p_price is: " << p_price << endl;
	cout << "The contents of *p_price is: " << *p_price << endl;
	cout << endl;

	cout << "The address of maxSize is: " << &maxSize << endl;
	cout << "The contents of maxSize is: " << maxSize << endl;
	cout << "The address of p_size is: " << &p_size << endl;
	cout << "The contents of p_size is: " << p_size << endl;
	cout << "The contents of *p_size is: " << *p_size << endl;
	cout << endl;

	cout << "The address of p_amount is: " << &p_amount << endl;
	cout << "The contents of p_amount is: " << p_amount << endl;
	cout << "The contents of *p_amount is: " << *p_amount << endl;
	cout << endl;

	cout << "The address of PI is: " << &PI << endl;
	cout << "The contents of PI is: " << PI << endl;
	cout << "The address of PI_div_2 is: " << &PI_div_2 << endl;
	cout << "The contents of PI_div_2 is: " << PI_div_2 << endl;
	cout << "The address of p_PI is: " << &p_PI << endl;
	cout << "The contents of p_PI is: " << p_PI << endl;
	cout << "The contents of *p_PI is: " << *p_PI << endl;
	cout << endl;

	cout << "The address of firstPerson is: " << &firstPerson << endl;
	cout << "The contents of firstPerson is: " << firstPerson << endl;
	cout << "The address of NameFirst is: " << &NameFirst << endl;
	cout << "The contents of NameFirst is: " << NameFirst << endl;
	cout << "The address of next1 is: " << &next1 << endl;
	cout << "The contents of next1 is: " << next1 << endl;
	cout << "The address of NameLast is: " << &NameLast << endl;
	cout << "The contents of NameLast is: " << NameLast << endl;
	cout << "The address of next2 is: " << &next2 << endl;
	cout << "The contents of next2 is: " << next2 << endl;
	cout << endl;

	cout << "The address of pArray is: " << &pArray << endl;
	cout << "The contents of pArray is: " << pArray << endl;
	cout << "The address of pArray[0] is: " << &pArray[0] << endl;
	cout << "The contents of pArray[0] is: " << pArray[0] << endl;
	cout << "The address of pArray[1] is: " << &pArray[1] << endl;
	cout << "The contents of pArray[1] is: " << pArray[1] << endl;
	cout << "The address of pArray[2] is: " << &pArray[2] << endl;
	cout << "The contents of pArray[2] is: " << pArray[2] << endl;
	cout << endl;

	delete[] pArray;
	delete p_amount;

	return 0;
}


int main() {
	int dummyInt;
	lab10();
	cout << "Press any key to continue . . . " << endl;
	cin >> dummyInt;
	return 0;
}

/*
The address of price is: 0060F8F8
The contents of price is: 19.95
The address of p_price is: 0060F878
The contents of p_price is: 0060F8F8
The contents of *p_price is: 19.95

The address of maxSize is: 0060F8EC
The contents of maxSize is: 752
The address of p_size is: 0060F854
The contents of p_size is: 0060F8EC
The contents of *p_size is: 752

The address of p_amount is: 0060F860
The contents of p_amount is: 007F93F0
The contents of *p_amount is: 34

The address of PI is: 0060F8DC
The contents of PI is: 3.14159
The address of PI_div_2 is: 0060F8CC
The contents of PI_div_2 is: 1.5708
The address of p_PI is: 0060F848
The contents of p_PI is: 0060F8DC
The contents of *p_PI is: 3.14159

The address of firstPerson is: 0060F83C
The contents of firstPerson is: 0060F8A8
The address of NameFirst is: 0060F8A8
The contents of NameFirst is: firstName
The address of next1 is: 0060F830
The contents of next1 is: 0060F884
The address of NameLast is: 0060F884
The contents of NameLast is: lastname
The address of next2 is: 0060F824
The contents of next2 is: 00000000

The address of pArray is: 0060F86C
The contents of pArray is: 007F93A8
The address of pArray[0] is: 007F93A8
The contents of pArray[0] is: 10
The address of pArray[1] is: 007F93AC
The contents of pArray[1] is: 20
The address of pArray[2] is: 007F93B0
The contents of pArray[2] is: 30

Press any key to continue . . .

*/