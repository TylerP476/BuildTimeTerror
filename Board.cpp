#include<iostream>
#include<ctime>
#include<cstdlib>
#include<stdlib.h>
#include "windows.h"
#include<string>
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
bool firstLaunch = true;
double input;
string winner;


void MenuDisplay();
void SnakeArt();
void MenuToggle();
void TakeTurnP1();
void TakeTurnP2();
void CheckPosP1();
void CheckPosP2();
void MainBoard();
void SnakesText();
void Reset();
void WinScreen();
void VictoryText();
void printLaddr();




//Main Menu
int main()
{
	if (firstLaunch) {
		SnakesText();
		firstLaunch = false;
	}
	system("pause>nul");
	system("CLS");
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
			running = true;
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
				cout << "\n\t\t\t\t4. If your player piece lands on a tile that says laddr on top and " << "\n\t\t\t\tbelow, you move to the tile denoted by the numbers beside your piece " << endl;
				cout << "\n\t\t\t\t5. If your player piece lands on a tile that says snake on top and " << "\n\t\t\t\tbelow, you move to the tile denoted by the numbers beside your piece" << endl;
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
void printLaddr() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << "Laddr";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
void printSnake() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << "Snake";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
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
	if (playerOnePos >= 5) {
		winner = "One";//Variable for denoting who the winner is in end screen
		WinScreen();
		Reset();
		main();
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
	case 21:
		cout << "Player One has landed on a LADDER and moved to tile 42!" << endl;
		cout << endl;
		playerOnePos = 42;
		system("Pause>nul");
		break;
	case 36:
		cout << "Player One has landed on a LADDER and moved to tile 44!" << endl;
		cout << endl;
		playerOnePos = 44;
		system("Pause>nul");
		break;
	case 47:
		cout << "Player One has landed on a SNAKE and moved to tile 26!" << endl;
		cout << endl;
		playerOnePos = 26;
		system("Pause>nul");
		break;
	case 51:
		cout << "Player One has landed on a LADDER and moved to tile 67!" << endl;
		cout << endl;
		playerOnePos = 67;
		system("Pause>nul");
		break;
	case 56:
		cout << "Player One has landed on a SNAKE and moved to tile 53!" << endl;
		cout << endl;
		playerOnePos = 53;
		system("Pause>nul");
		break;
	case 64:
		cout << "Player One has landed on a SNAKE and moved to tile 60!" << endl;
		cout << endl;
		playerOnePos = 60;
		system("Pause>nul");
		break;
	case 71:
		cout << "Player One has landed on a LADDER and moved to tile 91!" << endl;
		cout << endl;
		playerOnePos = 91;
		system("Pause>nul");
		break;
	case 87:
		cout << "Player One has landed on a SNAKE and moved to tile 24!" << endl;
		cout << endl;
		playerOnePos = 24;
		system("Pause>nul");
		break;
	case 93:
		cout << "Player One has landed on a SNAKE and moved to tile 73!" << endl;
		cout << endl;
		playerOnePos = 73;
		system("Pause>nul");
		break;
	case 98:
		cout << "Player One has landed on a SNAKE and moved to tile 78!" << endl;
		cout << endl;
		playerOnePos = 78;
		system("Pause>nul");
		break;
	}

}
//Checking function for second player
void CheckPosP2() {

	if (playerTwoPos >= 100) {
		winner = "Two";
		WinScreen();
		Reset();
		main();
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
	case 21:
		cout << "Player Two has landed on a LADDER and moved to tile 42!" << endl;
		cout << endl;
		playerTwoPos = 42;
		system("Pause>nul");
		break;
	case 36:
		cout << "Player Two has landed on a LADDER and moved to tile 44!" << endl;
		cout << endl;
		playerTwoPos = 44;
		system("Pause>nul");
		break;
	case 47:
		cout << "Player Two has landed on a SNAKE and moved to tile 26!" << endl;
		cout << endl;
		playerOnePos = 26;
		system("Pause>nul");
		break;
	case 51:
		cout << "Player Two has landed on a LADDER and moved to tile 67!" << endl;
		cout << endl;
		playerTwoPos = 67;
		system("Pause>nul");
		break;
	case 56:
		cout << "Player Two has landed on a SNAKE and moved to tile 53!" << endl;
		cout << endl;
		playerTwoPos = 53;
		system("Pause>nul");
		break;
	case 64:
		cout << "Player Two has landed on a SNAKE and moved to tile 60!" << endl;
		cout << endl;
		playerTwoPos = 60;
		system("Pause>nul");
		break;
	case 71:
		cout << "Player Two has landed on a LADDER and moved to tile 91!" << endl;
		cout << endl;
		playerTwoPos = 91;
		system("Pause>nul");
		break;
	case 87:
		cout << "Player Two has landed on a SNAKE and moved to tile 24!" << endl;
		cout << endl;
		playerTwoPos = 24;
		system("Pause>nul");
		break;
	case 93:
		cout << "Player Two has landed on a SNAKE and moved to tile 73!" << endl;
		cout << endl;
		playerTwoPos = 73;
		system("Pause>nul");
		break;
	case 98:
		cout << "Player Two has landed on a SNAKE and moved to tile 78!" << endl;
		cout << endl;
		playerTwoPos = 78;
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
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		board[playerOnePos - 1] = 'O';
		
		board[playerTwoPos - 1] = 'T';
		//check if both players are on the same space
		if (playerOnePos == playerTwoPos) {
			board[playerOnePos - 1] = 'B';
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		//display the board
		//To add a snake/ladder to the board, write snake or laddr on top and below the tile that the event starts on, then change the # on either side to be the tile which the snake/ladder ends on
		cout << "	#############"; printSnake(); cout << "#########################"; printSnake(); cout << "#############" << endl;
		cout << "	#  " << board[99] << "  #  " << board[98] << "  7  " << board[97] << "  8  " << board[96] << "  #  " << board[95] << "  #  " << board[94] << "  #  " << board[93] << "  7  " << board[92] << "  3  " << board[91] << "  #  " << board[90] << "  #" << endl;
		cout << "	<<<<<<<<<<<<<"; printSnake(); cout << "<<<<<<<<<<<<<<<<<<<"; printSnake(); cout << "<"; printSnake(); cout << "<<<<<<<<<<<<<" << endl;
		cout << "	#  " << board[80] << "  #  " << board[81] << "  #  " << board[82] << "  #  " << board[83] << "  #  " << board[84] << "  #  " << board[85] << "  2  " << board[86] << "  4  " << board[87] << "  #  " << board[88] << "  #  " << board[89] << "  ^" << endl;
		cout << "	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"; printSnake(); cout << ">>>>>>>>>>>>>"; printLaddr(); cout << ">" << endl;
		cout << "	^  " << board[79] << "  #  " << board[78] << "  #  " << board[77] << "  #  " << board[76] << "  #  " << board[75] << "  #  " << board[74] << "  #  " << board[73] << "  #  " << board[72] << "  #  " << board[71] << "  9  " << board[70] << "  1" << endl;
		cout << "	<<<<<<<<<<<<<<<<<<<"; printSnake(); cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"; printLaddr(); cout << "<" << endl;
		cout << "	#  " << board[60] << "  #  " << board[61] << "  #  " << board[62] << "  6  " << board[63] << "  0  " << board[64] << "  #  " << board[65] << "  #  " << board[66] << "  #  " << board[67] << "  #  " << board[68] << "  #  " << board[69] << "  ^" << endl;
		cout << "	>>>>>>>>>>>>>>>>>>>"; printSnake(); cout << ">"; printSnake(); cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
		cout << "	^  " << board[59] << "  #  " << board[58] << "  #  " << board[57] << "  #  " << board[56] << "  5  " << board[55] << "  3  " << board[54] << "  #  " << board[53] << "  #  " << board[52] << "  #  " << board[51] << "  #  " << board[50] << "  #" << endl;
		cout << "	<<<<<<<<<<<<<<<<<<<<<<<<<"; printSnake(); cout << "<<<<<<<"; printSnake(); cout << "<<<<<<<<<<<<<"; printLaddr(); cout << "<" << endl;
		cout << "	#  " << board[40] << "  #  " << board[41] << "  #  " << board[42] << "  #  " << board[43] << "  #  " << board[44] << "  #  " << board[45] << "  2  " << board[46] << "  6  " << board[47] << "  #  " << board[48] << "  6  " << board[49] << "  7" << endl;
		cout << "	>>>>>>>>>>>>>>>>>>>>>>>>>"; printLaddr(); cout << ">>>>>>>"; printSnake(); cout << ">>>>>>>>>>>>>"; printLaddr(); cout << ">" << endl;
		cout << "	^  " << board[39] << "  #  " << board[38] << "  #  " << board[37] << "  #  " << board[36] << "  4  " << board[35] << "  4  " << board[34] << "  #  " << board[33] << "  #  " << board[32] << "  #  " << board[31] << "  #  " << board[30] << "  #" << endl;
		cout << "	<"; printLaddr(); cout << "<<<<<<<<<<<<<<<<<<<"; printLaddr(); cout << "<<<<<<<<<<<<<"; printLaddr(); cout << "<<<<<<<<<<<<<" << endl;
		cout << "	4  " << board[20] << "  2  " << board[21] << "  #  " << board[22] << "  #  " << board[23] << "  #  " << board[24] << "  #  " << board[25] << "  #  " << board[26] << "  8  " << board[27] << "  4  " << board[28] << "  #  " << board[29] << "  ^" << endl;
		cout << "	>"; printLaddr(); cout << ">>>>>>>>>>>>>>>>>>>"; printSnake(); cout << ">>>>>>>>>>>>>"; printLaddr(); cout << ">>>>>>>>>>>>>" << endl;
		cout << "	^  " << board[19] << "  #  " << board[18] << "  #  " << board[17] << "  #  " << board[16] << "  0  " << board[15] << "  6  " << board[14] << "  #  " << board[13] << "  #  " << board[12] << "  #  " << board[11] << "  #  " << board[10] << "  #" << endl;
		cout << "	<<<<<<<<<<<<<<<<<<<"; printLaddr(); cout << "<"; printSnake(); cout << "<<<<<<<<<<<<<<<<<<<"; printLaddr(); cout << "<<<<<<<" << endl;
		cout << "	#  " << board[0] << "  #  " << board[1] << "  #  " << board[2] << "  1  " << board[3] << "  4  " << board[4] << "  #  " << board[5] << "  #  " << board[6] << "  #  " << board[7] << "  3  " << board[8] << "  1  " << board[9] << "  ^" << endl;
		cout << "	>>>>>>>>>>>>>>>>>>>"; printLaddr(); cout << ">>>>>>>>>>>>>>>>>>>>>>>>>"; printLaddr(); cout << ">>>>>>>" << endl << endl;
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

void WinScreen() {
	system("CLS");
	VictoryText();
	cout << endl << endl << endl;
	cout << "\t\t\t\t\t\tPlayer " << winner << " Is The Winner!";
	cout << "\n  \t\t\t\t\t\tPress ENTER to continue";
}

void Reset() {
	valid = false;
	running = false;
	playerOnePos = 1;
	playerTwoPos = 1;
	turnCounter = 0;
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

void SnakesText() {
	cout << "   ___    _    _      __      _    _   _____    ___  \n";
	cout << "  /   \\  | \\  | |    /  \\    | |  / / |  ___|  /   \\ \n";
	cout << " |  /\\_| |  \\ | |   / /\\ \\   | | / /  | |     |  /\\_| \n";
	cout << "  \\_\\_   |   \\| |  / /__\\ \\  | |/ /\   | |__    \\_\\_  \n";
	cout << "  _ \\ \\  | |\\   | |  ____  | | |\\ \\   |  __|   _ \\ \\ \n";
	cout << " | \\/  | | | \\  | | |    | | | | \\ \\  | |___  | \\/  | \n";
	cout << "  \\___/  |_|  \\_| |_|    |_| |_|  \\_\\ |_____|  \\___/  \n";
	cout << "                                        ____ \n";
	cout << "                                       / __ \\\n";
	cout << "                                      | /  \\ | \n";
	cout << "                                      | \\__/ |  \n";
	cout << "                                       \\    /   _\n";
	cout << "                                       / __ \\  / /\n";
	cout << "                                      | /  \\ \\/ /\n";
	cout << "                                      | \\__/ /\\ \\\n";
	cout << "                                       \\____/  \\_\\\n";
	cout << "                                 _           __      ____     ____     _____   _____     ___ \n";
	cout << "                                | |         /  \\    |  _ \\   |  _ \\   |  ___| |  __ \\   /   \\     \n";
	cout << "                                | |        / /\\ \\   | | \\ \\  | | \\ \\  | |     | |  \\ | |  /\\_|                  \n";
	cout << "                                | |       / /__\\ \\  | |  | | | |  | | | |__   | |__/ |  \\_\\_             \n";
	cout << "                                | |      |  ____  | | |  | | | |  | | |  __|  |    _/   _ \\ \\        \n";
	cout << "                                | |____  | |    | | | |_/ /  | |_/ /  | |___  | |\\ \\   | \\/  |              \n";
	cout << "                                |______| |_|    |_| |____/   |____/   |_____| |_| \\_\\   \\___/                \n";

}

void VictoryText() {
	//ART
	cout << endl;
	cout << "\t __" << "              __" << "   ___________" << "     ______" << "    ___________" << "     ______" << "      _______" << "    __        __ " << endl;
	cout << "\t \\ \\" << "            / /" << "  |____   ____|" << "   / ____ \\" << "  |____   ____|" << "   /  __  \\" << "    |  ____ \\" << "   \\ \\      / /" << endl;
	cout << "\t  \\ \\" << "          / /" << "        | |" << "       / /    \\ \\" << "      | |" << "       /  /  \\  \\" << "   | |    \\ \\" << "   \\ \\    / /" << endl;
	cout << "\t   \\ \\" << "        / /" << "         | |" << "      | |      |_|" << "     | |" << "      |  /    \\  |" << "  | |    | |" << "    \\ \\  / /" << endl;
	cout << "\t    \\ \\" << "      / /" << "          | |" << "      | |" << "              | |" << "      | |      | |" << "  | |____/ /" << "     \\ \\/ / " << endl;
	cout << "\t     \\ \\" << "    / /" << "           | |" << "      | |       _" << "      | |" << "      | |      | |" << "  |  _  __/" << "       \\  /" << endl;
	cout << "\t      \\ \\" << "  / /" << "            | |" << "      | |      | |" << "     | |" << "      |  \\    /  |" << "  | | \\ \\" << "         |  | " << endl;
	cout << "\t       \\ \\" << "/ /" << "         ____| |____" << "   \\ \\____/ /" << "      | |" << "       \\  \\__/  /" << "   | |  \\ \\" << "        |  | " << endl;
	cout << "\t        \\" << "__/" << "         |___________|" << "   \\______/" << "       |_|" << "        \\______/" << "    |_|   \\_\\" << "       |__|" << endl;

}