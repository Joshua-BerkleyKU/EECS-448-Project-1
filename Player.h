/**
 * @author Tyler Rains
 * @date 9/12
 * @brief Header file for the Player class.
 */

#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include "Boards.h"
#include "Ship.h"

class Player
{
    private:
        Boards m_ship_board;            //Contains the player's board where they placed their ships and which one of theirs has been sunk.
        Boards m_shoot_board;           //Contains where the player has shot, hit, or sunk the enemies ships.
        std::string m_player_number;    //Are they player one or player two?
        int m_ships_remaining;          //How many ships the player has remaining.

        int m_bs_remaining; //How many b's characters remain (haven't been sunk)
        int m_cs_remaining; //How many c characters remain
        int m_fs_remaining; //etc.
        int m_ss_remaining; //...
        int m_ds_remaining; //...
        
        /**
         * 	Checks if the coordinates the user entered to place a ship at is valid or not.
         *  It will be valid if the coordinates were entered in the correct format, is trying to be placed vertical or horizontal (not diagonal),
         *  and if one of their ships is not already occupying that location.
         *  @param ship_coord1 The coordinate for where their ship will begin at.
         *  @param ship_coord2 The coordinate where their ship will end at.
         *  @param ship_size How large the ship will be (sizes vary between 1 and 5).
         *  @returns True if the coordinates are valid, false if they are invalid.
         */        
        bool checkValidPlacement(std::string ship_coord1, std::string ship_coord2, int ship_size);

        /**
         * 	Marks the ships location onto the board so that the user can visually see its location.
         *  @param ship Takes in a ship, which will contain within it its' location data.
         *  @post Marks the ships location visually onto the board with the character it is marked as depending on the type of ship it is. For example, 'B' for battleship and 'F' for frigate.
         */
        void markBoard(Ship ship);

    public:

        /**
         * 	The default constructor for the Player class.
         */
        Player();

        /**
         * 	The destructor for the Player class.
         */
        ~Player();

        /**
         *  Asks the user for the coordinates of where they would like to place their ships.
         *  How many ships and the size of the ships is determined by how many ships they are playing with.
         *  @param number_ships The number of ships the players are playing with.
         *  @param player_number Is the player player number one or player number two.
         *  @post The ships will be placed onto their m_ship_board.
         */
        void placeShips(int number_ships, int player_number);

        /**
         *  If the player's shot successfully hits an enemies ship it will be marked as a hit (X), if they miss it's a miss (*).
         *  @param shot The coordinates of where the user shot at.
         *  @param hit A boolean value containing whether or not the shot was a hit (true) or a miss (false).
         *  @post The shot location will be marked as a hit (X) or a miss (*) on the player's m_shoot_board.
         */
        void markShot(std::string shot, bool hit);

        /**
         * 	Prints out the player's m_shoot_board, which is the locations of where they have shot and what the outcome has been.
         */
        void printShootBoard();

        /**
         * 	Prints out the player's m_ship_board, which is the location of their ships and what their current status are.
         */
        void printShipBoard();

        /**
         * 	Determines if the user has previously already shot at this location.
         *  @param shot A string containing the coordinates of where the player is attempting to shoot.
         *  @returns True if the player has not previously shot at that location, false if they've already shot and hit or missed.
         */
        bool uniqueShot(std::string shot);

        /**
         * 	Determines whether or not the enemies shot was a hit on one of the player's ships or not.
         *  @param shot The string containing the enemies shot attempt.
         *  @returns True if the enemies shot was successful in hitting a ship, false if not.
         */
        bool isHit(std::string shot);

        /**
         * 	Determines whether or not the shot that just hit the player's ship sunk it or not.
         *  @param shot The string containing the coordinates of the enemies shot.
         *  @returns True if the enemy just sunk one of the player's ships, false if not.
         */
        bool isSunk(std::string shot);

        /**
         * 	@returns How many ships the player has remaining that haven't been sunk.
         */
        int shipsRemaining();
};
#endif
