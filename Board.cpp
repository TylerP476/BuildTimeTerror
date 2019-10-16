#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
//Variables for game
bool running = true;
int turnCounter = 0;
int playerOnePos = 1;//player always starts on first tile
int playerTwoPos = 1;
char board[100];
double num;
bool valid = false;
bool goBack = false;
double input;
int winner;


void MenuDisplay();
void SnakeArt();
void MenuToggle();
void TakeTurnP1();
void TakeTurnP2();
void CheckPosP1();
void CheckPosP2();
void MainBoard();



//Main Menu
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
			MainBoard();
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
//Function that runs everytime the player takes a turn
void TakeTurnP1() {
	srand(time(NULL));

	cout <<	"\t\t\tIt is turn " << turnCounter << " for Player O " << endl;
	cout << "\t\t\tPress enter to roll the die" << endl;
	system("Pause>nul");
	int diceRoll = rand() % 6 + 1;
	cout << "\t\t\tPlayer O rolled " << diceRoll<<endl;

	playerOnePos += diceRoll;
	cout << "\t\t\tPress enter to end your turn" << endl;
	cout << endl;
	system("Pause>nul");

}
//Same function for player two
void TakeTurnP2() {
	srand(time(NULL));

	cout << "\t\t\tIt is turn " << turnCounter << " for Player T " << endl;
	cout << "\t\t\tPress enter to roll the die" << endl;
	system("Pause>nul");
	int diceRoll = rand() % 6 + 1;
	cout << "\t\t\tPlayer T rolled " << diceRoll<<endl;

	playerTwoPos += diceRoll;
	cout << "\t\t\tPress enter to end your turn" << endl;
	cout << endl;
	system("Pause>nul");
}
//Function that checks if the player is on a snake or ladder or has won
void CheckPosP1() {
	//Check if the player won
	if (playerOnePos >= 100) {
		winner = 1;//Variable for denoting who the winner is in end screen
		cout << "Player One Wins! Congratz!";
		running = false;
	}
	//switch statement that compares the player position to each ladder and snake to determine if they should move
	//to add a snake or ladder, just add the case for where it starts, and set the player pos to where it ends
	switch (playerOnePos) {
	case 4:
		cout << "Player One has landed on a LADDER and moved to tile 14!" << endl;
		cout << endl;
		playerOnePos = 14;
		system("Pause>nul");
		break;
	case 9:
		cout << "Player One has landed on a LADDER and moved to tile 31!" << endl;
		cout << endl;
		playerOnePos = 31;
		system("Pause>nul");
		break;
	case 16:
		cout << "Player One has landed on a SNAKE and moved to tile 6!" << endl;
		cout << endl;
		playerOnePos = 6;
		system("Pause>nul");
		break;
	}

}
//Checking function for second player
void CheckPosP2() {

	if (playerTwoPos >= 100) {
		cout << "Player Two Wins! Congratz!";
		running = false;
	}

	switch (playerTwoPos) {
	case 4:
		cout << "Player Two has landed on a LADDER and moved to tile 14!" << endl;
		cout << endl;
		playerTwoPos = 14;
		system("Pause>nul");
		break;
	case 9:
		cout << "Player Two has landed on a LADDER and moved to tile 31!" << endl;
		cout << endl;
		playerTwoPos = 31;
		system("Pause>nul");
		break;
	case 16:
		cout << "Player Two has landed on a SNAKE and moved to tile 6!" << endl;
		cout << endl;
		playerTwoPos = 6;
		system("Pause>nul");
		break;
	}

}

void MainBoard() {
	do {
		//clear the screen at the start of every game loop
		system("CLS");
		//increment the turn counter
		++turnCounter;
		//fill the board with periods
		for (int i = 0; i < 100; i++) {
			board[i] = '.';
		}
		//replace the periods at the player positions with the players icon
		board[playerOnePos - 1] = 'O';
		board[playerTwoPos - 1] = 'T';
		//check if both players are on the same space
		if (playerOnePos == playerTwoPos) {
			board[playerOnePos - 1] = 'B';
		}
		//display the board
		//To add a snake/ladder to the board, write snake or laddr on top and below the tile that the event starts on, then change the # on either side to be the tile which the snake/ladder ends on
		cout << "	#############################################################" << endl;
		cout << "	#  " << board[99] << "  #  " << board[98] << "  #  " << board[97] << "  #  " << board[96] << "  #  " << board[95] << "  #  " << board[94] << "  #  " << board[93] << "  #  " << board[92] << "  #  " << board[91] << "  #  " << board[90] << "  #" << endl;
		cout << "	<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
		cout << "	#  " << board[80] << "  #  " << board[81] << "  #  " << board[82] << "  #  " << board[83] << "  #  " << board[84] << "  #  " << board[85] << "  #  " << board[86] << "  #  " << board[87] << "  #  " << board[88] << "  #  " << board[89] << "  ^" << endl;
		cout << "	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
		cout << "	^  " << board[79] << "  #  " << board[78] << "  #  " << board[77] << "  #  " << board[76] << "  #  " << board[75] << "  #  " << board[74] << "  #  " << board[73] << "  #  " << board[72] << "  #  " << board[71] << "  #  " << board[70] << "  #" << endl;
		cout << "	<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
		cout << "	#  " << board[60] << "  #  " << board[61] << "  #  " << board[62] << "  #  " << board[63] << "  #  " << board[64] << "  #  " << board[65] << "  #  " << board[66] << "  #  " << board[67] << "  #  " << board[68] << "  #  " << board[69] << "  ^" << endl;
		cout << "	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
		cout << "	^  " << board[59] << "  #  " << board[58] << "  #  " << board[57] << "  #  " << board[56] << "  #  " << board[55] << "  #  " << board[54] << "  #  " << board[53] << "  #  " << board[52] << "  #  " << board[51] << "  #  " << board[50] << "  #" << endl;
		cout << "	<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
		cout << "	#  " << board[40] << "  #  " << board[41] << "  #  " << board[42] << "  #  " << board[43] << "  #  " << board[44] << "  #  " << board[45] << "  #  " << board[46] << "  #  " << board[47] << "  #  " << board[48] << "  #  " << board[49] << "  ^" << endl;
		cout << "	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
		cout << "	^  " << board[39] << "  #  " << board[38] << "  #  " << board[37] << "  #  " << board[36] << "  #  " << board[35] << "  #  " << board[34] << "  #  " << board[33] << "  #  " << board[32] << "  #  " << board[31] << "  #  " << board[30] << "  #" << endl;
		cout << "	<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Laddr<<<<<<<<<<<<<" << endl;
		cout << "	#  " << board[20] << "  #  " << board[21] << "  #  " << board[22] << "  #  " << board[23] << "  #  " << board[24] << "  #  " << board[25] << "  #  " << board[26] << "  8  " << board[27] << "  4  " << board[28] << "  #  " << board[29] << "  ^" << endl;
		cout << "	>>>>>>>>>>>>>>>>>>>>>>>>>Snake>>>>>>>>>>>>>Laddr>>>>>>>>>>>>>" << endl;
		cout << "	^  " << board[19] << "  #  " << board[18] << "  #  " << board[17] << "  #  " << board[16] << "  0  " << board[15] << "  6  " << board[14] << "  #  " << board[13] << "  #  " << board[12] << "  #  " << board[11] << "  #  " << board[10] << "  #" << endl;
		cout << "	<<<<<<<<<<<<<<<<<<<Laddr<Snake<<<<<<<<<<<<<<<<<<<Laddr<<<<<<<" << endl;
		cout << "	#  " << board[0] << "  #  " << board[1] << "  #  " << board[2] << "  1  " << board[3] << "  4  " << board[4] << "  #  " << board[5] << "  #  " << board[6] << "  #  " << board[7] << "  3  " << board[8] << "  1  " << board[9] << "  ^" << endl;
		cout << "	>>>>>>>>>>>>>>>>>>>Laddr>>>>>>>>>>>>>>>>>>>>>>>>>Laddr>>>>>>>" << endl << endl;
		//info that is displayed under board (Can be declared in rules)
		cout << "\t\t\tPlayer One: " << playerOnePos << " Character O." << endl;
		cout << "\t\t\tPlayer Two: " << playerTwoPos << " Character T." << endl;
		cout << "     If both players are on the same tile, the tile will be marked with B" << endl;
		cout << endl << endl;
		//P1 takes a turn
		TakeTurnP1();
		//Check if the player wins, if not check if they hit a S/L
		CheckPosP1();
		//If player one wins, it wont let player 2 take a turn, jumps right to end screen
		if (running) {
			//repeat for p2
			TakeTurnP2();
			//repeat for p2
			CheckPosP2();
		}

	} while (running);

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