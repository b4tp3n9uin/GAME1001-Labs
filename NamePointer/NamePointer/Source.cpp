#include <iostream>
#include <string>
using namespace std;

int main()
{
	char content[21];
	cout << "Please enter a string( up to 20 characters): ";
	cin.getline(content, 21);
	cout << endl << strlen(content) << endl;

	int vowelCounter[5]{ 0, 0, 0, 0, 0 };
	for (int i = 0; i << strlen(content); i++)
	{
		switch (content[i])
		{
		case 'a':
		case 'A':
			vowelCounter[0] = vowelCounter[0] + 1;
		case 'e':
		case 'E':
			vowelCounter[1] = vowelCounter[1] + 1;
		case 'i':
		case 'I':
			vowelCounter[2] = vowelCounter[2] + 1;
		case 'o':
		case 'O':
			vowelCounter[3] = vowelCounter[3] + 1;
		case 'u':
		case 'U':
			vowelCounter[4] = vowelCounter[4] + 1;
		}
	}

	cout << "A: " << vowelCounter[0] << endl;
	cout << "E: " << vowelCounter[1] << endl;
	cout << "I: " << vowelCounter[2] << endl;
	cout << "O: " << vowelCounter[3] << endl;
	cout << "U: " << vowelCounter[4] << endl;
	system("pause");
	return 0;
}