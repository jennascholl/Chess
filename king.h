#pragma once

#include "piece.h"

class King : public Piece
{
public:
   char getLetter();
   void display(ogstream gout);
   set<int> getMoves(Board board);
};