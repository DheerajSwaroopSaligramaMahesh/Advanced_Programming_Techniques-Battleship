/*
 * Ship.h
 *
 *  Created on: 20-Dec-2024
 *      Author: Dheeraj Swaroop S M
 */

#ifndef SHIP_H_
#define SHIP_H_

#include <set>
#include "GridPosition.h"

/**
 * @class Ship
 * @brief Represents a ship placed on the game grid, defined by its bow and stern positions.
 */
class Ship
{
private:
	/**< The starting position of the ship (bow). */
	GridPosition bow;

	/**< The ending position of the ship (stern). */
	GridPosition stern;

public:
	/**
	 * @brief Constructor to create a ship given its bow and stern positions.
	 * @param bow The starting position (bow) of the ship.
	 * @param stern The ending position (stern) of the ship.
	 */
	Ship(const GridPosition &bow, const GridPosition &stern);

	/**
	 * @brief Checks if the ship placement is valid (horizontal/vertical, length 2-5).
	 * @return True if the ship placement is valid, false otherwise.
	 */
	bool isValid() const;

	/**
	 * @brief Gets the bow position of the ship.
	 * @return The GridPosition representing the bow.
	 */
	GridPosition getBow() const;

	/**
	 * @brief Gets the stern position of the ship.
	 * @return The GridPosition representing the stern.
	 */
	GridPosition getStern() const;

	/**
	 * @brief Computes the length of the ship.
	 * @return The length of the ship.
	 */
	int length() const;

	/**
	 * @brief Gets all grid positions occupied by the ship.
	 * @return A set of GridPosition objects representing occupied positions.
	 */
	const std::set<GridPosition> occupiedArea() const;

	/**
	 * @brief Gets all grid positions blocked by the ship (occupied + adjacent positions).
	 * @return A set of GridPosition objects representing blocked positions.
	 */
	const std::set<GridPosition> blockedArea() const;
};

#endif /* SHIP_H_ */
