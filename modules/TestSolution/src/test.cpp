#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>
#include "MathFunctions.h"

/////////////////////////////////////////////////////////////////////////////////////////////
// UnitTest.
//

BOOST_AUTO_TEST_SUITE(triangleareaTest)

BOOST_AUTO_TEST_CASE(squareTest1)
{
	BOOST_CHECK(abs(mm::TriangleArea(4) - 6.928) < 0.001);
}

BOOST_AUTO_TEST_CASE(squareTest2)
{
	if (mm::TriangleArea(0) != 0)
		BOOST_ERROR("Square equals: " + std::to_string(mm::TriangleArea(0)));
}

BOOST_AUTO_TEST_CASE(squareTest3)
{
	BOOST_CHECK(abs(mm::TriangleArea(-5) - 10.825) < 0.001);
}

BOOST_AUTO_TEST_SUITE_END()