/*
 * Board.h
 *
 *  Created on: 23-Dec-2024
 *      Author: Dheeraj Swaroop S M
 */

#ifndef BOARD_H_
#define BOARD_H_

#include "OwnGrid.h"
#include "OpponentGrid.h"

/**
 * @class Board
 * @brief Represents the game board, containing both the player's grid and the opponent's grid.
 */
class Board
{
private:
	///< The player's grid for managing their ships and shots received.
	OwnGrid ownGrid;

	///< The opponent's grid for tracking shots fired and sunken ships.
	OpponentGrid opponentGrid;

	///< Number of rows in the game board.
	int rows;

	///< Number of columns in the game board.
	int columns;

public:
	/**
	 * @brief Constructor to initialize the board with specified dimensions.
	 * @param rows Number of rows in the board.
	 * @param columns Number of columns in the board.
	 */
	Board(int rows, int columns);

	/**
	 * @brief Gets the number of rows in the board.
	 * @return Number of rows.
	 */
	int getRows();

	/**
	 * @brief Gets the number of columns in the board.
	 * @return Number of columns.
	 */
	int getColumns();

	/**
	 * @brief Accessor for the player's grid.
	 * @return Reference to the player's OwnGrid object.
	 */
	OwnGrid& getOwnGrid();

	/**
	 * @brief Accessor for the opponent's grid.
	 * @return Reference to the opponent's OpponentGrid object.
	 */
	OpponentGrid& getOpponentGrid();
};

#endif /* BOARD_H_ */
