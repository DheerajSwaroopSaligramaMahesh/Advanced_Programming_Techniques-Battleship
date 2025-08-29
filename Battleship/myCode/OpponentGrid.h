/*
 * OpponentGrid.h
 *
 *  Created on: 23-Dec-2024
 *      Author: Dheeraj Swaroop S M
 */

#ifndef OPPONENTGRID_H_
#define OPPONENTGRID_H_

#include <vector>
#include <map>
#include "Ship.h"
#include "Shot.h"

class OpponentGrid
{
private:
	///< Number of rows in the grid.
	int rows;

	///< Number of columns in the grid.
	int columns;

	///< Map of shot positions to their impacts.
	std::map<GridPosition, Shot::Impact> shots;

	///< List of sunken ships.
	std::vector<Ship> sunkenShips;

	///< Map of ship lengths to their remaining counts.
	std::map<int, int> shipCounts;

public:
	/**
	 * @brief Constructor to initialize the grid with specified dimensions.
	 * @param rows Number of rows in the grid.
	 * @param columns Number of columns in the grid.
	 */
	OpponentGrid(int rows, int columns);

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
	 * @brief Records the result of a shot fired at the opponent's grid.
	 * Updates the shot impact and identifies sunken ships if applicable.
	 * @param shot The Shot object containing the target position.
	 * @param impact The impact of the shot (HIT, SUNKEN, or NONE).
	 */
	void shotResult(const Shot &shot, Shot::Impact impact);

	/**
	 * @brief Gets the map of shot positions and their impacts.
	 * @return A map of GridPosition to Shot::Impact.
	 */
	const std::map<GridPosition, Shot::Impact>& getShotsAt();

	/**
	 * @brief Identifies and records a sunken ship starting from a specific position.
	 * Updates the shot map and sunken ships list.
	 * @param position The position where a ship is identified as sunken.
	 */
	void insertSunkenShips(const GridPosition &position);
};

#endif /* OPPONENTGRID_H_ */
