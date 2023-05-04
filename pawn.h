#pragma once

#include "piece.h"

class Pawn : public Piece
{
public:
   char getLetter();
   void display(ogstream gout);
   set<int> getMoves(Board board);

};
