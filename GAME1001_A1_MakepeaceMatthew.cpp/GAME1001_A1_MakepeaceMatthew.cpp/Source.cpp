#include <iostream> // for input and output service.
#include <cstdlib> // for the Random function.
#include <fstream> // for text files.
#include <string> // for string variables.

using namespace std;

/*
- Implement a C++ console application that simulates a Rock-Paper-Scissor game against the computer.

- When played between two people, each person picks one of three options (usually shown by hand gesture)
  at the same time, and a winner is determined. In the game, Rock beats Scissors, Scissors beats Paper,
  and Paper beats Rock.

- The program should randomly choose one of the three options (without revealing it),

- then ask for user input (choice of Rock, Paper or Scissor), and finally compare with user’s choice.

- At that point, the program reveals both choices and prints a statement indicating if the user won,
  the computer won, or it was a tie.

- Application should keep track of the current score (i.e. the number of user wins, losses, and ties) and
  update the screen after every play.

- User should be prompted after every game if they want to continue playing.

- At the beginning of the game the program should also ask the user for their name and display this name
  when showing the score.

- You do not need to use any user-defined functions for this assignment but you can add whatever you like
  so long as the criteria at the end of this document has been met. No bonus marks will be given, however.


Appendix A:
As part of this assignment you are to implement storing of game data into a text file. Game should always
ask for a username (it has to be at least 8 characters) and store game results in a file with the same name
as the username (username.txt). If the user has played the game before, the date should be read from the file
and displayed on screen before starting a new game. At the end of the game the statistics should be saved on
the same file.


Appendix B [This is a challenge question and completing this task will award you a bonus of 10%]:
Game should not allow for same usernames. This means that the game should check for existing usernames
and prompt the new user to choose a different one if the one provided is taken. This would also guarantee
that every user will have a unique game data statistics stored and not overridden by another user with the
same username.

This is an individual assignment and that means you CANNOT work on the assignment with someone else.
Plagiarism penalties will apply.

*/
int main() // main function
{
	string userName;
	char playAgain;
	ofstream outputFile;
	int comp;
	int user;
	bool play = true; // This boolean determines when the player stops the game. 
	int userWin = 0, userTie = 0, userLost = 0; // The winning, tie and losing record starts at 0.

	outputFile.open("username.txt");

	cout << "Please enter your name: "; // Get the user to input his/her name.
	cin >> userName; // Store the input name of the user in the char varribale name.
	outputFile << userName << endl; // Store the name of the user in the string varribale name.

	while (play == true) // The game will continue as long as the boolean stays true.
	{
		comp = rand() % 3 + 1; // the computer can now make it's choice, since they are assigned a random variable.  

		// Ask the user to make it's move by chosing a number between 1-3.
		cout << "\nPlease select the following number to make your move:\n1. Rock\n2. Paper\n3. Sissors" << endl;
		cin >> user; // user inputs a number from 1-3 to make his/her move.

		while (user < 1 || user > 3) // the user gets asked to select a number again, when the user's number is 
		{                            // outside the range of 1-3. 
			// Ask the user to input a number from 1-3, again.
			cout << "This is an invalid number, please select the following number to make your move:";
			cout << "\n1. Rock\n2. Paper\n3. Sissors" << endl;
			cin >> user; // User inputs a number from 1-3 to make his/her move or else they
		}                // will get asked again and again, until he/she selects a number from 1-3.

		if (user == 1 && comp == 2) // Result if user picks rock and computer picks paper.
		{
			cout << "Paper covers Rock. Computer wins!";
			userLost++; // User losing record increments (add 1 to userLost).
		}

		else if (user == 1 && comp == 3) // Result if user picks rock and computer picks sissors.
		{
			cout << "Rock smashes Sissors. " << userName << " wins!";
			userWin++; // User winning record increments (add 1 to userWin).
		}

		else if (user == 2 && comp == 1) // Result if user picks paper and computer picks rock.
		{
			cout << "Paper covers Rock. " << userName << " wins!";
			userWin++; // User winning record increments (add 1 to userWin).
		}

		else if (user == 2 && comp == 3) // Result if user picks paper and computer picks sissors.
		{
			cout << "Sissors cuts Paper. Computer wins!";
			userLost++; // User lossing record increments (add 1 to userLost).
		}

		else if (user == 3 && comp == 1) // Result if user picks sissors and computer picks rock.
		{
			cout << "Rock smashes Sissors. Computer wins!";
			userLost++; // User losing  record increments (add 1 to userWon).
		}

		else if (user == 3 && comp == 2) // Result if user picks sissors and computer pick paper
		{
			cout << "Sissors cuts Paper. " << userName << " wins!";
			userWin++; // User winning record increments (add 1 to userWon).
		}

		else // Result when user and computer pick the and it ends in a draw.
		{
			cout << "It's a Draw!";
			userTie++; // User tie record increments (add 1 to userTie).
		}

		cout << "\n\nCurrent Score:" << endl; // Display the current record score board.
		cout << userName << ": (" << userWin << "-" << userTie << "-" << userLost << ")" << endl;
		cout << "Computer: (" << userWin << "-" << userTie << "-" << userLost << ")" << endl;
		cout << "\nType in 'Y' or 'y' if you want to play again?\n"; // Ask the player if he/she wants to play again.
		cin >> playAgain; // User inputs 'yes' or 'y' if he/she wants to play, and presses other keys if he/she wants to quit

		if (playAgain == 'Y' || playAgain == 'y')
		{
			play = true; // If the user types 'yes' or 'y', the game will run again.
		}

		else
		{
			play = false; // If the user types a different key, the game will quit. 
		}
	}

	outputFile << "\n\nCurrent Score Board-" << endl;
	outputFile << userName << ": (" << userWin << "-" << userTie << "-" << userLost << ")" << endl; // User record
	outputFile << "Computer: (" << userLost << "-" << userTie << "-" << userWin << ")" << endl; // Computer record

	cout << "Username and scores were successfully stored in file." << endl;
	outputFile.close();

	system("pause");
	return 0;
}