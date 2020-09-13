#include "Player.h"

Player::Player()
{

}

Player::~Player()
{

}

bool Player::checkValidPlacement(std::string ship_coord1, std::string ship_coord2, int ship_size)
{
	if (ship_coord1.length() + ship_coord2.length() != 4) //is it exactly 5 characters long?
  {	
		return false;
	}

	char letter1 = ship_coord1[0];
	int number1 = ship_coord1[1] - '0';
  char letter2 = ship_coord2[0];
  int number2 = ship_coord2[1] - '0';

  if ((number1 < 1) || (number1 > 9) || (number2 < 1) || (number2 > 9)) //makes sure the numbers are between 1-9
  {
    return false;
  }

  if ((letter1 < 'A') || (letter1 > 'I') || (letter2 < 'A') || (letter2 > 'I')) //are the letters within the correct range?
  {	
    return false;
  }

  //converts the letters in their integer ASCII form
  int letter1_int = letter1 - '0';
  int letter2_int = letter2 - '0';

  if ((number2-number1+1 == ship_size) && (letter1_int-letter2_int == 0)) //checks if the ship is placed vertically the right # of spaces
  {
    return true;
  }
  else if ((letter2_int-letter1_int+1 == ship_size) && (number1-number2 == 0)) //else checks if the ship is placed horizontally the right # of spaces
  {
    return true;
  }
  else //the ship must be placed diagonal, which isn't valid
  {
    return false;
  }
}

void Player::placeShips(int number_ships)
{
  std::string ship_coord1;
  std::string ship_coord2;
  bool invalid = true;
  if (number_ships == 3)
  {
    m_ship_board.print();
    std::cout << "\nTo place a ship, type its starting coordinate as one word, hit space, and then type its last coordinate as one word.\n";
    std::cout << "For example: A4 B4 is valid, A 4 B 4 is invalid, and (A,4) (B,4) is invalid.\n";
    std::cout << "\nWhere would you like to place your SIZE FOUR battleship?: ";
    std::cin >> ship_coord1;
    std::cin >> ship_coord2;
    while (!checkValidPlacement(ship_coord1, ship_coord2, 4))
    {
      std::cout << "not valid placement, try again: ";
      std::cin >> ship_coord1;
      std::cin >> ship_coord2;
      //if (ship_location)
    }
    //Ship battleship(4, );
  }
  /*
  else if (number_ships == 2)
  {
    Ship battleship(4, );
    Ship cruiser(3 , );
  }
  else if (number_ships == 3)
  {
    Ship battleship(4, );
    Ship cruiser(3, );
    Ship submarine(3, );
  }
  else if (number_ships == 4)
  {
    Ship battleship(4, );
    Ship cruiser(3, );
    Ship submarine(3, );
    Ship destroyed(2, );
  }
  else 
  {
    std::cout << "\nInvalid number of ships.\n";
    return;
  }
  m_ships_remaining = number_ships;
*/
  //needs to create as many ships as number_ships
  //then needs to let the user choose where to place these ships on the board
}

void Player::printBoards()
{
  m_ship_board.print();
  m_shoot_board.print();
}

bool Player::shoot(std::string shot)
{
  return true;  //remove this
}

bool Player::isHit(std::string shot)
{
  return false; //remove this
}

bool Player::isSunk(std::string shot)
{
  return false; //remove this
}

int Player::shipsRemaining()
{
  return 2; //remove this
}
