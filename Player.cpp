#include "Player.h"







// Just made these so I could test the client


void Player::placeShips(int number_ships){

  std::cout << "Testing\n";   //remove this

}
void Player::printBoards(){

  m_ship_board.print();
  m_shoot_board.print();

}
bool Player::shoot(std::string shot){

  return true;  //remove this

}
bool Player::isHit(std::string shot){

  return false; //remove this

}
bool Player::isSunk(std::string shot){

  return false; //remove this

}
int Player::shipsRemaining(){

  return 2; //remove this

}
