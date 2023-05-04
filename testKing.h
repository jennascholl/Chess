/***********************************************************************
 * Header File:
 *    Test King : Test the King class
 * Author:
 *    Jenna Scholl
 * Summary:
 *    All the unit tests for King
 ************************************************************************/

#pragma once

#include "king.h"
#include "chess.cpp"
#include <cassert>

/********************************
* TEST KING
* A friend class for King which contains all its unit tests
********************************/
class TestKing
{
public:
   void run()
   {
      test_getMoves_free();
      test_getMoves_blocked();
      test_getMoves_capture();
      test_getMoves_castle();
      test_getMoves_castle_king_moved();
      test_getMoves_castle_rook_moved();
      test_getMoves_castle_blocked();
      test_getMoves_castle();
   }

private:
   /********************************
   * GET MOVES TEST - white king free
   * +---a-b-c-d-e-f-g-h---+
   * |                     |
   * 8                     8
   * 7                     7
   * 6         . . .       6
   * 5         . k .       5
   * 4         . . .       4
   * 3                     3
   * 2                     2
   * 1                     1
   * |                     |
   * +---a-b-c-d-e-f-g-h---+
   ********************************/
   void test_getMoves_free()
   {
      // setup
      King* k = new King(Position(5, 5), true /*isWhite*/);
      Board* testBoard = new Board(EMPTY_BOARD);

      // exercise
      set<Move> possibleMoves = k->getMoves(testBoard, Move());

      // verify

      // teardown
   }

   /********************************
   * GET MOVES TEST - white king blocked
   * +---a-b-c-d-e-f-g-h---+
   * |                     |
   * 8                     8
   * 7                     7
   * 6         p p p       6
   * 5         p k p       5
   * 4         p p p       4
   * 3                     3
   * 2                     2
   * 1                     1
   * |                     |
   * +---a-b-c-d-e-f-g-h---+
   ********************************/
   void test_getMoves_blocked()
   {
      // setup

      // exercise

      // verify

      // teardown
   }

   /********************************
   * GET MOVES TEST - white king capture
   * +---a-b-c-d-e-f-g-h---+
   * |                     |
   * 8                     8
   * 7                     7
   * 6         P P P       6
   * 5         P k P       5
   * 4         P P P       4
   * 3                     3
   * 2                     2
   * 1                     1
   * |                     |
   * +---a-b-c-d-e-f-g-h---+
   ********************************/
   void test_getMoves_capture()
   {
      // setup

      // exercise

      // verify

      // teardown
   }

   /********************************
   * GET MOVES TEST - white king castle (king moved)
   * +---a-b-c-d-e-f-g-h---+
   * |                     |
   * 8                     8
   * 7                     7
   * 6                     6
   * 5                     5
   * 4                     4
   * 3                     3
   * 2         p p p       2
   * 1   r     . k .   r   1
   * |                     |
   * +---a-b-c-d-e-f-g-h---+
   ********************************/
   void test_getMoves_castle_king_moved()
   {
      // setup

      // exercise

      // verify

      // teardown
   }

   /********************************
   * GET MOVES TEST - white king castle (rook moved)
   * +---a-b-c-d-e-f-g-h---+
   * |                     |
   * 8                     8
   * 7                     7
   * 6                     6
   * 5                     5
   * 4                     4
   * 3                     3
   * 2         p p p       2
   * 1   r     . k .   r   1
   * |                     |
   * +---a-b-c-d-e-f-g-h---+
   ********************************/
   void test_getMoves_castle_rook_moved()
   {
      // setup

      // exercise

      // verify

      // teardown
   }

   /********************************
   * GET MOVES TEST - white king castle (blocked)
   * +---a-b-c-d-e-f-g-h---+
   * |                     |
   * 8                     8
   * 7                     7
   * 6                     6
   * 5                     5
   * 4                     4
   * 3                     3
   * 2         p p p       2
   * 1   r p   . k . p r   1
   * |                     |
   * +---a-b-c-d-e-f-g-h---+
   ********************************/
   void test_getMoves_castle_blocked()
   {
      // setup

      // exercise

      // verify

      // teardown
   }

   /********************************
   * GET MOVES TEST - white king castle
   * +---a-b-c-d-e-f-g-h---+
   * |                     |
   * 8                     8
   * 7                     7
   * 6                     6
   * 5                     5
   * 4                     4
   * 3                     3
   * 2         p p p       2
   * 1   r   . . k . . r   1
   * |                     |
   * +---a-b-c-d-e-f-g-h---+
   ********************************/
   void test_getMoves_castle()
   {
      // setup

      // exercise

      // verify

      // teardown
   }

};