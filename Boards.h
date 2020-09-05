#ifndef BOARDS_H
#define BOARDS_H
#include <iostream>
#include <fstream>

class Boards
{
  public:
	  /** @pre None.
	*   @post creates a battleship map
	*/
	  Boards();

	  /** @pre None.
	*   @post Deletes the battleship map.
	*/
	  ~Boards();

	  /** @pre None.
	*   @post prints the battleship map.
	*/
	  void print();

  private:
    // the board pointer
	  char** BattleBoard = nullptr;

    int sizerow = 10;

    int sizecol = 10;
};
#endif
