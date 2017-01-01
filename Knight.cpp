/*
 * Knight.cpp
 *
 *  Created on: Dec 30, 2016
 *      Author: helarabawy
 */

// including header file
#include "Knight.h"


// Constructor
Knight::Knight(char player, Grid* grid)
{
	m_player = player;
	m_type = 'P';
	gridptr = grid;
}

// Destructor
Knight::~Knight()
{
	delete gridptr;
}

// Return piece's type
char Knight::getType()
{
	return m_type;
}

// return player
char Knight::getPlayer()
{
	return m_player;
}

// returns if a move is possible
bool Knight::movePiece(int r1, int c1, int r2, int c2)
{
	// cannot remove one's own piece
	if (gridptr->getCellInfo(r2, c2).at(0) == m_player)
		return false;

	// any L shape is allowed
	if ( ((abs(r2 - r1) == 2) && (abs(c2 - c1) == 1)) ||
		 ((abs(r2 - r1) == 1) && (abs(c2 - c1) == 2)) )
		return true;

	return false;
}


