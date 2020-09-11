/**
 * @author Trey Werr
 * @date 9/7
 * @brief Definitions for class Ship
 */

#include "Ship.h"

Ship::Ship(int length, std::string location) {
	m_length = length;
	m_location = location;
	m_hits = 0;
}

bool Ship::isHit(std::string coord) const {
	// TODO track number of hits
	std::size_t found = m_location.find(coord);
	return (found != std::string::npos);
}

bool Ship::isSunk() const {
	return (m_hits == m_length);
}

int* Ship::stoiCoord(std::string coord) {
	int intCoord[2];
	
	intCoord[0] = coord.at(0) - 65; // 'A' has ASCII value of 65
	intCoord[1] = coord.at(1) - 48; // '0' has ASCII value of 48

	return intCoord;

}

std::string Ship::itosCoord(int* coord) {
	std::string strCoord = "";

	strCoord += (char)(coord[0]+65);
	strCoord += (char)(coord[1]+48);

	return strCoord;
}
