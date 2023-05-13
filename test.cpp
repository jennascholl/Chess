#include "test.h"
#include "testKing.h"
#include "testPawn.h"

/*********************************************
 * TEST RUNNER
 * A driver function to run all our unit tests
 *********************************************/
void testRunner()
{
   TestKing().run();
   TestPawn().run();
}