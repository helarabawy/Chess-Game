/*
 * Queen.cpp
 *
 *  Created on: Dec 30, 2016
 *      Author: helarabawy
 */

// including header file
#include "../Chess-Game/Queen.h"


// Constructor
Queen::Queen(int player, Grid* grid)
{
	if (player == PLAYER_WHITE)
		m_player = 'w';
	if (player == PLAYER_BLACK)
		m_player = 'b';

	m_type = 'P';

	gridptr = grid;
}

// Destructor
Queen::~Queen()
{}

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
	//todo: DO MOVE
}
