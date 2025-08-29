/*
 * OwnGrid.cpp
 *
 *  Created on: 22-Dec-2024
 *      Author: Dheeraj Swaroop S M
 */

#include <iostream>
#include <algorithm>
#include "OwnGrid.h"

/**
 * @brief Constructor to initialize the grid with specified dimensions.
 * Initializes the allowed ship count for each length.
 * @param rows Number of rows in the grid.
 * @param columns Number of columns in the grid.
 */
OwnGrid::OwnGrid(int rows, int columns) :
		rows(rows), columns(columns)
{
	shipCount =
	{
	{ 5, 1 },
	{ 4, 2 },
	{ 3, 3 },
	{ 2, 4 } };
}

/**
 * @brief Gets the number of rows in the grid.
 * @return Number of rows.
 */
int OwnGrid::getRows()
{
	return rows;
}

/**
 * @brief Gets the number of columns in the grid.
 * @return Number of columns.
 */
int OwnGrid::getColumns()
{
	return columns;
}

/**
 * @brief Places a ship on the grid.
 * Checks if the ship is valid, fits within the grid, does not touch other ships, and satisfies length constraints.
 * @param newShip The ship to be placed.
 * @return True if the ship is successfully placed, false otherwise.
 */
bool OwnGrid::placeShip(const Ship &newShip)
{
	if (!newShip.isValid())
	{
		return false;
	}

	// Check if the Ship Fits Within the Grid
	for (const GridPosition &pos : newShip.occupiedArea())
	{
		if (pos.getRow() < 'A' || pos.getRow() > 'A' + rows - 1)
		{
			return false;
		}
		if (pos.getColumn() < 1 || pos.getColumn() > columns)
		{
			return false;
		}
	}

	// Check ships don't touch
	std::set<GridPosition> occupiedPositions = newShip.occupiedArea();
	for (const Ship &ship : ships)
	{
		std::set<GridPosition> blockedPositions = ship.blockedArea();
		std::set<GridPosition> intersection;

		set_intersection(occupiedPositions.begin(), occupiedPositions.end(),
				blockedPositions.begin(), blockedPositions.end(),
				inserter(intersection, intersection.begin()));

		if (!intersection.empty())
		{
			return false;
		}
	}

	// Check length of new ship
	int shipLength = newShip.length();

	auto it = shipCount.find(shipLength);
	if (it == shipCount.end() || it->second <= 0)
	{
		return false;
	}

	it->second--;

	ships.push_back(newShip);

	return true;
}

/**
 * @brief Gets the list of ships placed on the grid.
 * @return A vector of Ship objects.
 */
const std::vector<Ship> OwnGrid::getShips()
{
	return ships;
}

/**
 * @brief Processes a shot fired at the grid.
 * Updates the grid with the shot's target position and determines its impact.
 * @param shot The Shot object containing the target position.
 * @return The impact of the shot (HIT, SUNKEN, or NONE).
 */
Shot::Impact OwnGrid::takeBlow(const Shot &shot)
{
	shotAt.insert(shot.getTargetPosition());

	for (const Ship &ship : ships)
	{
		std::set<GridPosition> occupiedPositions = ship.occupiedArea();

		// Check if the shot hits this ship.
		if (occupiedPositions.find(shot.getTargetPosition()) != occupiedPositions.end())
		{
			std::set<GridPosition> intersection;
			set_intersection(shotAt.begin(), shotAt.end(),
					occupiedPositions.begin(), occupiedPositions.end(),
					inserter(intersection, intersection.begin()));

			if (intersection.size() == ship.occupiedArea().size())
			{
				return Shot::SUNKEN;
			}

			return Shot::HIT;
		}
	}

	return Shot::NONE;
}

/**
 * @brief Gets the set of positions where shots have been fired.
 * @return A set of GridPosition objects.
 */
const std::set<GridPosition> OwnGrid::getShotAt()
{
	return shotAt;
}
