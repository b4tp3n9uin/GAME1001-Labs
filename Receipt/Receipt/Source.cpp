#include <iostream>
#include <fstream>
using namespace std;

// Reciept.txt
// Bread, Milk, Cheese, and Tomato

int main()
{
	int breadAmount, milkAmount, cheeseAmount, tomatoAmount;
	double bread = 0.99, milk = 1.49, cheese = 4.99, tomato = 2.49;
	ofstream outputFile;

	outputFile.open("C:\\Temp\\reciept.txt");

	cout << "Enter the amount of the following products you wish to purchase-" << endl;

	cout << "Enter the amount of bread you want to buy: ";
	cin >> breadAmount;
	cout << "Enter the amount of milk you want to buy: ";
	cin >> milkAmount;
	cout << "Enter the amount of cheese you want to buy: ";
	cin >> cheeseAmount;
	cout << "Enter the amount of tomatoes you want to buy: ";
	cin >> tomatoAmount;

	outputFile << "Reciept" << endl;
	outputFile << "Product-\tAmt-\tPrice" << endl;
	outputFile << "Bread\t\t" << breadAmount << "\t$" << (breadAmount*bread) << endl;
	outputFile << "Milk\t\t" << milkAmount << "\t$" << (milkAmount*milk) << endl;
	outputFile << "Cheese\t\t" << cheeseAmount << "\t$" << (cheeseAmount*cheese) << endl;
	outputFile << "Tomato\t\t" << tomatoAmount << "\t$" << (tomatoAmount*tomato) << endl;
	outputFile << "\nTotal:\t\t\t$" << ((breadAmount*bread) + (milkAmount*milk) + (cheeseAmount*cheese) + (tomatoAmount*tomato)) << endl;

	outputFile.close();

	cout << "Reciept was successfully saved in File." << endl;

	system("pause");
	return 0;
}