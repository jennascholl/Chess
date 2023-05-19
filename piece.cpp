#include "piece.h"
#include "board.h"

/******************************************************************************
 * BOARD : = Operator
 * Update position for Pieces.
 ******************************************************************************/
void Piece::operator=(Position pos)
{
    this->numMoves++;

    //Update pointer position. 
    (*this).position == pos;
   
    //How set last move?
}


/******************************************************************************
 * PIECE : GET MOVES NO SLIDE
 * Returns possible moves without sliding
 ******************************************************************************/
set<Move> Piece::getMovesNoSlide(const Board & board, array<Delta, 8> deltas)
{
   set<Move> moves;
   for (auto & delta : deltas)
   {
      Position posMove(position, delta);

      if (posMove.isValid())
      {
         // if the spot is a piece of the opposite color or a space, add to moves
         if (board[posMove].isWhite() != isWhite() 
            || board[posMove].getLetter() == ' ')
         {
            Move move;
            move.setSrc(getPosition());
            move.setDest(posMove);
            move.setWhiteMove(isWhite());
            if (board[posMove].getLetter() != ' ')
            {
               move.setCapture(board[posMove].getLetter());
            }
            moves.insert(move);
         }
      }
   }
   return moves;
}

/******************************************************************************
 * PIECE : GET MOVES SLIDE
 * Returns all the possible moves with sliding
 ******************************************************************************/
set<Move> Piece::getMovesSlide(const Board& board, array<Delta, 8> deltas)
{
   set<Move> moves;
   for (Delta delta : deltas)
   {
      Position posMove(position, delta);
      // while there are no other pieces and we're still on the board, keep sliding
      while (posMove.isValid() && board[posMove].getLetter() == ' ')
      {
         Move move;
         move.setSrc(getPosition());
         move.setDest(posMove);
         move.setWhiteMove(isWhite());
         moves.insert(move);
         // adjust the position we're moving to
         posMove = Position(posMove.getRow() + delta.y, posMove.getCol() + delta.x);
      }

      // if we encounter a piece of the opposite color, add the capture to moves
      if (posMove.isValid() && board[posMove].isWhite() != fWhite && board[posMove].getLetter() != ' ')
      {
         Move move;
         move.setSrc(getPosition());
         move.setDest(posMove);
         move.setWhiteMove(isWhite());
         move.setCapture(board[position].getLetter());
         moves.insert(move);
      }
   }
   return moves;
}