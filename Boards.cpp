#include "Boards.h"

Boards::Boards()
{
  char letters[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I"};
  char nummbers[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
  BattleBoard = new char*[sizerow];
  for (int i = 0; i < sizerow; i++)
  {
    BattleBoard[i] = new char*[sizecol];
  }
  for (int i = 0; i < sizerow; i++)
  {
    for (int j = 0; j < sizecol; j++)
    {
      if (i == 0 && j == 0)
      {
        BattleBoard[i][j] = "T";
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
        BattleBoard[i][j] = "X";
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

char Boards::getpointat(int row, int col)
{
  return(BattleBoard[row][col]);
}

void Boards::changepointat(int row, int col, char newpoint)
{
  BattleBoard[row][col] = newpoint;
}
