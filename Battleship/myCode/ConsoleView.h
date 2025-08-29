/*
 * ConsoleView.h
 *
 *  Created on: 23-Dec-2024
 *      Author: Dheeraj Swaroop S M
 */

#ifndef CONSOLEVIEW_H_
#define CONSOLEVIEW_H_

#include "Board.h"

/**
 * @class ConsoleView
 * @brief Handles the display of the game board on the console.
 */
class ConsoleView
{
private:
	///< Pointer to the game board to be displayed.
	Board *board;

public:
	/**
	 * @brief Constructor to initialize the ConsoleView with a game board.
	 * @param board Pointer to the Board object representing the game.
	 */
	ConsoleView(Board *board);

	/**
	 * @brief Prints the current state of the game board to the console.
	 */
	void print();
};

#endif /* CONSOLEVIEW_H_ */
