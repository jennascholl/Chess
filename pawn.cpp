#include "pawn.h"
#include "board.h"
#include <iostream>
using namespace std;

// set default constructor

set<Move> Pawn::getMoves(const Board& board)
{
	set<Move> moves;
	Position posMove(getPosition(), isWhite() ? Delta(0, 1) : Delta(0, -1));
	Move move;

	// move one space
	if (posMove.isValid() && board[posMove].getLetter() == ' ')
	{
		move.setSrc(getPosition());
		move.setDest(posMove);
		move.setWhiteMove(isWhite());

		if (posMove.getRow() == 7 || posMove.getRow() == 0)
		{
			move.setPromotion();
		}		
		moves.insert(move);
	}

	// move two spaces
	if (!isMoved())
	{
		Position posMove(isWhite() ? 3 : 4, getPosition().getCol());
		Position posCheck(isWhite() ? 2 : 5, getPosition().getCol());
		if (board[posMove].getLetter() == ' ' && board[posCheck].getLetter() == ' ')
		{
			move.setSrc(getPosition());
			move.setDest(posMove);
			move.setWhiteMove(isWhite());
			moves.insert(move);
		}
	}

	int values[2] = { -1, 1 }; // left and right

	// capture a pieces
	for (auto i : values)
	{
		Position posMove(position.getRow() + (isWhite() ? 1 : -1), position.getCol() + i);
		if (posMove.isValid() && board[posMove].getLetter() != ' ' && board[posMove].isWhite() != isWhite())
		{
			move.setSrc(getPosition());
			move.setDest(posMove);
			move.setWhiteMove(isWhite());
			move.setCapture(board[posMove].getLetter());
			if (posMove.getRow() == 7 || posMove.getRow() == 0)
			{
				move.setPromotion();
			}
			moves.insert(move);
		}
	}

	// en-passant
	for (auto i : values)
	{
		Position posMove(position.getRow() + (isWhite() ? 1 : -1), position.getCol() + i);
		Position posKill(position.getRow(), position.getCol() + i);

		if (posMove.isValid() && (position.getRow() == (isWhite() ? 3 : 4)) && board[posMove].getLetter() == ' ' &&
			board[posKill].getLetter() == 'p' && board[posKill].isWhite() != isWhite() &&
			board[posKill].getNMoves() == 1 && board[posKill].justMoved(board.getCurrentMove()))
		{
			move.setSrc(getPosition());
			move.setDest(posMove);
			move.setWhiteMove(isWhite());
			move.setCapture(board[posKill].getLetter());
			move.setEnpassant();
			moves.insert(move);
		}
	}
	return moves;

}