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
   char promote;
   bool castleK;
   bool castleQ;
   bool isWhite;

   void read(string textMove);

public:
   Move();
   Move(string textMove);
  /* Move(Position beg, Position dest);*/
   Position getSrc() const { return src; }
   Position getDest() const { return dest; }
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
   void setCapture(char c) { capture = c; }
   Move& operator=(const Move & move);
   bool operator==(const Move & move) const;
   bool operator<(const Move & move) const;
   //void operator=(string move);
   //void operator<<();
   //void operator>>();

};