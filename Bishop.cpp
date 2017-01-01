/*
 * Bishop.cpp
 *
 *  Created on: Dec 30, 2016
 *      Author: helarabawy
 */

// including header file
#include "Bishop.h"


// Constructor
Bishop::Bishop(int player, Grid* grid)
{
	if (player == PLAYER_WHITE)
		m_player = 'w';
	if (player == PLAYER_BLACK)
		m_player = 'b';

	m_type = 'P';

	gridptr = grid;
}

// Destructor
Bishop::~Bishop()
{}

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
	int rdiff = abs(r2 - r1);
	int cdiff = abs(c2 - c1);

	// movement must be diagonal
	if (rdiff != cdiff)
		return false;


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

	// cannot remove one's own piece
	if (gridptr->getCellInfo(r2, c2).at(0) == m_player)
		return false;

	return true;
}
