//#include "pawn.h"
//
////Set default constructor
//Pawn::Pawn(const Position& pos, bool isWhite) : Piece() 
//{
//	position = pos;
//	fWhite = isWhite;
//	pieceType = PAWN;
//}
//
//char Pawn::getLetter()
//{
//
//}
//void Pawn::display(ogstream gout)
//{
//
//}
//
//set<int> Pawn::getMoves(Board board)
//{
//
//	//Need to make different delta for black or white. 
//
//	Position delta[3];
//	if (isWhite)
//	{
//		Position delta[3] =
//		{
//			{-1,1}, {0,1}, {1,1}
//			         //P
//		};
//	} 
//	else
//	{
//		Position delta[3] =
//		{
//			           //P
//			{-1,-1}, {0,-1}, {1,-1}
//		}
//	}
//
//	//Might be simpler with moves = getMovesNoSlide
//
//	//See what each position holds. 
//	Position posLeftDiag((position.getRow() + delta[0].getRow(), 
//		(position.getCol() + delta[0].getCol());
//	Position posFront(position.getRow(), 
//		(position.getCol() + delta[1].getCol()));
//	Position posRightDiag((position.getRow() + delta[2].getRow(),
//		(position.getCol() + delta[2].getCol());
//
//	//How add moves into this?
//
//	Position options[3] = { posLeftDiag, posFront, posRightDiag };
//
//	//See if pawn next to you did an empassant. (numMoves = 1)
//
//	
//
//	//If the position isn't empty...
//
//	//Set an iterator to go through options
//	if((*board)[posLeftDiag]->getType() != SPACE)
//	{
//		r = posLeftDiag.getRow();
//		c = posLeftDiag.getCol();
//
//		if (amBlack && isNotBlack(board, r, c))
//			possible.insert(board, r, c);
//		else if (!amBlack && isNotWhite(board, r, c))
//			possible.insert(board, r, c);
//		else
//			assert(false), "Invalid Pawn Input";
//	}
//	return possible;
//}