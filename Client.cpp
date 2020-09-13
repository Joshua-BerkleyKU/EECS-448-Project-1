/* -----------------------------------------------------------------------------
 *
 * File Name:  Client.cpp
 * Author: Darrin Ternes
 * Team: 15

 ---------------------------------------------------------------------------- */

#include <iostream>
#include "Client.h"
#include <string>
#include "Player.h"


void Client::RunSetup(){

	while(end_program == false) {

		int userChoice = 0;

		std::cout << "\n========================\n---------{Menu}---------\n\n1) Start New Game of Battleship\n2) Edit Number of Ships\n3) Exit Battleship\n========================\nEnter your choice: ";
		std::cin >> userChoice;

		if (std::cin.fail()) {

			std::cin.clear();
			std::cin.ignore();
			std::cout << "\n\n\n\nPlease type the number to which function you would like to do\n\n";

		}

		if(userChoice == 1){	//###Start Game

			std::cout << "\nStarting the game with " << ship_count << " ships! \n\n";
			PlayGame(ship_count);
  		}

		if (userChoice == 2){	//###Edit Ship Count -- This checks for the correct num of ships

			int userShips = 0;

			std::cout << "\n\n Enter how many ships you would like next game to be played with (1 - 5): ";

			while (true) {

			bool valid_num_of_ships = true;
			std::cin >> userShips;

			if(std::cin.fail()) {
				valid_num_of_ships = false;
				std::cin.clear();
				std::cin.ignore();
				std::cout << "\n\nPlease enter the number of ships to play with\n\n";

			}
			if(userShips > 5) {
				valid_num_of_ships = false;
				std::cin.clear();
				std::cin.ignore();
				std::cout << "\n Please enter less than 5 ships to play with: ";

			}
			if(userShips <= 0) {
				valid_num_of_ships = false;
				std::cin.clear();
				std::cin.ignore();
				std::cout << "\n Please enter at least 1 ship to play with: ";

			}
			if(valid_num_of_ships == true) {

				break;

			}
	  }

		ship_count = userShips;
		std::cout << "\n\nGame settings updated to be played with " << ship_count << " ships!\n\n\n";

   }

		if (userChoice == 3){	//###Exit Program

			end_program = true;

		}
}	//end of run conidition
}	//end of Client::Run

void Client::PlayGame(int num_ships){

	Player* player1 = new Player;		//create each player
	Player* player2 = new Player;

	player1->placeShips(num_ships);	//let both players place ships
	player2->placeShips(num_ships);

	end_game = false;

	while (end_game == false){

		if(turn == false){

			std::cout << "\n\n Player 1, its your turn!\n\n";
			player1->printBoards();

			std::string shot;

			bool valid_input = false; //Makes sure that user input is good before advancing
			while (valid_input == false){ //start input loop

				std::cout << "\n\nCoordinate to fire at: ";
				std::cin >> shot;

				if(( CheckShotInput(shot) == false) || ( std::cin.fail() )) {	//Is the user input good?
					std::cin.clear();
					std::cin.ignore();
					std::cout << "\n\nConnection to missiles lost... Please enter a valid input..\n";
					std::cout << "Valid inputs are: < A thru I > then < 1 thru 9 >\n\n";

				} else {

					if (player1->shoot(shot) == true){		//Is the shot unique?

					std::cout << "\n\n\n FIRE!!!\n\n";
					valid_input = true;

					} else {

			 		std::cout << "\n\n Captain! We have already shot at that location! \n\n";


		}}} //end input loop

		if (player1->isHit(shot) == true){	//Is it a hit?

				std::cout << "\n!!! BANG !!!\n";

			if (player1->isSunk(shot) == true){	//Is it a sunk?

				std::cout << "\nYou have sunk their ship with that shot!\n";

			} else {

				std::cout << "\nThats a hit!\n";

			}
		} else {

				std::cout << "\n *bloooop...\n.\n.\n\nMissle was off-target\n\n";

		}

		if (player1->shipsRemaining() == 0){	//   Game won condition

			std::cout << "\n\n ##########- PLAYER 1 HAS WON THE GAME!!! -##########\n\n";
			player1->printBoards();
			std::cout << "\n\n ##########- PLAYER 1 HAS WON THE GAME!!! -##########\n\n";
			end_game = true;

		}

		//------------------------------------------------------------------------------------------


	} else {			//Player 2 turn

		std::cout << "\n\n Player 2, its your turn!\n\n";
		player2->printBoards();

		std::string shot;

		bool valid_input = false; //Makes sure that user input is good before advancing
		while (valid_input == false){ //start input loop

			std::cout << "\n\nCoordinate to fire at: ";
			std::cin >> shot;

			if(( CheckShotInput(shot) == false) || ( std::cin.fail() )) {	//Is the user input good?
				std::cin.clear();
				std::cin.ignore();
				std::cout << "\n\nConnection to missiles lost... Please enter a valid input..\n";
				std::cout << "Valid inputs are: < A thru I > then < 1 thru 9 >\n\n";

			} else {

				if (player2->shoot(shot) == true){		//Is the shot unique?

				std::cout << "\n\n\n FIRE!!!\n\n";
				valid_input = true;

				} else {

				std::cout << "\n\n Captain! We have already shot at that location! \n\n";


	}}} //end input loop

	if (player2->isHit(shot) == true){	//Is it a hit?

			std::cout << "\n!!! BANG !!!\n";

		if (player2->isSunk(shot) == true){	//Is it a sunk?

			std::cout << "\nYou have sunk their ship with that shot!\n";

		} else {

			std::cout << "\nThats a hit!\n";

		}
	} else {

			std::cout << "\n *bloooop...\n.\n.\n\nMissle was off-target\n\n";

	}

	if (player2->shipsRemaining() == 0){	//   Game won condition

		std::cout << "\n\n ##########- PLAYER 2 HAS WON THE GAME!!! -##########\n\n";
		player2->printBoards();
		std::cout << "\n\n ##########- PLAYER 2 HAS WON THE GAME!!! -##########\n\n";
		end_game = true;

	}}	//end of turn selection

		if (turn == false){				//Switch turns

			turn = true;

		} else {

			turn = false;

		}
	} // end_game loop


	delete player1;	//free heap
	delete player2;
	player1 = nullptr;
	player2 = nullptr;
}

bool Client::CheckShotInput(std::string shot_check){


	if (shot_check.length() != 2){			//Is it exactly two letter long?

		return false;

	}

	char letter = shot_check[0];
	char number = shot_check[1];


	 if (( number >= '1' ) && ( number <= '9' )){

		 //compares ascii values

		 if ( (letter >= 'A' ) && ( letter <= 'I' )){	//Is the alpha within range?

	 		return true;		//Then the input is good!

	 	}
	 }

	 return false;

}



Client::Client(){ // constructor that defaults to the ship count being 3

   end_program = false;
	 end_game = false;
	 ship_count = 3;
	 turn = false;

}


Client::~Client(){	//destructor


}	//end destructor

//---------------------------------------------------------------------
