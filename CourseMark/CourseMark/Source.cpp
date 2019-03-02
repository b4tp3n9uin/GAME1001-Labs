#include <iostream>
using namespace std;

int main() 
{
	double assign1, assign2, labs, midTerm, finalExam;

	cout << "Enter your mark from assignment 1: ";
	cin >> assign1;
	cout << "\nEnter your mark from assignment 2: ";
	cin >> assign2;
	cout << "\nEnter your mark from the labs: ";
	cin >> labs;
	cout << "\nEnter your mark from the Mid Terms: ";
	cin >> midTerm;
	cout << "\nEnter your mark from the Final Exam: ";
	cin >> finalExam;

	assign1 = assign1 * 0.1;
	assign2 = assign2 * 0.2;
	labs = labs * 0.2;
	midTerm = midTerm * 0.2;
	finalExam = finalExam * 0.3;

	double avg;
	avg = assign1 + assign2 + labs + midTerm + finalExam;

	if (avg >= 90) 
	{
		cout << "Your Final Grade is " << avg << "% [A+]";
	}
	else if (avg >= 80 && 90 > avg) 
	{
		cout << "Your Final Grade is " << avg << "% [A]";
	}
	else if (avg >= 70 && 80 > avg) 
	{
		cout << "Your Final Grade is " << avg << "% [B]";
	}
	else if (avg >= 60 && 70 > avg) 
	{
		cout << "Your Final Grade is " << avg << "% [C]";
	}
	else if ( avg >= 50 && 60 > avg) 
	{
		cout << "Your Final Grade is " << avg << "% [D]";
	}
	else 
	{
		cout << "Unfortunately you failed with a Final Grade having a " << avg << "% [F]" << endl;
	}

	system("pause");
	return 0;
}