#pragma once

#include "piece.h"
#include "move.h"
#include "uiDraw.h"

class Board
{
private:
   Piece* board[64];
   int currentMove;
   ogstream gout;

public:
   Board(ogstream gout);
   Board(Piece* boardTemplate[8][8]);
   int getCurrentMove() { return currentMove; }
   bool whiteTurn() { return currentMove % 2; }
   void display(Position posHover, Position posSelect);
   Piece* get(Position pos);
   void free();
   void reset();
   void move(Move move);
   void operator=(Piece piece);
   void swap(Position pos1, Position pos2);
   void assertBoard();
};