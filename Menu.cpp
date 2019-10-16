#include <iostream>;

using namespace std;

void MenuDisplay();
void SnakeArt();
void MenuToggle();

double num;
bool valid = false;
bool goBack = false;
double input;

int main()
{
	MenuDisplay();
	SnakeArt();
	MenuToggle();

	while (!valid)
	{
		valid = true;

		cout << endl << "\t\t\t\t\tType a corresponding number to continue: ";
		cin >> num;
		cin.ignore(256, '\n');

		//Checks if the user inputted a letter --> ERROR
		if (cin.fail())
		{			
			cin.clear();
			cin.ignore();
			cout << "\t\t\t\t\t  ERROR. Invalid input. Please try again" << endl;
			system("pause>nul");
			system("CLS");	
			cin.ignore(256, '\n');
			MenuDisplay();
			SnakeArt();
			MenuToggle();
			valid = false;
		}
		//Checks if the user inputted a decimal --> ERROR
		else if (num != static_cast<int>(num))
		{
			cout << "\t\t\t\t\t  ERROR. Invalid input. Please try again" << endl;
			system("pause>nul");		
			system("CLS");		
			MenuDisplay();
			SnakeArt();
			MenuToggle();
			valid = false;
		}
		//Checks that the user has inputted a 1, 2 or 3
		else if (num > 3 || num <= 0)
		{
			cout << "\t\t\t\t\t  ERROR. Invalid input. Please try again" << endl;
			system("pause>nul");
			system("CLS");
			MenuDisplay();
			SnakeArt();
			MenuToggle();
			valid = false;
		}
		//Switches to the corresponding screen that the player has inputted
		if (num == 1)
		{
			system("CLS");
			cout << "BOARD GAMEZ";
		}
		else if (num == 2)
		{
			system("CLS");
			goBack = false;

			//Checks the validity of the user input
			while (!goBack)
			{
				goBack = true;

				cout << "\t\t\t\t\t\t\t   RULES" << endl;
				cout << endl;
				cout << endl;
				cout << "\t\t\t\t1. Decide who goes first" << endl;
				cout << "\n\t\t\t\t2. Take turns rolling the dice by pressing ENTER" << endl;
				cout << "\n\t\t\t\t3. Your player piece will move accordingly to the dice roll around the board" << endl;
				cout << "\n\t\t\t\t4. If your player piece lands at the bottom of a ladder, it moves " << "\n\t\t\t\tto the top of the ladder" << endl;
				cout << "\n\t\t\t\t5. If your player piece lands on the head of the snake, it slides " << "\n\t\t\t\tdown to the bottom of the snake" << endl;
				cout << "\n\t\t\t\t6. The first player to reach the end of the board is the winner!" << endl;
				cout << "\n\n\n\n\t\t\t\t\t\t   [Press 4 to go back]" << endl;
				cout << "\t\t\t\t\t\t\t    ";
				cin >> input;
				cin.ignore(256, '\n');

				//If the user typed in a letter
				if (cin.fail())
				{
					cin.clear();
					cin.ignore();
					cout << "\t\t\t\t\t  ERROR. Invalid input. Please try again" << endl;
					system("pause>nul");
					system("CLS");
					cin.ignore(256, '\n');
					goBack = false;
				}
				//If the user typed a number other than 4
				else if (input != 4)
				{
					cout << "\t\t\t\t\t  ERROR. Invalid input. Please try again" << endl;
					system("pause>nul");
					system("CLS");
					goBack = false;
				}					
			}
			//If the user types in 4, return to the main menu
			if (input == 4)
			{
				system("CLS");
				MenuDisplay();
				SnakeArt();
				MenuToggle();
				valid = false;
			}
		}
		else if (num == 3)
		{
			exit(1);
		}				
	}

	system("pause>nul");

	return 0;
}

#pragma region Menu Word Art
//Word art for the menu
void MenuDisplay()
{
	cout << "\t\t\t\t\t\t" << "Welcome to Snakes and Ladders!" << endl;
	cout << "\t\t\t\t\t       " << "A game made by Build Time Terror" << endl;
	cout << "\t";

	for (int i = 0; i <= 102; ++i)
	{
		cout << "_";
	}
	cout << endl;
	cout << "       |" << "        \t\t\t\t\t  _____" << "\t\t\t\t\t\t       |" << endl;
	cout << "       |" << "        \t\t\t\t" << "|" << "\\" << "    /" << "|" << " |" << "\t |\\    |" << "  |" << "     |" << "\t\t\t       |" << endl;
	cout << "       |" << "        \t\t\t\t" << "|" << " \\" << "  /" << " |" << " |_____" << "\t | \\   |" << "  |" << "     |" << "\t\t\t       |" << endl;
	cout << "       |" << "        \t\t\t\t" << "|" << "  \\" << "/" << "  |" << " |" << "\t |  \\  |" << "  |" << "     |" << "\t\t\t       |" << endl;
	cout << "       |" << "        \t\t\t\t" << "|" << "      |" << " |" << "\t |   \\ |" << "  |" << "     |" << "\t\t\t       |" << endl;
	cout << "       |" << "        \t\t\t\t" << "|" << "      |" << " |_____" << "\t |    \\|" << "  |_____|" << "\t\t\t       |" << endl;
	cout << "       |" << "\t\t\t\t\t\t\t\t\t\t\t\t       |" << endl;

	cout << "       |";

	for (int i = 0; i <= 102; ++i)
	{
		cout << "_";
	}

	cout << "|";
}
#pragma endregion

#pragma region Menu Toggle
void MenuToggle()
{
	for (int i = 0; i < 2; ++i)
	{
		cout << endl;
	}

	cout << "\t\t\t\t\t\t       1. Play Game" << endl;
	cout << "\t\t\t\t\t\t       2. Rules" << endl;
	cout << "\t\t\t\t\t\t       3. Quit" << endl;
}

#pragma endregion

#pragma region Snake Art
void SnakeArt()
{
	cout << endl << "\t";

	for (int i = 0; i <= 102; ++i)
	{
		cout << "_";
	}

	cout << endl << "\t\t\t\t\t";
	cout << "\t\t\t ____" << endl;
	cout << "\t\t\t\t\t________________________/ 0  \\___/" << endl;
	cout << "\t\t\t\t       <_____________________________/   \\" << endl;

	cout << "\t\t\t\t\t ____" << "\t\t\t\t\t\t\t ____" << endl; 
	cout << "\t\t________________________/ 0  \\___/" << "\t\t\t________________________/ 0  \\___/" << endl;
	cout << "\t\t<_0_0_0_0_0_0_0_0_0_0_0_0____/   \\" << "\t\t       <%%%%%%%%%%%%%%%%%%%%%%%%_____/   \\" << endl;
}
#pragma endregion

