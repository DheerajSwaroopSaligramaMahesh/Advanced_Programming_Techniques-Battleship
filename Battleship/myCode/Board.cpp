/*
 * Board.cpp
 *
 *  Created on: 23-Dec-2024
 *      Author: Dheeraj Swaroop S M
 */

#include "Board.h"

/**
 * @brief Constructor to initialize the board with specified dimensions.
 * Initializes both the player's grid and the opponent's grid with the same dimensions.
 * @param rows Number of rows in the board.
 * @param columns Number of columns in the board.
 */
Board::Board(int rows, int columns) :
		ownGrid(rows, columns), opponentGrid(rows, columns), rows(rows), columns(
				columns)
{
}

/**
 * @brief Gets the number of rows in the board.
 * @return Number of rows.
 */
int Board::getRows()
{
	return rows;
}

/**
 * @brief Gets the number of columns in the board.
 * @return Number of columns.
 */
int Board::getColumns()
{
	return columns;
}

/**
 * @brief Accessor for the player's grid.
 * @return Reference to the player's OwnGrid object.
 */
OwnGrid& Board::getOwnGrid()
{
	return ownGrid;
}

/**
 * @brief Accessor for the opponent's grid.
 * @return Reference to the opponent's OpponentGrid object.
 */
OpponentGrid& Board::getOpponentGrid()
{
	return opponentGrid;
}
