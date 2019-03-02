#include <iostream>
using namespace std;

int main()
{
	double hoursWorked, hourlyRate;
	double regularPay, overTimePay, totalPay;

	cout << "Enter the number of hours worked: ";
	cin >> hoursWorked;

	cout << "Enter the hourly rate: ";
	cin >> hourlyRate;

	if (hoursWorked < 40) 
	{
		regularPay = hoursWorked * hourlyRate;
		overTimePay = 0;
	}

	else
	{
		regularPay = hourlyRate * 40;
		overTimePay = (hoursWorked - 40) * hourlyRate * 1.5;
	}

	totalPay = regularPay + overTimePay;

	cout << "Your regular pay is $" << regularPay << endl;
	cout << "Your overtime pay is $" << overTimePay << endl;
	cout << "Your total pay is $" << totalPay << endl;

	system("pause");
	return 0;
}