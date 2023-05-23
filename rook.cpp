#include "rook.h"

/******************************************************************************
 * ROOK : GET MOVES
 * Returns all the possible moves of the rook
 ******************************************************************************/
set<Move> Rook::getMoves(const Board& board)
{
   const Delta delta[] =
   {
      {-1, 0 }, {1, 0},
      {0, -1 }, {0, 1}
   };

   return getMovesSlide(board,
      delta, sizeof(delta) / sizeof(delta[0]));
}