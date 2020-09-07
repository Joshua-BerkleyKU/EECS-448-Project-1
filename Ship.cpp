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

bool Ship::isHit(/* The coords to check */) const {
	// TODO fill in method definition once coordinate system is decided
	return false;
}

bool Ship::isSunk() const {
	return (m_hits == m_length);
}
