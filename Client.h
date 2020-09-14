/**
 * @author Darrin Ternes
 * @date 9/12
 * @brief Header file for Client class.
 */

#ifndef CLIENT_H
#define CLIENT_H
#include <string>
#include <iostream>
#include <stdlib.h>
#include "Player.h"

class Client {

private:											

	bool end_program; 	//Returns as true if the user has decided to exit the game.
	bool end_game; 		//When a win condition has been met, this becomes trues.
	int ship_count; 	//Keeps track of how many ships the players intend to use.
	bool turn;			//False = player1, true = player2.

public:											

	/**
	 * The default constructor for Client.
	 */
	Client();										
	
	/**
	 * The destructor for Client.
	 */	
	~Client();					

	/**
	 * Runs the setup menu where the user can select to start, change the number of ships, or exit the program.
	 */						
	void RunSetup();		
	
	/**
	 * Runs the main loop of the game.
	 * Cycles between each players turns, showing them their boards, allowing them to shoot, and checking if a player has won.
	 * @param num_ships Passes how many ships the game will have (1-5).
	 */							
	void PlayGame(int num_ships);

	/**
	 * Checks that the shot input was in a valid format.
	 * @param shot_check Passes the coordinates that the user intends to shoot.
	 * @returns True if the shot is valid, false if it is invalid.
	 */
	bool CheckShotInput(std::string shot_check);
};
#endif
