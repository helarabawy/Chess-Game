/*
 * Queen.cpp
 *
 *  Created on: Dec 30, 2016
 *      Author: helarabawy
 */

// including header file
#include "../Chess-Game/Queen.h"


// Constructor
Queen::Queen(char player, Grid* grid)
{
	m_player = player;
	m_type = 'P';
	gridptr = grid;
}

// Destructor
Queen::~Queen()
{
	delete gridptr;
}

// Return piece's type
char Queen::getType()
{
	return m_type;
}

// return player
char Queen::getPlayer()
{
	return m_player;
}

// returns if a move is possible
bool Queen::movePiece(int r1, int c1, int r2, int c2)
{
	int rdiff = r2 - r1;
	int cdiff = c2 - c1;

	int m, n;

	// cannot remove one's own piece
	if (gridptr->getCellInfo(r2, c2).at(0) == m_player)
		return false;

	// making sure non-horizontal/non-vertical movement is purely diagonal
	if ((abs(rdiff) > 0 && abs(cdiff) > 0) &&
		(abs(rdiff) != abs(cdiff)))
		return false;

	// horizontal movement
	if (abs(rdiff) == 0 && abs(cdiff) > 0)
	{
		for (int i = 1; i < abs(cdiff); i++)
		{
			// accounting for movement in the negative direction
			if (cdiff < 0)
				n = -1 * i;
			else
				n = i;

			if (gridptr->getCellInfo(r1, c1 + n).size() != 0)
				return false;
		}

		return true;
	}

	// vertical movement
	if (abs(rdiff) > 0 && abs(cdiff) == 0)
	{
		for (int i = 1; i < abs(rdiff); i++)
		{
			// accounting for movement in the negative direction
			if (rdiff < 0)
				m = -1 * i;
			else
				m = i;

			if (gridptr->getCellInfo(r1 + m, c1).size() != 0)
				return false;
		}

		return true;
	}

	// diagonal movement
	for (int i = 1; i < abs(rdiff); i++)
	{
		for (int j = 1; j < abs(cdiff); j++)
		{
			if (i == j)
			{
				//accounting for movement in negative direction
				if (rdiff < 0)
					m = -1 * i;
				else
					m = i;

				if (cdiff < 0)
					n = -1 * j;
				else
					n = j;

				// there shouldn't be any pieces along the path
				if (gridptr->getCellInfo(r1 + m, c1 + n).size() > 0)
					return false;
			}
		}
	}

	return true;

}
