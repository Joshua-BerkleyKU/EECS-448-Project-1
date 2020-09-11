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

		bool isHit(std::string coord);

		int numHits() const { return m_hits; }

		bool isSunk() const;

		std::string getLocation() const { return m_location; }

		int* stoiCoord(std::string coord);

		std::string itosCoord(int* coord);

	private:
		int m_length;
		std::string m_location;
		std::string m_hitLocations;
		int m_hits;
};

#endif
