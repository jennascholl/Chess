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
   const Delta delta[] =
   {
      {-1, 1 }, {0, 1 }, {1, 1 },
      {-1, 0 },          {1, 0 },
      {-1, -1}, {0, -1}, {1, -1}
   };

   // make a set of valid moves using the deltas
   moves = getMovesNoSlide(board,
      delta, sizeof(delta) / sizeof(delta[0]));

   // king's castle
   if (!isMoved())
   {
      Position posSpace(position.getRow(), 5);
      Position posMove(position.getRow(), 6);
      Position posRook(position.getRow(), 7);

      // if the space between king and rook is empty and neither have moved
      if (board[posMove].getType() == SPACE
         && board[posSpace].getType() == SPACE
         && board[posRook].getType() == ROOK
         && board[posRook].isMoved() == false)
      {
        // add castling to the possible moves
         Move move;
         move.setSrc(getPosition());
         move.setDes(posMove);
         move.setWhiteMove(isWhite());
         move.setCastle(true);
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
      if (board[posMove].getType() == SPACE
         && board[posSpace1].getType() == SPACE
         && board[posRook].getType() == ROOK
         && board[posSpace2].getType() == SPACE
         && board[posRook].isMoved() == false)
      {
         // add castling to the possible moves
         Move move;
         move.setSrc(getPosition());
         move.setDes(posMove);
         move.setWhiteMove(isWhite());
         move.setCastle(false);
         moves.insert(move);
      }
   }

   return moves;
}