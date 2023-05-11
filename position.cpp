#include "position.h"

Position::Position(int r, int c)
{
   if ((0 <= r && r <= 7) && (0 <= c && c <= 7))
      location = c + ((7 - r) * 8);
   else
      location = -1;
}

void Position::set(int r, int c)
{
   if ((0 <= r && r <= 7) && (0 <= c && c <= 7))
      location = c + ((7 - r) * 8);
   else
      location = -1;
}