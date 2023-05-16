#include "position.h"

Position::Position(int r, int c) : location(-1)
{
   if ((0 <= r && r <= 7) && (0 <= c && c <= 7))
      location = c + ((7 - r) * 8);
}

Position::Position(int location) : location(-1)
{
   if (location >= 0 && location <= 63)
      this->location = location;
}

/***********************************************
 * PLACE PIECE
 * Insert a piece to the board, deleting whatever was in its place
 ************************************************/
void Position::set(int r, int c)
{
   if ((0 <= r && r <= 7) && (0 <= c && c <= 7))
      location = c + ((7 - r) * 8);
   else
      location = -1;
}