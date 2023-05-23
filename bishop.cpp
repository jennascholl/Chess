#include "bishop.h"

set<Move> Bishop::getMoves(const Board& board)
{
   const Delta delta[] =
   {
      {-1, 1}, {1, 1},
      {-1, -1}, {1, -1}
   };

   return getMovesSlide(board,
      delta, sizeof(delta) / sizeof(delta[0]));
}