#include <iostream>
using namespace std;

int main() 
{
	int bread, cheese, milk;

	cout << "Enter the amount of bread you want to purchase: ";
	cin >> bread;
	cout << "Enter the amount of milk you want to purchase: ";
	cin >> milk;
	cout << "Enter the amount of chesse you want to purchase: ";
	cin >> cheese;

	double total, hst, grandTotal;
	total = (bread * 1.99) + (milk * 3.99) + (cheese * 9.99);
	hst = total * 0.13;
	grandTotal = total + hst;

	cout << "\nThe total cost $" << total;
	cout << "\nThe hst is $" << hst;
	cout << "\nThe grand total is $" << grandTotal << endl;

	system("pause");
	return 0;
}