#include "board.h"

Board::Board(Piece* boardTemplate[8][8], ogstream& gout)
{

}

/***********************************************
 * PLACE PIECE
 * Insert a piece to the board, deleting whatever was in its place
 ************************************************/
void Board::placePiece(Piece* piece)
{
   int r = piece->getPosition().getRow();
   int c = piece->getPosition().getCol();

   delete& board[r][c];

   board[r][c] = piece;
}