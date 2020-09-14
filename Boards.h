/**
 * @author Joshua Berkley
 * @date 9/9
 * @brief Header file for the Board class.
 */

#ifndef BOARDS_H
#define BOARDS_H
#include <iostream>

class Boards
{
  public:
	/**
	 *  The default battleship board constructor.
	 */
	  Boards();

	/**
	 *  The battleship board destructor.
	 */
	  ~Boards();

	/**
	 *  Prints the battleship board to the console.
	 */
	  void print();

    /**
	 *  This method will return the character at the given coordinate. This can be used to see if at those coordinates there is a ship, sea, etc.
	 *  @param coord A string containing the coordinates in two characters: a letter between A-I (column) and a number between 1-9 (row).
	 *  @returns The corresponding character at those coordinates on the board.
	 */
    char getpointat(std::string coord);

    /**
	 * 	Given a coordinate, this method will change the board's character at that location to whatever character the user specifies.
	 *  @param coord A string containing the coordinates in two characters: a letter between A-I (column) and a number between 1-9 (row).
	 *  @param newpoint The character that the board should be updated with at those coordinates.
	 *  @post Changes the specified coordinate's character to the character of the user's choosing.
	 */
    void changepointat(std::string coord, char newpoint);

    /**
	 * 	If given a string containing coordinates in the right format, it will return the coordinates as an array of integers to be used individually.
	 *  @param coord A string containing the coordinates in two characters: a letter between A-I (column) and a number between 1-9 (row).
	 *  @returns An array (size 2) of integers with the coordinates inside.
	 */
    int* stoiCoord(std::string coord);

  private:
	char** BattleBoard = nullptr;	//The pointer to the main battleship board used. 
    int sizerow = 10;				//The row size of the board.
    int sizecol = 10;				//The column size of the board.
};
#endif
