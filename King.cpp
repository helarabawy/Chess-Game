/*
 * King.cpp
 *
 *  Created on: Dec 30, 2016
 *      Author: helarabawy
 */

// including header file
#include "../Chess-Game/King.h"


// Constructor
King::King(int player, Grid* grid)
{
	if (player == PLAYER_WHITE)
		m_player = 'w';
	if (player == PLAYER_BLACK)
		m_player = 'b';

	m_type = 'P';

	gridptr = grid;
}

// Destructor
King::~King()
{}

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

	if (rdiff > 1 || cdiff > 1)
	{
		return false;
	}

	if (gridptr->getCellInfo(r2,c2).at(0) == m_player)
	{
		return false;
	}
	//todo: dont forget to check if the king is taking out a piece of the other type
	return true;
}


