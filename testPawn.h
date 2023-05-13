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
#include <iostream>
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
		//getMovesBlockedMoveTest();
		getMovesInitialMoveTest();
		getMovesCaptureMoveTest();
		//getMovesEnpassantMoveTest();
		//getMovesPromotionMoveTest();
	}


private:
	/*********************************************
	* GET MOVES TEST - White Pawn alone
	*
	* +---0-1-2-3-4-5-6-7---+
	* |                     |
	* 7					   	7
	* 6                     6
	* 5	  					5
	* 4		    .		    4
	* 3	       (p)		    3
	* 2					   	2
	* 1					    1
	* 0						0
	* |					   	|
	* +---0-1-2-3-4-5-6-7---+
	********************************************/
	//https://www.udacity.com/blog/2021/05/cpp-sets-explained.html for help with sets

	void getMovesSimpleMoveTest()
	{
		// setup
		Pawn* p = new Pawn();
		p->fWhite = true;
		p->lastMove = 0;
		p->numMoves = 1;
		p->position = Position(3, 3);

		Board* testBoard = new Board();
		testBoard->setToEmpty();
		testBoard->placePiece(p);

		// exercise
		set <Move> moves = p->getMoves(*testBoard);


		// verify
		assert(moves.size() == 1);
		assert(moves.find(Move("d4d5")) != moves.end());

		// teardown
		delete p;
		//testBoard->free();
		delete testBoard;
	}


	/*********************************************
	* GET BLOCKED TEST - White Pawn, blocked by a black pawn
	*
	* +---a-b-c-d-e-f-g-h---+
	* |                     |
	* 8				   	    7
	* 7                     6
	* 6	  				   	5
	* 5			P  	        4
	* 4		   (p)			3
	* 3					   	2
	* 2					   	1
	* 1					   	0
	* |				   		|
	* +---0-1-2-3-4-5-6-7---+
	********************************************/

	/*void getMovesBlockedMoveTest()
	{

		// setup
		Pawn* wp = new Pawn();
		wp->fWhite = true;
		wp->lastMove = 0;
		wp->numMoves = 1;
		wp->position = Position(3, 3);

		Board* testBoard = new Board();
		testBoard->setToEmpty();
		//Pawn* wp = new Pawn(Position(3, 3), true);
		Pawn* bp = new Pawn(Position(3, 4), false);

		testBoard->placePiece(wp);
		testBoard->placePiece(bp);

		// exercise
		set <Move> moves = wp->getMoves(*testBoard);



		// verify
		assert(moves.size() == 1);
		assert(moves.find(Move("d4d5")) != moves.end());
		assert(moves.empty());

		// teardown
		delete wp;
		delete bp;
		//testBoard->free();
		delete testBoard;
	}*/


	/*********************************************
	* GET INITIAL TEST - White Pawn - Testing intial movement range.
	*
	* +---a-b-c-d-e-f-g-h---+
	* |                     |
	* 8					    7
	* 7                     6
	* 6	  				    5
	* 5					    4
	* 4	    .		   	    3
	* 3		.		  	    2
	* 2	   (p)		   	    1
	* 1					    0
	* |				   	    |
	* +---0-1-2-3-4-5-6-7---+
	********************************************/

	void getMovesInitialMoveTest()
	{
		// setup
		Pawn* p = new Pawn();
		p->fWhite = true;
		p->lastMove = 0;
		p->numMoves = 0;
		p->position = Position(1, 1);

		Board* testBoard = new Board();
		testBoard->setToEmpty();
		testBoard->placePiece(p);

		// exercise
		set <Move> moves = p->getMoves(*testBoard);


		// verify
		assert(moves.size() == 2);
		assert(moves.find(Move("b2b3")) != moves.end());
		assert(moves.find(Move("b2b4")) != moves.end());

		// teardown
		delete p;
		delete testBoard;
	}


	/*********************************************
	* GET CAPTURE TEST - White Pawn, 2 enpassant
	*
	* +---a-b-c-d-e-f-g-h---+
	* |                     |
	* 8				   	    7
	* 7                     6
	* 6	        		    5
	* 5		  P P P		    4
	* 4		   (p)	        3
	* 3				        2
	* 2					    1
	* 1				   	    0
	* |					    |
	* +---0-1-2-3-4-5-6-7---+
	********************************************/

	void getMovesCaptureMoveTest()
	{
		// setup
		Pawn* p = new Pawn();
		p->fWhite = true;
		p->lastMove = 0;
		p->numMoves = 1;
		p->position = Position(3, 3);

		Board* testBoard = new Board();
		testBoard->setToEmpty();
		Pawn* bp1 = new Pawn(Position(2, 4), false);
		Pawn* bp2 = new Pawn(Position(3, 4), false);
		Pawn* bp3 = new Pawn(Position(4, 4), false);


		testBoard->placePiece(p);
		testBoard->placePiece(bp1);
		testBoard->placePiece(bp2);
		testBoard->placePiece(bp3);

		// exercise
		set <Move> moves = p->getMoves(*testBoard);


		// verify
		//assert(moves.size() == 3); //Only applicable until blocked test can be fixed.
		assert(moves.size() == 2); //Actual correct value.
		//assert(moves.find(Move("d4d5")) != moves.end());
		//assert(moves.find(Move("d4d6")) != moves.end());


		assert(moves.find(Move("d4c5")) != moves.end());
		assert(moves.find(Move("d4e5")) != moves.end());

		// teardown
		delete p;
		delete testBoard;

	}

	/*********************************************
	* GET Enpassant TEST - White Pawn, 2 enpassant
	*
	* +---a-b-c-d-e-f-g-h---+
	* |                     |
	* 8					    7
	* 7                     6
	* 6	         			5
	* 5	      . P .   		4
	* 4		  P(p)P			3
	* 3				   		2
	* 2	   		     		1
	* 1				   		0
	* |					   	|
	* +---0-1-2-3-4-5-6-7---+
	********************************************/
	void getMovesEnpassantMoveTest()
	{ // setup
		Pawn* p = new Pawn();
		p->fWhite = true;
		p->lastMove = 0;
		p->numMoves = 1;
		p->position = Position(3, 3);

		Board* testBoard = new Board();
		testBoard->setToEmpty();
		Pawn* bp1 = new Pawn(Position(2, 3), false);
		Pawn* bp2 = new Pawn(Position(3, 4), false);
		Pawn* bp3 = new Pawn(Position(4, 3), false);


		testBoard->placePiece(p);
		testBoard->placePiece(bp1);
		testBoard->placePiece(bp2);
		testBoard->placePiece(bp3);

		// exercise
		set <Move> moves = p->getMoves(*testBoard);


		// verify
		assert(moves.size() == 2); //Actual correct value.

		assert(moves.find(Move("d4c5")) != moves.end());
		assert(moves.find(Move("d4e5")) != moves.end());

		// teardown
		delete p;
		delete testBoard;
	}


	/*********************************************
	* GET Promotion TEST - White Pawn, 2 enpassant
	*
	* +---a-b-c-d-e-f-g-h---+
	* |                     |
	* 8	   .   	           7
	* 7    (p)              6
	* 6	  				   5
	* 5				   	   4
	* 4					   3
	* 3				       2
	* 2				   	   1
	* 1				       0
	* |				       |
	* +---0-1-2-3-4-5-6-7---+
	********************************************/
	void getMovesPromotionMoveTest()
	{
		// setup
		Pawn* p = new Pawn();
		p->fWhite = true;
		p->lastMove = 0;
		p->numMoves = 1;
		p->position = Position(1, 6);

		Board* testBoard = new Board();
		testBoard->setToEmpty();
		testBoard->placePiece(p);

		// exercise
		set <Move> moves = p->getMoves(*testBoard);


		// verify
		assert(moves.size() == 1);
		assert(moves.find(Move("b6b7q")) != moves.end());

		// teardown
		delete p;
		//testBoard->free();
		delete testBoard;
	};

};