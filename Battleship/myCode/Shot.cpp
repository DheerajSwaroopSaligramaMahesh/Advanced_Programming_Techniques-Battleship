/*
 * Shot.cpp
 *
 *  Created on: 28-Dec-2024
 *      Author: Dheeraj Swaroop S M
 */

#include "Shot.h"

/**
 * @brief Constructs a Shot object with the specified target position.
 * @param targetPosition The position targeted by the shot.
 */
Shot::Shot(GridPosition targetPosition) :
		targetPosition(targetPosition)
{
}

/**
 * @brief Retrieves the target position of the shot.
 * @return The grid position targeted by the shot.
 */
GridPosition Shot::getTargetPosition() const
{
	return targetPosition;
}
