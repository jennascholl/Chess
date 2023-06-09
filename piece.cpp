#include "piece.h"
#include "board.h"

/******************************************************************************
 * BOARD : ASSIGNMENT OPERATOR - POSITION
 * Assign a piece to a new position
 ******************************************************************************/
void Piece::operator=(Position pos)
{
    position = pos;
    numMoves++;
}

/******************************************************************************
 * PIECE : GET MOVES NO SLIDE
 * Returns possible moves without sliding
 ******************************************************************************/
set<Move> Piece::getMovesNoSlide(const Board& board, const Delta deltas[], int numDeltas) const
{
   set<Move> moves;

   for (int i = 0; i < numDeltas; i++)
   {
      Position posMove(position, deltas[i]);

      if (posMove.isValid())
      {
         // if the spot is a piece of the opposite color or a space, add to moves
         if (board[posMove].isWhite() != isWhite() 
            || board[posMove].getType() == SPACE)
         {
            Move move;
            move.setSrc(getPosition());
            move.setDes(posMove);
            move.setWhiteMove(isWhite());
            if (board[posMove].getType() != SPACE)
            {
               move.setCapture(board[posMove].getType());
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
set<Move> Piece::getMovesSlide(const Board& board, const Delta deltas[], int numDeltas) const
{
   set<Move> moves;

   for (int i = 0; i < numDeltas; i++)
   {
      Position posMove(position, deltas[i]);
      // while there are no other pieces and we're still on the board, keep sliding
      while (posMove.isValid() && board[posMove].getType() == SPACE)
      {
         Move move;
         move.setSrc(getPosition());
         move.setDes(posMove);
         move.setWhiteMove(isWhite());
         moves.insert(move);
         // adjust the position we're moving to
         posMove = Position(posMove.getLocation(), deltas[i]);
      }

      // if we encounter a piece of the opposite color, add the capture to moves
      if (posMove.isValid() && board[posMove].isWhite() != fWhite && board[posMove].getType() != SPACE)
      {
         Move move;
         move.setSrc(getPosition());
         move.setDes(posMove);
         move.setWhiteMove(isWhite());
         move.setCapture(board[position].getType());
         moves.insert(move);
      }
   }
   return moves;
}