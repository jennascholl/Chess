/***********************************************************************
 * Header File:
 *    Test Pawn : Test the Pawn class
 * Author:
 *    Ashley Offret
 * Summary:
 *    This holds the unit tests for the Pawn class. 
 ************************************************************************/


#pragma once
using namespace std;

#include "king.h"
#include "rook.h"
#include "pawn.h"
#include "space.h"
#include "move.h"

#include <cassert>
#include <set>

using namespace std;

// an empty board for testing purposes
Piece* EMPTY_BOARD[NUM_ROWS][NUM_COLS] =
{
   { &Space(Position(0, 0)), &Space(Position(0, 1)), &Space(Position(0, 2)), &Space(Position(0, 3)), &Space(Position(0, 4)), &Space(Position(0, 5)), &Space(Position(0, 6)), &Space(Position(0, 7)) },
   { &Space(Position(1, 0)), &Space(Position(1, 1)), &Space(Position(1, 2)), &Space(Position(1, 3)), &Space(Position(1, 4)), &Space(Position(1, 5)), &Space(Position(1, 6)), &Space(Position(1, 7)) },
   { &Space(Position(2, 0)), &Space(Position(2, 1)), &Space(Position(2, 2)), &Space(Position(2, 3)), &Space(Position(2, 4)), &Space(Position(2, 5)), &Space(Position(2, 6)), &Space(Position(2, 7)) },
   { &Space(Position(3, 0)), &Space(Position(3, 1)), &Space(Position(3, 2)), &Space(Position(3, 3)), &Space(Position(3, 4)), &Space(Position(3, 5)), &Space(Position(3, 6)), &Space(Position(3, 7)) },
   { &Space(Position(4, 0)), &Space(Position(4, 1)), &Space(Position(4, 2)), &Space(Position(4, 3)), &Space(Position(4, 4)), &Space(Position(4, 5)), &Space(Position(4, 6)), &Space(Position(4, 7)) },
   { &Space(Position(5, 0)), &Space(Position(5, 1)), &Space(Position(5, 2)), &Space(Position(5, 3)), &Space(Position(5, 4)), &Space(Position(5, 5)), &Space(Position(5, 6)), &Space(Position(5, 7)) },
   { &Space(Position(6, 0)), &Space(Position(6, 1)), &Space(Position(6, 2)), &Space(Position(6, 3)), &Space(Position(6, 4)), &Space(Position(6, 5)), &Space(Position(6, 6)), &Space(Position(6, 7)) },
   { &Space(Position(7, 0)), &Space(Position(7, 1)), &Space(Position(7, 2)), &Space(Position(7, 3)), &Space(Position(7, 4)), &Space(Position(7, 5)), &Space(Position(7, 6)), &Space(Position(7, 7)) }
};

/********************************
* TEST PAWN
* A friend class for Pawn which contains all its unit tests
********************************/
class TestPawn
{
public:
	void run()
	{
		getMovesSimpleMoveTest();
		getMovesBlockedMoveTest();
		getMovesInitialMoveTest();
		getMovesCaptureMoveTest();
		getMovesEnpassantMoveTest();
		getMovesPromotionMoveTest();
	}


private:
	/*********************************************
	* GET MOVES TEST - White Pawn alone
	*
	* +---a-b-c-d-e-f-g-h---+
	* |                     |
	* 8					   	8
	* 7                     7
	* 6	  					   6
	* 5		     .		   5
	* 4	       (p)		   4
	* 3					   	3
	* 2						   2
	* 1						   1
	* |					   	|
	* +---a-b-c-d-e-f-g-h---+
	********************************************/
	//https://www.udacity.com/blog/2021/05/cpp-sets-explained.html for help with sets

	void getMovesSimpleMoveTest() 
	{
		// setup
		Pawn* p;
		p->fWhite = true;
		p->lastMove = 0;
		p->numMoves = 1;
		p->position = Position(4, 6);

		Board* testBoard = new Board(EMPTY_BOARD);
		testBoard->placePiece(p);

		set <Move> expectedMoves = set<Move>
		{
			{Move(Position(4, 5), Position(5,5))}
		};

		// exercise
		set<Move> possibleMoves = p->getMoves(testBoard, Move());

		// verify
		assert(possibleMoves == expectedMoves);

		// teardown
		delete p;
		testBoard->free();
		delete testBoard;

	}


	/*********************************************
	* GET BLOCKED TEST - White Pawn, blocked by a black pawn
	*
	* +---a-b-c-d-e-f-g-h---+
	* |                     |
	* 8				   	   8
	* 7                     7
	* 6	  				   	6
	* 5			  P 	      5
	* 4		    (p)			4
	* 3					   	3
	* 2					   	2
	* 1					   	1
	* |				   		|
	* +---a-b-c-d-e-f-g-h---+
	********************************************/

	void getMovesBlockedMoveTest() 
	{
		// setup
		Pawn* wp;
		wp->fWhite = true;
		wp->lastMove = 0;
		wp->numMoves = 0;
		wp->position = Position(4, 5);

		Pawn* bp;
		bp->fWhite = false;
		bp->lastMove = 0;
		bp->numMoves = 0;
		bp->position = Position(5, 5);

		Board* testBoard = new Board(EMPTY_BOARD);
		testBoard->placePiece(wp);
		testBoard->placePiece(bp);

		// exercise
		set<Move> possibleMoves = wp->getMoves(testBoard, Move());

		// verify
		assert(possibleMoves.empty());

		// teardown
		delete wp;
		delete bp;
		testBoard->free();
		delete testBoard;
	}
	

	/*********************************************
	* GET INITIAL TEST - White Pawn - Testing intial movement range. 
	*
	* +---a-b-c-d-e-f-g-h---+
	* |                     |
	* 8					      8
	* 7                     7
	* 6	  					   6
	* 5						   5
	* 4	  	 .				   4
	* 3		 .				   3
	* 2	   (p)				2
	* 1						   1
	* |						   |
	* +---a-b-c-d-e-f-g-h---+
	********************************************/

	void getMovesInitialMoveTest() 
	{
		// setup
		Pawn* p;
		p->fWhite = true;
		p->lastMove = 0;
		p->numMoves = 0;
		p->position = Position(2, 3);

		Board* testBoard = new Board(EMPTY_BOARD);
		testBoard->placePiece(p);

		set <Move> expectedMoves = set<Move>
		{
			{Move(Position(2, 3), Position(3,3))}, {Move(Position(2, 3), Position(4,3))}
		};

		// exercise
		set<Move> possibleMoves = p->getMoves(testBoard, Move());

		// verify
		assert(possibleMoves == expectedMoves);

		// teardown
		delete p;
		testBoard->free();
		delete testBoard;
	}

	/*********************************************
	* GET CAPTURE TEST - White Pawn, 2 enpassant
	*
	* +---a-b-c-d-e-f-g-h---+
	* |                     |
	* 8				   	   8
	* 7     P P P           7
	* 6	   (p)				6
	* 5						   5
	* 4						   4
	* 3						   3
	* 2						   2
	* 1						   1
	* |						   |
	* +---a-b-c-d-e-f-g-h---+
	********************************************/

	void getMovesCaptureMoveTest() 
	{
		// setup
		Pawn* wp;
		wp->fWhite = true;
		wp->lastMove = 0;
		wp->numMoves = 0;
		wp->position = Position(6, 2);

		Pawn* bp1 = new Pawn(Position(7, 2), false);
		Pawn* bp2 = new Pawn(Position(7, 3), false);
		Pawn* bp3 = new Pawn(Position(7, 4), false);
		

		Board* testBoard = new Board(EMPTY_BOARD);
		testBoard->placePiece(wp);
		testBoard->placePiece(bp1);
		testBoard->placePiece(bp2);
		testBoard->placePiece(bp3);

		set <Move> expectedMoves = set<Move>
		{
			{Move(Position(6, 3), Position(7,2))}, {Move(Position(6, 3), Position(7, 4))}
		};

		// exercise
		set<Move> possibleMoves = wp->getMoves(testBoard, Move());

		// verify
		assert(possibleMoves == expectedMoves);

		// teardown
		delete wp;
		delete bp1;
		delete bp2;
		delete bp3;

		testBoard->free();
		delete testBoard;
	}

	/*********************************************
	* GET Enpassant TEST - White Pawn, 2 enpassant
	*
	* +---a-b-c-d-e-f-g-h---+
	* |                     |
	* 8					      8
	* 7                     7
	* 6	  . P .  			6
	* 5	  P(p)P				5
	* 4					   	4
	* 3				   		3
	* 2	   		     		2
	* 1				   		1
	* |					   	|
	* +---a-b-c-d-e-f-g-h---+
	********************************************/
   void getMovesEnpassantMoveTest() 
   {
		// setup
		Pawn* wp;
		wp->fWhite = true;
		wp->lastMove = 0;
		wp->numMoves = 0;
		wp->position = Position(5, 3);

		Pawn* bp1;
		bp1->fWhite = false;
		bp1->lastMove = 0;
		bp1->numMoves = 0;
		bp1->position = Position(5, 2);

		Pawn* bp2;
		bp2->fWhite = false;
		bp2->lastMove = 0;
		bp2->numMoves = 1;
		bp2->position = Position(5, 4);

		Pawn* bp3;
		bp3->fWhite = false;
		bp3->lastMove = 0;
		bp3->numMoves = 1;
		bp3->position = Position(6, 3);

		Board* testBoard = new Board(EMPTY_BOARD);
		testBoard->placePiece(wp);
		testBoard->placePiece(bp1);
		testBoard->placePiece(bp2);
		testBoard->placePiece(bp3);

		Move enpassant1 = Move(Position(5, 3), Position(6, 2));
		Move enpassant2 = Move(Position(5, 3), Position(6, 4));
		enpassant1.setEnpassant();
		enpassant2.setEnpassant();

		set <Move> expectedMoves = set<Move>
		{
			enpassant1, enpassant2
		};

		// excercise
		set<Move> possibleMoves = wp->getMoves(testBoard, Move());

		// verify
		assert(possibleMoves == expectedMoves);

		// teardown
		delete wp;
		delete bp1;
		delete bp2;
		delete bp3;

		testBoard->free();
		delete testBoard;
	}

	/*********************************************
	* GET Promotion TEST - White Pawn, 2 enpassant
	*
	* +---a-b-c-d-e-f-g-h---+
	* |                     |
	* 8	  	.   	        8
	* 7    (p)              7
	* 6	  				    6
	* 5				   	    5
	* 4					    4
	* 3					   	3
	* 2				   	    2
	* 1					   	1
	* |					   	|
	* +---a-b-c-d-e-f-g-h---+
	********************************************/
	void getMovesPromotionMoveTest() 
	{
		// setup
		Pawn* p;
		p->fWhite = true;
		p->lastMove = 0;
		p->numMoves = 0;
		p->position = Position(7, 2);

		Board* testBoard = new Board(EMPTY_BOARD);
		testBoard->placePiece(p);

		Move promotion = Move(Position(7, 2), Position(8, 2));
		promotion.setPromotion();
		set <Move> expectedMoves = set<Move>
		{
			promotion;
		};

		// exercise
		set<Move> possibleMoves = p->getMoves(testBoard, Move());

		// verify
		assert(possibleMoves == expectedMoves);

		// teardown
		delete p;
		testBoard->free();
		delete testBoard;
	} 
};



