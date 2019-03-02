#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string items;
	double price;
	ifstream inputFile;
	ofstream outputFile;

	outputFile.open("C:\\Temp\\items.txt");
	inputFile.open("C:\\Temp\\prices.txt");
	

	cout << "Enter 5 items you have for sales-\n";

	for (int i = 1; i <= 5; i++)
	{
		inputFile >> items;
		cout << "Enter the price for these item " << i << ": ";
		cin >> price;
		outputFile << price << endl;
		
	}

	inputFile.close();
	outputFile.close();

	cout << "All prices were successfully saved in file.\n";

	system("pause");
	return 0;
}