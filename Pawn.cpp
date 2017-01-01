/*
 * Pawn.cpp
 *
 *  Created on: Dec 30, 2016
 *      Author: helarabawy
 */

// including header file
#include "../Chess-Game/Pawn.h"


// Constructor
Pawn::Pawn(int player, Grid* grid)
{
	if (player == PLAYER_WHITE)
		m_player = 'w';
	if (player == PLAYER_BLACK)
		m_player = 'b';

	m_type = 'P';

	gridptr = grid;
}

// Destructor
Pawn::~Pawn()
{}

// Return piece's type
char Pawn::getType()
{
	return m_type;
}

// return player
char Pawn::getPlayer()
{
	return m_player;
}

// returns if a move is possible
bool Pawn::movePiece(int r1, int c1, int r2, int c2)
{
	string cell2_info = gridptr->getCellInfo(r2, c2);
	// black pawn
	if (m_player == 'b')
	{
		if (r1 == 2) //can move one or two steps in first step
		{
			if ((c1 == c2) &&
				(r2 == (r1 + 1)) &&
				(gridptr->getCellInfo(r2, c2).size() == 0))
		 		return true;

			if ((c1 == c2) &&
				(r2 == (r1 + 2)) &&
				(gridptr->getCellInfo(r1 + 1, c2).size() == 0) &&
				(gridptr->getCellInfo(r2, c2).size() == 0))
				return true;
		} else
		{
			if ((c1 == c2) &&
				(r2 == (r1 + 1)) &&
				(gridptr->getCellInfo(r2, c2).size() == 0)) //only allowed one step after that
				return true;
		}

		if (((c2 == (c1 + 1)) || (c2 == (c1 - 1))) &&
			 (r2 == (r1 - 1)) &&
			 (gridptr->getCellInfo(r2, c2).size() > 0) &&
			 (cell2_info.at(0) == 'b')) //can go diagonal if there is an opposing piece there
			return true;

		// if the move fits none of the above, return false
		return false;

	}

	if (m_player == 'w')
	{
		if (r1 == 7) //can move one or two steps in first step
		{
			if ((c1 == c2) &&
				(r2 == (r1 - 1)) &&
				(gridptr->getCellInfo(r2, c2).size() == 0))
				return true;

			if ((c1 == c2) &&
				(r2 == (r1 - 2)) &&
				(gridptr->getCellInfo(r1 - 1, c2).size() == 0) &&
				(gridptr->getCellInfo(r2, c2).size() == 0))
				return true;
		} else
		{
			if ((c1 == c2) &&
				(r2 == (r1 - 1)) &&
				(gridptr->getCellInfo(r2, c2).size() == 0)) //only allowed one step after that
				return true;
		}

		if (((c2 == (c1 + 1)) || (c2 == (c1 - 1))) &&
			 (r2 == (r1 - 1)) &&
			 (gridptr->getCellInfo(r2, c2).size() > 0) &&
			 (gridptr->getCellInfo(r2, c2).at(0) == 'b')) //can go diagonal if there is an opposing piece there
			return true;

		// if the move fits none of the above, return false
		return false;
	}
}
