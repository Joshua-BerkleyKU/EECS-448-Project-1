/* -----------------------------------------------------------------------------
 *
 * File Name:  Client.cpp
 * Author: Darrin Ternes
 * Team: 15

 ---------------------------------------------------------------------------- */

#include <iostream>
#include "Client.h"
#include <string>

void Client::RunSetup(){

	while(end_program == false) {

		int userChoice = 0;

		std::cout << "\n\n\n\n========================\n---------{Menu}---------\n1) Start New Game of Battleship\n2) Edit Number of Ships\n3) Exit Battleship\n========================\n\nEnter your choice: ";
		std::cin >> userChoice;

		if (std::cin.fail()) {

			std::cin.clear();
			std::cin.ignore();
			std::cout << "\n\n\n\nPlease type the number to which function you would like to do\n\n";

		}

		if(userChoice == 1){	//###Start Game

			std::cout << "\n\n Starting Game with " << ship_count << " ships! \n\n";
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


		/* 			TODO -- !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

				#		Needs class "Player" to create two instances
								- Within each player should create the map and allow user to place Ships

				#	  Iterate between each players turn taking shots at opponents Boards

				#		Check for win condition after each return


		*/



}



Client::Client(){ // constructor that defaults to the ship count being 3

   end_program = false;
	 ship_count = 3;
	 turn = false;

}


Client::~Client(){	//destructor


}	//end destructor

//---------------------------------------------------------------------
