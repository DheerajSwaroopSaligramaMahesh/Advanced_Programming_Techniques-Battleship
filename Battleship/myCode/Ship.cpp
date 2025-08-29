/*
 * Ship.cpp
 *
 *  Created on: 20-Dec-2024
 *      Author: Dheeraj Swaroop S M
 */

#include <iostream>
#include <math.h>
#include "Ship.h"

/**
 * @brief Constructs a Ship object with a given bow and stern position.
 * @param bow The GridPosition of the bow (front) of the ship.
 * @param stern The GridPosition of the stern (back) of the ship.
 */
Ship::Ship(const GridPosition &bow, const GridPosition &stern) :
		bow(bow), stern(stern)
{
}

/**
 * @brief Checks if the ship is valid based on the game rules.
 * A ship is valid if it is either horizontal or vertical and has a length between 2 and 5.
 * @return True if the ship is valid, false otherwise.
 */
bool Ship::isValid() const
{
	if (bow.getRow() == stern.getRow())
	{
		if (length() >= 2 && length() <= 5)
		{
			return true;
		}
	}
	else if (bow.getColumn() == stern.getColumn())
	{
		if (length() >= 2 && length() <= 5)
		{
			return true;
		}
	}

	return false;
}

/**
 * @brief Retrieves the bow (front) position of the ship.
 * @return The GridPosition representing the bow.
 */
GridPosition Ship::getBow() const
{
	return bow;
}

/**
 * @brief Retrieves the stern (back) position of the ship.
 * @return The GridPosition representing the stern.
 */
GridPosition Ship::getStern() const
{
	return stern;
}

/**
 * @brief Calculates the length of the ship.
 * The length is the number of grid positions the ship occupies, including bow and stern.
 * @return The integer length of the ship.
 */
int Ship::length() const
{
	int length = 0;
	if (getBow().isValid() && getStern().isValid())
	{
		if (bow.getRow() == stern.getRow())
		{
			length = abs(bow.getColumn() - stern.getColumn()) + 1;
		}
		else if (bow.getColumn() == stern.getColumn())
		{
			length = abs(bow.getRow() - stern.getRow()) + 1;
		}
	}
	return length;
}

/**
 * @brief Computes the area occupied by the ship.
 * The occupied area includes all grid positions between the bow and stern.
 * @return A set of GridPosition objects representing the occupied area.
 */
const std::set<GridPosition> Ship::occupiedArea() const
{
	std::set<GridPosition> occupiedPositions;
	if (isValid())
	{
		if (bow.getRow() == stern.getRow())
		{
			char row = bow.getRow();
			int startCol = bow.getColumn();
			int endCol = stern.getColumn();

			for (int col = startCol; col <= endCol; col++)
			{
				occupiedPositions.insert(GridPosition(row, col));
			}
		}
		else if (bow.getColumn() == stern.getColumn())
		{
			int col = bow.getColumn();
			char startRow = bow.getRow();
			char endRow = stern.getRow();

			for (char row = startRow; row <= endRow; row++)
			{
				occupiedPositions.insert(GridPosition(row, col));
			}
		}
	}

	return occupiedPositions;
}

/**
 * @brief Computes the blocked area around the ship.
 * The blocked area includes the occupied area and all adjacent grid positions.
 * @return A set of GridPosition objects representing the blocked area.
 */
const std::set<GridPosition> Ship::blockedArea() const
{
	std::set<GridPosition> blockedPositions;
	std::set<GridPosition> occupiedPositions = occupiedArea();

	int rowIndex[8] =
	{ -1, -1, -1, 0, 0, 1, 1, 1 };
	int columnIndex[8] =
	{ -1, 0, 1, -1, 1, -1, 0, 1 };

	for (const GridPosition &pos : occupiedPositions)
	{
		blockedPositions.insert(pos);
		for (unsigned int i = 0; i < (sizeof(rowIndex) / sizeof(int)); i++)
		{
			char adjacentRow = pos.getRow() + rowIndex[i];
			int adjacentColumn = pos.getColumn() + columnIndex[i];

			GridPosition adjacentPosition(adjacentRow, adjacentColumn);
			if (adjacentPosition.isValid())
			{
				blockedPositions.insert(adjacentPosition);
			}
		}
	}

	return blockedPositions;
}
