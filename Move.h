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
   bool castleK;
   bool castleQ;
   bool isWhite;
   string error;

public:
   Move();
   string getText();
   Position getSrc() { return src; }
   Position getDest() { return dest; }
   char getPromotion();
   char getCapture() { return capture; }
   bool getEnpassant() { return enpassant; }
   bool getCastleK() { return castleK; }
   bool getCastleQ() { return castleQ; }
   bool getWhiteMove() { return isWhite; }
   void setEnpassant(bool enpassant) { this->enpassant = enpassant; }
   void setCastleK(bool castle) { castleK = castle; }
   void setCastleQ(bool castle) { castleQ = castle; }
   void setWhiteMove(bool white) { isWhite = white; }
   void operator=(Move move);
   void operator=(string move);
   //void operator<<();
   //void operator>>();

};