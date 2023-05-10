/***********************************************************************
 * Header File:
 *    Point : The representation of a position on the screen
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a location on the screen.
 ************************************************************************/


#pragma once

#include <iostream>
using namespace std;

 /*********************************************
  * POINT
  * A single position.
  *********************************************/
class Position
{
private:
   char location;
   double squareWidth;
   double squareHeight;

public:
   // constructors
	Position(int row, int col)
	{
		//I'm not sure if we are converting the rows into a letter or keeping
		// it a number (ex: 2,2 = B2). I'm making it assuming it is.
		
		//Convert the row number into a letter. Are we counting 0?
		char rowChar;
		switch (row)
		{
		case 1:
			rowChar = 'a';
			break;
		case 2:
			rowChar = 'b';
			break;
		case 3:
			rowChar = 'c';
			break;
		case 4:
			rowChar = 'd';
			break;
		case 5:
			rowChar = 'e';
			break;
		case 6:
			rowChar = 'f';
			break;
		case 7:
			rowChar = 'g';
			break;
		case 8:
			rowChar = 'h';
			break;
		default:
			cout << "Row character did not update properly. \n";
		}		
		
		//combine row and column values
		this->location = rowChar + char(col);
		


	};

   // getters
   int getRow();
   int getCol();

   // setters
   void setRow(int r);
   void setCol(int c);
   void set(int r, int c);
   void adjustRow(int dRow);
   void adjustCol(int dCol);

   bool isValid();
   bool operator==(Position rhs) { return location == rhs.location; }
   void operator=(Position rhs);
   // void operator+(Delta rhs);
};

// stream I/O useful for debugging
std::ostream& operator << (std::ostream& out, const Position& pt);
std::istream& operator >> (std::istream& in, Position& pt);


