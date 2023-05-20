/***********************************************************************
 * Header File:
 *    TEST MOVE : test the Move class
 * Author:
 *    Br. Helfrich
 ************************************************************************/


#pragma once

 /***************************************************
  * MOVE TEST
  * Test the Position class
  ***************************************************/
class MoveTest
{
public:
    void run() const
    {
        test_move_constructor();
        test_move_assignSimple();
        test_move_assignCapture();
        test_move_assignEnpassant();
        test_move_assignCastleKing();
        test_move_assignCastleQueen();

    }
private:

    void test_move_constructor() const;
    void test_move_assignSimple() const;
    void test_move_assignCapture() const;
    void test_move_assignEnpassant() const;
    void test_move_assignCastleKing() const;
    void test_move_assignCastleQueen() const;
};