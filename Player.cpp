#include "Player.h"

Player::Player()
{
  m_ships_remaining = 0;
  m_player_number = "";
  m_bs_remaining = 100;
  m_cs_remaining = 100;
  m_fs_remaining = 100;
  m_ss_remaining = 100;
  m_ds_remaining = 100;
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

  //breaks down the coordinates into their individual parts
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

  //checks if the user has previously placed a ship at this location
  if ((m_ship_board.getpointat(ship_coord1) == 'B') || m_ship_board.getpointat(ship_coord2) == 'B')
  {
    return false;
  }
  if ((m_ship_board.getpointat(ship_coord1) == 'C') || m_ship_board.getpointat(ship_coord2) == 'C')
  {
    return false;
  }
  if ((m_ship_board.getpointat(ship_coord1) == 'S') || m_ship_board.getpointat(ship_coord2) == 'S')
  {
    return false;
  }
  if ((m_ship_board.getpointat(ship_coord1) == 'D') || m_ship_board.getpointat(ship_coord2) == 'D')
  {
    return false;
  }
  if ((m_ship_board.getpointat(ship_coord1) == 'F') || m_ship_board.getpointat(ship_coord2) == 'F')
  {
    return false;
  }        

  //converts the letters in their integer ASCII form
  int letter1_int = letter1 - '0';
  int letter2_int = letter2 - '0';

  //these if statements are necessary so the user can write coordinates forwards or backwards. Example: both A1 A5 and A5 A1 are valid. 
  if ((number2 > number1))
  {
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
  else if (number2 < number1)
  {
    if ((number1-number2+1 == ship_size) && (letter1_int-letter2_int == 0)) //checks if the ship is placed vertically the right # of spaces
    {
      return true;
    }
    else if ((letter1_int-letter2_int+1 == ship_size) && (number1-number2 == 0)) //else checks if the ship is placed horizontally the right # of spaces
    {
      return true;
    }
    else //the ship must be placed diagonal, which isn't valid
    {
      return false;
    }    
  }
  else if (letter1_int < letter2_int)
  {
    if ((number1-number2+1 == ship_size) && (letter1_int-letter2_int == 0)) //checks if the ship is placed vertically the right # of spaces
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
  else
  {
    if ((number1-number2+1 == ship_size) && (letter1_int-letter2_int == 0)) //checks if the ship is placed vertically the right # of spaces
    {
      return true;
    }
    else if ((letter1_int-letter2_int+1 == ship_size) && (number1-number2 == 0)) //else checks if the ship is placed horizontally the right # of spaces
    {
      return true;
    }
    else //the ship must be placed diagonal, which isn't valid
    {
      return false;
    }           
  }
}

void Player::markBoard(Ship ship)
{
  bool vertical = false;
  std::string coord1 = ship.getCoord1();
  std::string coord2 = ship.getCoord2();

  //breaks down the coordinates into their individual parts
  char letter1 = coord1[0];
  int number1_string = coord1[1];
	int number1 = coord1[1] - '0';
  char letter2 = coord2[0];
  int number2 = coord2[1] - '0';

  //if the letter remains the same for both coordinates that must mean it is a vertical ship
  if (letter1 == letter2)
  {
    vertical = true;
  }

  if (vertical) //the ship must be vertical
  {
    if (number1 < number2)
    {
      for (int i = 0; i < ship.getLength(); i++)
      {
        //places the correct ship type
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
        else if (ship.getName() == "frigate")
        {
          m_ship_board.changepointat(coord1, 'F');
        }                  
        coord1.pop_back();                          //if coord1 before equaled A5, it is now just A
        number1++;                                  //the number is now increased by one, so using the last comment's example, 5+1=6
        std::string num = std::to_string(number1);  //the number is now converted to a string, so "6"
        coord1 += num;                              //coord1 is now A6, as A is concatenated with 6
      }
    }
    else
    {
      for (int i = 0; i < ship.getLength(); i++)
      {
        if (ship.getName() == "battleship")
        {
          m_ship_board.changepointat(coord2, 'B');
        }
        else if (ship.getName() == "cruiser")
        {
          m_ship_board.changepointat(coord2, 'C');
        }
        else if (ship.getName() == "submarine")
        {
          m_ship_board.changepointat(coord2, 'S');
        }
        else if (ship.getName() == "destroyer")
        {
          m_ship_board.changepointat(coord2, 'D');
        }
        else if (ship.getName() == "frigate")
        {
          m_ship_board.changepointat(coord2, 'F');
        }                  
        coord2.pop_back();                          //same as the previous code but just with the letters
        number2++;
        std::string num = std::to_string(number2);
        coord2 += num;
      }
    }
  }
  else //the ship must be horizontal
  {
    if (letter1 < letter2)
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
        else if (ship.getName() == "frigate")
        {
          m_ship_board.changepointat(coord1, 'F');
        }                     
        letter1++;                      //same code as above for the letters
        coord1 = letter1;
        coord1 += number1_string;
      } 
    }
    else
    {
      for (int i = 0; i < ship.getLength(); i++)
      {
        if (ship.getName() == "battleship")
        {
          m_ship_board.changepointat(coord2, 'B');
        }
        else if (ship.getName() == "cruiser")
        {
          m_ship_board.changepointat(coord2, 'C');
        }
        else if (ship.getName() == "submarine")
        {
          m_ship_board.changepointat(coord2, 'S');
        }
        else if (ship.getName() == "destroyer")
        {
          m_ship_board.changepointat(coord2, 'D');
        }
        else if (ship.getName() == "frigate")
        {
          m_ship_board.changepointat(coord2, 'F');
        }                     
        letter2++;                  //same
        coord2 = letter2;
        coord2 += number1_string;    
      }  
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

  //prints out the board the user references to place their ships and the instructions
  m_ship_board.print();
  std::cout << "\nINSTRUCTIONS\n";
  std::cout << "To place a ship, type its starting coordinate as one word, hit space, and then type its last coordinate as one word.\n";
  std::cout << "The letter must be capitalized.\n";
  std::cout << "For example: A4 B4 is valid, a4 b4 is invalid, A 4 B 4 is invalid, and (A,4) (B,4) is invalid.\n";
  std::cout << "Remember, ships can only be placed vertically and horizontally, NOT diagonally.\n";
  std::cout << "-------------------------------------------------------------------------------\n";
  std::cout << "PLAYER " << m_player_number << ", ";

  //--------------------------------------------------------------------------------------------------------
  //Five if statements depending on how many ships the players are playing with. This determines how many ships the
  //users will be placing and what sizes they will be.
  if (number_ships == 1)
  {
    std::cout << "Where would you like to place your SIZE ONE frigate?: ";
    std::cin >> ship_coord1;
		std::cin.clear();
		std::cin.ignore(10000, '\n'); //this has to be cleared and ignored in case the user types two coordinates instead of one, so it flushes the stream   
    ship_coord2 = ship_coord1;    //so that checkValidPlacement works correctly
    while (!checkValidPlacement(ship_coord1, ship_coord2, 1)) //runs until a valid placement is made
    {
      std::cout << "That is not a valid placement, check how you typed it and the location and try again: ";
      std::cin >> ship_coord1;
      std::cin.clear();
      std::cin.ignore(10000, '\n');       
      ship_coord2 = ship_coord1;
    }
    Ship frigate(1, ship_coord1, ship_coord2, "frigate"); //creates the correct ship
    m_fs_remaining = 1; //updates how many parts of it remain
    markBoard(frigate); //marks it on the map
  }
  //--------------------------------------------------------------------------------------------------------
  //the rest of the if statements are the same as above, just with more ships
  else if (number_ships == 2)
  {
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

    std::cout << "Where would you like to place your SIZE ONE frigate?: ";
    std::cin >> ship_coord1;
		std::cin.clear();
		std::cin.ignore(10000, '\n');     
    ship_coord2 = ship_coord1;    
    while (!checkValidPlacement(ship_coord1, ship_coord2, 1))
    {
      std::cout << "That is not a valid placement, check how you typed it and the location and try again: ";
      std::cin >> ship_coord1;
      std::cin.clear();
      std::cin.ignore(10000, '\n'); 
      ship_coord2 = ship_coord1;
    }        
    Ship frigate(1, ship_coord1, ship_coord2, "frigate");
    m_fs_remaining = 1;
    markBoard(frigate);
  }
  //--------------------------------------------------------------------------------------------------------
  else if (number_ships == 3)
  {
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

    std::cout << "Where would you like to place your SIZE ONE frigate?: ";
    std::cin >> ship_coord1;
		std::cin.clear();
		std::cin.ignore(10000, '\n');     
    ship_coord2 = ship_coord1;    
    while (!checkValidPlacement(ship_coord1, ship_coord2, 1))
    {
      std::cout << "That is not a valid placement, check how you typed it and the location and try again: ";
      std::cin >> ship_coord1;
      std::cin.clear();
      std::cin.ignore(10000, '\n'); 
      ship_coord2 = ship_coord1;
    }        
    Ship frigate(1, ship_coord1, ship_coord2, "frigate");
    m_fs_remaining = 1;
    markBoard(frigate);
  }
  //--------------------------------------------------------------------------------------------------------
  else if (number_ships == 4)
  {
    std::cout << "Where would you like to place your SIZE FOUR cruiser?: ";
    std::cin >> ship_coord1;
    std::cin >> ship_coord2;
    while (!checkValidPlacement(ship_coord1, ship_coord2, 4))
    {
      std::cout << "That is not a valid placement, check how you typed it and the location and try again: ";
      std::cin >> ship_coord1;
      std::cin >> ship_coord2;
    }    
    Ship cruiser(4, ship_coord1, ship_coord2, "cruiser");
    m_cs_remaining = 4;
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

    std::cout << "Where would you like to place your SIZE ONE frigate?: ";
    std::cin >> ship_coord1;
		std::cin.clear();
		std::cin.ignore(10000, '\n');     
    ship_coord2 = ship_coord1;    
    while (!checkValidPlacement(ship_coord1, ship_coord2, 1))
    {
      std::cout << "That is not a valid placement, check how you typed it and the location and try again: ";
      std::cin >> ship_coord1;
      std::cin.clear();
      std::cin.ignore(10000, '\n'); 
      ship_coord2 = ship_coord1;
    }    
    Ship frigate(1, ship_coord1, ship_coord2, "frigate");
    m_fs_remaining = 1;
    markBoard(frigate);
    //--------------------------------------------------------------------------------------------------------
  }
  else if (number_ships == 5)
  {
    std::cout << "Where would you like to place your SIZE FIVE battleship?: ";
    std::cin >> ship_coord1;
    std::cin >> ship_coord2;
    while (!checkValidPlacement(ship_coord1, ship_coord2, 5))
    {
      std::cout << "That is not a valid placement, check how you typed it and the location and try again: ";
      std::cin >> ship_coord1;
      std::cin >> ship_coord2;
    }    
    Ship battleship(5, ship_coord1, ship_coord2, "battleship");
    m_bs_remaining = 5;
    markBoard(battleship);

    std::cout << "Where would you like to place your SIZE FOUR cruiser?: ";
    std::cin >> ship_coord1;
    std::cin >> ship_coord2;
    while (!checkValidPlacement(ship_coord1, ship_coord2, 4))
    {
      std::cout << "That is not a valid placement, check how you typed it and the location and try again: ";
      std::cin >> ship_coord1;
      std::cin >> ship_coord2;
    }        
    Ship cruiser(4, ship_coord1, ship_coord2, "cruiser"); 
    m_cs_remaining = 4;
    markBoard(cruiser);
    
    std::cout << "Where would you like to place your second SIZE THREE submarine?: ";
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

    std::cout << "Where would you like to place your SIZE ONE frigate?: ";
    std::cin >> ship_coord1;
		std::cin.clear();
		std::cin.ignore(10000, '\n');     
    ship_coord2 = ship_coord1;    
    while (!checkValidPlacement(ship_coord1, ship_coord2, 1))
    {
      std::cout << "That is not a valid placement, check how you typed it and the location and try again: ";
      std::cin >> ship_coord1;
      std::cin.clear();
      std::cin.ignore(10000, '\n'); 
      ship_coord2 = ship_coord1;
    }    
    Ship frigate(1, ship_coord1, ship_coord2, "frigate");
    m_fs_remaining = 1;
    markBoard(frigate);
    //--------------------------------------------------------------------------------------------------------    
  }
  else 
  {
    std::cout << "\nInvalid number of ships.\n";
    return;
  }
  m_ships_remaining = number_ships; //updates the ships remaining counter to however many ships the game is being played with
}

void Player::markShot(std::string shot, bool hit)
{
  if (hit)  //if the shot is a hit
  {
    m_shoot_board.changepointat(shot, 'X');
  }
  else      //if it is a miss
  {
    m_shoot_board.changepointat(shot, '*');
  }
}

void Player::printShootBoard()
{
  m_shoot_board.print();
}

void Player::printShipBoard()
{
  m_ship_board.print();
}

bool Player::uniqueShot(std::string shot)
{
  if (m_shoot_board.getpointat(shot) == '*') //if this coordinate has already been shot at and was a miss
  {
    return false;
  }
  else if (m_shoot_board.getpointat(shot) == 'X') //if already shot at and was a hit
  {
    return false;
  } 
  return true;  
}

bool Player::isHit(std::string shot)
{
  //if the player's ship was hit, it will enter the correct if statement depending on which type of ship was hit
  if (m_ship_board.getpointat(shot) == 'B')
  {
    m_ship_board.changepointat(shot, 'X'); //updates it from a B to show its been hit 
    m_bs_remaining--;                      //lowers how many B's remain on the board. When this hits 0, you know the ship has been sunk. 
    return true;
  }
  else if (m_ship_board.getpointat(shot) == 'C')
  {
    m_ship_board.changepointat(shot, 'X'); //same as above
    m_cs_remaining--;
    return true;
  }
  else if (m_ship_board.getpointat(shot) == 'F')
  {
    m_ship_board.changepointat(shot, 'X');    
    m_fs_remaining--;
    return true;
  }
  else if (m_ship_board.getpointat(shot) == 'S')
  {
    m_ship_board.changepointat(shot, 'X');    
    m_ss_remaining--;
    return true;
  }
  else if (m_ship_board.getpointat(shot) == 'D')
  {
    m_ship_board.changepointat(shot, 'X');    
    m_ds_remaining--;
    return true;
  }      
  return false;
}

bool Player::isSunk(std::string shot)
{
  //if there are no more parts of a certain ship left un-hit, then it will be sunk.
  if (m_bs_remaining == 0)
  {
    m_bs_remaining = 100;
    m_ships_remaining--; //decrements the ships remaining counter since a ship has been sunk
    return true;
  }
  else if (m_cs_remaining == 0)
  {
    m_cs_remaining = 100;
    m_ships_remaining--;
    return true;
  }
  else if (m_fs_remaining == 0)
  {
    m_fs_remaining = 100;
    m_ships_remaining--;
    return true;
  }
  else if (m_ss_remaining == 0)
  {
    m_ss_remaining = 100;
    m_ships_remaining--;
    return true;
  }
  else if (m_ds_remaining == 0)
  {
    m_ds_remaining = 100;
    m_ships_remaining--;
    return true;
  }      
  return false;
}

int Player::shipsRemaining()
{
  return m_ships_remaining; 
}
