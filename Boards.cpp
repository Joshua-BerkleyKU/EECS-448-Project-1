#include "Boards.h"

 Boards::Boards()
{
  Map = new char*[sizerow];
  for (int i = 0; i < sizerow; i++)
  {
    Map[i] = new char[sizecol];
  }
  for (int i = 0; i < sizerow; i++)
  {
    for (int j = 0; j < sizecol; j++)
    {
      if (i == 1)
      {
        Map[i][j] = "1";
      }
      else if (j == 1)
      {
        Map[i][j] = "A"
      }
      else
      {
        Map[i][j] = "X";
      }
    }
  }
}

void Boards::print()
{
  std::cout << "test Boards:" << "\n";
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      std::cout << Map[i][j] << " ";
    }
    std::cout << '\n';
  }
}
