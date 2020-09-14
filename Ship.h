/**
 * @author Trey Werr
 * @date 9/7
 * @brief Header file for the Ship class.
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
		Ship(int length, std::string coord1, std::string coord2, std::string name);
		
		int getLength() const { return m_length; }

		bool isHit(std::string coord);

		int numHits() const { return m_hits; }

		bool isSunk() const;

		std::string getCoord1() const { return m_coord1; }
		std::string getCoord2() const { return m_coord2; }

		/**
		 * @return The type of ship it is. Example: "cruiser" or "destroyer".
		 */
		std::string getName() const { return m_name; }

		int* stoiCoord(std::string coord);

		std::string itosCoord(int* coord);

	private:
		int m_length;
		std::string m_coord1;
		std::string m_coord2;
		std::string m_hitLocations;
		std::string m_name;
		int m_hits;
};

#endif
