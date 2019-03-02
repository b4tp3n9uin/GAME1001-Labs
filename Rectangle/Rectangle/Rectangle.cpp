#include <iostream>;
using namespace std;

class Rectangle
{
private: 
	double length;
	double width;
public:
	Rectangle()
	{
		length = 1;
		width = 1;
	}

	Rectangle(double l, double w)
	{
		length = l;
		width = w;
	}

	void setLength(double l) 
	{
		length = l;
	}
	double getLength() 
	{
		return length;
	}
	void setWidth(double w) 
	{
		width = w;
	}
	double getWidth() 
	{
		return width;
	}
	double getArea()
	{
		return length * width;
	}
	double getParameter() 
	{
		return 2 * (length + width);
	}
};

int main()
{
	Rectangle r1;
	Rectangle r2(11, 11);
	double length;
	double width;


	cout << "Area of the rectangle for r1 is: " << r1.getArea() << "ft." << endl;
	cout << "Parameter of the rectangle for r1 is: " << r1.getParameter() << "ft.\n" << endl;

	cout << "Area of the rectangle for r2 is: " << r2.getArea() << "ft." << endl;
	cout << "Parameter of the rectangle for r2 is: " << r2.getParameter() << "ft." << endl;

	system("pause");
	return 0;
}