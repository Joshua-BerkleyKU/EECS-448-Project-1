/**
 * @author Trey Werr
 * @date 9/7
 * @brief Definitions for class Ship
 */

#include "Ship.h"

Ship::Ship(int length, std::string coord1, std::string coord2) {
	m_length = length;
	m_coord1 = coord1;
	m_coord2 = coord2;
	m_hits = 0;
	m_hitLocations = "";
}

bool Ship::isHit(std::string coord)
{
	bool isFound = true; //(m_location.find(coord) != std::string::npos); // Checks if coord is a substring of m_location
	
	if (isFound)
	{
		if (m_hits == 0)
		{
			// Ship has not been hit before
			m_hitLocations = coord;
			m_hits++;
		} else if (m_hitLocations.find(coord) == std::string::npos)
		{
			m_hitLocations += ' ' + coord;
			m_hits++;
		} // else the coordinate given has already been hit
	}
	return (isFound);
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
