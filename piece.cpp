#include "piece.h"
#include "board.h"

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