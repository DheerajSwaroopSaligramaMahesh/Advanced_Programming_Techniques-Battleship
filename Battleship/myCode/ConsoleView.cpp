/*
 * ConsolView.cpp
 *
 *  Created on: 23-Dec-2024
 *      Author: Dheeraj Swaroop S M
 */

#include <iostream>
#include "ConsoleView.h"
#include "OwnGrid.h"

/**
 * @brief Constructor to initialize the ConsoleView with a game board.
 * @param board Pointer to the Board object representing the game.
 */
ConsoleView::ConsoleView(Board *board) :
		board(board)
{
}

/**
 * @brief Prints the current state of the game board to the console.
 *
 * The console display includes two grids:
 * - The player's grid showing ships, hits ('O'), and misses ('^').
 * - The opponent's grid showing fired shots and the results ('O', '^', or '#' for sunken ships).
 */
void ConsoleView::print()
{
	int rows = board->getRows();
	int columns = board->getColumns();

	char ownGrid[rows][columns];
	char opponentGrid[rows][columns];

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			ownGrid[i][j] = '~';
			opponentGrid[i][j] = '~';
		}
	}

	for (const Ship &ship : board->getOwnGrid().getShips())
	{
		for (const GridPosition &position : ship.occupiedArea())
		{
			int row = position.getRow() - 'A';
			int column = position.getColumn() - 1;
			ownGrid[row][column] = '#';
		}
	}

	std::cout << std::endl;

	std::set<GridPosition> shotAt = board->getOwnGrid().getShotAt();
	for (const GridPosition &eachShot : shotAt)
	{
		int row = eachShot.getRow() - 'A';
		int column = eachShot.getColumn() - 1;
		if (board->getOwnGrid().takeBlow(eachShot) == Shot::Impact::HIT)
		{
			ownGrid[row][column] = 'O';
		}
		if (board->getOwnGrid().takeBlow(eachShot) == Shot::Impact::NONE)
		{
			ownGrid[row][column] = '^';
		}
	}

	std::cout << std::endl;

	std::map<GridPosition, Shot::Impact> shots =
			board->getOpponentGrid().getShotsAt();
	for (const auto &itr : shots)
	{
		int row = itr.first.getRow() - 'A';
		int column = itr.first.getColumn() - 1;
		if (itr.second == Shot::Impact::HIT)
		{
			opponentGrid[row][column] = 'O';
		}
		if (itr.second == Shot::Impact::NONE)
		{
			opponentGrid[row][column] = '^';
		}
		if (itr.second == Shot::Impact::SUNKEN)
		{
			opponentGrid[row][column] = '#';
		}
	}

	// Print tens place row
	std::cout << "          ";
	for (int i = 1; i <= columns; i++)
	{
		if (i >= 10)
		{
			std::cout << " " << i / 10;
		}
		else
		{
			std::cout << " ";
		}
	}
	std::cout << "             ";
	for (int i = 1; i <= columns; i++)
	{
		if (i >= 10)
		{
			std::cout << " " << i / 10;
		}
		else
		{
			std::cout << " ";
		}
	}
	std::cout << std::endl;

	// Print ones place row
	std::cout << " ";
	for (int i = 1; i <= columns; i++)
	{
		std::cout << " " << i % 10;
	}
	std::cout << "    ";
	for (int i = 1; i <= columns; i++)
	{
		std::cout << " " << i % 10;
	}
	std::cout << std::endl;

	for (int i = 0; i < rows; i++)
	{
		char rowLabel = 'A' + i;
		std::cout << rowLabel << " ";
		for (int j = 0; j < columns; j++)
		{
			std::cout << ownGrid[i][j] << " ";
		}
		std::cout << "  ";
		std::cout << rowLabel << " ";
		for (int j = 0; j < columns; j++)
		{
			std::cout << opponentGrid[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
