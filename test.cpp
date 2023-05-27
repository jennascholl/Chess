#include "test.h"
#include "testKing.h"
#include "testPawn.h"
#include "testPosition.h"
#include "testMove.h"

/*********************************************
 * TEST RUNNER
 * A driver function to run all our unit tests
 *********************************************/
void testRunner()
{
   TestKing().run();
   TestPawn().run();
   PositionTest().run();
   MoveTest().run();
}