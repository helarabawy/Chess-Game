/*
 * Knight.cpp
 *
 *  Created on: Dec 30, 2016
 *      Author: helarabawy
 */

// including header file
#include "../Chess-Game/Knight.h"


// Constructor
Knight::Knight(int player, Grid* grid)
{
	if (player == PLAYER_WHITE)
		m_player = 'w';
	if (player == PLAYER_BLACK)
		m_player = 'b';

	m_type = 'P';

	gridptr = grid;
}

// Destructor
Knight::~Knight()
{}

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
	// any L shape is allowed
	if ( ((abs(r2 - r1) == 2) && (abs(c2 - c1) == 1)) ||
		 ((abs(r2 - r1) == 1) && (abs(c2 - c1) == 2)) )
		return true;

	return false;
}


