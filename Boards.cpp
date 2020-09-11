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
        BattleBoard[i][j] = letters[j];
      }
      else if (j == 0)
      {
        BattleBoard[i][j] = nummbers[i];
      }
      else
      {
        BattleBoard[i][j] = 'X';
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
  std::cout << "test Boards:" << "\n";
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
  int* coordloaction = new int[2];
  coordloaction = stoiCoord(coord);
  char temp = BattleBoard[coordloaction[0]][coordloaction[1]];
  delete coordloaction;
  return(temp);
}

void Boards::changepointat(std::string coord, char newpoint)
{
  int* coordloaction = new int[2];
  coordloaction = stoiCoord(coord);
  BattleBoard[coordloaction[0]][coordloaction[1]] = newpoint;
  delete coordloaction;
}

int* Boards::stoiCoord(std::string coord)
{
	int intCoord[2];
	intCoord[0] = coord.at(0) - 65; // 'A' has ASCII value of 65
	intCoord[1] = coord.at(1) - 48; // '0' has ASCII value of 48

	return intCoord;

}
