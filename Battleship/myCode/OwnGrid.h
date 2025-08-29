/*
 * OwnGrid.h
 *
 *  Created on: 22-Dec-2024
 *      Author: Dheeraj Swaroop S M
 */

#ifndef OWNGRID_H_
#define OWNGRID_H_

#include <vector>
#include <map>
#include "Ship.h"
#include "Shot.h"

/**
 * @class OwnGrid
 * @brief Represents the player's grid, managing ship placement and shots.
 */
class OwnGrid
{
private:
	///< Number of rows in the grid.
	int rows;

	///< Number of columns in the grid.
	int columns;

	///< List of ships placed on the grid.
	std::vector<Ship> ships;

	///< Map of ship lengths to their count.
	std::map<int, int> shipCount;

	///< Set of positions where shots have been fired.
	std::set<GridPosition> shotAt;

public:
	/**
	 * @brief Constructor to initialize the grid with specified dimensions.
	 * @param rows Number of rows in the grid.
	 * @param columns Number of columns in the grid.
	 */
	OwnGrid(int rows, int columns);

	/**
	 * @brief Gets the number of rows in the grid.
	 * @return Number of rows.
	 */
	int getRows();

	/**
	 * @brief Gets the number of columns in the grid.
	 * @return Number of columns.
	 */
	int getColumns();

	/**
	 * @brief Places a ship on the grid.
	 * @param newShip The ship to be placed.
	 * @return True if the ship is successfully placed, false otherwise.
	 */
	bool placeShip(const Ship &newShip);

	/**
	 * @brief Gets the list of ships placed on the grid.
	 * @return A vector of Ship objects.
	 */
	const std::vector<Ship> getShips();

	/**
	 * @brief Processes a shot fired at the grid.
	 * @param shot The Shot object containing the target position.
	 * @return The impact of the shot (HIT, SUNKEN, or NONE).
	 */
	Shot::Impact takeBlow(const Shot &shot);

	/**
	 * @brief Gets the set of positions where shots have been fired.
	 * @return A set of GridPosition objects.
	 */
	const std::set<GridPosition> getShotAt();
};

#endif /* OWNGRID_H_ */
