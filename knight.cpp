#include "knight.h"

/******************************************************************************
 * KNIGHT : GET MOVES
 * Returns all the possible moves of the knight
 ******************************************************************************/
set<Move> Knight::getMoves(const Board& board)
{
   const Delta delta[] =
   {
      {-1, 2}, {1, 2}, {-1, -2}, {1, -2},
      {-2, 1}, {2, 1}, {-2, -1}, {2, -1}
   };

   return getMovesNoSlide(board,
      delta, sizeof(delta) / sizeof(delta[0]));
}