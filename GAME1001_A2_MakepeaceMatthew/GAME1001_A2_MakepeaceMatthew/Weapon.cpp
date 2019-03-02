#include <iostream>
#include <string>
using namespace std;

// Name: Matthew Makepeace
// Student number: 101179668

/*
Create a C++ application that simulates a numbered inventory slot system for weapons. The application will be split
into two parts, the first of which will have the user populating their inventory slots with weapons they will ‘buy’
from a simple store with a few options. Once the player has their weapons, the second part will be a simulation on 
switching and using the weapons in the slots. The following criteria will help with the guidelines for this 
assignment:

Inventory Guidelines-

1)	You can choose to have as many as 9 weapons, but if you choose a minimum, it should at least be 5.
2)	The slots will be represented by the number keys 1-9. You don’t need a 0.
3)	It will be up to you to choose what weapons you want.
4)	Since the second half of the course introduces abstract data types (classes), you are required to create a 
	simple class for your weapons or objects to build objects from. The name of the class should be generic like 
	Weapon or ElderScroll or Wand, etc. Here are the attributes you should create:
	a.	A Boolean flag to know if you own that weapon.
	b.	A string for the weapon name.
	c.	A string for the sound the weapon/item makes when it’s used.
	d.  For part of the bonus that is outlined later, an integer for the ammo/uses of each weapon/item

Part 1: The Store

5)	The store is represented as a simple menu system with the following options:
	a.	Buy Weapon
	b.	Check Balance
	c.	Exit Store

6)	The player will start off with an amount of money that you specify, and the amount should be enough to buy the most expensive weapon 
	the store offers, but not enough to buy ALL the weapons. The details of this is up to you. Some creativity is encouraged.

7)	The ‘Buy Weapon’ interaction consists of asking the player which weapon they want to buy. The slot the weapon goes into should also
	be conveyed.
	d.	You must do a check to see if there is already a weapon in that slot.
	e.	You must check to see if the player has enough money to buy.
	f.	Hint: If a buy is successful, flip the Boolean flag on the weapon object to true and store that object in your array of weapon 
		objects.
	i.	You can also use this array to ensure that the player doesn’t have a weapon in that slot. Also deduct the weapon cost from the
		player's money.

8)	The ‘Check Balance’ option simply displays the amount of money the player has left.

9)	The ‘Exit Store’ option will move the game onto the second stage. You MUST ensure that the player has at least bought one weapon 
	before proceeding. Hint: Loop through the objects array to check if there’s an element OR create a simple bool variable that is set 
	when the player purchases.

Part 2: The Simulation

10)	After the store menu loop, your game should go into another loop that represents using the weapons and being able to switch 
	between them. You have lots of freedom to do this how you choose but follow the criteria below.

11)	During this simulation, you must be able to:
	a.	Switch between weapons by entering an option from 1 to 9 or how many weapons (at least 5) you are using.
	b.	Use a weapon by entering a key option of your choice. Like ‘e’ or ‘f’ or something. More details in item 4.

12)	You can use simple cin for this as this is basic C++. The downside is you need to hit enter after your option.

13)	When you use a weapon/item, output the string from the object attribute that stores a description of the sound when the weapon 
	is used. Use your imagination for the strings but keep it clean.

14)	Hint: for this part, you need to keep track of the weapon/item being selected so you should have an int variable that represents 
	the index of the weapon/item.

*/

class Weapon // Weapon class
{
private:
	string wName; // string variable that stores the name of the weapon
	int wCost; // integer variable that stores the weapon's cost.
	string wSound; // string variable that stores the sound each weapon makes.
public:
	Weapon() {} // default constructor
	Weapon(string n, int c, string s) //parameters consists the weapon's name, cost, and sound.
	{ // non-default constructor
		setName(n);
		setCost(c);
		setSound(s);
	}

	// setters
	void setName(string name)
	{
		wName = name;
	}

	void setCost(int cost)
	{
		wCost = cost;
	}

	void setSound(string s)
	{
		wSound = s;
	}

	// getters
	string getName()
	{
		return wName;
	}

	int getCost()
	{
		return wCost;
	}

	string getSound()
	{
		return wSound;
	}
};

int main()
{
	const int NUM_WEAPONS = 8; // constant int that represents the total amount of guns in the store.

	Weapon gun[NUM_WEAPONS]; // the weapon constructor that has an array for each weapon.
	gun[0] = Weapon("M1911", 500, "Poom!"); //Each Constructor stores the weapon's name, cost, and it's sound.
	gun[1] = Weapon("Uzi", 725, "Skkkkrrrr-rrrrapppp!"); 
	gun[2] = Weapon("Shotgun", 875, "BOOOM! Chk-Chkk!");
	gun[3] = Weapon("MP5", 1000, "Brrrakkkkaa-brrrraaakkka!");
	gun[4] = Weapon("M4 Carbine", 1250, "PAA-PAA-PAAAAMM!");
	gun[5] = Weapon("AK-47", 1500, "TAATAAATAATATAAM-TAATAAM-TAATAATAAAM!");
	gun[6] = Weapon("RPG", 2000, "Psssssss-KAABOOOOOM!");
	gun[7] = Weapon("Minigun", 2500, "ZZZZRRRRRR-BUUUUZZZZZZZZZZZZZZZ!");

	bool inStore = true, //boolean flag that represents if your inside the store.
		buyWeapon, // boolean flag that represents if your in the weapon menu.
		wOwned[NUM_WEAPONS]{ false }; // boolean array that stores if you own the weapon or not.
	char menuOption, // player's selection for the store menu. 
		buyOption; // player's selection for the weapon menu
	int numOfWeapons = 0, // int variable that stores the total number of weapons you own. If you don't own any weapons
		                  // you can't exit the store.
		balance = 3000, // int variable that stors your current balance
		iOption; // int variable that stores the char buyOption.

	while (inStore == true)
	{
		cout << "\nWelcome to the gun store! Here are the following menu options- " << endl;
		cout << "a. Buy Weapon \nb. Check Balance \nc. Exit Store \n\n"; // Gun menu
		cin >> menuOption; // players menu option.
		if (menuOption == 'a' || menuOption == 'A') // buy weapon option
		{
			buyWeapon = true; // boolean flag for the store menu.
			while (buyWeapon == true)
			{
				cout << "\nHere are the weapon options:" << endl;
				for (int i = 0; i < NUM_WEAPONS; i++) // Weapon options
				{
					cout << i + 1 << ") " << gun[i].getName();
					cout << ": $" << gun[i].getCost();
					if (wOwned[i] == true)
						cout << "-Already Owned" << endl; // if you already own a weapon it will display on screen.
					else
						cout << "" << endl;
				}
				cout << "Press 'X' if you want to exit the Weapon Menu" << endl;
				cin >> buyOption;
				if (buyOption == 'X' || buyOption == 'x') // if the player presses 'X', it will go back to the store menu.
				{
					buyWeapon = false;
				}
				else
				{
					iOption = buyOption - 49; // integer variable that converts the char buyOption to an int.
					if (gun[iOption].getCost() > balance)
						cout << "You don't have enough money to buy this weapon." << endl; // When you don't have enough money to buy the Weapon
					else if (wOwned[iOption] == true) // When you already own the weapon
						cout << "You already own this weapon." << endl;
					else
					{ // When a purchase is a success.
						wOwned[iOption] = true;
						balance = balance - gun[iOption].getCost();
						numOfWeapons++;
						cout << "Weapon successfully purchased!" << endl;
					}
				}

			}
		}
		else if (menuOption == 'b' || menuOption == 'B') // Check Balance Option
		{
			cout << "\nYour current balance is $" << balance << endl;
		}
		else // Exit store option
		{
			if (numOfWeapons < 1) // You can't leave the store without owning a weapon.
			{
				cout << "You can't exit the store without buying a gun!" << endl;
			}

			else // when you exit the gun store and the simulation starts.
			{
				inStore = false;
				cout << "\nNow moving on to the gun simulation." << endl;
			}
		}
	}

	bool sim = true, // Boolean flag for the simulatuion.
		shoot = false; // Boolean flag for using a gun
	char selectedW, // Char variable for the player's selected weapon to use. 
		fire; // char variable to fire the weapon
	int wAmmo[NUM_WEAPONS]{10, 25, 6, 30, 33, 35, 3, 100}; //

	while (sim)
	{
		cout << "\nWelcome to the firing range! You may shoot the following guns you own. \nPress 'X' if you want to exit the store. ";
		cout << "Have Fun!" << endl; // cout that the player is in the firing range.
		cin >> selectedW; // player makes the weapon selection to use
		switch (selectedW) //Switch statement for the weapons.
		{
		case '1':
			if (wOwned[0] == false) // if you dont own the weapon, you can't use it.
			{
				cout << "\nYou can not use this weapon, because you don't own it." << endl;
			}
			else
			{
				shoot = true;
				while (shoot) //when the player is using the weapon.
				{
					cout << "\nCurrent Gun: " << gun[0].getName() << endl; // tell the player what weapon they're using
					cout << "Ammo: " << wAmmo[0] << endl; // show the player how much ammo they have left.
					cout << "* Press 'F' to fire your weapon." << endl;
					cout << "* Press 'X' if you want to switch weapons.\n" << endl;

					cin >> fire;
					if (fire == 'F' || fire == 'f') // Player fires the weapon
					{
						if (wAmmo [0] <= 0) // When the weapon has no bullets left.
						{
							cout << "NO AMMO!\n" << endl;
						}
						else // Firing the weapon.
						{
							wAmmo[0] = wAmmo[0] - 1; // bullet fires one shot.
							cout << gun[0].getSound() << endl; // Gun makes a sound.
						}
					}
					else if (fire == 'X' || fire == 'x') // When the player presses 'X', you go back to the weapon selection.
						shoot = false;
				}
			}
			break;
		case '2':
			if (wOwned[1] == false)
			{
				cout << "\nYou can not use this weapon, because you don't own it." << endl;
			}
			else
			{
				shoot = true;
				while (shoot)
				{
					cout << "\nCurrent Gun: " << gun[1].getName() << endl;
					cout << "Ammo: " << wAmmo[1] << endl;
					cout << "* Press 'F' to fire your weapon." << endl;
					cout << "* Press 'X' if you want to switch weapons.\n" << endl;

					cin >> fire;
					if (fire == 'F' || fire == 'f')
					{
						if (wAmmo[1] <= 0)
						{
							cout << "NO AMMO!\n" << endl;
						}
						else
						{
							wAmmo[1] = wAmmo[1] - 1;
							cout << gun[1].getSound() << endl;
						}
					}
					else if (fire == 'X' || fire == 'x')
						shoot = false;
				}
			}
			break;
		case '3':
			if (wOwned[2] == false)
			{
				cout << "\nYou can not use this weapon, because you don't own it." << endl;
			}
			else
			{
				shoot = true;
				while (shoot)
				{
					cout << "\nCurrent Gun: " << gun[2].getName() << endl;
					cout << "Ammo: " << wAmmo[2] << endl;
					cout << "* Press 'F' to fire your weapon." << endl;
					cout << "* Press 'X' if you want to change your weapon.\n" << endl;

					cin >> fire;
					if (fire == 'F' || fire == 'f')
					{
						if (wAmmo[2] <= 0)
						{
							cout << "NO AMMO!\n" << endl;
						}
						else
						{
							wAmmo[2] = wAmmo[2] - 1;
							cout << gun[2].getSound() << endl;
						}
					}
					else if (fire == 'X' || fire == 'x')
						shoot = false;
				}
			}
			break;
		case '4':
			if (wOwned[3] == false)
			{
				cout << "\nYou can not use this weapon, because you don't own it." << endl;
			}
			else
			{
				shoot = true;
				while (shoot)
				{
					cout << "\nCurrent Gun: " << gun[3].getName() << endl;
					cout << "Ammo: " << wAmmo[3] << endl;
					cout << "* Press 'F' to fire your weapon." << endl;
					cout << "* Press 'X' if you want to change your weapon.\n" << endl;

					cin >> fire;
					if (fire == 'F' || fire == 'f')
					{
						if (wAmmo[3] <= 0)
						{
							cout << "NO AMMO!\n" << endl;
						}
						else
						{
							wAmmo[3] = wAmmo[3] - 1;
							cout << gun[3].getSound() << endl;
						}
					}
					else if (fire == 'X' || fire == 'x')
						shoot = false;
				}
			}
			break;
		case '5':
			if (wOwned[4] == false)
			{
				cout << "\nYou can not use this weapon, because you don't own it." << endl;
			}
			else
			{
				shoot = true;
				while (shoot)
				{
					cout << "\nCurrent Gun: " << gun[4].getName() << endl;
					cout << "Ammo: " << wAmmo[4] << endl;
					cout << "* Press 'F' to fire your weapon." << endl;
					cout << "* Press 'X' if you want to switch weapons.\n" << endl;

					cin >> fire;
					if (fire == 'F' || fire == 'f')
					{
						if (wAmmo[4] <= 0)
						{
							cout << "NO AMMO!\n" << endl;
						}
						else
						{
							wAmmo[4] = wAmmo[4] - 3; // The M4 Carbine is a three burst weapon, so it fires three bullets in one tap.
							cout << gun[4].getSound() << endl;
						}
					}
					else if (fire == 'X' || fire == 'x')
						shoot = false;
				}
			}
			break;
		case '6':
			if (wOwned[5] == false)
			{
				cout << "\nYou can not use this weapon, because you don't own it." << endl;
			}
			else
			{
				shoot = true;
				while (shoot)
				{
					cout << "\nCurrent Gun: " << gun[5].getName() << endl;
					cout << "Ammo: " << wAmmo[5] << endl;
					cout << "* Press 'F' to fire your weapon." << endl;
					cout << "* Press 'X' if you want to switch weapons.\n" << endl;

					cin >> fire;
					if (fire == 'F' || fire == 'f')
					{
						if (wAmmo[5] <= 0)
						{
							cout << "NO AMMO!\n" << endl;
						}
						else
						{
							wAmmo[5] = wAmmo[5] - 1;
							cout << gun[5].getSound() << endl;
						}
					}
					else if (fire == 'X' || fire == 'x')
						shoot = false;
				}
			}
			break;
		case '7':
			if (wOwned[6] == false)
			{
				cout << "\nYou can not use this weapon, because you don't own it." << endl;
			}
			else
			{
				shoot = true;
				while (shoot)
				{
					cout << "\nCurrent Gun: " << gun[6].getName() << endl;
					cout << "Ammo: " << wAmmo[6] << endl;
					cout << "* Press 'F' to fire your weapon" << endl;
					cout << "* Press 'X' if you want to switch weapons.\n" << endl;

					cin >> fire;
					if (fire == 'F' || fire == 'f')
					{
						if (wAmmo[6] <= 0)
						{
							cout << "NO AMMO!\n" << endl;
						}
						else
						{
							wAmmo[6] = wAmmo[6] - 1;
							cout << gun[6].getSound() << endl;
						}
					}
					else if (fire == 'X' || fire == 'x')
						shoot = false;
				}
			}
			break;
		case '8':
			if (wOwned[7] == false)
			{
				cout << "\nYou can not use this weapon, because you don't own it." << endl;
			}
			else
			{
				shoot = true;
				while (shoot)
				{
					cout << "\nCurrent Gun: " << gun[7].getName() << endl;
					cout << "Ammo: " << wAmmo[7] << endl;
					cout << "* Press 'F' to fire your weapon" << endl;
					cout << "* Press 'X' if you want to switch weapons.\n" << endl;

					cin >> fire;
					if (fire == 'F' || fire == 'f')
					{
						if (wAmmo[7] <= 0)
						{
							cout << "NO AMMO!\n" << endl;
						}
						else
						{
							wAmmo[7] = wAmmo[7] - 1;
							cout << gun[7].getSound() << endl;
						}
					}
					else if (fire == 'X' || fire == 'x')
						shoot = false;
				}
			}
			break;
		case 'X': // When the player presses 'X', they leave the simulation.
		case 'x':
			sim = false; 
			break;
		default:
			cout << "\nPlease select a valid option.\n" << endl; // When the player enters an invalid option.
			continue;
		}
	}
	cout << "Bye-bye!" << endl;
	system("pause");
	return 0; // The end!
}