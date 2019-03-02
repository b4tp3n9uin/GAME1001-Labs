#include <iostream>
using namespace std;

double sumCal(double n1, double n2, double n3);
double prodCal(double n1, double n2, double n3);
double getAverage(double n1, double n2, double n3);



int main()
{
	double number1, number2, number3; // declare input variables

	cout << "Please enter the first number: ";
	cin >> number1;

	cout << "Please enter the second number: ";
	cin >> number2;

	cout << "Please enter the third number: ";
	cin >> number3;

	cout << "\n\nThe sum of the three numbers is: " << sumCal(number1, number2, number3) << endl;

	cout << "\nThe product of the three numbers is: " << prodCal(number1, number2, number3) << endl;

	cout << "\nThe average of the three numbers is: " << getAverage(number1, number2, number3) << endl;

	system("pause");
	return 0;
}

double sumCal(double n1, double n2, double n3)
{
	return n1 + n2 + n3;
}

double prodCal(double n1, double n2, double n3)
{
	return n1 * n2*n3;
}

double getAverage(double n1, double n2, double n3)
{
	return (n1*n2*n3) / 3;
}
