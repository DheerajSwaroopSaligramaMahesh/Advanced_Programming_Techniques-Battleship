/*
 * OpponenGrid.cpp
 *
 *  Created on: 23-Dec-2024
 *      Author: Dheeraj Swaroop S M
 */

#include "OpponentGrid.h"

/**
 * @brief Constructor to initialize the grid with specified dimensions.
 * @param rows Number of rows in the grid.
 * @param columns Number of columns in the grid.
 */
OpponentGrid::OpponentGrid(int rows, int columns) :
		rows(rows), columns(columns)
{
}

/**
 * @brief Gets the number of rows in the grid.
 * @return Number of rows.
 */
int OpponentGrid::getRows()
{
	return rows;
}

/**
 * @brief Gets the number of columns in the grid.
 * @return Number of columns.
 */
int OpponentGrid::getColumns()
{
	return columns;
}

/**
 * @brief Identifies and records a sunken ship starting from a specific position.
 * Searches horizontally and vertically to determine the ship's boundaries, updates the shots map, and records the sunken ship.
 * @param position The position where a ship is identified as sunken.
 */
void OpponentGrid::insertSunkenShips(const GridPosition &position)
{
	char row = position.getRow();
	int column = position.getColumn();

	std::map<GridPosition, Shot::Impact> shotsCopy = getShotsAt();

	// Check horizontally to the left
	int leftColumn = column;
	while (--leftColumn >= 1 && shotsCopy[
	{ row, leftColumn }] == Shot::Impact::HIT)
		;

	// Check horizontally to the right
	int rightColumn = column;
	while (++rightColumn <= getColumns() && shotsCopy[
	{ row, rightColumn }] == Shot::Impact::HIT)
		;

	// Check vertically upwards
	char upRow = row;
	while (--upRow >= 'A' && shotsCopy[
	{ upRow, column }] == Shot::Impact::HIT)
		;

	// Check vertically downwards
	char downRow = row;
	while (++downRow <= ('A' + getRows() - 1) && shotsCopy[
	{ downRow, column }] == Shot::Impact::HIT)
		;

	char newRow = upRow + 1;
	char newColumn = downRow - 1;
	GridPosition bow(newRow, leftColumn + 1);
	GridPosition stern(newColumn, rightColumn - 1);

	int shipLength = Ship(bow, stern).length();

	if ((row == bow.getRow() && row == stern.getRow())
			|| (column == bow.getColumn() && column == stern.getColumn()))
	{
		auto it = shipCounts.find(shipLength);
		if (it != shipCounts.end() && it->second > 0)
		{
			sunkenShips.emplace_back(bow, stern);
			it->second--;
		}
	}
	Ship s1
	{ bow, stern };
	std::set<GridPosition> sunkenShipsOccupied = s1.occupiedArea();
	for (auto &itr : sunkenShipsOccupied)
	{
		shots[itr] = Shot::Impact::SUNKEN;
	}

}

/**
 * @brief Records the result of a shot fired at the opponent's grid.
 * Updates the shot impact and identifies sunken ships if applicable.
 * @param shot The Shot object containing the target position.
 * @param impact The impact of the shot (HIT, SUNKEN, or NONE).
 */
void OpponentGrid::shotResult(const Shot &shot, Shot::Impact impact)
{
	const GridPosition targetPosition = shot.getTargetPosition();
	if (targetPosition.isValid())
	{
		shots[targetPosition] = impact;
		if (impact == Shot::Impact::SUNKEN)
		{
			insertSunkenShips(targetPosition);
		}
	}
}

/**
 * @brief Gets the map of shot positions and their impacts.
 * @return A map of GridPosition to Shot::Impact.
 */
const std::map<GridPosition, Shot::Impact>& OpponentGrid::getShotsAt()
{
	return shots;
}
