/**
 * @author Trey Werr
 * @date 9/7
 * @brief Header file for the Ships
 */

#ifndef SHIP_H
#define SHIP_H

#include "ShipInterface.h"

class Ship : public ShipInterface
{
	public:
		/**
		 * Constructor for Ship.
		 * @param length - the length of the Ship, or how many spaces it occupies
		 * @param location - the coordinates of the spaces the Ship occupies on the board
		 */
		Ship(int length, std::string location);

		int getLength() const { return m_length; }

		// TODO fill in the correct format of coordinates when it's decided
		bool isHit(/* The coords to check */) const;

		int numHits() const { return m_hits; }

		bool isSunk() const;

		std::string getLocation() const { return m_location; }

	private:
		int m_length;
		std::string m_location;
		int m_hits;
};

#include "Ship.cpp"

#endif
