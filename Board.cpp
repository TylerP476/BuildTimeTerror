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
char input;
//Function that runs everytime the player takes a turn
void TakeTurnP1() {
	srand(time(NULL));

	cout <<	"	It is turn " << turnCounter << " for Player O " << endl;
	cout << "Press enter to roll the die" << endl;
	system("Pause>nul");
	int diceRoll = rand() % 6 + 1;
	cout << "	Player O rolled " << diceRoll<<endl;

	playerOnePos += diceRoll;
	cout << "Press enter to end your turn" << endl;
	cout << endl;
	system("Pause>nul");

}
//Same function for player two
void TakeTurnP2() {
	srand(time(NULL));

	cout << "	It is turn " << turnCounter << " for Player T " << endl;
	cout << "Press enter to roll the die" << endl;
	system("Pause>nul");
	int diceRoll = rand() % 6 + 1;
	cout << "	Player T rolled " << diceRoll<<endl;

	playerTwoPos += diceRoll;
	cout << "Press enter to end your turn" << endl;
	cout << endl;
	system("Pause>nul");
}
//Function that checks if the player is on a snake or ladder or has won
void checkPosP1() {
	//Check if the player won
	if (playerOnePos >= 100) {
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
void checkPosP2() {

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

//Main function holds the board
int main() {
	
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
		cout << endl;
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
		cout << "Player One: " << playerOnePos << " Character O." << endl;
		cout << "Player Two: " << playerTwoPos << " Character T." << endl;
		cout << "If both players are on the same tile, the tile will be marked with B" << endl;
		cout << endl << endl;
		//P1 takes a turn
		TakeTurnP1();
		//Check if the player wins, if not check if they hit a S/L
		checkPosP1();
		//If player one wins, it wont let player 2 take a turn, jumps right to end screen
		if (running) {
			//repeat for p2
			TakeTurnP2();
			//repeat for p2
			checkPosP2();
		}
		
	} while (running);
	//stops the game from closing to quickly
	system("Pause");


	return 0;

}