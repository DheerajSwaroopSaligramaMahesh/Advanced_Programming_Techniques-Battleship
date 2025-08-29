/*
 * GridPosition.cpp
 *
 *  Created on: 20-Dec-2024
 *      Author: Dheeraj Swaroop S M
 */

#include <iostream>
#include "GridPosition.h"

/**
 * @brief Constructs a GridPosition object from a row and column.
 * @param row The character representing the row (A-Z).
 * @param column The integer representing the column (>0).
 */
GridPosition::GridPosition(char row, int column) :
		row(row), column(column)
{
}

/**
 * @brief Constructs a GridPosition object from a string representation (e.g., "B2").
 * @param position A string representation of the grid position.
 */
GridPosition::GridPosition(std::string position)
{
	this->row = position[0];
	if (isdigit(position[1]))
	{
		this->column = stoi(position.substr(1));
	}
	else
	{
		column = 0;
	}
}

/**
 * @brief Checks if the grid position is valid (row between A-Z and column > 0).
 * @return True if the grid position is valid, false otherwise.
 */
bool GridPosition::isValid() const
{
	if (row >= 'A' && row <= 'Z' && column > 0)
		return true;
	else
		return false;
}

/**
 * @brief Retrieves the row of the grid position.
 * @return The character representing the row.
 */
char GridPosition::getRow() const
{
	return row;
}

/**
 * @brief Retrieves the column of the grid position.
 * @return The integer representing the column.
 */
int GridPosition::getColumn() const
{
	return column;
}

/**
 * @brief Converts the GridPosition to its string representation (e.g., "B2").
 * @return A string representation of the grid position.
 */
GridPosition::operator std::string() const
{
	std::string position = std::string(1, row) + std::to_string(column);

	return position;
}

/**
 * @brief Compares two GridPosition objects for equality.
 * @param other Another GridPosition object to compare with.
 * @return True if the row and column are equal, false otherwise.
 */
bool GridPosition::operator ==(const GridPosition &other) const
{
	if (row == other.row && column == other.column)
		return true;
	else
		return false;
}

/**
 * @brief Determines the ordering of two GridPosition objects for sorting or sets.
 * @param other Another GridPosition object to compare with.
 * @return True if this GridPosition is less than the other, false otherwise.
 */
bool GridPosition::operator <(GridPosition other) const
{
	if ((row < other.row) || (row == other.row && column < other.column))
		return true;
	else
		return false;
}
