#include "move.h"

/*********************************************
 * DEFAULT CONSTRUCTOR
 * Create a default move
 *********************************************/
Move::Move()
{
   // set the source and destination
   src = Position(0, 0);
   dest = Position(0, 0);

   // capture and promotion information
   capture = ' ';
   promote = ' ';
   castleK = false;
   castleQ = false;
   enpassant = false;
}

/*********************************************
 * NON-DEFAULT CONSTRUCTOR
 * Create a move using Smith notation
 *********************************************/
Move::Move(string textMove)
{
   read(textMove);
}

/*********************************************
 * READ
 * Parse Smith notation into the move object
 *********************************************/
void Move::read(string textMove)
{
   string::const_iterator it = textMove.cbegin();

   // get the source
   int col = *it - 'a';
   it++;
   int row = *it - '1';
   it++;
   src.setLocation(row * 8 + col);

   // get the destination
   col = *it - 'a';
   it++;
   row = *it - '1';
   it++;
   dest.setLocation(row * 8 + col);

   // capture and promotion information
   for (; it != textMove.end(); ++it)
   {
      switch (*it)
      {
      case 'p':   // capture a pawn
      case 'n':   // capture a knight
      case 'b':   // capture a bishop
      case 'r':   // capture a rook
      case 'q':   // capture a queen
      case 'k':   // !! you can't capture a king you silly!
         capture = tolower(*it);
         break;

      case 'c':  // short castling or king's castle
         castleK = true;
         break;
      case 'C':  // long castling or queen's castle
         castleQ = true;
         break;
      case 'E':  // En-passant
         enpassant = true;
         break;

      case 'N':  // Promote to knight
      case 'B':  // Promote to Bishop
      case 'R':  // Promote to Rook
      case 'Q':  // Promote to Queen
         promote = *it;
         break;

      }
   }

   // error checking
   if (dest.getLocation() < 0 || src.getLocation() >= 64 ||
      dest.getLocation() < 0 || dest.getLocation() >= 64)
      src.setLocation(src.getLocation() - 1);
}

/*********************************************
 * ASSIGNMENT OPERATOR
 * Assign another move to this one
 *********************************************/
Move& Move::operator=(const Move & move)
{
   src = move.src;
   dest = move.dest;
   piece = move.piece;
   capture = move.capture;
   enpassant = move.enpassant;
   promote = move.promote;
   castleK = move.castleK;
   castleQ = move.castleQ;
   isWhite = move.isWhite;

   return *this;
}

/*********************************************
 * COMPARISON OPERATORS
 * Compare two move to one another
 *********************************************/
bool Move::operator==(const Move & move)
{
   return (src == move.src && dest == move.dest);
}

bool Move::operator<(const Move & move) const
{
   return (getDest().getLocation() < move.getDest().getLocation());
}
