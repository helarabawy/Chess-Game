/*
 * Grid.cpp
 *
 *  Created on: Dec 22, 2016
 *      Author: helarabawy
 */

#include "Grid.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"


// Constants
const int NUM_ROWS = 8;
const int NUM_COLS = 8;

const static int SUCCESS = 0;
const static int INVALID_INPUT = 1;
const static int INVALID_MOVE = 2;

// Constructor
Grid::Grid()
{
	// setting every cell to a null pointer to start
	for (int r = 0; r < 10; r++)
	{
		for (int c = 0; c < 10; c++)
		{
			grid[r][c] = NULL;
		}
	}

	m_nWhite = 0;
	m_nBlack = 0;
}

// Destructor
Grid::~Grid()
{
	// deleting every pointer
	for (int r = 0; r < 10; r++)
		{
			for (int c = 0; c < 10; c++)
			{
				delete grid[r][c];
				grid[r][c] = NULL;
			}
		}
}

// to set up chess board
void Grid::setUp()
{
	// PAWNS
	for (int i = 1; i <= 8; i++)
	{
		grid[2][i] = new Pawn(PLAYER_BLACK, this);
		grid[7][i] = new Pawn(PLAYER_WHITE, this);
	}

	// ROOKS

		// locating black rooks
		grid[1][1] = new Rook(PLAYER_BLACK, this);
		grid[1][8] = new Rook(PLAYER_BLACK, this);

		// locating white rooks
		grid[8][1] = new Rook(PLAYER_WHITE, this);
		grid[8][8] = new Rook(PLAYER_WHITE, this);

	// KNIGHTS

		// locating black knights
		grid[1][2] = new Knight(PLAYER_BLACK, this);
		grid[1][7] = new Knight(PLAYER_BLACK, this);

		// locating white knights
		grid[8][2] = new Knight(PLAYER_WHITE, this);
		grid[8][7] = new Knight(PLAYER_WHITE, this);

	// BISHOPS

		// locating black bishops
		grid[1][3] = new Bishop(PLAYER_BLACK, this);
		grid[1][6] = new Bishop(PLAYER_BLACK, this);

		// locating white bishops
		grid[8][3] = new Bishop(PLAYER_WHITE, this);
		grid[8][6] = new Bishop(PLAYER_WHITE, this);

	// QUEENS

		// locating black queen
		grid[1][4] = new Queen(PLAYER_BLACK, this);

		// locating white queen
		grid[8][4] = new Queen(PLAYER_WHITE, this);

	// KINGS

		// locating black king
		grid[1][5] = new King(PLAYER_BLACK, this);

		// locating white king
		grid[8][5] = new King(PLAYER_WHITE, this);

	// Initializing respective piece counts
		m_nBlack = 16;
		m_nWhite = 16;
}

// to display grid
void Grid::display()
{
	char index;

	// top row
	cout << " ";
	for (int i = 0; i < NUM_COLS; i++)
	{
		index = 'a' + i;
		cout << index << "  ";
	}

	cout << endl;

	// first col of indices
	for (int i = 1; i <= NUM_ROWS; i++)
	{
		cout << i;
		for (int j = 1; j <= NUM_COLS; j++)
		{
			cout << " ";
			// content of grid
			if (grid[i][j] == NULL)
				cout << "* ";
			else
				cout << getCellInfo(i, j);
		}
		cout << endl;
	}
}

// to make a move
int Grid::makeMove(string input, int player)
{
	int r1, c1, r2, c2;
	bool hasMoved;

	// size doesn't follow syntax
	if (input.size() != 5)
	{
		return INVALID_INPUT;
	}

	// input content does not follow syntax
	if (!isalpha(input.at(0)) ||
		!isdigit(input.at(1)) ||
	    !isalpha(input.at(3)) ||
	    !isdigit(input.at(4)) ||
	    input.at(2) != ' ')
	{
		return INVALID_INPUT;
	}

	// decoding input
	r1 = input.at(1);
	c1 = tolower(input.at(0)) - 'a' + 1;

	r2 = input.at(4);
	c1 = tolower(input.at(3)) - 'a' + 1;

	// no piece at r1, c1
	if (grid[r1][c1] == NULL)
	{
		return INVALID_INPUT;
	}

	// input content moving wrong piece
	if (player != grid[r1][c1]->getPlayer())
	{
		return INVALID_INPUT;
	}

	// input content out of grid's bounds
	if (r1 < 1  || r1 > 8  ||
		c1 < 1  || c1 > 8  ||
		r2 < 1  || r2 > 8  ||
		c2 < 1  || c2 > 8)
	{
		return INVALID_INPUT;
	}

	// checking if move is valid
	hasMoved = grid[r1][c1]->movePiece(r1, c1, r2, c2);

	if (hasMoved)
	{
		if (grid[r2][c2] != NULL)
		{
			if (player == PLAYER_WHITE)
				m_nBlack--;
			if (player == PLAYER_BLACK)
				m_nWhite--;
		}
		// make move
		grid[r2][c2] = grid[r1][c1];
		grid[r1][c1] = NULL;
		return SUCCESS;
	} else
	{
		return INVALID_MOVE;
	}

}

// to return info about a certain cell
string Grid::getCellInfo(int r, int c)
{
	string info = "";

	// blank if there isn't a piece at that pos
	if (grid[r][c] == NULL)
		return info;

	// info in the form of player then type
	// ex. "bP" at in black pawn
	info += grid[r][c]->getPlayer();
	info += toupper(grid[r][c]->getType());

	return info;

}

//returns if game is over
bool Grid::isDone()
{
	if (m_nWhite == 0 || m_nBlack == 0)
		return true;
	return false;
}

//returns the winning player
string Grid::getWinner()
{
	if (m_nWhite == 0)
		return "Black";
	if (m_nBlack == 0)
		return "White";
	return "";
}
