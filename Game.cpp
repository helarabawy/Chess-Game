/*
 * Game.cpp
 *
 *  Created on: Dec 22, 2016
 *      Author: helarabawy
 */
#include "Game.h"

// Constructor
Game::Game()
{}

// Destructor
Game::~Game()
{}

// Start game of chess
void Game::start()
{
	// declaring variables
	string input;
	char player = PLAYER_WHITE;
	int move;

	cout << "Welcome to Chess!" << endl <<
			"-----------------------------------------------------"
			<< endl << endl;

	// set up game
	chessGrid.setUp();

	while (!chessGrid.isDone())
	{
		cout << endl;

		// display grid
		chessGrid.display();

		// take user's input
		if (player == PLAYER_WHITE)
			cout << "White: Your Move: ";

		if (player == PLAYER_BLACK)
			cout << "Black: Your Move: ";

		getline(cin, input);

		// make move
		move = chessGrid.makeMove(input, player);

		// error and success messages
		switch (move)
		{
			case SUCCESS:
				{
					cout << "Valid move.";

					// switching players
					if (player == PLAYER_WHITE)
						player = PLAYER_BLACK;
					else
						player = PLAYER_WHITE;

					break;
				}
			case INVALID_INPUT:
				{ cout << "This is an invalid entry. Out of bounds or no piece where you specified."; break;}
			case INVALID_MOVE:
				{ cout << "This is an invalid move. Not an allowed move for this piece."; break; }
			default: break;
		}

		cout << endl << "-----------------------------------------------------" << endl;
	}

	// printing the winner
	if (chessGrid.isDone())
	{
		cout << "-----------------------------------------------------"
			<< chessGrid.getWinner() << "Player! YOU WON!!!!!!!!!" <<  endl
			<< endl << "-----------------------------------------------------"
			<< endl << "-----------------------------------------------------";
	}
}



