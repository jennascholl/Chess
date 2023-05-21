#include "king.h"
#include "board.h"

//
//void King::display(ogstream gout)
//{
//   //gout.drawKing(position, fWhite);
//}
//

/******************************************************************************
 * KING : GET MOVES
 * Returns all the possible moves of the king
 ******************************************************************************/
set<Move> King::getMoves(const Board& board)
{
   set<Move> moves;

   // all the possible ways the king could move
   array<Delta, 8> delta =
   {
      Delta(-1, 1),  Delta(0, 1),  Delta(1, 1),
      Delta(-1, 0),                Delta(1, 0),
      Delta(-1, -1), Delta(0, -1), Delta(1, -1)
   };

   // make a set of valid moves using the deltas
   moves = getMovesNoSlide(board, delta);

   // king's castle
   if (!isMoved())
   {
      Position posSpace(position.getRow(), 5);
      Position posMove(position.getRow(), 6);
      Position posRook(position.getRow(), 7);

      // if the space between king and rook is empty and neither have moved
      if (board[posMove].getLetter() == ' '
         && board[posSpace].getLetter() == ' '
         && board[posRook].getLetter() == 'r'
         && board[posRook].isMoved() == false)
      {
        // add castling to the possible moves
         Move move;
         move.setSrc(getPosition());
         move.setDes(posMove);
         move.setWhiteMove(isWhite());
         move.setCastleK();
         moves.insert(move);
      }
   }

   // queen's castle
   if (!isMoved())
   {
      Position posSpace1(position.getRow(), 3);
      Position posMove(position.getRow(), 2);
      Position posSpace2(position.getRow(), 1);
      Position posRook(position.getRow(), 0);

      // if the space between king and rook is empty and neither have moved
      if (board[posMove].getLetter() == ' '
         && board[posSpace1].getLetter() == ' '
         && board[posRook].getLetter() == 'r'
         && board[posSpace2].getLetter() == ' '
         && board[posRook].isMoved() == false)
      {
         // add castling to the possible moves
         Move move;
         move.setSrc(getPosition());
         move.setDes(posMove);
         move.setWhiteMove(isWhite());
         move.setCastleK();
         moves.insert(move);
      }
   }

   return moves;
}