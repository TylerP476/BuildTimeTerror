#include <iostream>
#include <cstdlib>
#include <ctime>

bool End(false);

int p1pos = 1;
int p2pos = 1;
int newPos1, newPos2; 

int player1 = 0;  // also the turn counter 
int player2 = 0; 

int rollDice = 0; 

int dice = (rand() % 6) + 1;

int main() {

	srand(unsigned(time(NULL)));

	while (End == false) {

		while (p1pos < 100 || p2pos < 100) {

			if (rollDice == 1) {
				dice;
			}

			void TakeTurnP1(); {
				rollDice = 0; 
				player1 += 1; 

				std::cout << "\nIt is turn " << player1 << " for Player 1 "; 
				std::cout << " \nWould you like to roll the dice? If so enter '1' \n";
				std::cin >> rollDice;
				std::cout << " Player 1 rolled " << dice; 

				newPos1 = p1pos + dice; 
				std::cout << ". Their position is " << newPos1 << ". \n"; 
				p1pos = newPos1; 
				newPos1 = 0; 

			}

			void TakeTurnP2(); {
				rollDice = 0; 
				player2 += 1; 

				std::cout << "\nIt is turn " << player2 << " for Player 2 \n";
				std::cout << "Would you like to roll the dice? If so enter '1' \n";
				std::cin >> rollDice; 
				std::cout << " Player 2 rolled " << dice; 

				newPos2 = p2pos + dice;
				std::cout << ". Their position is " << newPos2 << ". \n"; 
				p2pos = newPos2;
				newPos2 = 0;
			}

		}
	}
	return 0; 
}



/*
PLayer 1 and two determine their position 
dice roll add roll to the player position 
add turns for two players 
add where snakes and ladders are if position is this go here display in words what happened 
display what the player rolled, who the player is and what position they are now on after they rolled 
if they landed on a snake add what they landed on and where they are now

integer array fro snakes 

*/