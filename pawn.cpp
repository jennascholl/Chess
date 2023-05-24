#include "pawn.h"
#include "board.h"
#include <iostream>
using namespace std;

// set default constructor

/******************************************************************************
 * PAWN : GET MOVES
 * Returns all the possible moves of the pawn
 ******************************************************************************/
set<Move> Pawn::getMoves(const Board& board)
{
	set<Move> moves;
	Position posMove(getPosition(), isWhite() ? Delta({ 1, 0 }) : Delta({ -1, 0 }));

	// move one space
	if (posMove.isValid() && board[posMove].getType() == SPACE)
	{
		Move move;
		move.setSrc(getPosition());
		move.setDes(posMove);
		move.setWhiteMove(isWhite());

		if (posMove.getRow() == (isWhite() ? 7 : 0))
		{
			move.setPromote(QUEEN);
		}		
		moves.insert(move);
	}

	// move two spaces
	if (!isMoved())
	{
		Position posMove(isWhite() ? 3 : 4, getPosition().getCol());
		Position posCheck(isWhite() ? 2 : 5, getPosition().getCol());

		if (board[posMove].getType() == SPACE && board[posCheck].getType() == SPACE)
		{
			Move move;
			move.setSrc(getPosition());
			move.setDes(posMove);
			move.setWhiteMove(isWhite());
			moves.insert(move);
		}
	}

	int values[2] = { -1, 1 }; // left and right

	// capture a pieces
	for (auto i : values)
	{
		Position posMove(position.getRow() + (isWhite() ? 1 : -1), position.getCol() + i);
		if (posMove.isValid() && board[posMove].getType() != SPACE && board[posMove].isWhite() != isWhite())
		{
			Move move;
			move.setSrc(getPosition());
			move.setDes(posMove);
			move.setWhiteMove(isWhite());
			move.setCapture(board[posMove].getType());
			if (posMove.getRow() == 7 || posMove.getRow() == 0)
			{
				move.setPromote(QUEEN);
			}
			moves.insert(move);
		}
	}

	// en-passant
	for (auto i : values)
	{
		Position posMove(position.getRow() + (isWhite() ? 1 : -1), position.getCol() + i);
		Position posKill(position.getRow(), position.getCol() + i);

		if (posMove.isValid() && (position.getRow() == (isWhite() ? 3 : 4)) && board[posMove].getType() == SPACE &&
			board[posKill].getType() == PAWN && board[posKill].isWhite() != isWhite() &&
			board[posKill].getNMoves() == 1 && board[posKill].justMoved(board.getCurrentMove()))
		{
			Move move;
			move.setSrc(getPosition());
			move.setDes(posMove);
			move.setWhiteMove(isWhite());
			move.setCapture(board[posKill].getType());
			move.setEnPassant();
			moves.insert(move);
		}
	}
	return moves;

}