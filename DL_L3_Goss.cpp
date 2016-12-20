// Author: Cecilia Goss     Course: COSC 1337 Spring 2015 DL  Instructor: Thayer
// Assignment: Lab 03
// This program tests you on your math skills, gives your final grade and a recommendation on 
//		whether you need to work on a specific topic.

#include <ctime> // Gets the time
#include <cstdlib> // srand() and rand()
#include <iostream> // Needed for cout, cin
#include <string> // Needed to define string variables
#include <iomanip> // Needed for setprecision()

using namespace std;

int main () { // Main function.
	
	srand(time(NULL));	// Bases random function off of computer's time.
	
	string operation;
	
	int sign,
		operand_1,
		operand_2,
		answer,			// Actual answer to problem.
		userAnswer,		// User input.
		numCorrect = 0, // Grand total number of correct answers.
		numTotal = 0;	// Grand total number of questions asked.
	
	int correct[4] = { 0 }; // Holds the number of correct answers for each type of question.
	int total[4] = { 0 };	// Holds the total number of questions for each type of question.
	
	cout << "Welcome to math tutor! If you get tired, you may enter a negative number to exit the program. \n" << endl;
	
	while (true) {

		sign = rand() % 4; // Choose a sign at random to be the operator.
		
		if ( sign == 0 ) { // Operation is addition when sign == 0.
			operation = " + ";
			operand_1 = rand() % 51;		// First operand range: [0,50]
			operand_2 = rand() % 51;		// Second operand range: [0,50]
			answer = operand_1 + operand_2; // Answer range: [0,100]
		}
		else if ( sign == 1 ) { // Operation is subtraction when sign == 1.
			operation = " - ";
			answer = rand() % 51;			// Answer range: [0,100]
			operand_2 = rand() % 51;		// Second operand range: [0,50]
			operand_1 = operand_2 + answer; // First operand range: [0,100]
		}
		else if ( sign == 2 ) {	// Operation is multiplication when sign == 2.
			operation = " × ";
			operand_1 = rand() % 11;		// First operand range: [0,10]
			operand_2 = rand() % 11;		// Second operand range: [0,10]
			answer = operand_1 * operand_2; // Answer range: [0,100]
		}
		else { // Operation is division when sign == 3.
			operation = " ÷ ";
			answer = rand() % 11;			// Answer range: [0,10]
			operand_2 = rand() % 10 + 1;	// Second operand range: [1,10] (Cannot equal zero)
			operand_1 = operand_2 * answer; // First operand range: [0,10]
		}
		
		cout << operand_1 << operation << operand_2 << " = "; // Displays math problem.
		cin >> userAnswer;

		if ( userAnswer == answer ) { // If answer is correct, record.
			numCorrect++;
			correct[sign]++;
		}
		else if ( userAnswer <= -1 ) { // If sentinel value -1 is entered, exit loop.
			break;
		}
		
		numTotal++;		// Increment number of total questions asked by one.
		total[sign]++;	// Increment number of type of questions asked by one.
		
	}
	
	// Statistics
	double percentCorrect = (double) numCorrect / numTotal * 100;
	double additionMastery = (double) correct[0] / total[0] * 100;
	double subtractionMastery = (double) correct[1] / total[1] * 100;
	double multiplicationMastery =  (double) correct[2] / total[2] * 100;
	double divisionMastery = (double) correct[3] / total[3] * 100;
	
	// Display statistics.
	cout << fixed << setprecision(2);
	
	cout << "\nTotal questions: " << numTotal << endl;
	cout << "Number of... " << endl;
	cout << "\t...correct answers: " << numCorrect << endl;
	cout << "\t...incorrect answers: " << ( numTotal - numCorrect ) << endl;
	cout << "Final score: "  << percentCorrect << "%" << endl;
	
	cout << "\nTotal number of addition problems: " << total[0] << endl;
	cout << "Addition mastery: " << additionMastery << "%" << endl;
	
	cout << "\nTotal number of subtraction problems: " << total[1] << endl;
	cout << "Subtraction mastery: " << subtractionMastery << "%" << endl;
	
	cout << "\nTotal number of multiplication problems: " << total[2] << endl;
	cout << "Multiplication mastery: " << multiplicationMastery << "%" << endl;
	
	cout << "\nTotal number of division problems: " << total[3] << endl;
	cout << "Division mastery: " << divisionMastery << "%" << endl;
	
	string words[4];
	string lastWords = "";
	int numWords = 0;
	
	// If grade is less than 70% for any type of math problem, add to recommendation.
	if ( additionMastery < 70 ) {
		words[numWords] = "addition";
		numWords++;
	}
	if ( subtractionMastery < 70 ) {
		words[numWords] = "subtraction";
		numWords++;
	}
	if ( multiplicationMastery < 70 ) {
		words[numWords] = "multiplication";
		numWords++;
	}
	if ( divisionMastery < 70 ) {
		words[numWords] = "division";
		numWords++;
	}
	
	// Final recommendation.
	if ( numWords > 0 ) {
		cout << "It is recommended you brush up on your ";
		if ( numWords == 1 ) {
			cout << words[0];
		}
		else if ( numWords == 2 ) {
			cout << words[0] << " and " << words[1];
		}
		else {
			for ( int k = 0; k < numWords; k++ ) {
				cout << words[k];
				if ( k < numWords - 1 ) {
					cout << ",";
				}
				if ( k == numWords - 2 ) {
					cout << " and";
				}
					cout << " ";
			}
		}
		cout << "facts.";
	}
	return 0;
}

/*
 Welcome to math tutor! If you get tired, you may enter a negative number to exit the program. 
 
 14 ÷ 7 = 2
 40 + 50 = 90
 49 - 21 = 28
 37 + 5 = 42
 45 + 22 = 68
 59 - 21 = 9
 40 ÷ 8 = 29
 60 ÷ 10 = 555
 0 × 3 = 333
 51 - 33 = 121
 37 - 28 = 0
 6 × 5 = 0
 20 ÷ 10 = 0
 54 ÷ 6 = 9
 7 × 0 = 0
 7 × 0 = 0
 5 × 3 = 15
 48 ÷ 6 = 12
 28 + 5 = 33
 30 ÷ 3 = 10
 35 ÷ 7 = 5
 10 × 7 = 70
 46 - 18 = 0
 12 + 12 = 0
 8 + 10 = 0
 6 × 9 = 0
 11 - 6 = 0
 61 - 16 = 0
 30 - 2 = 0
 5 × 2 = 22
 12 + 5 = 17
 5 × 6 = 30
 46 - 38 = -3
 
 Total questions: 32
 Number of... 
 ...correct answers: 14
 ...incorrect answers: 18
 Final score: 43.75%
 
 Total number of addition problems: 7
 Addition mastery: 57.14%
 
 Total number of subtraction problems: 8
 Subtraction mastery: 12.50%
 
 Total number of multiplication problems: 9
 Multiplication mastery: 55.56%
 
 Total number of division problems: 8
 Division mastery: 50.00%
 It is recommended you brush up on your addition, subtraction, multiplication, and division facts.
 */
