#include <iostream>
#include <string>
using namespace std;

class employee
{
private:
	int eNumber;
	string name;
	double payrate;
	int hours;

public:
	string getName(string n)
	{
		return n;
	}

	int getEmpID(int id)
	{
		return id;
	}

	double getWage(double p, int h)
	{
		return p * h;
	}
};

employee* searchEmployee(const employee l[], int size, int position);
void printEmployees(const employee* l[], int size);

int main()
{
	employee Employee1, Employee2, Employee3;

	int EmpNum1, EmpNum2, EmpNum3, hrs1, hrs2, hrs3, searchID;
	string name1, name2, name3;
	double pyRt1, pyRt2, pyRt3;

	cout << "\nEnter employee 1's ID number: " << endl;
	cin >> EmpNum1;
	cout << "Enter employee 1's name: " << endl;
	cin >> name1;
	cout << "Enter employee 1's pay rate: " << endl;
	cin >> pyRt1;
	cout << "Enter the hours employee 1 worked: " << endl;
	cin >> hrs1;

	cout << "\nEnter employee 2's ID number: " << endl;
	cin >> EmpNum2;
	cout << "Enter employee 2's name: " << endl;
	cin >> name2;
	cout << "Enter employee 2's pay rate: " << endl;
	cin >> pyRt2;
	cout << "Enter the hours employee 2 worked: " << endl;
	cin >> hrs2; 
	
	cout << "\nEnter employee 3's ID number: " << endl;
	cin >> EmpNum3;
	cout << "Enter employee 3's name: " << endl;
	cin >> name3;
	cout << "Enter employee 3's pay rate: " << endl;
	cin >> pyRt3;
	cout << "Enter the hours employee 3 worked: " << endl;
	cin >> hrs3;

	Employee1.getEmpID(EmpNum1);
	Employee1.getName(name1);
	Employee1.getWage(pyRt1, hrs1);

	Employee2.getEmpID(EmpNum2);
	Employee2.getName(name2);
	Employee2.getWage(pyRt2, hrs2);

	Employee3.getEmpID(EmpNum3);
	Employee3.getName(name3);
	Employee3.getWage(pyRt3, hrs3);

	if (Employee1.getWage(pyRt1, hrs1) > Employee2.getWage(pyRt2, hrs2) && Employee2.getWage(pyRt2, hrs2) > Employee3.getWage(pyRt3, hrs3))
	{
		cout << "\nThe employee with the highest wage is " << Employee1.getName(name1) << "(" << Employee1.getEmpID(EmpNum1) << ") with a total wage of $" << Employee1.getWage(pyRt1, hrs1) << endl;
		cout << "The employee with the lowest wage is " << Employee3.getName(name3) << "(" << Employee3.getEmpID(EmpNum3) << ") with a total wage of $" << Employee3.getWage(pyRt3, hrs3) << endl;
	}
	else if (Employee2.getWage(pyRt2, hrs2) > Employee1.getWage(pyRt1, hrs1) && Employee1.getWage(pyRt1, hrs1) > Employee3.getWage(pyRt3, hrs3))
	{
		cout << "The employee with the highest wage is " << Employee2.getName(name2) << "(" << Employee2.getEmpID(EmpNum2) << ") with a total wage of $" << Employee2.getWage(pyRt2, hrs2) << endl;
		cout << "The employee with the lowest wage is " << Employee3.getName(name3) << "(" << Employee3.getEmpID(EmpNum3) << ") with a total wage of $" << Employee3.getWage(pyRt3, hrs3) << endl;
	}
	else if (Employee1.getWage(pyRt1, hrs1) > Employee3.getWage(pyRt3, hrs3) && Employee3.getWage(pyRt3, hrs3) > Employee2.getWage(pyRt2, hrs2))
	{
		cout << "The employee with the highest wage is " << Employee1.getName(name1) << "(" << Employee1.getEmpID(EmpNum1) << ") with a total wage of $" << Employee1.getWage(pyRt1, hrs1) << endl;
		cout << "The employee with the lowest wage is " << Employee2.getName(name2) << "(" << Employee2.getEmpID(EmpNum2) << ") with a total wage of $" << Employee2.getWage(pyRt2, hrs2) << endl;
	}
	else if (Employee2.getWage(pyRt2, hrs2) > Employee3.getWage(pyRt3, hrs3) && Employee3.getWage(pyRt3, hrs3) > Employee1.getWage(pyRt1, hrs1))
	{
		cout << "The employee with the highest wage is " << Employee2.getName(name2) << "(" << Employee1.getEmpID(EmpNum2) << ") with a total wage of $" << Employee2.getWage(pyRt2, hrs2) << endl;
		cout << "The employee with the lowest wage is " << Employee1.getName(name1) << "(" << Employee1.getEmpID(EmpNum1) << ") with a total wage of $" << Employee3.getWage(pyRt1, hrs1) << endl;
	}
	else if (Employee3.getWage(pyRt3, hrs3) > Employee1.getWage(pyRt1, hrs1) && Employee1.getWage(pyRt1, hrs1) > Employee2.getWage(pyRt2, hrs2))
	{
		cout << "The employee with the highest wage is " << Employee3.getName(name3) << "(" << Employee3.getEmpID(EmpNum3) << ") with a total wage of $" << Employee3.getWage(pyRt3, hrs3) << endl;
		cout << "The employee with the lowest wage is " << Employee2.getName(name2) << "(" << Employee2.getEmpID(EmpNum2) << ") with a total wage of $" << Employee2.getWage(pyRt2, hrs2) << endl;
	}
	else if (Employee3.getWage(pyRt3, hrs3) > Employee2.getWage(pyRt2, hrs2) && Employee2.getWage(pyRt2, hrs2) > Employee1.getWage(pyRt1, hrs1))
	{
		cout << "The employee with the highest wage is " << Employee3.getName(name3) << "(" << Employee3.getEmpID(EmpNum3) << ") with a total wage of $" << Employee3.getWage(pyRt3, hrs3) << endl;
		cout << "The employee with the lowest wage is " << Employee1.getName(name1) << "(" << Employee1.getEmpID(EmpNum1) << ") with a total wage of $" << Employee1.getWage(pyRt1, hrs1) << endl;
	}

	cout << "Please enter an employee ID number: ";
	cin >> searchID;

	const employee* employeeID;
	searchEmployee(employeeID, 3, searchID);

	cout << "Employee Successfully searched!" << endl;

	system("pause");
	return 0;
}

int searchEmployee(const employee* l[], int size, int eid)
{
	int i = 0;
	l[i] = NULL;
	bool found = false;
	while (i < size && !found)
	{
		if (l[i].getEmpID(i) == eid)
		{
			found = true;
			size = i;
		}
		i++;
	}
	return l[eid].getEmpID(i);
}

void printEmployees(const employee* l[], int size)
{
	int id;
	string n;
	for ( int i = 0; i < size; i++ )
	{
		
	}
}