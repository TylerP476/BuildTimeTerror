#include<iostream>
using namespace std;
bool running = true;
int main() {
	int playerOnePos = 1;
	int playerTwoPos = 1;
	char board[100];
	char input;
	
	do {
		system("CLS");
		for (int i = 0; i < 100; i++) {
			board[i] = '.';
		}
		board[playerOnePos - 1] = 'O';
		board[playerTwoPos - 1] = 'T'; 
		if (playerOnePos == playerTwoPos) {
			board[playerOnePos - 1] = 'B';
		}
		cout << endl;
		cout << "	#########################################" << endl;
		cout << "	# " << board[99] << " # " << board[98] << " # " << board[97] << " # " << board[96] << " # " << board[95] << " # " << board[94] << " # " << board[93] << " # " << board[92] << " # " << board[91] << " # " << board[90] << " #" << endl;
		cout << "	<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
		cout << "	# " << board[80] << " # " << board[81] << " # " << board[82] << " # " << board[83] << " # " << board[84] << " # " << board[85] << " # " << board[86] << " # " << board[87] << " # " << board[88] << " # " << board[89] << " ^" << endl;
		cout << "	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
		cout << "	^ " << board[79] << " # " << board[78] << " # " << board[77] << " # " << board[76] << " # " << board[75] << " # " << board[74] << " # " << board[73] << " # " << board[72] << " # " << board[71] << " # " << board[70] << " #" << endl;
		cout << "	<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
		cout << "	# " << board[60] << " # " << board[61] << " # " << board[62] << " # " << board[63] << " # " << board[64] << " # " << board[65] << " # " << board[66] << " # " << board[67] << " # " << board[68] << " # " << board[69] << " ^" << endl;
		cout << "	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
		cout << "	^ " << board[59] << " # " << board[58] << " # " << board[57] << " # " << board[56] << " # " << board[55] << " # " << board[54] << " # " << board[53] << " # " << board[52] << " # " << board[51] << " # " << board[50] << " #" << endl;
		cout << "	<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
		cout << "	# " << board[40] << " # " << board[41] << " # " << board[42] << " # " << board[43] << " # " << board[44] << " # " << board[45] << " # " << board[46] << " # " << board[47] << " # " << board[48] << " # " << board[49] << " ^" << endl;
		cout << "	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
		cout << "	^ " << board[39] << " # " << board[38] << " # " << board[37] << " # " << board[36] << " # " << board[35] << " # " << board[34] << " # " << board[33] << " # " << board[32] << " # " << board[31] << " # " << board[30] << " #" << endl;
		cout << "	<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
		cout << "	# " << board[20] << " # " << board[21] << " # " << board[22] << " # " << board[23] << " # " << board[24] << " # " << board[25] << " # " << board[26] << " # " << board[27] << " # " << board[28] << " # " << board[29] << " ^" << endl;
		cout << "	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
		cout << "	^ " << board[19] << " # " << board[18] << " # " << board[17] << " # " << board[16] << " # " << board[15] << " # " << board[14] << " # " << board[13] << " # " << board[12] << " # " << board[11] << " # " << board[10] << " #" << endl;
		cout << "	<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
		cout << "	# " << board[0] << " # " << board[1] << " # " << board[2] << " # " << board[3] << " # " << board[4] << " # " << board[5] << " # " << board[6] << " # " << board[7] << " # " << board[8] << " # " << board[9] << " ^" << endl;
		cout << "	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl << endl;
		cout << "Player One: " << playerOnePos << " Character O." << endl;
		cout << "Player Two: " << playerTwoPos << " Character T." << endl;
		cout << "If both players are on the same tile, the tile will be marked with B" << endl;
		cout << endl << endl;
		cout << "What space should player one move to: ";
		cin >> playerOnePos;
		cout << "What space should player two move to: ";
		cin >> playerTwoPos;
		cout << "Quit?";
		cin >> input;
		if (input == 'y')
			running = false;
	} while (running);
	system("Pause");


	return 0;
}