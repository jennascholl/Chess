#include "pawn.h"
#include "board.h"
#include <iostream>
using namespace std;

//Set default constructor

/*void Pawn::display(ogstream gout)
{

}*/


set<Move> Pawn::getMoves(const Board& board)
{
	set<Move> moves;

	//Need to make different delta for black or white.
	//Make it white by default
	array<Delta, 4> delta =
	{
		//ADD 2 space range!!
		Delta(-1,1), Delta(0, 1), Delta(1,1),
					Delta(0,2)
						//P
	};

	//If black, adjust the delta.
	if (fWhite == false)
	{
		delta =
		{					//P
			Delta(-1,-1), Delta(0, -1), Delta(1,-1),
						  Delta(0,-2)
		};
	}



	//See what each position holds. 
	Position posLeftDiag(position, delta[0]);
	Position posFront(position, delta[1]);
	Position posRightDiag(position, delta[2]);

	//Check for front movement
	
	if (posFront.isValid() && board[posFront].getLetter() == ' ')
	{
		Move move;
		move.setSrc(getPosition());
		move.setDest(posFront);
		move.setWhiteMove(isWhite());
		moves.insert(move);

		//Add the second spot if it's the first move.
		if (numMoves == 0)
		{
			Move move1;
			Position posTwoFront(position, delta[3]);
			move1.setSrc(getPosition());
			move1.setDest(posTwoFront);
			move1.setWhiteMove(isWhite());
			moves.insert(move1);

		}


		/*//See if can be promoted
		if (posFront.getRow() == 7 || posFront.getRow() == 0)
		{
			move.setPromotion(); //double check this line for right funciton
		}
		else
		{
			moves.insert(move);
		}*/
		
	}

	/*if (!isMoved())
	{
		pov
	}*/

	

	return moves;

}

/*set<Move> Pawn::getMoves(const Board& board)
{

	set<Move> moves;

	//Need to make different delta for black or white.
	//Make it white by default
	array<Delta, 3> delta =
	{
		Delta(-1,1), Delta(0, 1), Delta(1,1),
					Delta(0, 2)
						//P
	};
	
	//If black, adjust the delta.
	if(fWhite == false)
	{
		delta =
		{					//P
			Delta(-1,-1), Delta(0, -1), Delta(1,-1),
						  Delta(0, -2)
			
		};
	}
	


	//See what each position holds. 
	Position posLeftDiag(position, delta[0]);
	Position posFront(position, delta[1]);
	Position posRightDiag(position, delta[2]);

	array<Position,3> options = { posLeftDiag, posFront, posRightDiag };


	//Empassant positions
	Position empassantLeft(position, Delta(-1, 0));
	Position empassantRight(position, Delta(1, 0));


	//Has front move and normal captures.
	//Set an iterator to go through options
	for (int i = 0; i < options.size(); i++) {

		

		//If it's a front move and nothing's in the way, then add it automatically.
		if (i == 1 && board[options[i]].getLetter() == ' ')
		{

			Move move;
			move.setSrc(getPosition());
			move.setDest(options[i]);
			move.setWhiteMove(isWhite());
			move.setCastleK();
			moves.insert(move);
		}
		else
			//If the position isn't empty and the position isn't taken same color spot, then move.
			//board[options[i] doesnt have appropriate permission. 
			//Piece* comparePiece = board.getPiece(options[i]);

			if (board[options[i]].getLetter() != ' '
				&& board[options[i]].isWhite() != fWhite)
			{

				Move move;
				move.setSrc(getPosition());
				move.setDest(options[i]);
				move.setWhiteMove(isWhite());
				move.setCapture(board[options[i]].getLetter());
				moves.insert(move);

			}


	}

	//Empassant Check on left
	if (board[options[0]].getLetter() != ' '
		&& board[empassantLeft].isWhite() != board[position].isWhite())
	{
		Move move;
			move.setSrc(getPosition());
			move.setDest(options[0]);
			move.setWhiteMove(isWhite());
			move.setCastleK();
			moves.insert(move);
	}
	//Right empassant Check
	if (board[options[2]].getLetter() != ' '
		&& board[empassantRight].isWhite() != board[position].isWhite())
	{
		Move move;
			move.setSrc(getPosition());
			move.setDest(options[2]);
			move.setWhiteMove(isWhite());
			move.setCastleK();
			moves.insert(move);
	}

	return moves;
}*/