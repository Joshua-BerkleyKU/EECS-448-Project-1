#include "Player.h"

Player::Player()
{
  m_ships_remaining = 0;
  m_player_number = "";
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

  if ((m_ship_board.getpointat(ship_coord1) == 'S') || m_ship_board.getpointat(ship_coord2) == 'S')
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

void Player::markBoard(Ship ship)
{
  bool vertical = false;
  std::string coord1 = ship.getCoord1();
  std::string coord2 = ship.getCoord2();

  char letter1 = coord1[0];
  int number1_string = coord1[1];
	int number1 = coord1[1] - '0';
  char letter2 = coord2[0];
  if (letter1 == letter2)
  {
    vertical = true;
  }

  if (vertical) //the ship must be vertical
  {
    for (int i = 0; i < ship.getLength(); i++)
    {
      if (ship.getName() == "battleship")
      {
        m_ship_board.changepointat(coord1, 'B');
      }
      else if (ship.getName() == "cruiser")
      {
        m_ship_board.changepointat(coord1, 'C');
      }
      else if (ship.getName() == "submarine")
      {
        m_ship_board.changepointat(coord1, 'S');
      }
      else if (ship.getName() == "destroyer")
      {
        m_ship_board.changepointat(coord1, 'D');
      }
      else if (ship.getName() == "cruiser2")
      {
        m_ship_board.changepointat(coord1, 'K');
      }                  
      coord1.pop_back();
      number1++;
      std::string num = std::to_string(number1);
      coord1 += num;
    }
  }
  else //the ship must be horizontal
  {
    for (int i = 0; i < ship.getLength(); i++)
    {
      if (ship.getName() == "battleship")
      {
        m_ship_board.changepointat(coord1, 'B');
      }
      else if (ship.getName() == "cruiser")
      {
        m_ship_board.changepointat(coord1, 'C');
      }
      else if (ship.getName() == "submarine")
      {
        m_ship_board.changepointat(coord1, 'S');
      }
      else if (ship.getName() == "destroyer")
      {
        m_ship_board.changepointat(coord1, 'D');
      }
      else if (ship.getName() == "cruiser2")
      {
        m_ship_board.changepointat(coord1, 'K');
      }                     
      letter1++;
      coord1 = letter1;
      coord1 += number1_string;
    } 
  }
}

void Player::placeShips(int number_ships, int player_number)
{
  std::string ship_coord1;
  std::string ship_coord2;

  if (player_number == 1)
  {
    m_player_number = "ONE";
  }
  else
  {
    m_player_number = "TWO";
  }

  m_ship_board.print();
  std::cout << "\nINSTRUCTIONS\n";
  std::cout << "To place a ship, type its starting coordinate as one word, hit space, and then type its last coordinate as one word.\n";
  std::cout << "The letter must be capitalized.\n";
  std::cout << "For example: A4 B4 is valid, a4 b4 is invalid, A 4 B 4 is invalid, and (A,4) (B,4) is invalid.\n";
  std::cout << "Remember, ships can only be placed vertically and horizontally, NOT diagonally.\n";
  std::cout << "-------------------------------------------------------------------------------\n";
  std::cout << "PLAYER " << m_player_number << ", ";

  //--------------------------------------------------------------------------------------------------------
  if (number_ships == 1)
  {
    std::cout << "Where would you like to place your SIZE FOUR battleship?: ";
    std::cin >> ship_coord1;
    std::cin >> ship_coord2;
    while (!checkValidPlacement(ship_coord1, ship_coord2, 4))
    {
      std::cout << "That is not a valid placement, check how you typed it and the location and try again: ";
      std::cin >> ship_coord1;
      std::cin >> ship_coord2;
    }
    Ship battleship(4, ship_coord1, ship_coord2, "battleship");
    m_bs_remaining = 4;
    markBoard(battleship);
  }
  //--------------------------------------------------------------------------------------------------------
  else if (number_ships == 2)
  {
    std::cout << "Where would you like to place your SIZE FOUR battleship?: ";
    std::cin >> ship_coord1;
    std::cin >> ship_coord2;
    while (!checkValidPlacement(ship_coord1, ship_coord2, 4))
    {
      std::cout << "That is not a valid placement, check how you typed it and the location and try again: ";
      std::cin >> ship_coord1;
      std::cin >> ship_coord2;
    }    
    Ship battleship(4, ship_coord1, ship_coord2, "battleship");
    m_bs_remaining = 4;    
    markBoard(battleship);

    std::cout << "Where would you like to place your SIZE THREE cruiser?: ";
    std::cin >> ship_coord1;
    std::cin >> ship_coord2;
    while (!checkValidPlacement(ship_coord1, ship_coord2, 3))
    {
      std::cout << "That is not a valid placement, check how you typed it and the location and try again: ";
      std::cin >> ship_coord1;
      std::cin >> ship_coord2;
    }        
    Ship cruiser(3, ship_coord1, ship_coord2, "cruiser");
    m_cs_remaining = 3;
    markBoard(cruiser);
  }
  //--------------------------------------------------------------------------------------------------------
  else if (number_ships == 3)
  {
    std::cout << "Where would you like to place your SIZE FOUR battleship?: ";
    std::cin >> ship_coord1;
    std::cin >> ship_coord2;
    while (!checkValidPlacement(ship_coord1, ship_coord2, 4))
    {
      std::cout << "That is not a valid placement, check how you typed it and the location and try again: ";
      std::cin >> ship_coord1;
      std::cin >> ship_coord2;
    }    
    Ship battleship(4, ship_coord1, ship_coord2, "battleship");
    m_bs_remaining = 4;
    markBoard(battleship);

    std::cout << "Where would you like to place your SIZE THREE cruiser?: ";
    std::cin >> ship_coord1;
    std::cin >> ship_coord2;
    while (!checkValidPlacement(ship_coord1, ship_coord2, 3))
    {
      std::cout << "That is not a valid placement, check how you typed it and the location and try again: ";
      std::cin >> ship_coord1;
      std::cin >> ship_coord2;
    }        
    Ship cruiser(3, ship_coord1, ship_coord2, "cruiser"); 
    m_cs_remaining = 3;
    markBoard(cruiser);   

    std::cout << "Where would you like to place your SIZE THREE submarine?: ";
    std::cin >> ship_coord1;
    std::cin >> ship_coord2;
    while (!checkValidPlacement(ship_coord1, ship_coord2, 3))
    {
      std::cout << "That is not a valid placement, check how you typed it and the location and try again: ";
      std::cin >> ship_coord1;
      std::cin >> ship_coord2;
    }        
    Ship submarine(3, ship_coord1, ship_coord2, "submarine");
    m_ss_remaining = 3;
    markBoard(submarine);
  }
  //--------------------------------------------------------------------------------------------------------
  else if (number_ships == 4)
  {
    std::cout << "Where would you like to place your SIZE FOUR battleship?: ";
    std::cin >> ship_coord1;
    std::cin >> ship_coord2;
    while (!checkValidPlacement(ship_coord1, ship_coord2, 4))
    {
      std::cout << "That is not a valid placement, check how you typed it and the location and try again: ";
      std::cin >> ship_coord1;
      std::cin >> ship_coord2;
    }    
    Ship battleship(4, ship_coord1, ship_coord2, "battleship");
    m_bs_remaining = 4;
    markBoard(battleship);

    std::cout << "Where would you like to place your SIZE THREE cruiser?: ";
    std::cin >> ship_coord1;
    std::cin >> ship_coord2;
    while (!checkValidPlacement(ship_coord1, ship_coord2, 3))
    {
      std::cout << "That is not a valid placement, check how you typed it and the location and try again: ";
      std::cin >> ship_coord1;
      std::cin >> ship_coord2;
    }        
    Ship cruiser(3, ship_coord1, ship_coord2, "cruiser"); 
    m_cs_remaining = 3;
    markBoard(cruiser);   

    std::cout << "Where would you like to place your SIZE THREE submarine?: ";
    std::cin >> ship_coord1;
    std::cin >> ship_coord2;
    while (!checkValidPlacement(ship_coord1, ship_coord2, 3))
    {
      std::cout << "That is not a valid placement, check how you typed it and the location and try again: ";
      std::cin >> ship_coord1;
      std::cin >> ship_coord2;
    }        
    Ship submarine(3, ship_coord1, ship_coord2, "submarine");
    m_ss_remaining = 3;
    markBoard(submarine);

    std::cout << "Where would you like to place your SIZE TWO destroyer?: ";
    std::cin >> ship_coord1;
    std::cin >> ship_coord2;
    while (!checkValidPlacement(ship_coord1, ship_coord2, 2))
    {
      std::cout << "That is not a valid placement, check how you typed it and the location and try again: ";
      std::cin >> ship_coord1;
      std::cin >> ship_coord2;
    }    
    Ship destroyer(2, ship_coord1, ship_coord2, "destroyer");
    m_ds_remaining = 2;
    markBoard(destroyer);
    //--------------------------------------------------------------------------------------------------------
  }
  else if (number_ships == 5)
  {
    std::cout << "Where would you like to place your SIZE FOUR battleship?: ";
    std::cin >> ship_coord1;
    std::cin >> ship_coord2;
    while (!checkValidPlacement(ship_coord1, ship_coord2, 4))
    {
      std::cout << "That is not a valid placement, check how you typed it and the location and try again: ";
      std::cin >> ship_coord1;
      std::cin >> ship_coord2;
    }    
    Ship battleship(4, ship_coord1, ship_coord2, "battleship");
    m_bs_remaining = 4;
    markBoard(battleship);

    std::cout << "Where would you like to place your SIZE THREE cruiser?: ";
    std::cin >> ship_coord1;
    std::cin >> ship_coord2;
    while (!checkValidPlacement(ship_coord1, ship_coord2, 3))
    {
      std::cout << "That is not a valid placement, check how you typed it and the location and try again: ";
      std::cin >> ship_coord1;
      std::cin >> ship_coord2;
    }        
    Ship cruiser(3, ship_coord1, ship_coord2, "cruiser"); 
    m_cs_remaining = 3;
    markBoard(cruiser);
    
    std::cout << "Where would you like to place your second SIZE THREE cruiser?: ";
    std::cin >> ship_coord1;
    std::cin >> ship_coord2;
    while (!checkValidPlacement(ship_coord1, ship_coord2, 3))
    {
      std::cout << "That is not a valid placement, check how you typed it and the location and try again: ";
      std::cin >> ship_coord1;
      std::cin >> ship_coord2;
    }        
    Ship cruiser2(3, ship_coord1, ship_coord2, "cruiser2"); 
    m_ks_remaining = 3;
    markBoard(cruiser2);          

    std::cout << "Where would you like to place your SIZE THREE submarine?: ";
    std::cin >> ship_coord1;
    std::cin >> ship_coord2;
    while (!checkValidPlacement(ship_coord1, ship_coord2, 3))
    {
      std::cout << "That is not a valid placement, check how you typed it and the location and try again: ";
      std::cin >> ship_coord1;
      std::cin >> ship_coord2;
    }        
    Ship submarine(3, ship_coord1, ship_coord2, "submarine");
    m_ss_remaining = 3;
    markBoard(submarine);

    std::cout << "Where would you like to place your SIZE TWO destroyer?: ";
    std::cin >> ship_coord1;
    std::cin >> ship_coord2;
    while (!checkValidPlacement(ship_coord1, ship_coord2, 2))
    {
      std::cout << "That is not a valid placement, check how you typed it and the location and try again: ";
      std::cin >> ship_coord1;
      std::cin >> ship_coord2;
    }    
    Ship destroyer(2, ship_coord1, ship_coord2, "destroyer");
    m_ds_remaining = 2;
    markBoard(destroyer);
    //--------------------------------------------------------------------------------------------------------    
  }
  else 
  {
    std::cout << "\nInvalid number of ships.\n";
    return;
  }
  m_ships_remaining = number_ships;
}

void Player::markShot(std::string shot, bool hit)
{
  if (hit)
  {
    m_shoot_board.changepointat(shot, 'X');
  }
  else
  {
    m_shoot_board.changepointat(shot, '*');
  }
}

void Player::printShootBoard()
{
  m_shoot_board.print();
}

bool Player::uniqueShot(std::string shot)
{
  if (m_shoot_board.getpointat(shot) == '*')
  {
    return false;
  }
  else if (m_shoot_board.getpointat(shot) == 'X')
  {
    return false;
  } 
  return true;  
}

bool Player::isHit(std::string shot)
{
  if (m_ship_board.getpointat(shot) == 'B')
  {
    m_bs_remaining--;
    return true;
  }
  else if (m_ship_board.getpointat(shot) == 'C')
  {
    m_cs_remaining--;
    return true;
  }
  else if (m_ship_board.getpointat(shot) == 'K')
  {
    m_ks_remaining--;
    return true;
  }
  else if (m_ship_board.getpointat(shot) == 'S')
  {
    m_ss_remaining--;
    return true;
  }
  else if (m_ship_board.getpointat(shot) == 'D')
  {
    m_ds_remaining--;
    return true;
  }      
  return false;
}

bool Player::isSunk(std::string shot)
{
  if (m_bs_remaining == 0)
  {
    m_ships_remaining--;
    return true;
  }
  else if (m_cs_remaining == 0)
  {
    m_ships_remaining--;
    return true;
  }
  else if (m_ks_remaining == 0)
  {
    m_ships_remaining--;
    return true;
  }
  else if (m_ss_remaining == 0)
  {
    m_ships_remaining--;
    return true;
  }
  else if (m_ds_remaining == 0)
  {
    m_ships_remaining--;
    return true;
  }      
  return false;
}

int Player::shipsRemaining()
{
  return m_ships_remaining; 
}
