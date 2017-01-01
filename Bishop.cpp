/*
 * Bishop.cpp
 *
 *  Created on: Dec 30, 2016
 *      Author: helarabawy
 */

// including header file
#include "Bishop.h"


// Constructor
Bishop::Bishop(char player, Grid* grid)
{
	m_player = player;
	m_type = 'P';
	gridptr = grid;
}

// Destructor
Bishop::~Bishop()
{
	delete gridptr;
}

// Return piece's type
char Bishop::getType()
{
	return m_type;
}

// return player
char Bishop::getPlayer()
{
	return m_player;
}

// returns if a move is possible
bool Bishop::movePiece(int r1, int c1, int r2, int c2)
{
	// calculating horizontal and vertical movement
	int rdiff = r2 - r1;
	int cdiff = c2 - c1;

	int m, n;

	// movement must be diagonal
	if (abs(rdiff) != abs(cdiff))
		return false;


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

	// cannot remove one's own piece
	if (gridptr->getCellInfo(r2, c2).at(0) == m_player)
		return false;

	return true;

}
