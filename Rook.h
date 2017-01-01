/*
* Rook.h
*
*  Created on: Dec 30, 2016
*      Author: helarabawy
*/

#ifndef ROOK_H_
#define ROOK_H_

// including Piece header
#include "../Chess-Game/Piece.h"

class Rook : public Piece
{
	public:

		// Constructor
		Rook(char player, Grid* grid);

		// Deconstructor
		~Rook();

		// Public functions
		char getType();
		char getPlayer();
		bool movePiece(int r1, int c1, int r2, int c2);

	private:

		// Private variables
		Grid* gridptr;
		char m_type;
		char m_player;
};


#endif /* ROOK_H_ */
