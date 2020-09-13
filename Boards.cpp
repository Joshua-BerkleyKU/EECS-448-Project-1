#include "Boards.h"

Boards::Boards()
{
  //these are for the outside board for the markers
  char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
  char nummbers[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

  BattleBoard = new char*[sizerow];
  for (int i = 0; i < sizerow; i++)
  {
    BattleBoard[i] = new char[sizecol];
  }
  for (int i = 0; i < sizerow; i++)
  {
    for (int j = 0; j < sizecol; j++)
    {
      if (i == 0 && j == 0)
      {
        BattleBoard[i][j] = '_';
      }
      else if (i == 0)
      {
        BattleBoard[i][j] = letters[j-1];
      }
      else if (j == 0)
      {
        BattleBoard[i][j] = nummbers[i-1];
      }
      else
      {
        BattleBoard[i][j] = '~';
      }
    }
  }
}

Boards::~Boards()
{
  for (int i = 0; i < sizerow; i++)
  {
    delete BattleBoard[i];
  }
  delete[] BattleBoard;
}

void Boards::print()
{
  for (int i = 0; i < sizerow; i++)
  {
    for (int j = 0; j < sizecol; j++)
    {
      std::cout << BattleBoard[i][j] << " ";
    }
    std::cout << '\n';
  }
}

char Boards::getpointat(std::string coord)
{
  int intCoord[2];
  intCoord[0] = (coord[0] - 'A') + 1;
  intCoord[1] = (coord[1] - '0');
  char temp = BattleBoard[intCoord[1]][intCoord[0]];
  return temp;
}

void Boards::changepointat(std::string coord, char newpoint)
{
  int intCoord[2];
  intCoord[0] = (coord[0] - 'A') + 1;
  intCoord[1] = (coord[1] - '0');
  BattleBoard[intCoord[1]][intCoord[0]] = newpoint;
}

int* Boards::stoiCoord(std::string coord)
{
	int intCoord[2];
	intCoord[0] = coord.at(0) - 65; // 'A' has ASCII value of 65
	intCoord[1] = coord.at(1) - 48; // '0' has ASCII value of 48

	return intCoord;
}
