
/**
* @author Joshua Berkley
* @date 9/7
* @brief Header file for the Boards
*/

#ifndef BOARDS_H
#define BOARDS_H
#include <iostream>

class Boards
{
  public:
	  /**
	*   @post creates a battleship board.
	*/
	  Boards();

	  /**
	*   @post Deletes the battleship board.
	*/
	  ~Boards();

	  /**
	*   @post prints the battleship board.
	*/
	  void print();

    /** @pre a string of the coords
	*   @post returns a certan point on the board.
	*/
    char getpointat(std::string coord);

    /** @pre a string of the coords and a char to change the point on the board
	*   @post changes a certan point on the board.
	*/
    void changepointat(std::string coord, char newpoint);

    /** @pre a string of the coords
	*   @post returns a array of ints that represents the points on the board
	*/
    int* stoiCoord(std::string coord);

  private:
    // the board pointer
	  char** BattleBoard = nullptr;

    int sizerow = 10;

    int sizecol = 10;
};
#endif
