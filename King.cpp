/*
 * King.cpp
 *
 *  Created on: Dec 30, 2016
 *      Author: helarabawy
 */

// including header file
#include "../Chess-Game/King.h"


// Constructor
King::King(char player, Grid* grid)
{
	m_player = player;
	m_type = 'P';
	gridptr = grid;
}

// Destructor
King::~King()
{
	delete gridptr;
}

// Return piece's type
char King::getType()
{
	return m_type;
}

// return player
char King::getPlayer()
{
	return m_player;
}

// returns if a move is possible
bool King::movePiece(int r1, int c1, int r2, int c2)
{
	int rdiff = abs(r2 - r1);
	int cdiff = abs(c2 - c1);

	// can only move one step
	if (rdiff > 1 || cdiff > 1)
	{
		return false;
	}

	// cannot remove one's own piece
	if (gridptr->getCellInfo(r2,c2).at(0) == m_player)
	{
		return false;
	}

	return true;
}


