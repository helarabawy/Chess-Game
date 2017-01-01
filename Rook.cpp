/*
 * Rook.cpp
 *
 *  Created on: Dec 30, 2016
 *      Author: helarabawy
 */

// including header file
#include "../Chess-Game/Rook.h"


// Constructor
Rook::Rook(char player, Grid* grid)
{
	m_player = player;
	m_type = 'P';
	gridptr = grid;
}

// Destructor
Rook::~Rook()
{
	delete gridptr;
}

// Return piece's type
char Rook::getType()
{
	return m_type;
}

// return player
char Rook::getPlayer()
{
	return m_player;
}

// returns if a move is possible
bool Rook::movePiece(int r1, int c1, int r2, int c2)
{
	int rdiff = abs(r2 - r1);
	int cdiff = abs(c2 - c1);

	//making sure movement is vertical/horizontal
	if (rdiff > 0 && cdiff > 0)
		return false;

	//horizontal movement
	if (rdiff == 0 && cdiff > 0)
	{
		for (int i = 1; i < cdiff; i++)
		{
			if (gridptr->getCellInfo(r1, c1 + i).size() != 0)
				return false;
		}
	}

	//vertical movement
	if (rdiff > 0 && cdiff == 0)
	{
		for (int i = 1; i < rdiff; i++)
		{
			if (gridptr->getCellInfo(r1 + i, c1).size() != 0)
				return false;
		}
	}

	// cannot remove one's own piece
	if (gridptr->getCellInfo(r2, c2).at(0) == m_player)
		return false;

	return true;
}



