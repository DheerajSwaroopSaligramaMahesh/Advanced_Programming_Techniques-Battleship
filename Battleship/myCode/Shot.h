/*
 * Shot.h
 *
 *  Created on: 28-Dec-2024
 *      Author: Dheeraj Swaroop S M
 */

#ifndef SHOT_H_
#define SHOT_H_

#include "GridPosition.h"

/**
 * @class Shot
 * @brief Represents a shot fired at a specific position on the game grid.
 */
class Shot
{
private:
	///< The grid position targeted by the shot.
	GridPosition targetPosition;

public:
	/**
	 * @enum Impact
	 * @brief Describes the result of a shot fired at a target.
	 */
	enum Impact
	{
		///< No impact, shot missed.
		NONE,

		///< The shot hit a ship.
		HIT,

		///< The shot sank a ship.
		SUNKEN
	};

	/**
	 * @brief Constructs a Shot object with the specified target position.
	 * @param targetPosition The position targeted by the shot.
	 */
	Shot(GridPosition targetPosition);

	/**
	 * @brief Retrieves the target position of the shot.
	 * @return The grid position targeted by the shot.
	 */
	GridPosition getTargetPosition() const;
};

#endif /* SHOT_H_ */
