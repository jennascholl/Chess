#include "king.h"

/*********************************************
 * NONDEFAULT CONSTRUCTOR
 * Create a King with a position and color
 *********************************************/
King::King(const Position & pos, bool isWhite) : Piece()
{
   position = pos;
   fWhite = isWhite;
   pieceType = KING;
}

void King::display(ogstream gout)
{
   //gout.drawKing(position, fWhite);
}

set<Move> King::getMoves(Board* board, Move move)
{
   set<Move> moves;

   Position delta[8] =
   {
      {-1,  1}, {0,  1}, {1,  1},
      {-1,  0},          {1,  0},
      {-1, -1}, {0, -1}, {1, -1}
   };

   //moves = getMovesNoSlide(board, delta);

   if (!isMoved())
   {
      Position posSpace(position.getRow(), 5);
      Position posMove(position.getRow(), 6);
      Position posRook(position.getRow(), 7);

      if ((*board)[posMove]->getType() == SPACE
         && (*board)[posSpace]->getType() == SPACE
         && (*board)[posRook]->getType() == ROOK
         && (*board)[posRook]->isMoved() == false)
      {
         Move move;
         move.setSrc(getPosition());
         move.setDest(posMove);
         move.setWhiteMove(isWhite());
         move.setCastle
      }
   }

   for (int i = 0; i < 8; i++)
   {
      r = row + moves[i].row;
      c = col + moves[i].col;
      if (amBlack && isNotBlack(board, r, c))
         possible.insert(r * 8 + c);
      if (!amBlack && isNotWhite(board, r, c))
         possible.insert(r * 8 + c);
   }
   // what about castling?
}