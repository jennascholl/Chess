/***********************************************************************
* Header File:
* TEST MOVE : test the Move class
* Author:
* Br. Helfrich
************************************************************************/
#include "testMove.h"
#include "move.h"
#include <cassert>
/*************************************
* Constructor
**************************************/
void MoveTest::test_move_constructor() const
{ // SETUP
// EXERCISE
	Move moveTest; // default constructor
	// VERIFY
	assert(Position() == moveTest.source);
	assert(Position() == moveTest.dest);
	assert(SPACE == moveTest.piece);
	assert(SPACE == moveTest.capture);
	assert(!moveTest.enpassant);
	assert(!moveTest.castleK);
	assert(!moveTest.castleQ);
	assert(moveTest.isWhite);
} // TEARDOWN
/*************************************
* ASSIGN string
**************************************/
void MoveTest::test_move_assignSimple() const
{ // SETUP
	Move move;
	move.source = "f8";
	move.dest = "f8";
	move.piece = KNIGHT;
	move.capture = BISHOP;
	move.enpassant = true;
	move.castleK = true;
	move.castleQ = true;
	move.isWhite = false;
	move.error = "ERROR";
	// EXERCISE
	move = string("e5e6");
	// VERIFY
	assert(Position(4, 4) == move.source);
	assert(Position(5, 4) == move.dest);
	assert(SPACE == move.piece);
	assert(SPACE == move.capture);
	assert(false == move.enpassant);
	assert(false == move.castleK);
	assert(false == move.castleQ);
	assert(true == move.isWhite);
} // TEARDOWN
void MoveTest::test_move_assignCapture() const
{ // SETUP
	Move move;
	move.source = "f8";
	move.dest = "f8";
	move.piece = KNIGHT;
	move.capture = BISHOP;
	move.enpassant = true;
	move.castleK = true;
	move.castleQ = true;
	move.isWhite = false;
	move.error = "ERROR";
	// EXERCISE
	move = string("e5e6r");
	// VERIFY
	assert(Position(4, 4) == move.source);
	assert(Position(5, 4) == move.dest);
	assert(SPACE == move.piece);
	assert(ROOK == move.capture);
	assert(false == move.enpassant);
	assert(false == move.castleK);
	assert(false == move.castleQ);
	assert(true == move.isWhite);
} // TEARDOWN
void MoveTest::test_move_assignEnpassant() const
{ // SETUP
	Move move;
	move.source = "f8";
	move.dest = "f8";
	move.piece = KNIGHT;
	move.capture = BISHOP;
	move.enpassant = false;
	move.castleK = true;
	move.castleQ = true;
	move.isWhite = false;
	move.error = "ERROR";
	// EXERCISE
	move = string("e5f6E");
	// VERIFY
	assert(Position(4, 4) == move.source);
	assert(Position(5, 5) == move.dest);
	assert(SPACE == move.piece);
	assert(SPACE == move.capture);
	assert(true == move.enpassant);
	assert(false == move.castleK);
	assert(false == move.castleQ);
	assert(true == move.isWhite);
} // TEARDOWN
void MoveTest::test_move_assignCastleKing() const
{ // SETUP
	Move move;
	move.source = "f8";
	move.dest = "f8";
	move.piece = KNIGHT;
	move.capture = BISHOP;
	move.enpassant = true;
	move.castleK = true;
	move.castleQ = true;
	move.isWhite = false;
	move.error = "ERROR";
	// EXERCISE
	move = string("e1g1c");
	// VERIFY
	assert(Position(0, 4) == move.source);
	assert(Position(0, 6) == move.dest);
	assert(SPACE == move.piece);
	assert(SPACE == move.capture);
	assert(false == move.enpassant);
	assert(true == move.castleK);
	assert(false == move.castleQ);
	assert(true == move.isWhite);
} // TEARDOWN
void MoveTest::test_move_assignCastleQueen() const
{ // SETUP
	Move move;
	move.source = "f8";
	move.dest = "f8";
	move.piece = KNIGHT;
	move.capture = BISHOP;
	move.enpassant = true;
	move.castleK = true;
	move.castleQ = true;
	move.isWhite = false;
	move.error = "ERROR";
	// EXERCISE
	move = string("e1c1C");
	// VERIFY
	assert(Position(0, 4) == move.source);
	assert(Position(0, 2) == move.dest);
	assert(SPACE == move.piece);
	assert(SPACE == move.capture);
	assert(false == move.enpassant);
	assert(false == move.castleK);
	assert(true == move.castleQ);
	assert(true == move.isWhite);
} // TEARDOWN