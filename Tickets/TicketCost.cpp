#include <iostream>
using namespace std;

int main()
{
	int ticketSelection;
	double cost;

	cout << "Please select your ticket: " << endl;
	cout << "Press 1 to select adult tickets(ages 15-64)." << endl;
	cout << "Press 2 to select child tickets(ages 14 and under)." << endl;
	cout << "Press 3 to select senior tickets(ages 65 and over)." << endl;
	cout << "Press 4 to exit." << endl;
	cout << "\nYour ticket selection is: ";
	cin >> ticketSelection;

	if (ticketSelection == 1) 
	{
		cost = 20.00;
		cout << "Your ticket will cost $" << cost << "." << endl;
	}
	else if (ticketSelection == 2)
	{
		cost = 20.00 - (20.00 * 0.5);
		cout << "Your ticket will cost $" << cost << "." << endl;
	}
	else if (ticketSelection == 3)
	{
		cost = 20.00 - (20.00 * 0.2);
		cout << "Your ticket will cost $" << cost << "." << endl;
	}
	else
	{
		return 0;
	}
	system("pause");
	return 0;
}