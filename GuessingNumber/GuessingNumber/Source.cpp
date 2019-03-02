#include <iostream>
using namespace std;

int main()
{
	int number1, number2, sum1 = 0, sum2 = 0;
	cout << "Please enter a positive number: ";
	cin >> number1;
	cout << "Please enter another pisitive number: ";
	cin >> number2;

	while (number1 <= 0 )
	{
		cout << "Please enter a positive number, (Negative to EXIT!)\n";
		cin >> number1;
	}

	while (number2 <= 0)
	{
		cout << "Please enter a positive number, (Negative to EXIT!)\n";
		cin >> number2;
	}

	for (int i = 1; i <= number1; i++)
	{
		sum1 += i;
		cout << "\n\nThe sum of the first number from 1 to " << number1 << " is " << sum1 << "!";
	}

	for (int i = 1; i <= number2; i++)
	{
		sum2 += i;
		cout << "\n\nThe sum of the second number from 1 to " << number2 << " is " << sum2 << "!";
	}
	
	system("pause");
	return 0;
}