/**
 * @author Trey Werr
 * @date 9/6
 * @brief Interface for the Ship class
 */

#ifndef SHIPINTERFACE_H
#define SHIPINTERFACE_H

#include <string>

class ShipInterface {
	public:
		/* Destructor */
		virtual ~ShipInterface() {}
		
		/**
		 * @return the length of the Ship
		 */
		virtual int getLength() const=0;

		/**
		 * Checks if the given coordinate is a hit on this Ship.
		 * @return true if it is a hit, false otherwise
		 */
		virtual bool isHit(/* The coords to check */) const=0;

		/**
		 * @return the number of hits on this Ship
		 */
		virtual int numHits() const=0;

		/**
		 * @return true if all the ship's spaces have been hit, false otherwise
		 */
		virtual bool isSunk() const=0;
		
		/**
		 * @return the coordinates the Ship occupies
		 */
		virtual std::string getLocation() const=0;
	
};

#endif
