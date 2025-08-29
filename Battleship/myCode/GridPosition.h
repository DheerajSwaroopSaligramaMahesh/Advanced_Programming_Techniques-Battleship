/*
 * GridPosition.h
 *
 *  Created on: 20-Dec-2024
 *      Author: Dheeraj Swaroop S M
 */

#ifndef GRIDPOSITION_H_
#define GRIDPOSITION_H_

#include <string>

/**
 * @class GridPosition
 * @brief Represents a position on a grid with a row (character) and a column (integer).
 */
class GridPosition
{
private:
	/**< Row on the grid (A-Z). */
	char row;

	/**< Column on the grid (positive integer). */
	int column;

public:
	/**
	 * @brief Constructor to create a GridPosition from row and column values.
	 * @param row Character representing the row (A-Z).
	 * @param column Integer representing the column (>0).
	 */
	GridPosition(char row, int column);

	/**
	 * @brief Constructor to create a GridPosition from a string representation (e.g., "B2").
	 * @param position String representation of the grid position.
	 */
	GridPosition(std::string position);

	/**
	 * @brief Checks if the grid position is valid (row: A-Z, column > 0).
	 * @return True if valid, false otherwise.
	 */
	bool isValid() const;

	/**
	 * @brief Gets the row of the grid position.
	 * @return The row character.
	 */
	char getRow() const;

	/**
	 * @brief Gets the column of the grid position.
	 * @return The column integer.
	 */
	int getColumn() const;

	/**
	 * @brief Converts the GridPosition to its string representation.
	 * @return A string representation of the grid position.
	 */
	operator std::string() const;

	/**
	 * @brief Compares two GridPosition objects for equality.
	 * @param other Another GridPosition to compare with.
	 * @return True if equal, false otherwise.
	 */
	bool operator ==(const GridPosition &other) const;

	/**
	 * @brief Less-than operator for GridPosition (used for sorting or sets).
	 * @param other Another GridPosition to compare with.
	 * @return True if this object is less than the other.
	 */
	bool operator <(GridPosition other) const;
};

#endif /* GRIDPOSITION_H_ */
