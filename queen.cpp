#include "queen.h"

/******************************************************************************
 * QUEEN : GET MOVES
 * Returns all the possible moves of the queen
 ******************************************************************************/
set<Move> Queen::getMoves(const Board& board)
{
   const Delta delta[] =
   {
      {-1, 1 }, {0, 1 }, {1, 1},
      {-1, 0 },          {1, 0},
      {-1, -1}, {0, -1}, {1, -1}
   };

   return getMovesSlide(board,
      delta, sizeof(delta) / sizeof(delta[0]));
}