#ifndef BOARDS_H
#define BOARDS_H
#include <iostream>
#include <fstream>

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

    /** @pre a number for the row and column, the number be between 1 and 9.
	*   @post returns a certan point on the board.
	*/
    char getpointat(int row, int col);

    /** @pre a number for the row and column, the number be between 1 and 9. also
  *   a char to change the point on the board
	*   @post changes a certan point on the board.
	*/
    void changepointat(int row, int col, char newpoint);

  private:
    // the board pointer
	  char** BattleBoard = nullptr;

    int sizerow = 10;

    int sizecol = 10;
};
#endif
