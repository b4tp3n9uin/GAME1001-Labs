// This program stores students assignment average in an int array. It uses
// one loop to input the marks and another loop to display them.
#include <iostream>
using namespace std;

int main()
{
	const int NUM_ASSIGNMENTS = 5;
	int mark[NUM_ASSIGNMENTS];      // Holds hours worked for 6 employees
	int count = 0;                     // Loop counter
	int sum = 0;
	int high = 0, low = 0;
	double avg = 0;

	// Input the hours worked by each employee
	cout << "Enter the marks scored by " << NUM_ASSIGNMENTS
		<< " assignments: ";

	for (count = 0; count < NUM_ASSIGNMENTS; count++)
		cin >> mark[count];

	low = mark[0];
	for (count = 0; count < NUM_ASSIGNMENTS; count++)
	{
		if (mark[count] < low)
		{
			low = mark[count];
		}
	}

	high = mark[0];
	for (count = 0; count < NUM_ASSIGNMENTS; count++)
	{
		if (mark[count] > high)
		{
			high = mark[count];
		}
	}

	// Display the contents of the array
	cout << "The marks for your assignments are:";

	for (count = 0; count < NUM_ASSIGNMENTS; count++)
	{
		cout << " " << mark[count] << ",";
	}

	for (count = 0; count < NUM_ASSIGNMENTS; count++)
	{
		sum += mark[count];
	}
	avg = sum / NUM_ASSIGNMENTS;

	cout << "\nThe average mark for all of your assignments is " << avg << "%." << endl;
	cout << "Your lowest mark is " << low << "%." << endl;
	cout << "Your highest mark is " << high << "%." << endl;
	
	system("pause");
	return 0;
}
