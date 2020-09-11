#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include "Boards.h"

class Player
{
    private:
        Boards m_ship_board;
        Boards m_shoot_board; 

    public:
        void placeShips();
        void shoot();

};
#endif