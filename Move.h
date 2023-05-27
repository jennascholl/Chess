/***********************************************************************
* Header File:
* MOVE : Keep track of a single chess move
* Author:
* Br. Helfrich
* Summary:
* Everything we need to know about a single chess move
************************************************************************/
#pragma once
#include <string>
#include "position.h" // Every move has two Positions as attributes
#include "pieceType.h" // A piece type

class Board;
class MoveTest;

/***************************************************
* MOVE
* One move across the board
***************************************************/
class Move
{
private:
	void read(const std::string& s);
	char letterFromPieceType(PieceType pt) const;
	PieceType pieceTypeFromLetter(char letter) const;
	Position source; // where the move originated from
	Position dest; // where the move finished
	PieceType piece; // piece to be promoted to
	PieceType capture; // did a capture happen this move?
	bool enpassant; // Enpassant pawn capture
	bool castleK; // kingside castle
	bool castleQ; // queenside castle
	bool isWhite; // white's move?
	string error; // if in error state, what was the bug?

public:
	friend MoveTest;
	// constructor
	Move();
	Move(const Move& rhs) { *this = rhs; }
	Move(const char* s) { *this = s; }
	// getters
	string getText() const;
	const Position& getDes() const { return dest; }
	const Position& getSrc() const { return source; }
	PieceType getPromotion() const { return piece; }
	PieceType getCapture() const { return capture; }


	bool getEnPassant() const { return enpassant; }
	bool getCastleK() const { return castleK; }
	bool getCastleQ() const { return castleQ; }
	bool getWhiteMove() const { return isWhite; }
	bool operator == (const Move& rhs) const;
	bool operator == (const string& rhs) const { return getText() == rhs; }
	bool operator != (const string& rhs) const { return getText() != rhs; }
	bool operator != (const Move& rhs) const { return !(*this == rhs); }
	bool operator < (const Move& rhs) const {
		return dest.getLocation() <
			rhs.dest.getLocation();
	}
	// setters
	void setCapture(PieceType pt) { capture = pt; }
	void setWhiteMove(bool f) { isWhite = f; }
	void setSrc(const Position& src) { source = src; }
	void setDes(const Position& des) { dest = des; }
	void setEnPassant() { enpassant = true; }
	void setPromote(PieceType pt) { piece = pt; }
	void complete(const Board& board);
	void setCastle(bool isKing)
	{
		if (isKing)
			castleK = true;
		else
			castleQ = true;
	};
	// for file I/O though only file input is currently implemented
	friend ostream& operator << (ostream& out, Move& rhs);
	friend istream& operator >> (istream& in, Move& rhs);
	const Move& operator = (const Move& rhs);
	const Move& operator = (const string& s)
	{
		read(s);
		return *this;
	}
	const Move& operator = (const char* s)
	{
		const string str(s);
		read(str);
		return *this;
	}
};



//------------------------------------------------------------------
/*#pragma once

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
  // Move(Position beg, Position dest);
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

}; */