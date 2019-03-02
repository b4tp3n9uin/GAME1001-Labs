#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string items;
	ifstream inputFile;
	ofstream outputFile;

	outputFile.open("C:\\Temp\\items.txt");


	cout << "Enter 5 items you have for sales-\n";

	for (int i = 1; i <= 5; i++)
	{
		cout << "Enter item #" << i << ": ";
		cin >> items;
		outputFile << items << endl;

	}

	outputFile.close();

	cout << "Items were successfully saved in file.\n";

	system("pause");
	return 0;
}