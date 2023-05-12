// #include "pawn.h"
//
//Set default constructor
Pawn::Pawn(const Position& pos, bool isWhite) : Piece() 
{
	position = pos;
	fWhite = isWhite;
	pieceType = PAWN;
}
//Get Letter on board and see what that is.
char Pawn::getLetter()
{

}
void Pawn::display(ogstream gout)
{

}

set<int> Pawn::getMoves(Board board)
{

	set<Moves> moves;

	//Need to make different delta for black or white. 
	array<Delta, 3> delta;
	if (isWhite)
	{
		Position delta[3] =
		{
			{-1,1}, {0,1}, {1,1}
			         //P
		};
	} 
	else
	{
		Position delta[3] =
		{
			           //P
			{-1,-1}, {0,-1}, {1,-1}
		}
	}

	//Might be simpler with moves = getMovesNoSlide

	//See what each position holds. 
	Position posLeftDiag((position.getRow() + delta[0].getRow(), 
		(position.getCol() + delta[0].getCol());
	Position posFront(position.getRow(), 
		(position.getCol() + delta[1].getCol()));
	Position posRightDiag((position.getRow() + delta[2].getRow(),
		(position.getCol() + delta[2].getCol());

	//How add moves into this?

	Position options[3] = { posLeftDiag, posFront, posRightDiag };

	

	
	//Has front move and normal captures.
	//Still needs to process Empassants
	

	//Set an iterator to go through options
	for (int i = 0; i < options.size(); i++) {

		//If it's a front move and nothings in the way, then add it automatically.
		if (i == 1 && board[options[i]]->getType() == SPACE) {
			
			Move move;
			move.setSrc(getPosition());
			move.setDest(option[i]);
			move.setWhiteMove(isWhite());
			move.setCastleK();
			moves.insert(move);
		}
		else
		//If the position isn't empty and the position isn't taken same color spot, then move.
		if (board[options[i]]->getType() != SPACE
			&& board[options[i]].isWhite() != board[pos].isWhite())
		{
			
			Move move;
			move.setSrc(getPosition());
			move.setDest(options[i]);
			move.setWhiteMove(isWhite());
			move.setCapture(board[posMove].getLetter());
			moves.insert(move);
			
		} 
		
		
			
	}
	return possible;
}