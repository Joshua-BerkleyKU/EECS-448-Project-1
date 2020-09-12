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
        void placeShips(int number_ships);
        void printBoards();
        bool shoot(std::string shot);
        bool isHit(std::string shot);
        bool isSunk(std::string shot);
        int shipsRemaining();



        //void placeShips(??) -- Not sure what para for this. Should I send how many ships total
        //                  or send the size of the ship, and have multiple calls? Need more info


        //void printBoards()


        //bool shoot(std::string shot) -- returns true if shot is placed. returns false if
                        // - Shot has already been performed
                        // - Expect user input to be good (already filtered)


        //bool isHit(std::string shot) -- returns true if shot is a hit

        //bool isSunk(std::sting shot) -- returns true if sunk

        //int shipsRemaining()  --  returns number of ships NOT sunk







};
#endif
