/*
 * testFiles.h
 *
 *  Created on: 26-Dec-2024
 *      Author: Dheeraj Swaroop S M
 */

#ifndef TESTFILES_H_
#define TESTFILES_H_

#include <iostream>
#include <cstdlib>
#include <string>

#include "GridPosition.h"
#include "Ship.h"
#include "OwnGrid.h"
#include "OpponentGrid.h"
#include "Board.h"
#include "ConsoleView.h"
#include "Shot.h"

using namespace std;

/**
 * @brief Checks if a condition is true, and outputs a failure message if it is false.
 * @param condition The condition to check.
 * @param failedMessage The message to output if the condition is false.
 */
void assertTrue(bool condition, string failedMessage);

/**
 * @brief Runs the first set of tests for validating basic functionality.
 */
void part1tests();

/**
 * @brief Runs the second set of tests for additional game functionality.
 */
void part2tests();

/**
 * @brief Runs the third set of tests for advanced game functionality.
 */
void part3tests();

#endif /* TESTFILES_H_ */
