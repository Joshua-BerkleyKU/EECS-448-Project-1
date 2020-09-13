#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include "Boards.h"
#include "Ship.h"

class Player
{
    private:
        Boards m_ship_board;
        Boards m_shoot_board;
        std::string m_player_number;
        int m_ships_remaining;

        int m_bs_remaining; //how many character b's remain
        int m_cs_remaining; //how many c characters remain
        int m_ks_remaining; //etc.
        int m_ss_remaining;
        int m_ds_remaining;
        
        bool checkValidPlacement(std::string ship_coord1, std::string ship_coord2, int ship_size);
        void markBoard(Ship ship);

    public:
        Player();
        ~Player();
        void placeShips(int number_ships, int player_number);
        void markShot(std::string shot, bool hit);
        void printShootBoard();
        bool uniqueShot(std::string shot);
        bool isHit(std::string shot);
        bool isSunk(std::string shot);
        int shipsRemaining();
};
#endif
