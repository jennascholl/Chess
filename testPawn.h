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
	* +---0-1-2-3-4-5-6-7---+
	* |                     |
	* 7					   	7
	* 6                     6
	* 5                     5
	* 4		     .         4
	* 3	       (p)		   3
	* 2					   	2
	* 1					      1
	* 0						   0
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
		*testBoard += p;

		// exercise
		set <Move> moves = p->getMoves(*testBoard);

		// verify
		assert(moves.size() == 1);
		moves.begin()->getText();
		assert(moves.find(Move("d4d5")) != moves.end());
		assert(p->fWhite);
		assert(p->lastMove == 0);
		assert(p->numMoves == 1);
		assert(p->position == Position(3, 3));

		// teardown
		testBoard->free();
		delete testBoard;
	}


	/*********************************************
	* GET BLOCKED TEST - White Pawn, blocked by a black pawn
	*
	* +---a-b-c-d-e-f-g-h---+
	* |                     |
	* 8				   	   7
	* 7                     6
	* 6	  				   	5
	* 5			P           4
	* 4		  (p)          3
	* 3					   	2
	* 2					   	1
	* 1					   	0
	* |				   		|
	* +---0-1-2-3-4-5-6-7---+
	********************************************/

	void getMovesBlockedMoveTest()
	{

		// setup
		Pawn* wp = new Pawn();
		wp->fWhite = true;
		wp->lastMove = 0;
		wp->numMoves = 1;
		wp->position = Position(3, 3);

		Board* testBoard = new Board();
		testBoard->setToEmpty();
		Pawn* bp = new Pawn(Position(4, 3), false);

		*testBoard += wp;
		*testBoard += bp;

		// exercise
		set <Move> moves = wp->getMoves(*testBoard);

		// verify
		assert(moves.size() == 0);
		assert(moves.empty());
		assert(wp->fWhite);
		assert(wp->lastMove == 0);
		assert(wp->numMoves == 1);
		assert(wp->position == Position(3, 3));

		// teardown
		testBoard->free();
		delete testBoard;
	}


	/*********************************************
	* GET INITIAL TEST - White Pawn - Testing intial movement range.
	*
	* +---a-b-c-d-e-f-g-h---+
	* |                     |
	* 8					      7
	* 7                     6
	* 6	  				      5
	* 5					      4
	* 4	  .               3
	* 3	  .		  	      2
	* 2	 (p)		   	   1
	* 1                     0
	* |				   	   |
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
		*testBoard += p;

		// exercise
		set <Move> moves = p->getMoves(*testBoard);
		moves.rbegin()->getText();

		// verify
		assert(moves.size() == 2);
		assert(moves.find(Move("b2b3")) != moves.end());
		assert(moves.find(Move("b2b4")) != moves.end());
		assert(p->fWhite);
		assert(p->lastMove == 0);
		assert(p->numMoves == 0);
		assert(p->position == Position(1, 1));

		// teardown
		testBoard->free();
		delete testBoard;
	}


	/*********************************************
	* GET CAPTURE TEST - White Pawn, 2 enpassant
	*
	* +---a-b-c-d-e-f-g-h---+
	* |                     |
	* 8                     7
	* 7                     6
	* 6                     5
	* 5		 P P P         4
	* 4		  (p)          3
	* 3				         2
	* 2					      1
	* 1				   	   0
	* |					      |
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
		Pawn* bp1 = new Pawn(Position(4, 2), false);
		Pawn* bp2 = new Pawn(Position(4, 3), false);
		Pawn* bp3 = new Pawn(Position(4, 4), false);

		*testBoard += p;
		*testBoard += bp1;
		*testBoard += bp2;
		*testBoard += bp3;

		// exercise
		set <Move> moves = p->getMoves(*testBoard);


		// verify
		assert(moves.size() == 2);
		assert(moves.find(Move("d4c5p")) != moves.end());
		assert(moves.find(Move("d4e5p")) != moves.end());
		assert(p->fWhite);
		assert(p->lastMove == 0);
		assert(p->numMoves == 1);
		assert(p->position == Position(3, 3));

		// teardown
		testBoard->free();
		delete testBoard;

	}

	/*********************************************
	* GET Enpassant TEST - White Pawn, 2 enpassant
	*
	* +---a-b-c-d-e-f-g-h---+
	* |                     |
	* 8                     7
	* 7                     6
	* 6	         			5
	* 5	    . P .   		4
	* 4	    P(p)P			3
	* 3				   		2
	* 2	   		     		1
	* 1				   		0
	* |					   	|
	* +---0-1-2-3-4-5-6-7---+
	********************************************/
	void getMovesEnpassantMoveTest()
	{ 
		// setup
		Pawn* p = new Pawn();
		p->fWhite = true;
		p->lastMove = 0;
		p->numMoves = 1;
		p->position = Position(3, 3);

		Board* testBoard = new Board();
		testBoard->setToEmpty();
		Pawn* bp1 = new Pawn(Position(3, 2), false);
		Pawn* bp2 = new Pawn(Position(3, 4), false);
		Pawn* bp3 = new Pawn(Position(4, 3), false);
		bp1->numMoves = 1;
		bp2->numMoves = 1;

		*testBoard += p;
		*testBoard += bp1;
		*testBoard += bp2;
		*testBoard += bp3;

		// exercise
		set <Move> moves = p->getMoves(*testBoard);


		// verify
		assert(moves.size() == 2); //Actual correct value.
		assert(moves.find(Move("d4c5E")) != moves.end());
		assert(moves.find(Move("d4e5E")) != moves.end());
		assert(p->fWhite);
		assert(p->lastMove == 0);
		assert(p->numMoves == 1);
		assert(p->position == Position(3, 3));

		// teardown
		testBoard->free();
		delete testBoard;
	}


	/*********************************************
	* GET Promotion TEST - White Pawn, 2 enpassant
	*
	* +---a-b-c-d-e-f-g-h---+
	* |                     |
	* 8	  .               7
	* 7    (p)              6
	* 6	  				      5
	* 5				   	   4
	* 4					      3
	* 3				         2
	* 2				   	   1
	* 1				         0
	* |				         |
	* +---0-1-2-3-4-5-6-7---+
	********************************************/
	void getMovesPromotionMoveTest()
	{
		// setup
		Pawn* p = new Pawn();
		p->fWhite = true;
		p->lastMove = 0;
		p->numMoves = 1;
		p->position = Position(6, 1);

		Board* testBoard = new Board();
		testBoard->setToEmpty();
		*testBoard += p;

		// exercise
		set <Move> moves = p->getMoves(*testBoard);

		// verify
		assert(moves.size() == 1);
		assert(moves.find(Move("b7b8Q")) != moves.end());
		assert(p->fWhite);
		assert(p->lastMove == 0);
		assert(p->numMoves == 1);
		assert(p->position == Position(6, 1));

		// teardown
		testBoard->free();
		delete testBoard;
	};

};