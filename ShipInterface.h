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
		 * @param coord - the coordinate to check given as a string (e.g. "A2")
		 * @return true if it is a hit, false otherwise
		 */
		virtual bool isHit(std::string coord) const=0;

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

		/**
		 * Takes in a single coordinate as a string and returns it as a pair of ints.
		 * @param coord - the coordinate formatted as a string
		 * @return the coordinate as a pair of ints, inside an array of length 2
		 */
		virtual int* stoiCoord(std::string coord)=0;

		/**
		 * Takes in a single coordinate as a pair of ints and returns it as a string.
		 * @param coord - the coordinate formatted as a pair of ints in an array of length 2
		 * @return the coordinate as a string
		 */
		virtual std::string itosCoord(int* coord)=0;
	
};

#endif
