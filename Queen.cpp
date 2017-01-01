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
	int rdiff = abs(r2 - r1);
	int cdiff = abs(c2 - c1);

	// cannot remove one's own piece
	if (gridptr->getCellInfo(r2, c2).at(0) == m_player)
		return false;

	// making sure non-horizontal/non-vertical movement is purely diagonal
	if ((rdiff > 0 && cdiff > 0) &&
		(rdiff != cdiff))
		return false;

	// horizontal movement
	if (rdiff == 0 && cdiff > 0)
	{
		for (int i = 1; i < cdiff; i++)
		{
			if (gridptr->getCellInfo(r1, c1 + i).size() != 0)
				return false;
		}

		return true;
	}

	// vertical movement
	if (rdiff > 0 && cdiff == 0)
	{
		for (int i = 1; i < rdiff; i++)
		{
			if (gridptr->getCellInfo(r1 + i, c1).size() != 0)
				return false;
		}

		return true;
	}

	// diagonal movement
	for (int i = 1; i < rdiff; i++)
	{
		for (int j = 1; j < cdiff; j++)
		{
			if (i == j)
			{
				// there shouldn't be any pieces along the path
				if (gridptr->getCellInfo(r1 + i, c1 + j).size() > 0)
					return false;
			}
		}
	}

	return true;

	//TODO: BUG!! Diagonal movement is only in positive diagonal direction

}
