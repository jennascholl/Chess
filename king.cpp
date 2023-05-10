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

   //Meant to calculate each potential location 
   // immedately around the king. 
   Position delta[8] =
   {
      {-1,  1}, {0,  1}, {1,  1},
      {-1,  0},          {1,  0},
      {-1, -1}, {0, -1}, {1, -1}
   };

   //Make array of moves immediately around king. 
   //moves = getMovesNoSlide(board, delta);

   //If the king hasn't moved, and the rook has
   //2 open spaces and hasn't moved, then you can castle.
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
        //Move the king to the new castling position. 
         Move move;
         move.setSrc(getPosition());
         move.setDest(posMove);
         move.setWhiteMove(isWhite());
         move.setCastle
      }
   }

   //For each move in delta, 
   for (int i = 0; i < 8; i++)
   {
      //Add appropriate modifiers to each location. 
      r = row + moves[i].row;
      c = col + moves[i].col;

      //Only allow if my same color isn't in that spot. 
      //Insert numerical location (0-64) as possible. 
      if (amBlack && isNotBlack(board, r, c))
         possible.insert(r * 8 + c);
      if (!amBlack && isNotWhite(board, r, c))
         possible.insert(r * 8 + c);
   }
   // what about castling?
}