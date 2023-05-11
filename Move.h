#pragma once

#include "position.h"
#include <string>

using namespace std;

class Move
{
private:
   Position src;
   Position dest;
   char piece;
   char capture;
   bool enpassant;
   bool promote;
   bool castleK;
   bool castleQ;
   bool isWhite;
   string text;

public:
   Move();
   Move(const char[6]);
   Move(Position beg, Position dest);
   string getText() { return text; }
   Position getSrc() { return src; }
   Position getDest() { return dest; }
   bool getPromotion() { return promote; }
   char getCapture() { return capture; }
   bool getEnpassant() { return enpassant; }
   bool getCastleK() { return castleK; }
   bool getCastleQ() { return castleQ; }
   bool getWhiteMove() { return isWhite; }
   void setSrc(Position src) { this->src = src; }
   void setDest(Position dest) { this->dest = dest; }
   void setEnpassant() { enpassant = true; }
   void setCastleK() { castleK = true; }
   void setCastleQ() { castleQ = true; }
   void setPromotion() { promote = true; }
   void setWhiteMove(bool white) { isWhite = white; }
   //void operator=(Move move);
   //void operator=(string move);
   //void operator<<();
   //void operator>>();

};