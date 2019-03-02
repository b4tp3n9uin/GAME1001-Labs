#include <iostream>
using namespace std;

double ticketPrice (int selection, double price);

int main()
{
	int selection;
	double price = 20;

	cout << "Please make your selection from the menu below!\n";
	cout << "1. Adult [15 - 64]\n";
	cout << "2. Child [0 - 14]\n";
	cout << "3. Senior [65 - ]\n";
	cout << "4. Exit\n\n";
	cout << "And your selection is: ";

	cin >> selection;

	ticketPrice(selection, price);

	cout << "The price is $" << ticketPrice(selection, price) << endl;

	system("pause");
	return 0;
}

double ticketPrice(int selection, double price)
{
	if (selection == 1)
	{
		return price;
	}
	else if (selection == 2)
	{
		return price * 0.5;
	}
	else if (selection == 3)
	{
		return price * 0.8;
	}
	else
	{
		return -1;
	}
	system("pause");
}
