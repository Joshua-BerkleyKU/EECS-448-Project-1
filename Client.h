/* -----------------------------------------------------------------------------
 *
 * File Name:  Client.h
 * Author: Darrin Ternes
 * Team: 15

 ---------------------------------------------------------------------------- */

#ifndef CLIENT_H
#define CLIENT_H
#include <string>
#include "Player.h"

class Client {

private:											//private vars

	bool end_program;
	bool end_game;
	int ship_count;
	bool turn;										//false = player1, true = player2

public:												//public vars

	Client();										//Constructor
	~Client();										//destructor
	void RunSetup();								//Actual Program Method
	void PlayGame(int num_ships);
	bool CheckShotInput(std::string shot_check);


};
//#include "Client.cpp"
#endif
//---------------------------------------------------------------------
